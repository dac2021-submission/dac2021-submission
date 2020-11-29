#include "riscv.h"
#include "riscv_rtl.h"
class Ilated {
  public:
    riscv* i_top;
    Ilated() {
      i_top = new riscv();
    }
    void tandem_swap(RTLVerilated* v) {
      reset_sequence(v);
      std::cout << "riscv_pc" << i_top->riscv_pc << std::endl;
      v->v_top->Rocket->mem_reg_pc = i_top->riscv_pc;
      v->v_top->Rocket->_T_590[0] = i_top->riscv_x0;
      v->v_top->Rocket->_T_590[1] = i_top->riscv_x1;
      v->v_top->Rocket->_T_590[2] = i_top->riscv_x2;
      v->v_top->Rocket->_T_590[3] = i_top->riscv_x3;
      v->v_top->Rocket->_T_590[4] = i_top->riscv_x4;
      v->v_top->Rocket->_T_590[5] = i_top->riscv_x5;
      v->v_top->Rocket->_T_590[6] = i_top->riscv_x6;
      v->v_top->Rocket->_T_590[7] = i_top->riscv_x7;
      v->v_top->Rocket->_T_590[8] = i_top->riscv_x8;
      v->v_top->Rocket->_T_590[9] = i_top->riscv_x9;
      v->v_top->Rocket->_T_590[10] = i_top->riscv_x10;
      v->v_top->Rocket->_T_590[11] = i_top->riscv_x11;
      v->v_top->Rocket->_T_590[12] = i_top->riscv_x12;
      v->v_top->Rocket->_T_590[13] = i_top->riscv_x13;
      v->v_top->Rocket->_T_590[14] = i_top->riscv_x14;
      v->v_top->Rocket->_T_590[15] = i_top->riscv_x15;
      v->v_top->Rocket->_T_590[16] = i_top->riscv_x16;
      v->v_top->Rocket->_T_590[17] = i_top->riscv_x17;
      v->v_top->Rocket->_T_590[18] = i_top->riscv_x18;
      v->v_top->Rocket->_T_590[19] = i_top->riscv_x19;
      v->v_top->Rocket->_T_590[20] = i_top->riscv_x20;
      v->v_top->Rocket->_T_590[21] = i_top->riscv_x21;
      v->v_top->Rocket->_T_590[22] = i_top->riscv_x22;
      v->v_top->Rocket->_T_590[23] = i_top->riscv_x23;
      v->v_top->Rocket->_T_590[24] = i_top->riscv_x24;
      v->v_top->Rocket->_T_590[25] = i_top->riscv_x25;
      v->v_top->Rocket->_T_590[26] = i_top->riscv_x26;
      v->v_top->Rocket->_T_590[27] = i_top->riscv_x27;
      v->v_top->Rocket->_T_590[28] = i_top->riscv_x28;
      v->v_top->Rocket->_T_590[29] = i_top->riscv_x29;
      v->v_top->Rocket->_T_590[30] = i_top->riscv_x30;
      v->v_top->Rocket->_T_590[31] = i_top->riscv_x31;
      for (int i = 0; i < 2; i ++) {  
        v->v_top->clock = 0;
        v->v_top->eval();
        v->v_top->clock = 1;
        v->v_top->eval();      
      }     
    }    
    void reset_sequence(RTLVerilated* v) {
      v->v_top->reset = 1;
      for (int i = 0; i < 2; i ++) {  
        v->v_top->clock = 0;
        v->v_top->eval();
        v->v_top->clock = 1;
        v->v_top->eval();      
      } 
      v->v_top->reset = 0;  
      for (int i = 0; i < 10; i++) {
        v->v_top->clock = 0;
        v->v_top->eval();
        v->v_top->clock = 1;
        v->v_top->eval();         
      }
    }    
    ~Ilated() {
      //delete i_top;
    }
};
