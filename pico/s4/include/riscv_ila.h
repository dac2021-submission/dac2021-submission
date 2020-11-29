#include "riscv.h"
#include "riscv_rtl.h"

class Ilated {
  public:
    riscv* i_top;
    Ilated() {
      i_top = new riscv();
    }
    ~Ilated() {
      //delete i_top;
    }
    void tandem_swap(RTLVerilated* v) {
      v->v_top->picorv32_simple->reg_pc = i_top->riscv_pc;
      v->v_top->picorv32_simple->reg_next_pc = i_top->riscv_pc + 4;       
      v->v_top->picorv32_simple->cpuregs[0] = i_top->riscv_x0;
      v->v_top->picorv32_simple->cpuregs[1] = i_top->riscv_x1;
      v->v_top->picorv32_simple->cpuregs[2] = i_top->riscv_x2;
      v->v_top->picorv32_simple->cpuregs[3] = i_top->riscv_x3;
      v->v_top->picorv32_simple->cpuregs[4] = i_top->riscv_x4;
      v->v_top->picorv32_simple->cpuregs[5] = i_top->riscv_x5;
      v->v_top->picorv32_simple->cpuregs[6] = i_top->riscv_x6;
      v->v_top->picorv32_simple->cpuregs[7] = i_top->riscv_x7;
      v->v_top->picorv32_simple->cpuregs[8] = i_top->riscv_x8;
      v->v_top->picorv32_simple->cpuregs[9] = i_top->riscv_x9;
      v->v_top->picorv32_simple->cpuregs[10] = i_top->riscv_x10;
      v->v_top->picorv32_simple->cpuregs[11] = i_top->riscv_x11;
      v->v_top->picorv32_simple->cpuregs[12] = i_top->riscv_x12;
      v->v_top->picorv32_simple->cpuregs[13] = i_top->riscv_x13;
      v->v_top->picorv32_simple->cpuregs[14] = i_top->riscv_x14;
      v->v_top->picorv32_simple->cpuregs[15] = i_top->riscv_x15;
      v->v_top->picorv32_simple->cpuregs[16] = i_top->riscv_x16;
      v->v_top->picorv32_simple->cpuregs[17] = i_top->riscv_x17;
      v->v_top->picorv32_simple->cpuregs[18] = i_top->riscv_x18;
      v->v_top->picorv32_simple->cpuregs[19] = i_top->riscv_x19;
      v->v_top->picorv32_simple->cpuregs[20] = i_top->riscv_x20;
      v->v_top->picorv32_simple->cpuregs[21] = i_top->riscv_x21;
      v->v_top->picorv32_simple->cpuregs[22] = i_top->riscv_x22;
      v->v_top->picorv32_simple->cpuregs[23] = i_top->riscv_x23;
      v->v_top->picorv32_simple->cpuregs[24] = i_top->riscv_x24;
      v->v_top->picorv32_simple->cpuregs[25] = i_top->riscv_x25;
      v->v_top->picorv32_simple->cpuregs[26] = i_top->riscv_x26;
      v->v_top->picorv32_simple->cpuregs[27] = i_top->riscv_x27;
      v->v_top->picorv32_simple->cpuregs[28] = i_top->riscv_x28;
      v->v_top->picorv32_simple->cpuregs[29] = i_top->riscv_x29;
      v->v_top->picorv32_simple->cpuregs[30] = i_top->riscv_x30;
      v->v_top->picorv32_simple->cpuregs[31] = i_top->riscv_x31;
    }
};
