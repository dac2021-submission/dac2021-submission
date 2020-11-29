/*
 * Copyright (c) 2016-2018, Harvard University.  All rights reserved.
*/
#include <systemc.h>
#include <ac_reset_signal_is.h>
#include "axi/axi4.h"
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

#include "axi/testbench/MasterFromFile.h"
#include "SM6Spec.h"
#include "AxiSpec.h"
#include "AdpfloatSpec.h"
#include "AdpfloatUtils.h"

#include "helper.h"
#include "Top.h"
#include <chrono>

#include <iostream>
#include <sstream>
#include <iomanip>

#ifdef RUN_ILATOR
#include "flex.h"
#endif

#define NVHLS_VERIFY_BLOCKS (Top)
#define TANDEM_VERIFICATION
#include <nvhls_verify.h>

#ifdef COV_ENABLE
   #pragma CTC SKIP
#endif

bool correct = true;

SC_MODULE(Source) {
  sc_in<bool> clk;
  sc_in<bool> rst;  
  
  SC_CTOR(Source) {
    SC_THREAD(run);
    sensitive << clk.pos();
    async_reset_signal_is(rst, false);

  }
  
  void run(){
    wait(1000);
    // std::cout << "@" << sc_time_stamp() <<" TB checkpoint " << std::endl;

  } //run
};

SC_MODULE(Dest) {
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_in<bool> interrupt;

  SC_CTOR(Dest) {
    SC_THREAD(PopInterrupt);
    sensitive << clk.pos();
    async_reset_signal_is(rst, false);
  }  


  void PopInterrupt() {
   wait();
 
   while (1) {
     if (interrupt == 1) {
        cout << sc_time_stamp() << " - Interrupt signal issued!" << endl;
     }
     wait(); 
   } // while
   
  } //PopInterrupt

};



