#include "AES.h"
class Ilated {
  public:
    Ilated(int checkpoint_mode) {
      i_top = new AES(checkpoint_mode);
    }
    ~Ilated() {
      delete i_top;
    }
    AES* i_top;
};

class i_in {
public:
  uint2_t AES_cmd;
  uint16_t AES_cmdaddr;
  uint8_t AES_cmddata;
};
