#include "AES.h"
#ifdef TANDEM_VERIFICATION
AES::AES(int checkpoint_mode) {
  tandem_f[0] = &AES::tandem_instr_WRITE_ADDRESS;
  tandem_f[1] = &AES::tandem_instr_START_ENCRYPT;
  tandem_f[2] = &AES::tandem_instr_READ_LENGTH;
  tandem_f[3] = &AES::tandem_instr_READ_ADDRESS;
  tandem_f[4] = &AES::tandem_instr_READ_KEY;
  tandem_f[5] = &AES::tandem_instr_READ_COUNTER;
  tandem_f[6] = &AES::tandem_instr_GET_STATUS;
  tandem_f[7] = &AES::tandem_instr_WRITE_LENGTH;
  tandem_f[8] = &AES::tandem_instr_WRITE_KEY;
  tandem_f[9] = &AES::tandem_instr_WRITE_COUNTER;
  if (checkpoint_mode == 1) {
    checkpoint_period = 1000;
  } else if (checkpoint_mode == 2) {
    checkpoint_time = new uint32_t[11];
    for (int i = 0; i < 11; i++)
      checkpoint_time[i] = i * 1000;
    checkpoint_ptr = 0;
  } else
    checkpoint_mode = 3;  
}
#endif
