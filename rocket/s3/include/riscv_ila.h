#include "riscv.h"
#include <chrono>
class Ilated {
  public:
    int checkpoint_mode;
    int instr_ctr;
    long long int duration;
    uint32_t checkpoint_period;
    uint32_t* checkpoint_time;
    uint32_t checkpoint_ptr;   
    riscv* i_top;
    Ilated(int cpm) {
      i_top = new riscv();
      checkpoint_mode = cpm;
      duration = 0;
      instr_ctr = 0;
      if (checkpoint_mode == 1) {
        checkpoint_period = 10000;
      } else if (checkpoint_mode == 2) {
        checkpoint_time = new uint32_t[15];
        for (int i = 0; i < 15; i++)
          checkpoint_time[i] = i * 10000;      
        checkpoint_ptr = 0;
      } else {
        checkpoint_mode = 3;
      }          
    }
    void icount_inc1() {
      instr_ctr++;
    }
    bool checkpoint_on() {
      auto timer1 = std::chrono::high_resolution_clock::now();
      bool ret = false;
      if (checkpoint_mode == 1) {
        if (instr_ctr % checkpoint_period == 0) 
          ret = true;
      } else if (checkpoint_mode == 2) {
        if (instr_ctr == checkpoint_time[checkpoint_ptr]) {
          checkpoint_ptr++;
          ret = true;
        }
      } else {
        if (i_top->riscv_pc % 10000 == 0)
          ret = true;
      }
      auto timer2 = std::chrono::high_resolution_clock::now();
      duration += std::chrono::duration_cast<std::chrono::nanoseconds>( timer2 - timer1 ).count();
      return ret;
    }        
    ~Ilated() {
      //delete i_top;
    }
};
