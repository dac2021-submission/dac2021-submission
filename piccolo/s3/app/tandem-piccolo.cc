// Include Ilated Model
#include "piccolo_ila.h"

// Include Verilated Impl
#include "piccolo_rtl.h"

// Include library
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <fstream>
#include <iostream>


class Ilated;
class RTLVerilated;

// Util function
vluint64_t main_time = 0;
// VerilatedVcdC* tfp = new VerilatedVcdC;
double sc_time_stamp () {
  return main_time;
}

// Decl

void i_input(Ilated *i, i_in& test_input) {
  i->i_top->riscv_inst = test_input.riscv_inst;
}

void v_input(RTLVerilated *v, v_in& test_input) {
  v->v_top->prob_imem_instr = test_input.prob_imem_instr;
}

void v_check_dmem(RTLVerilated* v) {
  if (v->v_top->dmem_master_arvalid) {
    v->v_top->dmem_master_arready = 1;
  } else 
    v->v_top->dmem_master_arready = 0;

  if (v->v_top->dmem_master_rready) {
    v->v_top->dmem_master_rvalid = 1;
    v->v_top->dmem_master_rdata = 1;
  }
  else
    v->v_top->dmem_master_rvalid = 0;

  if (v->v_top->dmem_master_awvalid) {
    v->v_top->dmem_master_awready = 1;
  } else 
    v->v_top->dmem_master_awready = 0; 

  if (v->v_top->dmem_master_wvalid) {
    v->v_top->dmem_master_wready = 1;
  }
  else
    v->v_top->dmem_master_wready = 0;
}

void next_instr(Ilated* i) {
  i->i_top->compute();
  return; 
}

void next_cycle(RTLVerilated* v) {
  v_check_dmem(v);
  v->v_top->CLK = 0;
  v->v_top->eval();
  main_time += 5;
  // tfp->dump(main_time);
  v->v_top->CLK = 1;
  v->v_top->eval();
  main_time += 5;
  // tfp->dump(main_time);
}

void update_monitor(RTLVerilated* v, std::vector<std::vector<bool>>& m, std::vector<uint32_t>& p_m) {
  for (int i = 2; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      m[i][j] = m[i - 1][j];
    }
  }
  m[0][0] = v->v_top->mkCPU->stage1_rg_full;
  m[1][1] = v->v_top->mkCPU->s1_to_s2__024D_IN && v->v_top->mkCPU->s1_to_s2__024EN;
  m[2][2] = v->v_top->mkCPU->s2_to_s3__024D_IN && v->v_top->mkCPU->s2_to_s3__024EN;

  p_m[2] = p_m[1];
  p_m[1] = p_m[0];
  p_m[0] = v->v_top->mkCPU->yxdbg_pc;
  
  return;
}

bool check_monitor(std::vector<std::vector<bool>>& m) {
  return m[2][0] && m[2][1] && m[2][2];
}

