// Include Ilated Model
#include "GBHigh_ila.h"

// Include Verilated Impl


// Include library
#include <fstream>
#include <iostream>
#include <chrono>


class Ilated;
class RTLVerilated;

// Util function

// Decl
i_in test_v_to_i(v_in t_v) {
  i_in t_i;
  t_i.GBHigh_arg_0_TREADY = t_v.arg_0_TREADY;
  t_i.GBHigh_arg_1_TVALID = t_v.arg_1_TVALID;
  t_i.GBHigh_arg_1_TDATA = t_v.arg_1_TDATA;
  
  return t_i;
}

void i_input(Ilated *i, i_in& test_input) {
  i->i_top->GBHigh_arg_0_TREADY = test_input.GBHigh_arg_0_TREADY;
  i->i_top->GBHigh_arg_1_TVALID = test_input.GBHigh_arg_1_TVALID;
  i->i_top->GBHigh_arg_1_TDATA = test_input.GBHigh_arg_1_TDATA;
}

void v_input(RTLVerilated* v, v_in& test_input) {
  v->v_top->arg_0_TREADY = test_input.arg_0_TREADY;
  v->v_top->arg_1_TVALID = test_input.arg_1_TVALID;
  v->v_top->arg_1_TDATA = test_input.arg_1_TDATA;
}

void next_instr(Ilated* i, RTLVerilated* v) {
  i->i_top->compute(v); 
  i->ila_pc = i->ila_pc + 1; 
}

void swap(Ilated* i, RTLVerilated* v) {
  i->i_top->tandem_swap(v);
  v->v_top->hls_target->GB_pc = i->ila_pc;
}

void next_cycle(RTLVerilated* v) {
  v->v_top->ap_clk = 0;
  v->v_top->eval();
  v->v_top->ap_clk = 1;
  v->v_top->eval();
}

int main(int argc, char** argv) {
  int swap_time;
  std::istringstream argv_3(argv[3]);
  argv_3 >> swap_time;
  // Instantiate Model -- i
  Ilated* i = new Ilated();
  // Initialize Model -- i

  // Instantiate Implementation -- v
  RTLVerilated* v = new RTLVerilated;
  v->v_top->ap_rst_n = 0;
  next_cycle(v);
  next_cycle(v);
  v->v_top->ap_rst_n = 1;
  v->v_top->hls_target->ap_start = 1;

  // verilog tv
  std::vector<v_in> tv_v;
  std::string t_input;
  // Initialize Implementation -- v
  // tmps

  if (argc < 2)
    std::cout << "Need test-vector input." << std::endl;
  // verilog tv
  std::ifstream tv_file;
  tv_file.open(argv[1]);

  int j = 0;
  while (getline(tv_file, t_input)) {
    v_in t_in;
    std::stringstream t_input_ss(t_input);
    std::string t_input_tt;
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.arg_0_TREADY = std::stoul(t_input_tt, 0, 16);
    }
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.arg_1_TVALID = std::stoul(t_input_tt, 0, 16);
    }
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.arg_1_TDATA = std::stoul(t_input_tt, 0, 16);
    }
    tv_v.push_back(t_in);
  }
  tv_file.close();


  std::vector<i_in> tv_i;
  tv_file.open(argv[2]);
  while (getline(tv_file, t_input)) {
    i_in t_in;
    std::stringstream t_input_ss(t_input);
    std::string t_input_tt;
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.GBHigh_arg_0_TREADY = std::stoul(t_input_tt, 0, 16);
    }
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.GBHigh_arg_1_TVALID = std::stoul(t_input_tt, 0, 16);
    }
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.GBHigh_arg_1_TDATA = std::stoul(t_input_tt, 0, 16);
    }
    tv_i.push_back(t_in);
  }
  tv_file.close();  

  // ila tv
  while (i->ila_pc < swap_time) {
    auto t_i = tv_i[i->ila_pc];
    i_input(i, t_i);
    next_instr(i, v);    
  }

  auto timer1 = std::chrono::high_resolution_clock::now();
  swap(i, v);
  auto timer2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( timer2 - timer1 ).count();
  std::cout << "duration: " << duration << std::endl;

  while (v->v_top->hls_target->GB_pc < tv_v.size()) {
    auto t_v = tv_v[v->v_top->hls_target->GB_pc];
    v_input(v, t_v);
    next_cycle(v);
    while (v->v_top->arg_0_TVALID != 1 && v->v_top->arg_1_TREADY != 1) {
      next_cycle(v);
    }
  }

  return 0;
}
