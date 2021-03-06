module ClockGroupAggregator_3( // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41798.2]
  input   auto_in_member_1_clock, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
  input   auto_in_member_1_reset, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
  input   auto_in_member_0_clock, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
  input   auto_in_member_0_reset, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
  output  auto_out_1_member_0_clock, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
  output  auto_out_1_member_0_reset, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
  output  auto_out_0_member_0_clock, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
  output  auto_out_0_member_0_reset // @[:freechips.rocketchip.system.DefaultRV32Config.fir@41799.4]
);
  assign auto_out_1_member_0_clock = auto_in_member_1_clock; // @[LazyModule.scala 305:12:freechips.rocketchip.system.DefaultRV32Config.fir@41816.4]
  assign auto_out_1_member_0_reset = auto_in_member_1_reset; // @[LazyModule.scala 305:12:freechips.rocketchip.system.DefaultRV32Config.fir@41816.4]
  assign auto_out_0_member_0_clock = auto_in_member_0_clock; // @[LazyModule.scala 305:12:freechips.rocketchip.system.DefaultRV32Config.fir@41815.4]
  assign auto_out_0_member_0_reset = auto_in_member_0_reset; // @[LazyModule.scala 305:12:freechips.rocketchip.system.DefaultRV32Config.fir@41815.4]
endmodule
