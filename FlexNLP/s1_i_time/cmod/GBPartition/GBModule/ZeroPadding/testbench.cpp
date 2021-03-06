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

#include "SM6Spec.h"
#include "AxiSpec.h"
#include "AdpfloatSpec.h"
#include "AdpfloatUtils.h"

#include "helper.h"
#include "GBSpec.h"
#include "ZeroPadding.h"

#include <iostream>
#include <sstream>
#include <iomanip>


#define NVHLS_VERIFY_BLOCKS (ZeroPadding)
#include <nvhls_verify.h>
#ifdef COV_ENABLE
   #pragma CTC SKIP
#endif

SC_MODULE(Source) {
  sc_in<bool> clk;
  sc_in<bool> rst;  
  Connections::Out<spec::Axi::SlaveToRVA::Write> rva_in;
  
  Connections::Out<bool> start;
  Connections::Out<spec::GB::Large::DataRsp<1>>    large_rsp;

  std::vector<spec::Axi::SlaveToRVA::Write> src_vec;
  
    
  SC_CTOR(Source) {
    SC_THREAD(run);
    sensitive << clk.pos();
    async_reset_signal_is(rst, false);

  }
  
  void run(){
    spec::Axi::SlaveToRVA::Write  rva_in_src; 
    rva_in_src.rw = 1;
    rva_in_src.data = set_bytes<16>("01_00_00_02_01_42_01_40_00_10_00_01_00_00_00_01"); //is_valid=1, mode=0, sendback=0, memory_index=1, output_memory_index=0, num_vector= 16, num_output_vector=0, num_timestep=320, num_timestep_padding=0, adpbias_act=2, adpbias_atten=0, adpbias_beta = 0, adpbias_gamma=1
    rva_in_src.addr = set_bytes<3>("A0_00_10");  // last 4 bits never used 
    rva_in.Push(rva_in_src);
    wait();

    start.Push(1);
    wait();

  }
};

SC_MODULE(Dest) {
  sc_in<bool> clk;
  sc_in<bool> rst;
  Connections::In<spec::Axi::SlaveToRVA::Read> rva_out;
  Connections::In<bool> done;
  Connections::In<spec::GB::Large::DataReq>      large_req;
  
  
  std::vector<spec::Axi::SlaveToRVA::Read> dest_vec;


  SC_CTOR(Dest) {
    SC_THREAD(run);
    sensitive << clk.pos();
    async_reset_signal_is(rst, false);
  }
  
  void run(){
    wait();
    
    while (1) {
      spec::Axi::SlaveToRVA::Read rva_out_dest;
      spec::StreamType output_port_dest;
      spec::GB::Large::DataReq large_req_dest;

      if (large_req.PopNB(large_req_dest)) {
         cout << "large buffer request sent: " << " - mem index: " << large_req_dest.memory_index << " -vector index: " << large_req_dest.vector_index << " -timestep_index: " << large_req_dest.timestep_index << endl;
      }

      if (rva_out.PopNB(rva_out_dest)) {
        cout << hex << sc_time_stamp() << " Dest rva data = " << rva_out_dest.data << endl;
      }
      
      wait();    
    }
  }
};



SC_MODULE(testbench) {
  SC_HAS_PROCESS(testbench);
	sc_clock clk;
  sc_signal<bool> rst;
  
  Connections::Combinational<spec::Axi::SlaveToRVA::Write> rva_in;
  Connections::Combinational<spec::Axi::SlaveToRVA::Read> rva_out;
  Connections::Combinational<bool> start;
  Connections::Combinational<bool> done;
 
  Connections::Combinational<spec::GB::Large::DataReq>      large_req;
  Connections::Combinational<spec::GB::Large::DataRsp<1>>    large_rsp;  

  NVHLS_DESIGN(ZeroPadding) dut;
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
    dut.rva_in(rva_in);
    dut.rva_out(rva_out);
    dut.start(start);
    dut.done(done);
    dut.large_req(large_req);
    dut.large_rsp(large_rsp);
    
    source.clk(clk);
    source.rst(rst);
		source.rva_in(rva_in);
		source.start(start);
		source.large_rsp(large_rsp);
			      		
		dest.clk(clk);
		dest.rst(rst);
		dest.rva_out(rva_out);
	  dest.done(done);
	  dest.large_req(large_req);
	  
    //testset();
    		
    SC_THREAD(run);
  }
  
  /*void testset() {
    spec::Axi::SlaveToRVA::Write rva_write_tmp;
    spec::Axi::SlaveToRVA::Read  rva_read_tmp;    
    
    // AXI write 
    
    // PE config

    // Congig write
    rva_write_tmp.rw = 1;
    rva_write_tmp.data = set_bytes<16>("00_02_04_02_00_64_00_60_00_10_00_00_00_00_00_01");
    rva_write_tmp.addr = set_bytes<3>("A0_00_10");  // last 4 bits never used 
    rva_read_tmp.data = rva_write_tmp.data; 
    source.src_vec.push_back(rva_write_tmp);
    dest.dest_vec.push_back(rva_read_tmp);    
    
    // AXI read
    rva_write_tmp.rw = 0;
    rva_write_tmp.addr = set_bytes<3>("A0_00_10");
    source.src_vec.push_back(rva_write_tmp); 
     
  } */

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
};  


int sc_main(int argc, char *argv[]) {
  nvhls::set_random_seed();
  
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


