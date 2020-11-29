/*
 * Copyright (c) 2016-2018, Harvard University.  All rights reserved.
*/
#include "PEModule.h"
#include <systemc.h>
#include <mc_scverify.h>
#include <testbench/nvhls_rand.h>
#include <nvhls_connections.h>
#include <map>
#include <vector>
#include <deque>
#include <utility>
#include <sstream>
#include <string>
#include <cstdlib>
#include <math.h> // testbench only
#include <queue>
#include <iomanip>
#include <nvhls_int.h>
#include <nvhls_types.h>
#include <nvhls_vector.h>

#include "SM6Spec.h"
#include "AxiSpec.h"
#include "AdpfloatSpec.h"
#include "AdpfloatUtils.h"

#include "helper.h"

#include "../../testbench/libnpy/npy.hpp"

#define NVHLS_VERIFY_BLOCKS (PEModule)
#include <nvhls_verify.h>


#ifdef COV_ENABLE
   #pragma CTC SKIP
#endif

SC_MODULE(Source) {
  sc_in<bool> clk;
  sc_in<bool> rst;  
  Connections::Out<spec::StreamType> input_port;  
  Connections::Out<bool> start; 
  Connections::Out<spec::Axi::SlaveToRVA::Write> rva_in;

  std::vector<spec::Axi::SlaveToRVA::Write> src_vec;
 
  SC_CTOR(Source) {
    SC_THREAD(run);
    sensitive << clk.pos();
    async_reset_signal_is(rst, false);
  }

  void run() {
    spec::Axi::SlaveToRVA::Write  rva_in_src;

    wait();
    for (unsigned i = 0; i < src_vec.size(); i++) {
      if (src_vec[i].rw == 1) {
        cout << hex << sc_time_stamp() << " Source rva write data " << src_vec[i].data << endl;
      }
    
      rva_in.Push(src_vec[i]);
      wait(1);
    }
  } // run()
}; //SC MODULE Source

SC_MODULE(Dest) {
  sc_in<bool> clk;
  sc_in<bool> rst;
  Connections::In<spec::Axi::SlaveToRVA::Read> rva_out;
  Connections::In<spec::StreamType> output_port; 
  Connections::In<bool> done;  

  std::vector<spec::Axi::SlaveToRVA::Read> dest_vec;
  spec::Axi::SlaveToRVA::Read rva_out_dest;

  SC_CTOR(Dest) {
    SC_THREAD(run);
    sensitive << clk.pos();
    async_reset_signal_is(rst, false);

  }

  void run(){
    wait();
    
    unsigned i = 0;
    while (1) {
      if (rva_out.PopNB(rva_out_dest)) {
        cout << hex << sc_time_stamp() << " Dest rva data = " << rva_out_dest.data << endl;
        //assert(rva_out_dest.data == dest_vec[i].data);
        i++;
      }
      wait(1);    
    }
  }

}; //SC MODULE Dest


