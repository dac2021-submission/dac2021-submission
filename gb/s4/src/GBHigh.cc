#include "GBHigh.h"
#ifdef TANDEM_VERIFICATION
GBHigh::GBHigh() {
  tandem_f[0] = &GBHigh::tandem_instr_Write;
  tandem_f[1] = &GBHigh::tandem_instr_Read; 
}
#endif
