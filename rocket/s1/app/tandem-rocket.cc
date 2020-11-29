// Include Ilated Model
#include "riscv_ila.h"

// Include Verilated Impl
#include "riscv_rtl.h"

// Include library
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <fstream>
#include <iostream>
#include <chrono>

class Ilated;
class RTLVerilated;


vluint64_t main_time = 0;
VerilatedVcdC* tfp = new VerilatedVcdC;
double sc_time_stamp() { return main_time; }
// Decl

void v_input(RTLVerilated* v, uint32_t test_input) {
  v->v_top->io_imem_resp_bits_data = test_input;
  v->v_top->io_imem_resp_bits_pc = v->v_top->io_imem_req_bits_pc;
  v->v_top->io_imem_resp_valid = v->v_top->io_imem_resp_ready;
  return;
}


void i_input(Ilated* i, uint32_t test_input) {
  i->i_top->riscv_inst = test_input;
  return;
}
void next_cycle(RTLVerilated* v) {
  v->v_top->clock = 0;
  v->v_top->eval();
  v->v_top->clock = 1;
  v->v_top->eval();
  return;
}
void next_instr(Ilated* i) {
  i->i_top->compute(); 
}

int main(int argc, char **argv) {
  bool run_ilator = (argc > 2);

  // Instantiate Model -- i
  Ilated* i = new Ilated;
  // Initialize Model -- i 

  // Instantiate Implementation -- v
  RTLVerilated* v = new RTLVerilated;
  // Initialize Implementation -- v
  v->v_top->reset = 1;
  for (int i = 0; i < 2; i++) {
    next_cycle(v);
  }
  v->v_top->reset = 0;
  next_cycle(v);
  next_cycle(v);
  for (int i = 0; i < 10; i++) {
    next_cycle(v);
  }
  // tmps
  
  if (argc < 2) 
    std::cout << "Need test-vector input." << std::endl;
  std::ifstream tv_file;
  tv_file.open(argv[1]);
  
  std::string tv_input;
  uint32_t tv_end = 0;
  int j = 0;
  while (getline(tv_file, tv_input)) {
    uint32_t tmp = (std::stoul(tv_input, 0, 16));
    v->mem[j] = tmp;
    i->i_top->riscv_mem[j++] = tmp;
    tv_end++;
  }
  tv_end = tv_end * 4;

  auto timer1 = std::chrono::high_resolution_clock::now();
  long long unsigned int duration = 0;
  while((v->v_top->io_imem_req_bits_pc != tv_end)) {
    auto t = v->mem[v->v_top->io_imem_req_bits_pc / 4 ];
    v_input(v, t);
    v->prev_pc = v->v_top->io_imem_req_bits_pc;
    v_input(v, t);
    while(v->prev_pc == v->v_top->io_imem_req_bits_pc)
      next_cycle(v);

    if (run_ilator) {
      timer1 = std::chrono::high_resolution_clock::now();
      t = i->i_top->riscv_mem[i->i_top->riscv_pc];
      i_input(i, t);
      next_instr(i);
      auto timer2 = std::chrono::high_resolution_clock::now();
      duration += std::chrono::duration_cast<std::chrono::nanoseconds>( timer2 - timer1 ).count();
    } 
  }
  if (!run_ilator) {
    auto timer2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>( timer2 - timer1 ).count();
  }
  std::cout << "duration: " << duration << std::endl;
}  