SC_MODULE(testbench) {
  SC_HAS_PROCESS(testbench);
  sc_clock clk;
  sc_signal<bool> rst;

  Connections::Combinational<spec::StreamType> input_port;     
  Connections::Combinational<bool> start;  
  Connections::Combinational<spec::Axi::SlaveToRVA::Write> rva_in;
  Connections::Combinational<spec::Axi::SlaveToRVA::Read> rva_out;
  Connections::Combinational<spec::StreamType> output_port; 
  Connections::Combinational<bool> done;  

  NVHLS_DESIGN(PEModule) dut;
  Source  source;
  Dest    dest;

  testbench(sc_module_name name)
  : sc_module(name),
    clk("clk", 1.0, SC_NS, 0.5, 0, SC_NS, true),
    rst("rst"),
    dut("dut"),
    source("source"),   
    dest("dest")
   {
     dut.clk(clk);
     dut.rst(rst);
     dut.input_port(input_port);
     dut.start(start);
     dut.rva_in(rva_in);
     dut.rva_out(rva_out);
     dut.output_port(output_port);
     dut.done(done);

     source.clk(clk);
     source.rst(rst);
     source.input_port(input_port);
     source.start(start);
     source.rva_in(rva_in);

     dest.clk(clk);
     dest.rst(rst);
     dest.rva_out(rva_out);
     dest.output_port(output_port);
     dest.done(done);

     testset();

     SC_THREAD(run);
   }

  void testset() {
    spec::Axi::SlaveToRVA::Write rva_write_tmp;
    spec::Axi::SlaveToRVA::Read  rva_read_tmp;
 
    // AXI write 
    // PE config
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = set_bytes<16>("00_00_00_00_00_00_00_00_00_00_20_02_01_01_01_01");
    rva_write_tmp.addr = set_bytes<3>("40_00_10");  // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data;
    source.src_vec.push_back(rva_write_tmp);
    dest.dest_vec.push_back(rva_read_tmp);    
    
    // Weight SRAM
    cout << "weight sram" << endl;
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = nvhls::get_rand<32>();
    rva_write_tmp.addr = 0x500000 + 1*16 ;
    cout << "rva_write_tmp.addr: " << hex << rva_write_tmp.addr << endl;
    //rva_write_tmp.addr = set_bytes<3>("50_00_10");  // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data;
    source.src_vec.push_back(rva_write_tmp);
    dest.dest_vec.push_back(rva_read_tmp);
    
    // Input/Bias SRAM
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = nvhls::get_rand<32>();
    rva_write_tmp.addr = set_bytes<3>("60_00_30");  // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data;
    source.src_vec.push_back(rva_write_tmp);    
    dest.dest_vec.push_back(rva_read_tmp);    
   
    
    // manager 1
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = set_bytes<16>("00_00_00_00_00_00_00_20_00_00_00_10_01_01_01_00");
    rva_write_tmp.addr = set_bytes<3>("40_00_20"); // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data;
    source.src_vec.push_back(rva_write_tmp);
    dest.dest_vec.push_back(rva_read_tmp);        
    
    // manager 1 cluster
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = nvhls::get_rand<32>();
    rva_write_tmp.addr = set_bytes<3>("40_00_30"); // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data;
    source.src_vec.push_back(rva_write_tmp);
    dest.dest_vec.push_back(rva_read_tmp); 
       
    // manager 2
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = set_bytes<16>("00_00_00_00_00_10_00_60_20_00_00_10_01_01_01_01");
    rva_write_tmp.addr = set_bytes<3>("40_00_40"); // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data;
    source.src_vec.push_back(rva_write_tmp);
    dest.dest_vec.push_back(rva_read_tmp);    
    
    // manager 2 cluster
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = nvhls::get_rand<32>();
    rva_write_tmp.addr = set_bytes<3>("40_00_50"); // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data;
    source.src_vec.push_back(rva_write_tmp);
    dest.dest_vec.push_back(rva_read_tmp);        
            
    // AXI read
    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("40_00_10");
    source.src_vec.push_back(rva_write_tmp); 

    cout << "weight sram" << endl;  
    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("50_00_10");
    source.src_vec.push_back(rva_write_tmp);    


    cout << "input/bias sram" << endl;
    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("60_00_30");
    source.src_vec.push_back(rva_write_tmp);
    
    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("40_00_20");
    source.src_vec.push_back(rva_write_tmp);
               
    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("40_00_30");
    source.src_vec.push_back(rva_write_tmp);    

    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("40_00_40");
    source.src_vec.push_back(rva_write_tmp);

    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("40_00_50");
    source.src_vec.push_back(rva_write_tmp);
  }
  


  void run(){
    wait(2, SC_NS );
    std::cout << "@" << sc_time_stamp() <<" Asserting reset" << std::endl;
    rst.write(false);
    wait(2, SC_NS );
    rst.write(true);
    std::cout << "@" << sc_time_stamp() <<" De-Asserting reset" << std::endl;
    wait(1000, SC_NS );
    std::cout << "@" << sc_time_stamp() <<" sc_stop" << std::endl;
    sc_stop();
  }  

}; //SC MODULE testbench


int sc_main(int argc, char *argv[]) {
  nvhls::set_random_seed();
  NVINT8 test = 14;
  cout << fixed2float<8, 3>(test) << endl;

  
  testbench tb("tb");
  
  sc_report_handler::set_actions(SC_ERROR, SC_DISPLAY);
  sc_start();


  bool rc = (sc_report_handler::get_count(SC_ERROR) > 0);
  if (rc)
    DCOUT("TESTBENCH FAIL" << endl);
  else
    DCOUT("TESTBENCH PASS" << endl);
  return rc;
}
