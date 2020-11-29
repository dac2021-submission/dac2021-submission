
#include <gb/gb_high.h>
#include <ilang/target-sc/ila_sim.h>

#include <ilang/util/log.h>

using namespace ilang;

int main() {
  SetToStdErr(1);
  EnableDebug("GbHigh");

  auto gb_high = GbHigh().get();
  IlaSim ila_sim;
  ila_sim.set_instr_lvl_abs(gb_high.get());
  ila_sim.sim_gen("./sim/", false, true, true, true, true, "../refinement/ref-rel-var-map.json");

  return 0;
}