void check_state(Ilated* i, RTLVerilated* v, std::vector<uint32_t> p_m) {
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[0] != i->i_top->riscv_x0)
    std::cout << "Error x0" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[1] != i->i_top->riscv_x1)
    std::cout << "Error x1" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[2] != i->i_top->riscv_x2)
    std::cout << "Error x2" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[3] != i->i_top->riscv_x3)
    std::cout << "Error x3" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[4] != i->i_top->riscv_x4)
    std::cout << "Error x4" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[5] != i->i_top->riscv_x5)
    std::cout << "Error x5" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[6] != i->i_top->riscv_x6)
    std::cout << "Error x6" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[7] != i->i_top->riscv_x7)
    std::cout << "Error x7" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[8] != i->i_top->riscv_x8)
    std::cout << "Error x8" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[9] != i->i_top->riscv_x9)
    std::cout << "Error x9" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[10] != i->i_top->riscv_x10)
    std::cout << "Error x10" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[11] != i->i_top->riscv_x11)
    std::cout << "Error x11" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[12] != i->i_top->riscv_x12)
    std::cout << "Error x12" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[13] != i->i_top->riscv_x13)
    std::cout << "Error x13" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[14] != i->i_top->riscv_x14)
    std::cout << "Error x14" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[15] != i->i_top->riscv_x15)
    std::cout << "Error x15" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[16] != i->i_top->riscv_x16)
    std::cout << "Error x16" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[17] != i->i_top->riscv_x17)
    std::cout << "Error x17" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[18] != i->i_top->riscv_x18)
    std::cout << "Error x18" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[19] != i->i_top->riscv_x19)
    std::cout << "Error x19" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[20] != i->i_top->riscv_x20)
    std::cout << "Error x20" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[21] != i->i_top->riscv_x21)
    std::cout << "Error x21" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[22] != i->i_top->riscv_x22)
    std::cout << "Error x22" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[23] != i->i_top->riscv_x23)
    std::cout << "Error x23" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[24] != i->i_top->riscv_x24)
    std::cout << "Error x24" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[25] != i->i_top->riscv_x25)
    std::cout << "Error x25" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[26] != i->i_top->riscv_x26)
    std::cout << "Error x26" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[27] != i->i_top->riscv_x27)
    std::cout << "Error x27" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[28] != i->i_top->riscv_x28)
    std::cout << "Error x28" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[29] != i->i_top->riscv_x29)
    std::cout << "Error x29" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[30] != i->i_top->riscv_x30)
    std::cout << "Error x30" << std::endl;
  if (v->v_top->mkCPU->gpr_regfile->regfile->arr[31] != i->i_top->riscv_x31)
    std::cout << "Error x31" << std::endl;
  if (p_m[2] != i->i_top->riscv_pc)
    std::cout << "Error pc" << p_m[2] <<
                 ":" << i->i_top->riscv_pc << std::endl;               


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
  i->i_top->riscv_pc = 4096;

  // Instantiate Implementation -- v
  Verilated::traceEverOn(true);
  RTLVerilated* v = new RTLVerilated;
  // v->v_top->trace(tfp, 99);
  // tfp->open("./out.vcd");
  v->v_top->RST_N = 0;
  for (int i = 0; i < 2; i ++) {  
    next_cycle(v);
  } 
  v->v_top->RST_N = 1;
  next_cycle(v);
  v->v_top->hart0_server_reset_request_put = 1;
  v->v_top->EN_hart0_server_reset_request_put = 1;
  next_cycle(v);
  v->v_top->EN_hart0_server_reset_request_put = 0;
  for (int i = 0; i < 133; i ++) {  
    next_cycle(v);
  }  

  // ila tv
  std::vector<v_in> tv_v;
  std::string t_input;

  // Initialize Implementation -- v
  // tmps
  
  if (argc < 2) 
    std::cout << "Need test-vector input." << std::endl;
  // verilog tv
  std::ifstream tv_file;
  tv_file.open(argv[1]);
  uint32_t tv_end = 0;

  while (getline(tv_file, t_input)) {
    v_in t_in;
    std::stringstream t_input_ss(t_input);
    std::string t_input_tt;
    if (getline(t_input_ss, t_input_tt, ',')) {
      t_in.prob_imem_instr = std::stoul(t_input_tt, 0, 16); 
      tv_end++;
    } 
    tv_v.push_back(t_in);
  }
  tv_end = tv_end*4 + 4096;
  
  // ila tv  
  std::vector<std::vector<bool>> monitor{{false, false ,false}, {false, false,false}, {false, false, false}};
  std::vector<uint32_t> pc_monitor{0,0,0};
  while (v->v_top->mkCPU->yxdbg_pc < tv_end) {
    auto t_v = tv_v[(v->v_top->mkCPU->yxdbg_pc - 4096) / 4]; 
    v_input(v, t_v);
    next_cycle(v);
    update_monitor(v, monitor, pc_monitor);
    if (run_ilator) {
      if (check_monitor(monitor)) {
        i_in t_i;
        auto t_v = tv_v[(i->i_top->riscv_pc - 4096)/4];
        t_i.riscv_inst = t_v.prob_imem_instr;
        i_input(i, t_i);
        next_instr(i);
        if (i->checkpoint_on())
          check_state(i, v, pc_monitor);
      }
    }
  }
  std::cout << "duration: " << i->duration << std::endl;
  // tfp->close();  
}  
