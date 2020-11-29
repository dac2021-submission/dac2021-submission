#include "GBHigh.h"
#ifdef TANDEM_VERIFICATION
GBHigh::GBHigh(int checkpoint_mode) {
  tandem_f[0] = &GBHigh::tandem_instr_Write;
  tandem_f[1] = &GBHigh::tandem_instr_Read;
  if (checkpoint_mode == 1) {
    checkpoint_period = 390;
  } else if (checkpoint_mode == 2) {
    checkpoint_time = new uint32_t[11];
    for (int i = 0; i < 11; i++)
      checkpoint_time[i] = i * 390;
    checkpoint_ptr = 0;
  } else
    checkpoint_mode = 3;    
}
#endif
