#include <VRocket.h>
#include <VRocket_Rocket.h>

class RTLVerilated {
public:
  VRocket *v_top;
  RTLVerilated() {
    v_top = new VRocket("v_top");
  }
  uint32_t prev_pc;
  uint32_t mem[16384*256];
  ~RTLVerilated() {}
};
