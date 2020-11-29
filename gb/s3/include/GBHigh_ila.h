#include "GBHigh.h"
class Ilated {
  public:
    Ilated(int checkpoint_mode) {
      i_top = new GBHigh(checkpoint_mode);
    }
    ~Ilated() {
      delete i_top;
    }
    GBHigh* i_top;
    uint32_t ila_pc = 0;
};

class i_in {
public:
  bool GBHigh_arg_0_TREADY;
  bool GBHigh_arg_1_TVALID;
  uint8_t GBHigh_arg_1_TDATA;
};
