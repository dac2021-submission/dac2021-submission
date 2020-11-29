#include "AES_impl.h"

class RTLVerilated {
public:
  c_model *v_top;
  RTLVerilated() {
    v_top = new c_model;
    finish = 0;
  }
  bool finish;
  uint32_t prev_pc;
  uint8_t xram[65535];
  ~RTLVerilated() {}
};

class v_in {
public:
  bool wr;
  bool stb;
  uint16_t addr;
  uint8_t data_in;
  uint8_t xram_data_in;
  bool xram_ack;
};


