// Include Ilated Model
#include "AES_ila.h"

// Include Verilated Impl

// Include library
#include <fstream>
#include <iostream>
#include <exception>
#include <chrono>




class Ilated;
class RTLVerilated;

#define AES_START 0xff00
#define AES_STATE 0xff01
#define AES_ADDR 0xff02
#define AES_LENGTH 0xff04
#define AES_KEY 0xff10
#define AES_CNT 0xff20

#define CMD_NOP 0
#define CMD_READ 1
#define CMD_WRITE 2

#define AES_STATE_IDLE 0
#define AES_STATE_READ_DATA 1
#define AES_STATE_OPERATE 2
#define AES_STATE_WRITE_DATA 3
// Util function


// Decl
i_in test_v_to_i(v_in t_v) {
  i_in t_i;
  t_i.AES_cmd = (t_v.wr == 1) ? 2 : 1;
  t_i.AES_cmdaddr = t_v.addr;
  t_i.AES_cmddata = t_v.data_in;
  
  return t_i;
}

void i_input(Ilated *i, i_in& test_input) {
  i->i_top->AES_cmd = test_input.AES_cmd;
  i->i_top->AES_cmddata = test_input.AES_cmddata;
  i->i_top->AES_cmdaddr = test_input.AES_cmdaddr;
}

void next_instr(Ilated* i, RTLVerilated* v) {
  i->i_top->compute(v); 
}

void next_cycle(RTLVerilated* v, i_in& test_input) {
  v->v_top->c_run((uint8_t) test_input.AES_cmd, test_input.AES_cmdaddr, test_input.AES_cmddata);
}


int main(int argc, char **argv) {
  bool run_ilator = (argc > 2);
  bool tandem_enable = (argc > 3);
  bool checkpoint_enable = (argc > 4);
  std::istringstream argv_4(argv[4]);
  int checkpoint_mode;
  argv_4 >> checkpoint_mode;  
  // Instantiate Model -- i
  Ilated* i = new Ilated(checkpoint_mode);
  // Initialize Model -- i 

  // Instantiate Implementation -- v
  RTLVerilated* v = new RTLVerilated;

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
      t_in.wr = std::stoul(t_input_tt, 0, 16); 
    } 
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.stb = std::stoul(t_input_tt, 0, 16); 
    } 
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.addr = std::stoul(t_input_tt, 0, 16); 
    } 
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.data_in = std::stoul(t_input_tt, 0, 16); 
    } 
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.xram_data_in = std::stoul(t_input_tt, 0, 16); 
    } 
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.xram_ack = std::stoul(t_input_tt, 0, 16); 
    } 
    tv_v.push_back(t_in);
  }
  
  // ila tv  
  while (v->v_top->pc < tv_v.size()) {
    auto t_v = tv_v[v->v_top->pc]; 
    i_in t_i = test_v_to_i(t_v);
    // v_input(v, t_i);
    next_cycle(v, t_i);
    i_input(i, t_i);
    next_instr(i, v);
  } 
  std::cout << "duration: " << i->i_top->duration << std::endl;
  return 0;
}  