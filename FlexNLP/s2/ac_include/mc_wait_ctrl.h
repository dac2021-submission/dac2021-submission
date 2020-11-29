#ifndef MC_WAIT_CTRL_H
#define MC_WAIT_CTRL_H
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
// mc_wait_ctrl
////////////////////////////////////////////////////////////////////////////////

struct mc_wait_ctrl {
  enum enum_wait_mode     {UNIFORM  = 0, RANDOM = 1};
  enum enum_wait_elements {INITIAL  = 0, ALL  = 1, FIXED_INTERVAL = 2, RANDOM_INTERVAL = 3, IDLE_FLUSH = 4};

  explicit mc_wait_ctrl() :
    iteration(-1),
    stopat(-1),
    cycles(-1),
    interval(0),
    mode(UNIFORM),
    elements(INITIAL),
    ischannel(false)
    {}

  mc_wait_ctrl(
    int i,
    int s,
    int c,
    enum_wait_mode m,
    enum_wait_elements e,
    int n,
    bool chan=false) : iteration(i), stopat(s), cycles(c),
    interval(n), mode(m), elements(e), ischannel(chan)
    {}
  void clear() { iteration=0; stopat=0; cycles=0; mode=UNIFORM; elements=INITIAL; interval=0; }
  bool is_set() { return (cycles > 0); }
  int                   iteration;  // testbench iteration (transaction) to which this info applies
  int                   stopat;     // testbench value capture count to stopat (clear) current waits (for ac_channels)
  int                   cycles;     // num of cycles to wait (constant or 1/2 average of random)
  unsigned              interval;   // streamed element interval (fixed or max rand) at which wait cycles applied
  enum_wait_mode        mode;       // UNIFORM or RANDOM
  enum_wait_elements    elements;   // INITIAL (begin of transaction) or ALL (all elements in array/channel)
  bool                  ischannel;  // true if I/O is an ac_channel
};

inline
std::ostream& operator<<(std::ostream& os, const mc_wait_ctrl& wi) {
  if (wi.mode == mc_wait_ctrl::UNIFORM)
    os << " a UNIFORM delay of ";
  else
    os << " a RANDOM delay of up to ";
  os << wi.cycles << " cycles";
  switch (wi.elements) {
    case mc_wait_ctrl::INITIAL: {
      os << " applied to the INITIAL element";
      break;
    }
    case mc_wait_ctrl::ALL: {
      os << " applied to ALL elements";
      break;
    }
    case mc_wait_ctrl::FIXED_INTERVAL: {
      os << " applied at a FIXED_INTERVAL (every " << wi.interval << " elements)";
      break;
    }
    case mc_wait_ctrl::RANDOM_INTERVAL: {
      os << " applied at a RANDOM_INTERVAL (up to every " << wi.interval << " elements)";
      break;
    }
    case mc_wait_ctrl::IDLE_FLUSH: {
      os << " applied at after IDLE flush";
      break;
    }
  }
  if (wi.stopat != wi.iteration+1) {
    if (wi.ischannel) os << " for values ";
    else              os << " for iterations ";
    os << wi.iteration+1 << " to " << wi.stopat;
  } else {
    if (wi.ischannel) os << " for value ";
    else              os << " for iteration ";
    os << wi.iteration+1;
  }
  return os;
}
#endif
