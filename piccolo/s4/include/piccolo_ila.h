#include "riscv.h"
#include "piccolo_rtl.h"
class Ilated {
  public:
    Ilated() {
      i_top = new riscv;
    }
    ~Ilated() {
      delete i_top;
    }
    void tandem_swap(RTLVerilated* v) {
      v->v_top->ila_pc_reset_value = i_top->riscv_pc;
      reset_sequence(v);
      v->v_top->mkCPU->gpr_regfile->regfile->arr[0] = i_top->riscv_x0;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[1] = i_top->riscv_x1;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[2] = i_top->riscv_x2;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[3] = i_top->riscv_x3;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[4] = i_top->riscv_x4;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[5] = i_top->riscv_x5;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[6] = i_top->riscv_x6;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[7] = i_top->riscv_x7;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[8] = i_top->riscv_x8;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[9] = i_top->riscv_x9;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[10] = i_top->riscv_x10;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[11] = i_top->riscv_x11;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[12] = i_top->riscv_x12;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[13] = i_top->riscv_x13;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[14] = i_top->riscv_x14;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[15] = i_top->riscv_x15;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[16] = i_top->riscv_x16;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[17] = i_top->riscv_x17;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[18] = i_top->riscv_x18;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[19] = i_top->riscv_x19;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[20] = i_top->riscv_x20;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[21] = i_top->riscv_x21;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[22] = i_top->riscv_x22;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[23] = i_top->riscv_x23;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[24] = i_top->riscv_x24;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[25] = i_top->riscv_x25;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[26] = i_top->riscv_x26;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[27] = i_top->riscv_x27;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[28] = i_top->riscv_x28;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[29] = i_top->riscv_x29;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[30] = i_top->riscv_x30;
      v->v_top->mkCPU->gpr_regfile->regfile->arr[31] = i_top->riscv_x31;
    }    
    void reset_sequence(RTLVerilated* v) {
      v->v_top->RST_N = 0;
      for (int i = 0; i < 2; i ++) {  
        v->v_top->CLK = 0;
        v->v_top->eval();
        v->v_top->CLK = 1;
        v->v_top->eval();        
      } 
      v->v_top->RST_N = 1;
      v->v_top->CLK = 0;
      v->v_top->eval();
      v->v_top->CLK = 1;
      v->v_top->eval();       
      v->v_top->hart0_server_reset_request_put = 1;
      v->v_top->EN_hart0_server_reset_request_put = 1;
      v->v_top->CLK = 0;
      v->v_top->eval();
      v->v_top->CLK = 1;
      v->v_top->eval();   
      v->v_top->EN_hart0_server_reset_request_put = 0;
      for (int i = 0; i < 133; i ++) {  
        v->v_top->CLK = 0;
        v->v_top->eval();
        v->v_top->CLK = 1;
        v->v_top->eval();       
      }  
    }
    riscv* i_top;
};

class i_in {
  public:
    uint32_t riscv_inst;
};
