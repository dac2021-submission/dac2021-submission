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
void check_state(Ilated* i, RTLVerilated* v) {
  if (v->v_top->Rocket->_T_590[31] != i->i_top->riscv_x0)
    std::cout << "Error x0" << std::endl;
  if (v->v_top->Rocket->_T_590[30] != i->i_top->riscv_x1)
    std::cout << "Error x1" << std::endl;
  if (v->v_top->Rocket->_T_590[29] != i->i_top->riscv_x2)
    std::cout << "Error x2" << std::endl;
  if (v->v_top->Rocket->_T_590[28] != i->i_top->riscv_x3)
    std::cout << "Error x3" << std::endl;
  if (v->v_top->Rocket->_T_590[27] != i->i_top->riscv_x4)
    std::cout << "Error x4" << std::endl;
  if (v->v_top->Rocket->_T_590[26] != i->i_top->riscv_x5)
    std::cout << "Error x5" << std::endl;
  if (v->v_top->Rocket->_T_590[25] != i->i_top->riscv_x6)
    std::cout << "Error x6" << std::endl;
  if (v->v_top->Rocket->_T_590[24] != i->i_top->riscv_x7)
    std::cout << "Error x7" << std::endl;
  if (v->v_top->Rocket->_T_590[23] != i->i_top->riscv_x8)
    std::cout << "Error x8" << std::endl;
  if (v->v_top->Rocket->_T_590[22] != i->i_top->riscv_x9)
    std::cout << "Error x9" << std::endl;
  if (v->v_top->Rocket->_T_590[21] != i->i_top->riscv_x10)
    std::cout << "Error x10" << v->v_top->Rocket->_T_590[21] << ":"
              << i->i_top->riscv_x10 << std::endl;
  if (v->v_top->Rocket->_T_590[20] != i->i_top->riscv_x11)
    std::cout << "Error x11" << v->v_top->Rocket->_T_590[11] << ":"
              << i->i_top->riscv_x11 << std::endl;
  if (v->v_top->Rocket->_T_590[19] != i->i_top->riscv_x12)
    std::cout << "Error x12" << std::endl;
  if (v->v_top->Rocket->_T_590[18] != i->i_top->riscv_x13)
    std::cout << "Error x13" << std::endl;
  if (v->v_top->Rocket->_T_590[17] != i->i_top->riscv_x14)
    std::cout << "Error x14" << std::endl;
  if (v->v_top->Rocket->_T_590[16] != i->i_top->riscv_x15)
    std::cout << "Error x15" << std::endl;
  if (v->v_top->Rocket->_T_590[15] != i->i_top->riscv_x16)
    std::cout << "Error x16" << std::endl;
  if (v->v_top->Rocket->_T_590[14] != i->i_top->riscv_x17)
    std::cout << "Error x17" << std::endl;
  if (v->v_top->Rocket->_T_590[13] != i->i_top->riscv_x18)
    std::cout << "Error x18" << std::endl;
  if (v->v_top->Rocket->_T_590[12] != i->i_top->riscv_x19)
    std::cout << "Error x19" << std::endl;
  if (v->v_top->Rocket->_T_590[11] != i->i_top->riscv_x20)
    std::cout << "Error x20" << std::endl;
  if (v->v_top->Rocket->_T_590[10] != i->i_top->riscv_x21)
    std::cout << "Error x21" << std::endl;
  if (v->v_top->Rocket->_T_590[9] != i->i_top->riscv_x22)
    std::cout << "Error x22" << std::endl;
  if (v->v_top->Rocket->_T_590[8] != i->i_top->riscv_x23)
    std::cout << "Error x23" << std::endl;
  if (v->v_top->Rocket->_T_590[7] != i->i_top->riscv_x24)
    std::cout << "Error x24" << std::endl;
  if (v->v_top->Rocket->_T_590[6] != i->i_top->riscv_x25)
    std::cout << "Error x25" << std::endl;
  if (v->v_top->Rocket->_T_590[5] != i->i_top->riscv_x26)
    std::cout << "Error x26" << std::endl;
  if (v->v_top->Rocket->_T_590[4] != i->i_top->riscv_x27)
    std::cout << "Error x27" << std::endl;
  if (v->v_top->Rocket->_T_590[3] != i->i_top->riscv_x28)
    std::cout << "Error x28" << std::endl;
  if (v->v_top->Rocket->_T_590[2] != i->i_top->riscv_x29)
    std::cout << "Error x29" << std::endl;
  if (v->v_top->Rocket->_T_590[1] != i->i_top->riscv_x30)
    std::cout << "Error x30" << std::endl;
  if (v->v_top->Rocket->_T_590[0] != i->i_top->riscv_x31)
    std::cout << "Error x31" << std::endl;
}

bool check_monitor(std::vector<std::vector<bool>>& m) {
  return m[1][0] && m[1][1];
}

void update_monitor(RTLVerilated* v, std::vector<std::vector<bool>>& m) {
  for (int i = 1; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      m[i][j] = m[i - 1][j];
    }
  }
  m[0][0] = 1;
  m[1][1] = m[1][0];
  return;
}





int main(int argc, char **argv) {

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
  std::vector<std::vector<bool>> monitor{{false, false}, {false, false}};

  long long unsigned int duration = 0; 
  while((v->v_top->io_imem_req_bits_pc != tv_end)) {
    auto t = v->mem[v->v_top->io_imem_req_bits_pc / 4 ];
    v_input(v, t);
    v->prev_pc = v->v_top->io_imem_req_bits_pc;
    v_input(v, t);
    while(v->prev_pc == v->v_top->io_imem_req_bits_pc)
      next_cycle(v);

    auto timer1 = std::chrono::high_resolution_clock::now();
    update_monitor(v, monitor);
    if (check_monitor(monitor)) {
      t = v->mem[i->i_top->riscv_pc / 4 ];
      i_input(i, t);
      next_instr(i);
      check_state(i, v);
    }
    auto timer2 = std::chrono::high_resolution_clock::now();
    duration += std::chrono::duration_cast<std::chrono::nanoseconds>( timer2 - timer1 ).count();  

  }
  std::cout << "duration: " << duration << std::endl;
}  
  
  