SC_MODULE(testbench) {
  SC_HAS_PROCESS(testbench);
  MasterFromFile<spec::Axi::axiCfg, true> master;

  sc_clock clk;
  sc_signal<bool> rst;
  sc_signal<bool> master_done;
  sc_signal<bool> interrupt;
  sc_signal<bool> master_inst_done;
  #ifdef RUN_ILATOR
  sc_signal< sc_biguint<1> > flex_wr_signal;
  sc_signal< sc_biguint<1> > flex_rd_signal;
  sc_signal< sc_biguint<32> > flex_addr_signal;
  sc_signal< sc_biguint<8> > flex_data_signal[16];
  uint32_t interrupted = 0;
  #endif  

  
  NVHLS_DESIGN(Top) dut;
  Source  source;
  Dest    dest;
  #ifdef RUN_ILATOR
  flex flex_i;
  #endif

  typename axi::axi4<spec::Axi::axiCfg>::read::template chan<> axi_read;
  typename axi::axi4<spec::Axi::axiCfg>::write::template chan<> axi_write;

  
  testbench(sc_module_name name)
  : sc_module(name),
     master("master", "axi_commands_for_2_lstm_64x64.txt"), //"axi_commands_for_kmeans_clustering_for_LSTM_4_timesteps_zero_first_enabled_4PEs.csv"),
     clk("clk", 1.0, SC_NS, 0.5, 0, SC_NS, true),
     rst("rst"),
     dut("dut"),
     source("source"),
     dest("dest"),
     axi_read("axi_read"),
     axi_write("axi_write")
     #ifdef RUN_ILATOR
     ,flex_i("flexnlp")
     #endif 
     {
     
    dut.clk(clk);
    dut.rst(rst);
    dut.if_axi_wr(axi_write);
    dut.if_axi_rd(axi_read);
    dut.interrupt(interrupt);

    master.clk(clk);
    master.reset_bar(rst);
    master.done(master_done);
    master.interrupt(interrupt);
    master.if_rd(axi_read);
    master.if_wr(axi_write);
    master.inst_done(master_inst_done);
    
    source.clk(clk);
    source.rst(rst);

    dest.clk(clk);
    dest.rst(rst);
    dest.interrupt(interrupt);

    #ifdef RUN_ILATOR    				
    flex_i.flex_if_axi_rd_in(flex_rd_signal);
    flex_i.flex_if_axi_wr_in(flex_wr_signal);
    flex_i.flex_addr_in_in(flex_addr_signal);
    flex_i.flex_data_in_0_in(flex_data_signal[0]);
    flex_i.flex_data_in_1_in(flex_data_signal[1]);
    flex_i.flex_data_in_2_in(flex_data_signal[2]);
    flex_i.flex_data_in_3_in(flex_data_signal[3]);
    flex_i.flex_data_in_4_in(flex_data_signal[4]);
    flex_i.flex_data_in_5_in(flex_data_signal[5]);
    flex_i.flex_data_in_6_in(flex_data_signal[6]);
    flex_i.flex_data_in_7_in(flex_data_signal[7]);
    flex_i.flex_data_in_8_in(flex_data_signal[8]);
    flex_i.flex_data_in_9_in(flex_data_signal[9]);
    flex_i.flex_data_in_10_in(flex_data_signal[10]);
    flex_i.flex_data_in_11_in(flex_data_signal[11]);
    flex_i.flex_data_in_12_in(flex_data_signal[12]);
    flex_i.flex_data_in_13_in(flex_data_signal[13]);
    flex_i.flex_data_in_14_in(flex_data_signal[14]);
    flex_i.flex_data_in_15_in(flex_data_signal[15]);
    #endif


    SC_THREAD(run);
    #ifdef RUN_ILATOR
    SC_METHOD(run_ilator);
    sensitive << master.inst_done.pos() << dut.interrupt.pos();
    #endif

  }
  
  
  void run(){
    // flex_i.instr_log.open("./instr_log_lstm.txt", ofstream::out | ofstream::trunc);

    wait(2, SC_NS );
    // std::cout << "@" << sc_time_stamp() <<" Asserting reset" << std::endl;
    rst.write(false);
    wait(2, SC_NS );
    auto t1 = std::chrono::high_resolution_clock::now();
    rst.write(true);

    // std::cout << "@" << sc_time_stamp() <<" De-Asserting reset" << std::endl;

    /*while (1) {
      wait(1, SC_NS);
      if (master_done==1) {
        cout << "Master has finished issuing AXI Writes" << endl;
      }
    }*/
    wait(150, SC_NS);
    // flex_i.instr_log.close();
    // std::cout << "Done " << std::endl;

    wait(15158, SC_NS);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << "duration: " << duration << std::endl;
    wait(50000, SC_NS );
    std::cout << "@" << sc_time_stamp() <<" sc_stop" << std::endl;

    sc_stop();
  }

  #ifdef RUN_ILATOR

  #ifdef TANDEM_VERIFICATION
  void tandem_verification_PE0_CONFIG_RNN_LAYER_SIZING() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CONFIG_RNN_LAYER_SIZING" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CONFIG_RNN_LAYER_SIZING";
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_config.is_valid != flex_i.flex_pe0_rnn_layer_sizing_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_config.is_zero_first!= flex_i.flex_pe0_rnn_layer_sizing_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_config.is_cluster != flex_i.flex_pe0_rnn_layer_sizing_is_cluster)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_config.is_bias != flex_i.flex_pe0_rnn_layer_sizing_is_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_config.num_manager != flex_i.flex_pe0_rnn_layer_sizing_num_manager)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_config.num_output != flex_i.flex_pe0_rnn_layer_sizing_num_output)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE1_CONFIG_RNN_LAYER_SIZING() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CONFIG_RNN_LAYER_SIZING" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CONFIG_RNN_LAYER_SIZING";
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_config.is_valid != flex_i.flex_pe1_rnn_layer_sizing_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_config.is_zero_first!= flex_i.flex_pe1_rnn_layer_sizing_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_config.is_cluster != flex_i.flex_pe1_rnn_layer_sizing_is_cluster)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_config.is_bias != flex_i.flex_pe1_rnn_layer_sizing_is_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_config.num_manager != flex_i.flex_pe1_rnn_layer_sizing_num_manager)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_config.num_output != flex_i.flex_pe1_rnn_layer_sizing_num_output)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE2_CONFIG_RNN_LAYER_SIZING() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CONFIG_RNN_LAYER_SIZING" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CONFIG_RNN_LAYER_SIZING";
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_config.is_valid != flex_i.flex_pe2_rnn_layer_sizing_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_config.is_zero_first!= flex_i.flex_pe2_rnn_layer_sizing_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_config.is_cluster != flex_i.flex_pe2_rnn_layer_sizing_is_cluster)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_config.is_bias != flex_i.flex_pe2_rnn_layer_sizing_is_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_config.num_manager != flex_i.flex_pe2_rnn_layer_sizing_num_manager)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_config.num_output != flex_i.flex_pe2_rnn_layer_sizing_num_output)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE3_CONFIG_RNN_LAYER_SIZING() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CONFIG_RNN_LAYER_SIZING" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CONFIG_RNN_LAYER_SIZING";
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_config.is_valid != flex_i.flex_pe3_rnn_layer_sizing_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_config.is_zero_first!= flex_i.flex_pe3_rnn_layer_sizing_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_config.is_cluster != flex_i.flex_pe3_rnn_layer_sizing_is_cluster)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_config.is_bias != flex_i.flex_pe3_rnn_layer_sizing_is_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_config.num_manager != flex_i.flex_pe3_rnn_layer_sizing_num_manager)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_config.num_output != flex_i.flex_pe3_rnn_layer_sizing_num_output)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_PE0_CONFIG_MEM_MNGR_FIRST() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CONFIG_MEM_MNGR_FIRST" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CONFIG_MEM_MNGR_FIRST";
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].zero_active != flex_i.flex_pe0_mem_mngr_first_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_weight != flex_i.flex_pe0_mem_mngr_first_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_bias != flex_i.flex_pe0_mem_mngr_first_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_input != flex_i.flex_pe0_mem_mngr_first_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].num_input != flex_i.flex_pe0_mem_mngr_first_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].base_weight != flex_i.flex_pe0_mem_mngr_first_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].base_bias != flex_i.flex_pe0_mem_mngr_first_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[0].base_input != flex_i.flex_pe0_mem_mngr_first_base_input)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE1_CONFIG_MEM_MNGR_FIRST() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CONFIG_MEM_MNGR_FIRST" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CONFIG_MEM_MNGR_FIRST";
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].zero_active != flex_i.flex_pe1_mem_mngr_first_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_weight != flex_i.flex_pe1_mem_mngr_first_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_bias != flex_i.flex_pe1_mem_mngr_first_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_input != flex_i.flex_pe1_mem_mngr_first_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].num_input != flex_i.flex_pe1_mem_mngr_first_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].base_weight != flex_i.flex_pe1_mem_mngr_first_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].base_bias != flex_i.flex_pe1_mem_mngr_first_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[0].base_input != flex_i.flex_pe1_mem_mngr_first_base_input)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE2_CONFIG_MEM_MNGR_FIRST() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CONFIG_MEM_MNGR_FIRST" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CONFIG_MEM_MNGR_FIRST";
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].zero_active != flex_i.flex_pe2_mem_mngr_first_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_weight != flex_i.flex_pe2_mem_mngr_first_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_bias != flex_i.flex_pe2_mem_mngr_first_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_input != flex_i.flex_pe2_mem_mngr_first_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].num_input != flex_i.flex_pe2_mem_mngr_first_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].base_weight != flex_i.flex_pe2_mem_mngr_first_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].base_bias != flex_i.flex_pe2_mem_mngr_first_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[0].base_input != flex_i.flex_pe2_mem_mngr_first_base_input)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE3_CONFIG_MEM_MNGR_FIRST() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CONFIG_MEM_MNGR_FIRST" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CONFIG_MEM_MNGR_FIRST";
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].zero_active != flex_i.flex_pe3_mem_mngr_first_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_weight != flex_i.flex_pe3_mem_mngr_first_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_bias != flex_i.flex_pe3_mem_mngr_first_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].adplfloat_bias_input != flex_i.flex_pe3_mem_mngr_first_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].num_input != flex_i.flex_pe3_mem_mngr_first_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].base_weight != flex_i.flex_pe3_mem_mngr_first_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].base_bias != flex_i.flex_pe3_mem_mngr_first_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[0].base_input != flex_i.flex_pe3_mem_mngr_first_base_input)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_PE0_CONFIG_MEM_MNGR_SECOND() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CONFIG_MEM_MNGR_SECOND" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CONFIG_MEM_MNGR_SECOND";
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].zero_active != flex_i.flex_pe0_mem_mngr_second_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_weight != flex_i.flex_pe0_mem_mngr_second_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_bias != flex_i.flex_pe0_mem_mngr_second_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_input != flex_i.flex_pe0_mem_mngr_second_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].num_input != flex_i.flex_pe0_mem_mngr_second_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].base_weight != flex_i.flex_pe0_mem_mngr_second_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].base_bias != flex_i.flex_pe0_mem_mngr_second_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.pecore_inst.pe_manager[1].base_input != flex_i.flex_pe0_mem_mngr_second_base_input)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE1_CONFIG_MEM_MNGR_SECOND() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CONFIG_MEM_MNGR_SECOND" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CONFIG_MEM_MNGR_SECOND";
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].zero_active != flex_i.flex_pe1_mem_mngr_second_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_weight != flex_i.flex_pe1_mem_mngr_second_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_bias != flex_i.flex_pe1_mem_mngr_second_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_input != flex_i.flex_pe1_mem_mngr_second_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].num_input != flex_i.flex_pe1_mem_mngr_second_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].base_weight != flex_i.flex_pe1_mem_mngr_second_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].base_bias != flex_i.flex_pe1_mem_mngr_second_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.pecore_inst.pe_manager[1].base_input != flex_i.flex_pe1_mem_mngr_second_base_input)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE2_CONFIG_MEM_MNGR_SECOND() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CONFIG_MEM_MNGR_SECOND" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CONFIG_MEM_MNGR_SECOND";
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].zero_active != flex_i.flex_pe2_mem_mngr_second_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_weight != flex_i.flex_pe2_mem_mngr_second_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_bias != flex_i.flex_pe2_mem_mngr_second_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_input != flex_i.flex_pe2_mem_mngr_second_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].num_input != flex_i.flex_pe2_mem_mngr_second_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].base_weight != flex_i.flex_pe2_mem_mngr_second_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].base_bias != flex_i.flex_pe2_mem_mngr_second_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.pecore_inst.pe_manager[1].base_input != flex_i.flex_pe2_mem_mngr_second_base_input)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE3_CONFIG_MEM_MNGR_SECOND() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CONFIG_MEM_MNGR_SECOND" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CONFIG_MEM_MNGR_SECOND";
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].zero_active != flex_i.flex_pe3_mem_mngr_second_zero_active)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_weight != flex_i.flex_pe3_mem_mngr_second_adpfloat_bias_w)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_bias != flex_i.flex_pe3_mem_mngr_second_adpfloat_bias_b)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].adplfloat_bias_input != flex_i.flex_pe3_mem_mngr_second_adpfloat_bias_i)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].num_input != flex_i.flex_pe3_mem_mngr_second_num_input)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].base_weight != flex_i.flex_pe3_mem_mngr_second_base_weight)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].base_bias != flex_i.flex_pe3_mem_mngr_second_base_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.pecore_inst.pe_manager[1].base_input != flex_i.flex_pe3_mem_mngr_second_base_input)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_PE0_CORE_STORE_WEIGHT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CORE_STORE_WEIGHT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CORE_STORE_WEIGHT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[0]->pemodule_inst.pecore_inst.weight_write_addrs[0];
    auto impl_word = dut.pe_ptrs[0]->pemodule_inst.pecore_inst.weight_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe0_core_weight_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }
  void tandem_verification_PE1_CORE_STORE_WEIGHT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CORE_STORE_WEIGHT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CORE_STORE_WEIGHT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[1]->pemodule_inst.pecore_inst.weight_write_addrs[0];
    auto impl_word = dut.pe_ptrs[1]->pemodule_inst.pecore_inst.weight_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe1_core_weight_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }
  void tandem_verification_PE2_CORE_STORE_WEIGHT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CORE_STORE_WEIGHT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CORE_STORE_WEIGHT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[2]->pemodule_inst.pecore_inst.weight_write_addrs[0];
    auto impl_word = dut.pe_ptrs[2]->pemodule_inst.pecore_inst.weight_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe2_core_weight_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }
  void tandem_verification_PE3_CORE_STORE_WEIGHT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CORE_STORE_WEIGHT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CORE_STORE_WEIGHT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[3]->pemodule_inst.pecore_inst.weight_write_addrs[0];
    auto impl_word = dut.pe_ptrs[3]->pemodule_inst.pecore_inst.weight_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe3_core_weight_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }

  void tandem_verification_PE0_CORE_STORE_INPUT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CORE_STORE_INPUT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CORE_STORE_INPUT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[0]->pemodule_inst.pecore_inst.input_write_addrs[0];
    auto impl_word = dut.pe_ptrs[0]->pemodule_inst.pecore_inst.input_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe0_core_input_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }
  void tandem_verification_PE1_CORE_STORE_INPUT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CORE_STORE_INPUT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CORE_STORE_INPUT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[1]->pemodule_inst.pecore_inst.input_write_addrs[0];
    auto impl_word = dut.pe_ptrs[1]->pemodule_inst.pecore_inst.input_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe1_core_input_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }
  void tandem_verification_PE2_CORE_STORE_INPUT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CORE_STORE_INPUT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CORE_STORE_INPUT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[2]->pemodule_inst.pecore_inst.input_write_addrs[0];
    auto impl_word = dut.pe_ptrs[2]->pemodule_inst.pecore_inst.input_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe2_core_input_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }
  void tandem_verification_PE3_CORE_STORE_INPUT_BUFFER() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CORE_STORE_INPUT_BUFFER" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CORE_STORE_INPUT_BUFFER";
    uint32_t word_addr = dut.pe_ptrs[3]->pemodule_inst.pecore_inst.input_write_addrs[0];
    auto impl_word = dut.pe_ptrs[3]->pemodule_inst.pecore_inst.input_mem.GetData(word_addr);
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr]  != flex_i.flex_pe3_core_input_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }

  void tandem_verification_PE0_CONFIG_ACT_MNGR() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CONFIG_ACT_MNGR" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CONFIG_ACT_MNGR";
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.is_valid != flex_i.flex_pe0_act_mngr_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.is_zero_first != flex_i.flex_pe0_act_mngr_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.adpfloat_bias != flex_i.flex_pe0_act_mngr_adpfloat_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.num_inst != flex_i.flex_pe0_act_mngr_num_inst)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.num_output != flex_i.flex_pe0_act_mngr_num_output)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.buffer_addr_base != flex_i.flex_pe0_act_mngr_buffer_addr_base)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.output_addr_base != flex_i.flex_pe0_act_mngr_output_addr_base)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE1_CONFIG_ACT_MNGR() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CONFIG_ACT_MNGR" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CONFIG_ACT_MNGR";
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.is_valid != flex_i.flex_pe1_act_mngr_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.is_zero_first != flex_i.flex_pe1_act_mngr_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.adpfloat_bias != flex_i.flex_pe1_act_mngr_adpfloat_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.num_inst != flex_i.flex_pe1_act_mngr_num_inst)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.num_output != flex_i.flex_pe1_act_mngr_num_output)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.buffer_addr_base != flex_i.flex_pe1_act_mngr_buffer_addr_base)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.output_addr_base != flex_i.flex_pe1_act_mngr_output_addr_base)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE2_CONFIG_ACT_MNGR() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CONFIG_ACT_MNGR" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CONFIG_ACT_MNGR";
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.is_valid != flex_i.flex_pe2_act_mngr_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.is_zero_first != flex_i.flex_pe2_act_mngr_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.adpfloat_bias != flex_i.flex_pe2_act_mngr_adpfloat_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.num_inst != flex_i.flex_pe2_act_mngr_num_inst)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.num_output != flex_i.flex_pe2_act_mngr_num_output)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.buffer_addr_base != flex_i.flex_pe2_act_mngr_buffer_addr_base)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.output_addr_base != flex_i.flex_pe2_act_mngr_output_addr_base)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE3_CONFIG_ACT_MNGR() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CONFIG_ACT_MNGR" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CONFIG_ACT_MNGR";
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.is_valid != flex_i.flex_pe3_act_mngr_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.is_zero_first != flex_i.flex_pe3_act_mngr_is_zero_first)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.adpfloat_bias != flex_i.flex_pe3_act_mngr_adpfloat_bias)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.num_inst != flex_i.flex_pe3_act_mngr_num_inst)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.num_output != flex_i.flex_pe3_act_mngr_num_output)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.buffer_addr_base != flex_i.flex_pe3_act_mngr_buffer_addr_base)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.output_addr_base != flex_i.flex_pe3_act_mngr_output_addr_base)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_PE0_CONFIG_ACT_VECTOR_0_15() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CONFIG_ACT_VECTOR_0_15" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CONFIG_ACT_VECTOR_0_15";
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[0] != flex_i.flex_pe0_act_vector_0_15_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[1] != flex_i.flex_pe0_act_vector_0_15_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[2] != flex_i.flex_pe0_act_vector_0_15_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[3] != flex_i.flex_pe0_act_vector_0_15_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[4] != flex_i.flex_pe0_act_vector_0_15_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[5] != flex_i.flex_pe0_act_vector_0_15_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[6] != flex_i.flex_pe0_act_vector_0_15_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[7] != flex_i.flex_pe0_act_vector_0_15_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[8] != flex_i.flex_pe0_act_vector_0_15_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[9] != flex_i.flex_pe0_act_vector_0_15_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[10] != flex_i.flex_pe0_act_vector_0_15_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[11] != flex_i.flex_pe0_act_vector_0_15_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[12] != flex_i.flex_pe0_act_vector_0_15_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[13] != flex_i.flex_pe0_act_vector_0_15_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[14] != flex_i.flex_pe0_act_vector_0_15_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[15] != flex_i.flex_pe0_act_vector_0_15_Inst15)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE1_CONFIG_ACT_VECTOR_0_15() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CONFIG_ACT_VECTOR_0_15" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CONFIG_ACT_VECTOR_0_15";
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[0] != flex_i.flex_pe1_act_vector_0_15_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[1] != flex_i.flex_pe1_act_vector_0_15_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[2] != flex_i.flex_pe1_act_vector_0_15_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[3] != flex_i.flex_pe1_act_vector_0_15_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[4] != flex_i.flex_pe1_act_vector_0_15_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[5] != flex_i.flex_pe1_act_vector_0_15_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[6] != flex_i.flex_pe1_act_vector_0_15_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[7] != flex_i.flex_pe1_act_vector_0_15_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[8] != flex_i.flex_pe1_act_vector_0_15_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[9] != flex_i.flex_pe1_act_vector_0_15_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[10] != flex_i.flex_pe1_act_vector_0_15_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[11] != flex_i.flex_pe1_act_vector_0_15_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[12] != flex_i.flex_pe1_act_vector_0_15_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[13] != flex_i.flex_pe1_act_vector_0_15_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[14] != flex_i.flex_pe1_act_vector_0_15_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[15] != flex_i.flex_pe1_act_vector_0_15_Inst15)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE2_CONFIG_ACT_VECTOR_0_15() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CONFIG_ACT_VECTOR_0_15" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CONFIG_ACT_VECTOR_0_15";
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[0] != flex_i.flex_pe2_act_vector_0_15_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[1] != flex_i.flex_pe2_act_vector_0_15_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[2] != flex_i.flex_pe2_act_vector_0_15_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[3] != flex_i.flex_pe2_act_vector_0_15_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[4] != flex_i.flex_pe2_act_vector_0_15_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[5] != flex_i.flex_pe2_act_vector_0_15_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[6] != flex_i.flex_pe2_act_vector_0_15_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[7] != flex_i.flex_pe2_act_vector_0_15_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[8] != flex_i.flex_pe2_act_vector_0_15_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[9] != flex_i.flex_pe2_act_vector_0_15_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[10] != flex_i.flex_pe2_act_vector_0_15_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[11] != flex_i.flex_pe2_act_vector_0_15_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[12] != flex_i.flex_pe2_act_vector_0_15_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[13] != flex_i.flex_pe2_act_vector_0_15_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[14] != flex_i.flex_pe2_act_vector_0_15_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[15] != flex_i.flex_pe2_act_vector_0_15_Inst15)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE3_CONFIG_ACT_VECTOR_0_15() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CONFIG_ACT_VECTOR_0_15" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CONFIG_ACT_VECTOR_0_15";
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[0] != flex_i.flex_pe3_act_vector_0_15_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[1] != flex_i.flex_pe3_act_vector_0_15_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[2] != flex_i.flex_pe3_act_vector_0_15_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[3] != flex_i.flex_pe3_act_vector_0_15_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[4] != flex_i.flex_pe3_act_vector_0_15_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[5] != flex_i.flex_pe3_act_vector_0_15_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[6] != flex_i.flex_pe3_act_vector_0_15_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[7] != flex_i.flex_pe3_act_vector_0_15_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[8] != flex_i.flex_pe3_act_vector_0_15_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[9] != flex_i.flex_pe3_act_vector_0_15_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[10] != flex_i.flex_pe3_act_vector_0_15_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[11] != flex_i.flex_pe3_act_vector_0_15_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[12] != flex_i.flex_pe3_act_vector_0_15_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[13] != flex_i.flex_pe3_act_vector_0_15_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[14] != flex_i.flex_pe3_act_vector_0_15_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[15] != flex_i.flex_pe3_act_vector_0_15_Inst15)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_PE0_CONFIG_ACT_VECTOR_16_31() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE0_CONFIG_ACT_VECTOR_16_31" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE0_CONFIG_ACT_VECTOR_16_31";
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[16] != flex_i.flex_pe0_act_vector_16_31_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[17] != flex_i.flex_pe0_act_vector_16_31_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[18] != flex_i.flex_pe0_act_vector_16_31_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[19] != flex_i.flex_pe0_act_vector_16_31_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[20] != flex_i.flex_pe0_act_vector_16_31_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[21] != flex_i.flex_pe0_act_vector_16_31_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[22] != flex_i.flex_pe0_act_vector_16_31_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[23] != flex_i.flex_pe0_act_vector_16_31_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[24] != flex_i.flex_pe0_act_vector_16_31_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[25] != flex_i.flex_pe0_act_vector_16_31_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[26] != flex_i.flex_pe0_act_vector_16_31_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[27] != flex_i.flex_pe0_act_vector_16_31_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[28] != flex_i.flex_pe0_act_vector_16_31_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[29] != flex_i.flex_pe0_act_vector_16_31_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[30] != flex_i.flex_pe0_act_vector_16_31_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[0]->pemodule_inst.act_inst.act_config.inst_regs[31] != flex_i.flex_pe0_act_vector_16_31_Inst15)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE1_CONFIG_ACT_VECTOR_16_31() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE1_CONFIG_ACT_VECTOR_16_31" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE1_CONFIG_ACT_VECTOR_16_31";
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[16] != flex_i.flex_pe1_act_vector_16_31_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[17] != flex_i.flex_pe1_act_vector_16_31_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[18] != flex_i.flex_pe1_act_vector_16_31_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[19] != flex_i.flex_pe1_act_vector_16_31_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[20] != flex_i.flex_pe1_act_vector_16_31_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[21] != flex_i.flex_pe1_act_vector_16_31_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[22] != flex_i.flex_pe1_act_vector_16_31_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[23] != flex_i.flex_pe1_act_vector_16_31_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[24] != flex_i.flex_pe1_act_vector_16_31_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[25] != flex_i.flex_pe1_act_vector_16_31_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[26] != flex_i.flex_pe1_act_vector_16_31_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[27] != flex_i.flex_pe1_act_vector_16_31_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[28] != flex_i.flex_pe1_act_vector_16_31_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[29] != flex_i.flex_pe1_act_vector_16_31_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[30] != flex_i.flex_pe1_act_vector_16_31_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[1]->pemodule_inst.act_inst.act_config.inst_regs[31] != flex_i.flex_pe1_act_vector_16_31_Inst15)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE2_CONFIG_ACT_VECTOR_16_31() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE2_CONFIG_ACT_VECTOR_16_31" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE2_CONFIG_ACT_VECTOR_16_31";
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[16] != flex_i.flex_pe2_act_vector_16_31_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[17] != flex_i.flex_pe2_act_vector_16_31_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[18] != flex_i.flex_pe2_act_vector_16_31_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[19] != flex_i.flex_pe2_act_vector_16_31_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[20] != flex_i.flex_pe2_act_vector_16_31_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[21] != flex_i.flex_pe2_act_vector_16_31_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[22] != flex_i.flex_pe2_act_vector_16_31_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[23] != flex_i.flex_pe2_act_vector_16_31_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[24] != flex_i.flex_pe2_act_vector_16_31_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[25] != flex_i.flex_pe2_act_vector_16_31_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[26] != flex_i.flex_pe2_act_vector_16_31_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[27] != flex_i.flex_pe2_act_vector_16_31_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[28] != flex_i.flex_pe2_act_vector_16_31_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[29] != flex_i.flex_pe2_act_vector_16_31_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[30] != flex_i.flex_pe2_act_vector_16_31_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[2]->pemodule_inst.act_inst.act_config.inst_regs[31] != flex_i.flex_pe2_act_vector_16_31_Inst15)
      std::cout << error_msg << std::endl;
  }
  void tandem_verification_PE3_CONFIG_ACT_VECTOR_16_31() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunPE3_CONFIG_ACT_VECTOR_16_31" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error PE3_CONFIG_ACT_VECTOR_16_31";
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[16] != flex_i.flex_pe3_act_vector_16_31_Inst0)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[17] != flex_i.flex_pe3_act_vector_16_31_Inst1)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[18] != flex_i.flex_pe3_act_vector_16_31_Inst2)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[19] != flex_i.flex_pe3_act_vector_16_31_Inst3)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[20] != flex_i.flex_pe3_act_vector_16_31_Inst4)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[21] != flex_i.flex_pe3_act_vector_16_31_Inst5)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[22] != flex_i.flex_pe3_act_vector_16_31_Inst6)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[23] != flex_i.flex_pe3_act_vector_16_31_Inst7)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[24] != flex_i.flex_pe3_act_vector_16_31_Inst8)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[25] != flex_i.flex_pe3_act_vector_16_31_Inst9)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[26] != flex_i.flex_pe3_act_vector_16_31_Inst10)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[27] != flex_i.flex_pe3_act_vector_16_31_Inst11)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[28] != flex_i.flex_pe3_act_vector_16_31_Inst12)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[29] != flex_i.flex_pe3_act_vector_16_31_Inst13)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[30] != flex_i.flex_pe3_act_vector_16_31_Inst14)
      std::cout << error_msg << std::endl;
    if (dut.pe_ptrs[3]->pemodule_inst.act_inst.act_config.inst_regs[31] != flex_i.flex_pe3_act_vector_16_31_Inst15)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_GB_CORE_STORE_LARGE() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunGB_CORE_STORE_LARGE" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error GB_CORE_STORE_LARGE";
    uint32_t word_addr = dut.gb_inst.gbmodule_inst.gbcore_inst.large_write_addrs[0];
    auto impl_word = dut.gb_inst.gbmodule_inst.gbcore_inst.large_mem.GetData(word_addr);    
    for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
      if (impl_word[byte_addr] != flex_i.flex_gb_core_large_buffer[(word_addr << 4) + byte_addr])
        std::cout << error_msg << std::endl;
    }
  }

  void tandem_verification_CONFIG_GB_CORE_MEM_MNGR_LARGE() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunCONFIG_GB_CORE_MEM_MNGR_LARGE" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error CONFIG_GB_CORE_MEM_MNGR_LARGE";
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.num_vector_large[0] != flex_i.flex_gb_core_mem_mngr_large_num_vector_0)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.num_vector_large[1] != flex_i.flex_gb_core_mem_mngr_large_num_vector_1)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.num_vector_large[2] != flex_i.flex_gb_core_mem_mngr_large_num_vector_2)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.num_vector_large[3] != flex_i.flex_gb_core_mem_mngr_large_num_vector_3)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.base_large[0] != flex_i.flex_gb_core_mem_mngr_large_base_large_0)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.base_large[1] != flex_i.flex_gb_core_mem_mngr_large_base_large_1)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.base_large[2] != flex_i.flex_gb_core_mem_mngr_large_base_large_2)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcore_inst.base_large[3] != flex_i.flex_gb_core_mem_mngr_large_base_large_3)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_CONFIG_GB_CONTROL() {
    #ifdef TANDEM_PRINT_DBG
    std::cout << "Tandem RunCONFIG_GB_CONTROL" << std::endl; 
    #endif
    std::string error_msg = "Tandem Error CONFIG_GB_CONTROL";
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.is_valid != flex_i.flex_gb_control_is_valid)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.mode != flex_i.flex_gb_control_mode)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.is_rnn != flex_i.flex_gb_control_is_rnn)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.memory_index_1 != flex_i.flex_gb_control_memory_index_1)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.memory_index_2 != flex_i.flex_gb_control_memory_index_2)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.num_vector_1 != flex_i.flex_gb_control_num_vector_1)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.num_vector_2 != flex_i.flex_gb_control_num_vector_2)
      std::cout << error_msg << std::endl;
    if (dut.gb_inst.gbmodule_inst.gbcontrol_inst.gbcontrol_config.num_timestep_1 != flex_i.flex_gb_control_num_timestep_1)
      std::cout << error_msg << std::endl;
  }

  void tandem_verification_GB_CONTROL_START() {
    std::cout << "Tandem RunGB_CONTROL_START" << std::endl; 
    std::string error_msg = "Tandem Error GB_CONTROL_START";
    for (int word_addr = 0; word_addr < (4096 >> 4); word_addr++) {
       auto impl_word = dut.gb_inst.gbmodule_inst.gbcore_inst.large_mem.GetData(word_addr);
       if (to_sc(impl_word[0]) == sc_biguint<8>(0xff))
         break;
       for (int byte_addr = 0; byte_addr < 16; byte_addr++) {
         auto impl_byte = to_sc(impl_word[byte_addr]);
         if (impl_byte != flex_i.flex_gb_core_large_buffer[(word_addr << 4) + byte_addr])
           std::cout << error_msg << std::endl;
      }
    }
  }
  #endif


  void run_ilator() {
    if (interrupted == 0 && interrupt == 1)
      interrupted = 1;
    else if (interrupted == 1)
      interrupted = 2;
    // if (master.inst_done == 1) {
      // std::cout << "run_ilator write" << std::endl;
      // std::cout << "master.wr_signal: " << master.wr_signal << std::endl;
      // std::cout << "master.addr_signal: " << master.addr_signal << std::endl;
      // flex_rd_signal.write(master.rd_signal);
      // flex_wr_signal.write(master.wr_signal);
      // flex_addr_signal.write(master.addr_signal);
      // for (int i = 0; i < 16; i++)
      //   flex_data_signal[i].write(master.data_signal[i]);
      // }
    if (interrupted == 0) {
      flex_i.flex_if_axi_wr = master.wr_signal;
      flex_i.flex_if_axi_rd = master.rd_signal;
      flex_i.flex_addr_in = master.addr_signal;
      flex_i.flex_data_in_0 = master.data_signal[0];
      flex_i.flex_data_in_1 = master.data_signal[1];
      flex_i.flex_data_in_2 = master.data_signal[2];
      flex_i.flex_data_in_3 = master.data_signal[3];
      flex_i.flex_data_in_4 = master.data_signal[4];
      flex_i.flex_data_in_5 = master.data_signal[5];
      flex_i.flex_data_in_6 = master.data_signal[6];
      flex_i.flex_data_in_7 = master.data_signal[7];
      flex_i.flex_data_in_8 = master.data_signal[8];
      flex_i.flex_data_in_9 = master.data_signal[9];
      flex_i.flex_data_in_10 = master.data_signal[10];
      flex_i.flex_data_in_11 = master.data_signal[11];
      flex_i.flex_data_in_12 = master.data_signal[12];
      flex_i.flex_data_in_13 = master.data_signal[13];
      flex_i.flex_data_in_14 = master.data_signal[14];
      flex_i.flex_data_in_15 = master.data_signal[15];

      flex_i.compute();
    }
    if (interrupted < 2) {
      #ifdef TANDEM_VERIFICATION
      switch(flex_i.e_inst) {
        case PE0_CONFIG_RNN_LAYER_SIZING : tandem_verification_PE0_CONFIG_RNN_LAYER_SIZING(); break;
        case PE0_CONFIG_MEM_MNGR_FIRST : tandem_verification_PE0_CONFIG_MEM_MNGR_FIRST(); break;
        case PE0_CONFIG_MEM_MNGR_SECOND : tandem_verification_PE0_CONFIG_MEM_MNGR_SECOND(); break;
        case PE0_CORE_STORE_WEIGHT_BUFFER : tandem_verification_PE0_CORE_STORE_WEIGHT_BUFFER(); break;
        case PE0_CORE_STORE_INPUT_BUFFER : tandem_verification_PE0_CORE_STORE_INPUT_BUFFER(); break;
        case PE0_CONFIG_ACT_MNGR : tandem_verification_PE0_CONFIG_ACT_MNGR(); break;
        case PE0_CONFIG_ACT_VECTOR_0_15 : tandem_verification_PE0_CONFIG_ACT_VECTOR_0_15(); break;
        case PE0_CONFIG_ACT_VECTOR_16_31 : tandem_verification_PE0_CONFIG_ACT_VECTOR_16_31(); break;
        case PE1_CONFIG_RNN_LAYER_SIZING : tandem_verification_PE1_CONFIG_RNN_LAYER_SIZING(); break;
        case PE1_CONFIG_MEM_MNGR_FIRST : tandem_verification_PE1_CONFIG_MEM_MNGR_FIRST(); break;
        case PE1_CONFIG_MEM_MNGR_SECOND : tandem_verification_PE1_CONFIG_MEM_MNGR_SECOND(); break;
        case PE1_CORE_STORE_WEIGHT_BUFFER : tandem_verification_PE1_CORE_STORE_WEIGHT_BUFFER(); break;
        case PE1_CORE_STORE_INPUT_BUFFER : tandem_verification_PE1_CORE_STORE_INPUT_BUFFER(); break;
        case PE1_CONFIG_ACT_MNGR : tandem_verification_PE1_CONFIG_ACT_MNGR(); break;
        case PE1_CONFIG_ACT_VECTOR_0_15 : tandem_verification_PE1_CONFIG_ACT_VECTOR_0_15(); break;
        case PE1_CONFIG_ACT_VECTOR_16_31 : tandem_verification_PE1_CONFIG_ACT_VECTOR_16_31(); break;
        case PE2_CONFIG_RNN_LAYER_SIZING : tandem_verification_PE2_CONFIG_RNN_LAYER_SIZING(); break;
        case PE2_CONFIG_MEM_MNGR_FIRST : tandem_verification_PE2_CONFIG_MEM_MNGR_FIRST(); break;
        case PE2_CONFIG_MEM_MNGR_SECOND : tandem_verification_PE2_CONFIG_MEM_MNGR_SECOND(); break;
        case PE2_CORE_STORE_WEIGHT_BUFFER : tandem_verification_PE2_CORE_STORE_WEIGHT_BUFFER(); break;
        case PE2_CORE_STORE_INPUT_BUFFER : tandem_verification_PE2_CORE_STORE_INPUT_BUFFER(); break;
        case PE2_CONFIG_ACT_MNGR : tandem_verification_PE2_CONFIG_ACT_MNGR(); break;
        case PE2_CONFIG_ACT_VECTOR_0_15 : tandem_verification_PE2_CONFIG_ACT_VECTOR_0_15(); break;
        case PE2_CONFIG_ACT_VECTOR_16_31 : tandem_verification_PE2_CONFIG_ACT_VECTOR_16_31(); break;
        case PE3_CONFIG_RNN_LAYER_SIZING : tandem_verification_PE3_CONFIG_RNN_LAYER_SIZING(); break;
        case PE3_CONFIG_MEM_MNGR_FIRST : tandem_verification_PE3_CONFIG_MEM_MNGR_FIRST(); break;
        case PE3_CONFIG_MEM_MNGR_SECOND : tandem_verification_PE3_CONFIG_MEM_MNGR_SECOND(); break;
        case PE3_CORE_STORE_WEIGHT_BUFFER : tandem_verification_PE3_CORE_STORE_WEIGHT_BUFFER(); break;
        case PE3_CORE_STORE_INPUT_BUFFER : tandem_verification_PE3_CORE_STORE_INPUT_BUFFER(); break;
        case PE3_CONFIG_ACT_MNGR : tandem_verification_PE3_CONFIG_ACT_MNGR(); break;
        case PE3_CONFIG_ACT_VECTOR_0_15 : tandem_verification_PE3_CONFIG_ACT_VECTOR_0_15(); break;
        case PE3_CONFIG_ACT_VECTOR_16_31 : tandem_verification_PE3_CONFIG_ACT_VECTOR_16_31(); break;
        case GB_CORE_STORE_LARGE : tandem_verification_GB_CORE_STORE_LARGE(); break;
        case CONFIG_GB_CORE_MEM_MNGR_LARGE : tandem_verification_CONFIG_GB_CORE_MEM_MNGR_LARGE(); break;
        case CONFIG_GB_CONTROL : tandem_verification_CONFIG_GB_CONTROL(); break;
        case GB_CONTROL_START: if (interrupted == 1) tandem_verification_GB_CONTROL_START(); break;
        default: break;
      }
      #endif
    }
  }
  #endif
};

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

#ifdef COV_ENABLE
   #pragma CTC ENDSKIP
#endif
