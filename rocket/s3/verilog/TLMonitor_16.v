module TLMonitor_16( // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43859.2]
  input         clock, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43860.4]
  input         reset, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43861.4]
  input         io_in_a_ready, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input         io_in_a_valid, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [2:0]  io_in_a_bits_opcode, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [2:0]  io_in_a_bits_param, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [3:0]  io_in_a_bits_size, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [4:0]  io_in_a_bits_source, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [27:0] io_in_a_bits_address, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [3:0]  io_in_a_bits_mask, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input         io_in_a_bits_corrupt, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input         io_in_d_ready, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input         io_in_d_valid, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [2:0]  io_in_d_bits_opcode, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [1:0]  io_in_d_bits_param, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [3:0]  io_in_d_bits_size, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input  [4:0]  io_in_d_bits_source, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input         io_in_d_bits_sink, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input         io_in_d_bits_denied, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
  input         io_in_d_bits_corrupt // @[:freechips.rocketchip.system.DefaultRV32Config.fir@43862.4]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [95:0] _RAND_14;
  reg [159:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] plusarg_reader_out; // @[PlusArg.scala 80:11:freechips.rocketchip.system.DefaultRV32Config.fir@45532.4]
  wire  _T_7; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@43876.6]
  wire  _T_15; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@43884.6]
  wire  _T_20; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@43889.6]
  wire  _T_21; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@43890.6]
  wire  _T_22; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@43891.6]
  wire  _T_24; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43899.6]
  wire  _T_25; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43900.6]
  wire  _T_26; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43901.6]
  wire  _T_27; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43902.6]
  wire [26:0] _T_29; // @[package.scala 207:77:freechips.rocketchip.system.DefaultRV32Config.fir@43904.6]
  wire [11:0] _T_31; // @[package.scala 207:46:freechips.rocketchip.system.DefaultRV32Config.fir@43906.6]
  wire [27:0] _GEN_56; // @[Edges.scala 22:16:freechips.rocketchip.system.DefaultRV32Config.fir@43907.6]
  wire [27:0] _T_32; // @[Edges.scala 22:16:freechips.rocketchip.system.DefaultRV32Config.fir@43907.6]
  wire  _T_33; // @[Edges.scala 22:24:freechips.rocketchip.system.DefaultRV32Config.fir@43908.6]
  wire [1:0] _T_36; // @[OneHot.scala 65:12:freechips.rocketchip.system.DefaultRV32Config.fir@43911.6]
  wire [1:0] _T_38; // @[Misc.scala 201:81:freechips.rocketchip.system.DefaultRV32Config.fir@43913.6]
  wire  _T_39; // @[Misc.scala 205:21:freechips.rocketchip.system.DefaultRV32Config.fir@43914.6]
  wire  _T_42; // @[Misc.scala 210:20:freechips.rocketchip.system.DefaultRV32Config.fir@43917.6]
  wire  _T_44; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43919.6]
  wire  _T_45; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43920.6]
  wire  _T_47; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43922.6]
  wire  _T_48; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43923.6]
  wire  _T_51; // @[Misc.scala 210:20:freechips.rocketchip.system.DefaultRV32Config.fir@43926.6]
  wire  _T_52; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43927.6]
  wire  _T_53; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43928.6]
  wire  _T_54; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43929.6]
  wire  _T_55; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43930.6]
  wire  _T_56; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43931.6]
  wire  _T_57; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43932.6]
  wire  _T_58; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43933.6]
  wire  _T_59; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43934.6]
  wire  _T_60; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43935.6]
  wire  _T_61; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43936.6]
  wire  _T_62; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43937.6]
  wire  _T_63; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43938.6]
  wire [3:0] _T_66; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@43941.6]
  wire [28:0] _T_77; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@43952.6]
  wire  _T_128; // @[Monitor.scala 79:25:freechips.rocketchip.system.DefaultRV32Config.fir@44007.6]
  wire [28:0] _T_133; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44013.8]
  wire  _T_134; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44014.8]
  wire [27:0] _T_135; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44015.8]
  wire [28:0] _T_136; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44016.8]
  wire [28:0] _T_138; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44018.8]
  wire  _T_139; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44019.8]
  wire [27:0] _T_140; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44020.8]
  wire [28:0] _T_141; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44021.8]
  wire [28:0] _T_143; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44023.8]
  wire  _T_144; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44024.8]
  wire [27:0] _T_145; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44025.8]
  wire [28:0] _T_146; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44026.8]
  wire [28:0] _T_148; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44028.8]
  wire  _T_149; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44029.8]
  wire [27:0] _T_150; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44030.8]
  wire [28:0] _T_151; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44031.8]
  wire [28:0] _T_153; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44033.8]
  wire  _T_154; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44034.8]
  wire  _T_155; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44035.8]
  wire  _T_163; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44043.8]
  wire  _T_184; // @[Parameters.scala 92:48:freechips.rocketchip.system.DefaultRV32Config.fir@44074.8]
  wire  _T_187; // @[Mux.scala 27:72:freechips.rocketchip.system.DefaultRV32Config.fir@44077.8]
  wire  _T_196; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44087.8]
  wire  _T_197; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44088.8]
  wire  _T_199; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44094.8]
  wire  _T_200; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44095.8]
  wire  _T_203; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44102.8]
  wire  _T_204; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44103.8]
  wire  _T_206; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44109.8]
  wire  _T_207; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44110.8]
  wire  _T_208; // @[Bundles.scala 110:27:freechips.rocketchip.system.DefaultRV32Config.fir@44115.8]
  wire  _T_210; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44117.8]
  wire  _T_211; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44118.8]
  wire [3:0] _T_212; // @[Monitor.scala 86:18:freechips.rocketchip.system.DefaultRV32Config.fir@44123.8]
  wire  _T_213; // @[Monitor.scala 86:31:freechips.rocketchip.system.DefaultRV32Config.fir@44124.8]
  wire  _T_215; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44126.8]
  wire  _T_216; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44127.8]
  wire  _T_217; // @[Monitor.scala 87:18:freechips.rocketchip.system.DefaultRV32Config.fir@44132.8]
  wire  _T_219; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44134.8]
  wire  _T_220; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44135.8]
  wire  _T_221; // @[Monitor.scala 90:25:freechips.rocketchip.system.DefaultRV32Config.fir@44141.6]
  wire  _T_305; // @[Monitor.scala 97:31:freechips.rocketchip.system.DefaultRV32Config.fir@44257.8]
  wire  _T_307; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44259.8]
  wire  _T_308; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44260.8]
  wire  _T_318; // @[Monitor.scala 102:25:freechips.rocketchip.system.DefaultRV32Config.fir@44283.6]
  wire  _T_320; // @[Parameters.scala 93:42:freechips.rocketchip.system.DefaultRV32Config.fir@44286.8]
  wire  _T_328; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44294.8]
  wire  _T_330; // @[Parameters.scala 93:42:freechips.rocketchip.system.DefaultRV32Config.fir@44296.8]
  wire  _T_353; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44319.8]
  wire  _T_354; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44320.8]
  wire  _T_355; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44321.8]
  wire  _T_356; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44322.8]
  wire  _T_358; // @[Parameters.scala 553:30:freechips.rocketchip.system.DefaultRV32Config.fir@44324.8]
  wire  _T_360; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44326.8]
  wire  _T_361; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44327.8]
  wire  _T_368; // @[Monitor.scala 106:31:freechips.rocketchip.system.DefaultRV32Config.fir@44346.8]
  wire  _T_370; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44348.8]
  wire  _T_371; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44349.8]
  wire  _T_372; // @[Monitor.scala 107:30:freechips.rocketchip.system.DefaultRV32Config.fir@44354.8]
  wire  _T_374; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44356.8]
  wire  _T_375; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44357.8]
  wire  _T_380; // @[Monitor.scala 111:25:freechips.rocketchip.system.DefaultRV32Config.fir@44371.6]
  wire  _T_410; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44402.8]
  wire  _T_411; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44403.8]
  wire  _T_412; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44404.8]
  wire  _T_421; // @[Parameters.scala 553:30:freechips.rocketchip.system.DefaultRV32Config.fir@44413.8]
  wire  _T_424; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44416.8]
  wire  _T_425; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44417.8]
  wire  _T_440; // @[Monitor.scala 119:25:freechips.rocketchip.system.DefaultRV32Config.fir@44453.6]
  wire [3:0] _T_496; // @[Monitor.scala 124:33:freechips.rocketchip.system.DefaultRV32Config.fir@44526.8]
  wire [3:0] _T_497; // @[Monitor.scala 124:31:freechips.rocketchip.system.DefaultRV32Config.fir@44527.8]
  wire  _T_498; // @[Monitor.scala 124:40:freechips.rocketchip.system.DefaultRV32Config.fir@44528.8]
  wire  _T_500; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44530.8]
  wire  _T_501; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44531.8]
  wire  _T_502; // @[Monitor.scala 127:25:freechips.rocketchip.system.DefaultRV32Config.fir@44537.6]
  wire  _T_504; // @[Parameters.scala 93:42:freechips.rocketchip.system.DefaultRV32Config.fir@44540.8]
  wire  _T_528; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44564.8]
  wire  _T_529; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44565.8]
  wire  _T_530; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44566.8]
  wire  _T_541; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44577.8]
  wire  _T_542; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44578.8]
  wire  _T_549; // @[Bundles.scala 140:33:freechips.rocketchip.system.DefaultRV32Config.fir@44597.8]
  wire  _T_551; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44599.8]
  wire  _T_552; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44600.8]
  wire  _T_557; // @[Monitor.scala 135:25:freechips.rocketchip.system.DefaultRV32Config.fir@44614.6]
  wire  _T_604; // @[Bundles.scala 147:30:freechips.rocketchip.system.DefaultRV32Config.fir@44674.8]
  wire  _T_606; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44676.8]
  wire  _T_607; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44677.8]
  wire  _T_612; // @[Monitor.scala 143:25:freechips.rocketchip.system.DefaultRV32Config.fir@44691.6]
  wire  _T_651; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44731.8]
  wire  _T_652; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44732.8]
  wire  _T_659; // @[Bundles.scala 160:28:freechips.rocketchip.system.DefaultRV32Config.fir@44751.8]
  wire  _T_661; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44753.8]
  wire  _T_662; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44754.8]
  wire  _T_671; // @[Bundles.scala 44:24:freechips.rocketchip.system.DefaultRV32Config.fir@44778.6]
  wire  _T_673; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44780.6]
  wire  _T_674; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44781.6]
  wire  _T_678; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@44789.6]
  wire  _T_686; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@44797.6]
  wire  _T_691; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@44802.6]
  wire  _T_692; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@44803.6]
  wire  _T_693; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@44804.6]
  wire  _T_695; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44812.6]
  wire  _T_696; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44813.6]
  wire  _T_697; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44814.6]
  wire  _T_698; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44815.6]
  wire  _T_700; // @[Monitor.scala 307:25:freechips.rocketchip.system.DefaultRV32Config.fir@44817.6]
  wire  _T_702; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44820.8]
  wire  _T_703; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44821.8]
  wire  _T_704; // @[Monitor.scala 309:27:freechips.rocketchip.system.DefaultRV32Config.fir@44826.8]
  wire  _T_706; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44828.8]
  wire  _T_707; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44829.8]
  wire  _T_708; // @[Monitor.scala 310:28:freechips.rocketchip.system.DefaultRV32Config.fir@44834.8]
  wire  _T_710; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44836.8]
  wire  _T_711; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44837.8]
  wire  _T_712; // @[Monitor.scala 311:15:freechips.rocketchip.system.DefaultRV32Config.fir@44842.8]
  wire  _T_714; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44844.8]
  wire  _T_715; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44845.8]
  wire  _T_716; // @[Monitor.scala 312:15:freechips.rocketchip.system.DefaultRV32Config.fir@44850.8]
  wire  _T_718; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44852.8]
  wire  _T_719; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44853.8]
  wire  _T_720; // @[Monitor.scala 315:25:freechips.rocketchip.system.DefaultRV32Config.fir@44859.6]
  wire  _T_731; // @[Bundles.scala 104:26:freechips.rocketchip.system.DefaultRV32Config.fir@44883.8]
  wire  _T_733; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44885.8]
  wire  _T_734; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44886.8]
  wire  _T_735; // @[Monitor.scala 320:28:freechips.rocketchip.system.DefaultRV32Config.fir@44891.8]
  wire  _T_737; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44893.8]
  wire  _T_738; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44894.8]
  wire  _T_748; // @[Monitor.scala 325:25:freechips.rocketchip.system.DefaultRV32Config.fir@44917.6]
  wire  _T_768; // @[Monitor.scala 331:30:freechips.rocketchip.system.DefaultRV32Config.fir@44958.8]
  wire  _T_770; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44960.8]
  wire  _T_771; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44961.8]
  wire  _T_777; // @[Monitor.scala 335:25:freechips.rocketchip.system.DefaultRV32Config.fir@44976.6]
  wire  _T_794; // @[Monitor.scala 343:25:freechips.rocketchip.system.DefaultRV32Config.fir@45011.6]
  wire  _T_812; // @[Monitor.scala 351:25:freechips.rocketchip.system.DefaultRV32Config.fir@45047.6]
  wire  _T_844; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@45113.4]
  wire  _T_851; // @[Edges.scala 93:28:freechips.rocketchip.system.DefaultRV32Config.fir@45120.4]
  reg [9:0] _T_853; // @[Edges.scala 230:27:freechips.rocketchip.system.DefaultRV32Config.fir@45122.4]
  wire [9:0] _T_855; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45124.4]
  wire  _T_856; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45125.4]
  reg [2:0] _T_864; // @[Monitor.scala 381:22:freechips.rocketchip.system.DefaultRV32Config.fir@45136.4]
  reg [2:0] _T_865; // @[Monitor.scala 382:22:freechips.rocketchip.system.DefaultRV32Config.fir@45137.4]
  reg [3:0] _T_866; // @[Monitor.scala 383:22:freechips.rocketchip.system.DefaultRV32Config.fir@45138.4]
  reg [4:0] _T_867; // @[Monitor.scala 384:22:freechips.rocketchip.system.DefaultRV32Config.fir@45139.4]
  reg [27:0] _T_868; // @[Monitor.scala 385:22:freechips.rocketchip.system.DefaultRV32Config.fir@45140.4]
  wire  _T_869; // @[Monitor.scala 386:22:freechips.rocketchip.system.DefaultRV32Config.fir@45141.4]
  wire  _T_870; // @[Monitor.scala 386:19:freechips.rocketchip.system.DefaultRV32Config.fir@45142.4]
  wire  _T_871; // @[Monitor.scala 387:32:freechips.rocketchip.system.DefaultRV32Config.fir@45144.6]
  wire  _T_873; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45146.6]
  wire  _T_874; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45147.6]
  wire  _T_875; // @[Monitor.scala 388:32:freechips.rocketchip.system.DefaultRV32Config.fir@45152.6]
  wire  _T_877; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45154.6]
  wire  _T_878; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45155.6]
  wire  _T_879; // @[Monitor.scala 389:32:freechips.rocketchip.system.DefaultRV32Config.fir@45160.6]
  wire  _T_881; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45162.6]
  wire  _T_882; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45163.6]
  wire  _T_883; // @[Monitor.scala 390:32:freechips.rocketchip.system.DefaultRV32Config.fir@45168.6]
  wire  _T_885; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45170.6]
  wire  _T_886; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45171.6]
  wire  _T_887; // @[Monitor.scala 391:32:freechips.rocketchip.system.DefaultRV32Config.fir@45176.6]
  wire  _T_889; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45178.6]
  wire  _T_890; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45179.6]
  wire  _T_892; // @[Monitor.scala 393:20:freechips.rocketchip.system.DefaultRV32Config.fir@45186.4]
  wire  _T_893; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@45194.4]
  wire [26:0] _T_895; // @[package.scala 207:77:freechips.rocketchip.system.DefaultRV32Config.fir@45196.4]
  wire [11:0] _T_897; // @[package.scala 207:46:freechips.rocketchip.system.DefaultRV32Config.fir@45198.4]
  reg [9:0] _T_901; // @[Edges.scala 230:27:freechips.rocketchip.system.DefaultRV32Config.fir@45202.4]
  wire [9:0] _T_903; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45204.4]
  wire  _T_904; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45205.4]
  reg [2:0] _T_912; // @[Monitor.scala 532:22:freechips.rocketchip.system.DefaultRV32Config.fir@45216.4]
  reg [1:0] _T_913; // @[Monitor.scala 533:22:freechips.rocketchip.system.DefaultRV32Config.fir@45217.4]
  reg [3:0] _T_914; // @[Monitor.scala 534:22:freechips.rocketchip.system.DefaultRV32Config.fir@45218.4]
  reg [4:0] _T_915; // @[Monitor.scala 535:22:freechips.rocketchip.system.DefaultRV32Config.fir@45219.4]
  reg  _T_916; // @[Monitor.scala 536:22:freechips.rocketchip.system.DefaultRV32Config.fir@45220.4]
  reg  _T_917; // @[Monitor.scala 537:22:freechips.rocketchip.system.DefaultRV32Config.fir@45221.4]
  wire  _T_918; // @[Monitor.scala 538:22:freechips.rocketchip.system.DefaultRV32Config.fir@45222.4]
  wire  _T_919; // @[Monitor.scala 538:19:freechips.rocketchip.system.DefaultRV32Config.fir@45223.4]
  wire  _T_920; // @[Monitor.scala 539:29:freechips.rocketchip.system.DefaultRV32Config.fir@45225.6]
  wire  _T_922; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45227.6]
  wire  _T_923; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45228.6]
  wire  _T_924; // @[Monitor.scala 540:29:freechips.rocketchip.system.DefaultRV32Config.fir@45233.6]
  wire  _T_926; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45235.6]
  wire  _T_927; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45236.6]
  wire  _T_928; // @[Monitor.scala 541:29:freechips.rocketchip.system.DefaultRV32Config.fir@45241.6]
  wire  _T_930; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45243.6]
  wire  _T_931; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45244.6]
  wire  _T_932; // @[Monitor.scala 542:29:freechips.rocketchip.system.DefaultRV32Config.fir@45249.6]
  wire  _T_934; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45251.6]
  wire  _T_935; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45252.6]
  wire  _T_936; // @[Monitor.scala 543:29:freechips.rocketchip.system.DefaultRV32Config.fir@45257.6]
  wire  _T_938; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45259.6]
  wire  _T_939; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45260.6]
  wire  _T_940; // @[Monitor.scala 544:29:freechips.rocketchip.system.DefaultRV32Config.fir@45265.6]
  wire  _T_942; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45267.6]
  wire  _T_943; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45268.6]
  wire  _T_945; // @[Monitor.scala 546:20:freechips.rocketchip.system.DefaultRV32Config.fir@45275.4]
  reg [18:0] inflight; // @[Monitor.scala 608:27:freechips.rocketchip.system.DefaultRV32Config.fir@45284.4]
  reg [75:0] inflight_opcodes; // @[Monitor.scala 610:35:freechips.rocketchip.system.DefaultRV32Config.fir@45285.4]
  reg [151:0] inflight_sizes; // @[Monitor.scala 612:33:freechips.rocketchip.system.DefaultRV32Config.fir@45286.4]
  reg [9:0] _T_955; // @[Edges.scala 230:27:freechips.rocketchip.system.DefaultRV32Config.fir@45296.4]
  wire [9:0] _T_957; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45298.4]
  wire  a_first; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45299.4]
  reg [9:0] _T_973; // @[Edges.scala 230:27:freechips.rocketchip.system.DefaultRV32Config.fir@45318.4]
  wire [9:0] _T_975; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45320.4]
  wire  d_first; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45321.4]
  wire [6:0] _GEN_57; // @[Monitor.scala 629:69:freechips.rocketchip.system.DefaultRV32Config.fir@45340.4]
  wire [7:0] _T_983; // @[Monitor.scala 629:69:freechips.rocketchip.system.DefaultRV32Config.fir@45340.4]
  wire [75:0] _T_984; // @[Monitor.scala 629:44:freechips.rocketchip.system.DefaultRV32Config.fir@45341.4]
  wire [15:0] _T_988; // @[Monitor.scala 606:57:freechips.rocketchip.system.DefaultRV32Config.fir@45345.4]
  wire [75:0] _GEN_58; // @[Monitor.scala 629:97:freechips.rocketchip.system.DefaultRV32Config.fir@45346.4]
  wire [75:0] _T_989; // @[Monitor.scala 629:97:freechips.rocketchip.system.DefaultRV32Config.fir@45346.4]
  wire [75:0] _T_990; // @[Monitor.scala 629:152:freechips.rocketchip.system.DefaultRV32Config.fir@45347.4]
  wire [7:0] _T_991; // @[Monitor.scala 633:65:freechips.rocketchip.system.DefaultRV32Config.fir@45351.4]
  wire [151:0] _T_992; // @[Monitor.scala 633:40:freechips.rocketchip.system.DefaultRV32Config.fir@45352.4]
  wire [15:0] _T_996; // @[Monitor.scala 606:57:freechips.rocketchip.system.DefaultRV32Config.fir@45356.4]
  wire [151:0] _GEN_60; // @[Monitor.scala 633:91:freechips.rocketchip.system.DefaultRV32Config.fir@45357.4]
  wire [151:0] _T_997; // @[Monitor.scala 633:91:freechips.rocketchip.system.DefaultRV32Config.fir@45357.4]
  wire [151:0] _T_998; // @[Monitor.scala 633:144:freechips.rocketchip.system.DefaultRV32Config.fir@45358.4]
  wire  _T_1002; // @[Monitor.scala 643:27:freechips.rocketchip.system.DefaultRV32Config.fir@45383.4]
  wire [31:0] _T_1004; // @[OneHot.scala 58:35:freechips.rocketchip.system.DefaultRV32Config.fir@45386.6]
  wire [3:0] _T_1005; // @[Monitor.scala 645:53:freechips.rocketchip.system.DefaultRV32Config.fir@45388.6]
  wire [3:0] _T_1006; // @[Monitor.scala 645:61:freechips.rocketchip.system.DefaultRV32Config.fir@45389.6]
  wire [4:0] _T_1007; // @[Monitor.scala 646:49:freechips.rocketchip.system.DefaultRV32Config.fir@45391.6]
  wire [4:0] _T_1008; // @[Monitor.scala 646:57:freechips.rocketchip.system.DefaultRV32Config.fir@45392.6]
  wire [6:0] _GEN_62; // @[Monitor.scala 647:72:freechips.rocketchip.system.DefaultRV32Config.fir@45394.6]
  wire [7:0] _T_1009; // @[Monitor.scala 647:72:freechips.rocketchip.system.DefaultRV32Config.fir@45394.6]
  wire [3:0] a_opcodes_set_interm; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  wire [258:0] _GEN_63; // @[Monitor.scala 647:47:freechips.rocketchip.system.DefaultRV32Config.fir@45395.6]
  wire [258:0] _T_1010; // @[Monitor.scala 647:47:freechips.rocketchip.system.DefaultRV32Config.fir@45395.6]
  wire [7:0] _T_1011; // @[Monitor.scala 648:68:freechips.rocketchip.system.DefaultRV32Config.fir@45397.6]
  wire [4:0] a_sizes_set_interm; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  wire [259:0] _GEN_64; // @[Monitor.scala 648:43:freechips.rocketchip.system.DefaultRV32Config.fir@45398.6]
  wire [259:0] _T_1012; // @[Monitor.scala 648:43:freechips.rocketchip.system.DefaultRV32Config.fir@45398.6]
  wire [18:0] _T_1013; // @[Monitor.scala 649:26:freechips.rocketchip.system.DefaultRV32Config.fir@45400.6]
  wire  _T_1015; // @[Monitor.scala 649:17:freechips.rocketchip.system.DefaultRV32Config.fir@45402.6]
  wire  _T_1017; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45404.6]
  wire  _T_1018; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45405.6]
  wire [31:0] _GEN_15; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  wire [258:0] _GEN_18; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  wire [259:0] _GEN_19; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  wire  _T_1021; // @[Monitor.scala 660:27:freechips.rocketchip.system.DefaultRV32Config.fir@45419.4]
  wire  _T_1023; // @[Monitor.scala 660:75:freechips.rocketchip.system.DefaultRV32Config.fir@45421.4]
  wire  _T_1024; // @[Monitor.scala 660:72:freechips.rocketchip.system.DefaultRV32Config.fir@45422.4]
  wire [31:0] _T_1025; // @[OneHot.scala 58:35:freechips.rocketchip.system.DefaultRV32Config.fir@45424.6]
  wire [270:0] _GEN_66; // @[Monitor.scala 662:76:freechips.rocketchip.system.DefaultRV32Config.fir@45431.6]
  wire [270:0] _T_1031; // @[Monitor.scala 662:76:freechips.rocketchip.system.DefaultRV32Config.fir@45431.6]
  wire [270:0] _GEN_67; // @[Monitor.scala 663:72:freechips.rocketchip.system.DefaultRV32Config.fir@45438.6]
  wire [270:0] _T_1037; // @[Monitor.scala 663:72:freechips.rocketchip.system.DefaultRV32Config.fir@45438.6]
  wire [31:0] _GEN_20; // @[Monitor.scala 660:91:freechips.rocketchip.system.DefaultRV32Config.fir@45423.4]
  wire [270:0] _GEN_21; // @[Monitor.scala 660:91:freechips.rocketchip.system.DefaultRV32Config.fir@45423.4]
  wire [270:0] _GEN_22; // @[Monitor.scala 660:91:freechips.rocketchip.system.DefaultRV32Config.fir@45423.4]
  wire  _T_1038; // @[Monitor.scala 665:26:freechips.rocketchip.system.DefaultRV32Config.fir@45441.4]
  wire  _T_1041; // @[Monitor.scala 665:71:freechips.rocketchip.system.DefaultRV32Config.fir@45444.4]
  wire [18:0] _T_1042; // @[Monitor.scala 666:25:freechips.rocketchip.system.DefaultRV32Config.fir@45446.6]
  wire  _T_1044; // @[Monitor.scala 666:93:freechips.rocketchip.system.DefaultRV32Config.fir@45448.6]
  wire  _T_1045; // @[Monitor.scala 666:68:freechips.rocketchip.system.DefaultRV32Config.fir@45449.6]
  wire  _T_1046; // @[Monitor.scala 666:142:freechips.rocketchip.system.DefaultRV32Config.fir@45450.6]
  wire  _T_1047; // @[Monitor.scala 666:119:freechips.rocketchip.system.DefaultRV32Config.fir@45451.6]
  wire  _T_1048; // @[Monitor.scala 666:166:freechips.rocketchip.system.DefaultRV32Config.fir@45452.6]
  wire  _T_1049; // @[Monitor.scala 666:49:freechips.rocketchip.system.DefaultRV32Config.fir@45453.6]
  wire  _T_1051; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45455.6]
  wire  _T_1052; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45456.6]
  wire [3:0] a_opcode_lookup; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45338.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45339.4 Monitor.scala 629:21:freechips.rocketchip.system.DefaultRV32Config.fir@45348.4]
  wire [2:0] _GEN_25; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  wire [2:0] _GEN_26; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  wire [2:0] _GEN_27; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  wire [2:0] _GEN_28; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  wire [2:0] _GEN_29; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  wire [2:0] _GEN_30; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  wire  _T_1054; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  wire [2:0] _GEN_37; // @[Monitor.scala 667:96:freechips.rocketchip.system.DefaultRV32Config.fir@45464.6]
  wire [2:0] _GEN_38; // @[Monitor.scala 667:96:freechips.rocketchip.system.DefaultRV32Config.fir@45464.6]
  wire  _T_1056; // @[Monitor.scala 667:96:freechips.rocketchip.system.DefaultRV32Config.fir@45464.6]
  wire  _T_1057; // @[Monitor.scala 667:71:freechips.rocketchip.system.DefaultRV32Config.fir@45465.6]
  wire [2:0] _GEN_41; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  wire [2:0] _GEN_42; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  wire [2:0] _GEN_43; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  wire [2:0] _GEN_44; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  wire [2:0] _GEN_45; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  wire [2:0] _GEN_46; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  wire  _T_1058; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  wire [2:0] _GEN_53; // @[Monitor.scala 668:124:freechips.rocketchip.system.DefaultRV32Config.fir@45467.6]
  wire [2:0] _GEN_54; // @[Monitor.scala 668:124:freechips.rocketchip.system.DefaultRV32Config.fir@45467.6]
  wire  _T_1059; // @[Monitor.scala 668:124:freechips.rocketchip.system.DefaultRV32Config.fir@45467.6]
  wire  _T_1060; // @[Monitor.scala 668:99:freechips.rocketchip.system.DefaultRV32Config.fir@45468.6]
  wire  _T_1061; // @[Monitor.scala 668:34:freechips.rocketchip.system.DefaultRV32Config.fir@45469.6]
  wire  _T_1062; // @[Monitor.scala 668:15:freechips.rocketchip.system.DefaultRV32Config.fir@45470.6]
  wire  _T_1064; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45472.6]
  wire  _T_1065; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45473.6]
  wire [7:0] a_size_lookup; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45349.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45350.4 Monitor.scala 633:19:freechips.rocketchip.system.DefaultRV32Config.fir@45359.4]
  wire [7:0] _GEN_68; // @[Monitor.scala 670:34:freechips.rocketchip.system.DefaultRV32Config.fir@45478.6]
  wire  _T_1066; // @[Monitor.scala 670:34:freechips.rocketchip.system.DefaultRV32Config.fir@45478.6]
  wire  _T_1068; // @[Monitor.scala 670:72:freechips.rocketchip.system.DefaultRV32Config.fir@45480.6]
  wire  _T_1069; // @[Monitor.scala 670:53:freechips.rocketchip.system.DefaultRV32Config.fir@45481.6]
  wire  _T_1071; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45483.6]
  wire  _T_1072; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45484.6]
  wire  _T_1074; // @[Monitor.scala 672:36:freechips.rocketchip.system.DefaultRV32Config.fir@45491.4]
  wire  _T_1075; // @[Monitor.scala 672:47:freechips.rocketchip.system.DefaultRV32Config.fir@45492.4]
  wire  _T_1077; // @[Monitor.scala 672:65:freechips.rocketchip.system.DefaultRV32Config.fir@45494.4]
  wire  _T_1079; // @[Monitor.scala 672:116:freechips.rocketchip.system.DefaultRV32Config.fir@45496.4]
  wire  _T_1080; // @[Monitor.scala 673:15:freechips.rocketchip.system.DefaultRV32Config.fir@45498.6]
  wire  _T_1081; // @[Monitor.scala 673:32:freechips.rocketchip.system.DefaultRV32Config.fir@45499.6]
  wire  _T_1083; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45501.6]
  wire  _T_1084; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45502.6]
  wire [18:0] a_set; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45332.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45333.4 Monitor.scala 644:13:freechips.rocketchip.system.DefaultRV32Config.fir@45387.6]
  wire [18:0] d_clr; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45411.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45412.4 Monitor.scala 661:13:freechips.rocketchip.system.DefaultRV32Config.fir@45425.6]
  wire  _T_1085; // @[Monitor.scala 677:20:freechips.rocketchip.system.DefaultRV32Config.fir@45508.4]
  wire  _T_1086; // @[Monitor.scala 677:40:freechips.rocketchip.system.DefaultRV32Config.fir@45509.4]
  wire  _T_1087; // @[Monitor.scala 677:33:freechips.rocketchip.system.DefaultRV32Config.fir@45510.4]
  wire  _T_1088; // @[Monitor.scala 677:30:freechips.rocketchip.system.DefaultRV32Config.fir@45511.4]
  wire  _T_1090; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45513.4]
  wire  _T_1091; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45514.4]
  wire [18:0] _T_1092; // @[Monitor.scala 680:27:freechips.rocketchip.system.DefaultRV32Config.fir@45519.4]
  wire [18:0] _T_1093; // @[Monitor.scala 680:38:freechips.rocketchip.system.DefaultRV32Config.fir@45520.4]
  wire [18:0] _T_1094; // @[Monitor.scala 680:36:freechips.rocketchip.system.DefaultRV32Config.fir@45521.4]
  wire [75:0] a_opcodes_set; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45334.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45335.4 Monitor.scala 647:21:freechips.rocketchip.system.DefaultRV32Config.fir@45396.6]
  wire [75:0] _T_1095; // @[Monitor.scala 681:43:freechips.rocketchip.system.DefaultRV32Config.fir@45523.4]
  wire [75:0] d_opcodes_clr; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45413.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45414.4 Monitor.scala 662:21:freechips.rocketchip.system.DefaultRV32Config.fir@45432.6]
  wire [75:0] _T_1096; // @[Monitor.scala 681:62:freechips.rocketchip.system.DefaultRV32Config.fir@45524.4]
  wire [75:0] _T_1097; // @[Monitor.scala 681:60:freechips.rocketchip.system.DefaultRV32Config.fir@45525.4]
  wire [151:0] a_sizes_set; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45336.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45337.4 Monitor.scala 648:19:freechips.rocketchip.system.DefaultRV32Config.fir@45399.6]
  wire [151:0] _T_1098; // @[Monitor.scala 682:39:freechips.rocketchip.system.DefaultRV32Config.fir@45527.4]
  wire [151:0] d_sizes_clr; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45415.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45416.4 Monitor.scala 663:19:freechips.rocketchip.system.DefaultRV32Config.fir@45439.6]
  wire [151:0] _T_1099; // @[Monitor.scala 682:56:freechips.rocketchip.system.DefaultRV32Config.fir@45528.4]
  wire [151:0] _T_1100; // @[Monitor.scala 682:54:freechips.rocketchip.system.DefaultRV32Config.fir@45529.4]
  reg [31:0] _T_1101; // @[Monitor.scala 684:27:freechips.rocketchip.system.DefaultRV32Config.fir@45531.4]
  wire  _T_1102; // @[Monitor.scala 687:26:freechips.rocketchip.system.DefaultRV32Config.fir@45534.4]
  wire  _T_1103; // @[Monitor.scala 687:16:freechips.rocketchip.system.DefaultRV32Config.fir@45535.4]
  wire  _T_1104; // @[Monitor.scala 687:39:freechips.rocketchip.system.DefaultRV32Config.fir@45536.4]
  wire  _T_1105; // @[Monitor.scala 687:30:freechips.rocketchip.system.DefaultRV32Config.fir@45537.4]
  wire  _T_1106; // @[Monitor.scala 687:59:freechips.rocketchip.system.DefaultRV32Config.fir@45538.4]
  wire  _T_1107; // @[Monitor.scala 687:47:freechips.rocketchip.system.DefaultRV32Config.fir@45539.4]
  wire  _T_1109; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45541.4]
  wire  _T_1110; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45542.4]
  wire [31:0] _T_1112; // @[Monitor.scala 689:26:freechips.rocketchip.system.DefaultRV32Config.fir@45548.4]
  wire  _T_1115; // @[Monitor.scala 690:27:freechips.rocketchip.system.DefaultRV32Config.fir@45552.4]
  wire  _GEN_69; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44045.10]
  wire  _GEN_85; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44179.10]
  wire  _GEN_103; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44329.10]
  wire  _GEN_115; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44419.10]
  wire  _GEN_125; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44501.10]
  wire  _GEN_135; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44580.10]
  wire  _GEN_145; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44657.10]
  wire  _GEN_155; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44734.10]
  wire  _GEN_167; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44823.10]
  wire  _GEN_177; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44865.10]
  wire  _GEN_189; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44923.10]
  wire  _GEN_201; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44982.10]
  wire  _GEN_207; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45017.10]
  wire  _GEN_213; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45053.10]
  plusarg_reader #(.FORMAT("tilelink_timeout=%d"), .DEFAULT(0), .WIDTH(32)) plusarg_reader ( // @[PlusArg.scala 80:11:freechips.rocketchip.system.DefaultRV32Config.fir@45532.4]
    .out(plusarg_reader_out)
  );
  assign _T_7 = io_in_a_bits_source[4:3] == 2'h0; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@43876.6]
  assign _T_15 = io_in_a_bits_source[4:3] == 2'h1; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@43884.6]
  assign _T_20 = io_in_a_bits_source == 5'h10; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@43889.6]
  assign _T_21 = io_in_a_bits_source == 5'h11; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@43890.6]
  assign _T_22 = io_in_a_bits_source == 5'h12; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@43891.6]
  assign _T_24 = _T_7 | _T_15; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43899.6]
  assign _T_25 = _T_24 | _T_20; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43900.6]
  assign _T_26 = _T_25 | _T_21; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43901.6]
  assign _T_27 = _T_26 | _T_22; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@43902.6]
  assign _T_29 = 27'hfff << io_in_a_bits_size; // @[package.scala 207:77:freechips.rocketchip.system.DefaultRV32Config.fir@43904.6]
  assign _T_31 = ~_T_29[11:0]; // @[package.scala 207:46:freechips.rocketchip.system.DefaultRV32Config.fir@43906.6]
  assign _GEN_56 = {{16'd0}, _T_31}; // @[Edges.scala 22:16:freechips.rocketchip.system.DefaultRV32Config.fir@43907.6]
  assign _T_32 = io_in_a_bits_address & _GEN_56; // @[Edges.scala 22:16:freechips.rocketchip.system.DefaultRV32Config.fir@43907.6]
  assign _T_33 = _T_32 == 28'h0; // @[Edges.scala 22:24:freechips.rocketchip.system.DefaultRV32Config.fir@43908.6]
  assign _T_36 = 2'h1 << io_in_a_bits_size[0]; // @[OneHot.scala 65:12:freechips.rocketchip.system.DefaultRV32Config.fir@43911.6]
  assign _T_38 = _T_36 | 2'h1; // @[Misc.scala 201:81:freechips.rocketchip.system.DefaultRV32Config.fir@43913.6]
  assign _T_39 = io_in_a_bits_size >= 4'h2; // @[Misc.scala 205:21:freechips.rocketchip.system.DefaultRV32Config.fir@43914.6]
  assign _T_42 = ~io_in_a_bits_address[1]; // @[Misc.scala 210:20:freechips.rocketchip.system.DefaultRV32Config.fir@43917.6]
  assign _T_44 = _T_38[1] & _T_42; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43919.6]
  assign _T_45 = _T_39 | _T_44; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43920.6]
  assign _T_47 = _T_38[1] & io_in_a_bits_address[1]; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43922.6]
  assign _T_48 = _T_39 | _T_47; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43923.6]
  assign _T_51 = ~io_in_a_bits_address[0]; // @[Misc.scala 210:20:freechips.rocketchip.system.DefaultRV32Config.fir@43926.6]
  assign _T_52 = _T_42 & _T_51; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43927.6]
  assign _T_53 = _T_38[0] & _T_52; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43928.6]
  assign _T_54 = _T_45 | _T_53; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43929.6]
  assign _T_55 = _T_42 & io_in_a_bits_address[0]; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43930.6]
  assign _T_56 = _T_38[0] & _T_55; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43931.6]
  assign _T_57 = _T_45 | _T_56; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43932.6]
  assign _T_58 = io_in_a_bits_address[1] & _T_51; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43933.6]
  assign _T_59 = _T_38[0] & _T_58; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43934.6]
  assign _T_60 = _T_48 | _T_59; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43935.6]
  assign _T_61 = io_in_a_bits_address[1] & io_in_a_bits_address[0]; // @[Misc.scala 213:27:freechips.rocketchip.system.DefaultRV32Config.fir@43936.6]
  assign _T_62 = _T_38[0] & _T_61; // @[Misc.scala 214:38:freechips.rocketchip.system.DefaultRV32Config.fir@43937.6]
  assign _T_63 = _T_48 | _T_62; // @[Misc.scala 214:29:freechips.rocketchip.system.DefaultRV32Config.fir@43938.6]
  assign _T_66 = {_T_63,_T_60,_T_57,_T_54}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@43941.6]
  assign _T_77 = {1'b0,$signed(io_in_a_bits_address)}; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@43952.6]
  assign _T_128 = io_in_a_bits_opcode == 3'h6; // @[Monitor.scala 79:25:freechips.rocketchip.system.DefaultRV32Config.fir@44007.6]
  assign _T_133 = $signed(_T_77) & -29'sh1000; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44013.8]
  assign _T_134 = $signed(_T_133) == 29'sh0; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44014.8]
  assign _T_135 = io_in_a_bits_address ^ 28'h3000; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44015.8]
  assign _T_136 = {1'b0,$signed(_T_135)}; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44016.8]
  assign _T_138 = $signed(_T_136) & -29'sh1000; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44018.8]
  assign _T_139 = $signed(_T_138) == 29'sh0; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44019.8]
  assign _T_140 = io_in_a_bits_address ^ 28'h10000; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44020.8]
  assign _T_141 = {1'b0,$signed(_T_140)}; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44021.8]
  assign _T_143 = $signed(_T_141) & -29'sh10000; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44023.8]
  assign _T_144 = $signed(_T_143) == 29'sh0; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44024.8]
  assign _T_145 = io_in_a_bits_address ^ 28'h2000000; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44025.8]
  assign _T_146 = {1'b0,$signed(_T_145)}; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44026.8]
  assign _T_148 = $signed(_T_146) & -29'sh10000; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44028.8]
  assign _T_149 = $signed(_T_148) == 29'sh0; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44029.8]
  assign _T_150 = io_in_a_bits_address ^ 28'hc000000; // @[Parameters.scala 137:31:freechips.rocketchip.system.DefaultRV32Config.fir@44030.8]
  assign _T_151 = {1'b0,$signed(_T_150)}; // @[Parameters.scala 137:49:freechips.rocketchip.system.DefaultRV32Config.fir@44031.8]
  assign _T_153 = $signed(_T_151) & -29'sh4000000; // @[Parameters.scala 137:52:freechips.rocketchip.system.DefaultRV32Config.fir@44033.8]
  assign _T_154 = $signed(_T_153) == 29'sh0; // @[Parameters.scala 137:67:freechips.rocketchip.system.DefaultRV32Config.fir@44034.8]
  assign _T_155 = _T_134 | _T_139; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44035.8]
  assign _T_163 = ~reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44043.8]
  assign _T_184 = 4'h6 == io_in_a_bits_size; // @[Parameters.scala 92:48:freechips.rocketchip.system.DefaultRV32Config.fir@44074.8]
  assign _T_187 = _T_20 & _T_184; // @[Mux.scala 27:72:freechips.rocketchip.system.DefaultRV32Config.fir@44077.8]
  assign _T_196 = _T_187 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44087.8]
  assign _T_197 = ~_T_196; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44088.8]
  assign _T_199 = _T_27 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44094.8]
  assign _T_200 = ~_T_199; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44095.8]
  assign _T_203 = _T_39 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44102.8]
  assign _T_204 = ~_T_203; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44103.8]
  assign _T_206 = _T_33 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44109.8]
  assign _T_207 = ~_T_206; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44110.8]
  assign _T_208 = io_in_a_bits_param <= 3'h2; // @[Bundles.scala 110:27:freechips.rocketchip.system.DefaultRV32Config.fir@44115.8]
  assign _T_210 = _T_208 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44117.8]
  assign _T_211 = ~_T_210; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44118.8]
  assign _T_212 = ~io_in_a_bits_mask; // @[Monitor.scala 86:18:freechips.rocketchip.system.DefaultRV32Config.fir@44123.8]
  assign _T_213 = _T_212 == 4'h0; // @[Monitor.scala 86:31:freechips.rocketchip.system.DefaultRV32Config.fir@44124.8]
  assign _T_215 = _T_213 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44126.8]
  assign _T_216 = ~_T_215; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44127.8]
  assign _T_217 = ~io_in_a_bits_corrupt; // @[Monitor.scala 87:18:freechips.rocketchip.system.DefaultRV32Config.fir@44132.8]
  assign _T_219 = _T_217 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44134.8]
  assign _T_220 = ~_T_219; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44135.8]
  assign _T_221 = io_in_a_bits_opcode == 3'h7; // @[Monitor.scala 90:25:freechips.rocketchip.system.DefaultRV32Config.fir@44141.6]
  assign _T_305 = io_in_a_bits_param != 3'h0; // @[Monitor.scala 97:31:freechips.rocketchip.system.DefaultRV32Config.fir@44257.8]
  assign _T_307 = _T_305 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44259.8]
  assign _T_308 = ~_T_307; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44260.8]
  assign _T_318 = io_in_a_bits_opcode == 3'h4; // @[Monitor.scala 102:25:freechips.rocketchip.system.DefaultRV32Config.fir@44283.6]
  assign _T_320 = io_in_a_bits_size <= 4'hc; // @[Parameters.scala 93:42:freechips.rocketchip.system.DefaultRV32Config.fir@44286.8]
  assign _T_328 = _T_320 & _T_139; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44294.8]
  assign _T_330 = io_in_a_bits_size <= 4'h6; // @[Parameters.scala 93:42:freechips.rocketchip.system.DefaultRV32Config.fir@44296.8]
  assign _T_353 = _T_134 | _T_144; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44319.8]
  assign _T_354 = _T_353 | _T_149; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44320.8]
  assign _T_355 = _T_354 | _T_154; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44321.8]
  assign _T_356 = _T_330 & _T_355; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44322.8]
  assign _T_358 = _T_328 | _T_356; // @[Parameters.scala 553:30:freechips.rocketchip.system.DefaultRV32Config.fir@44324.8]
  assign _T_360 = _T_358 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44326.8]
  assign _T_361 = ~_T_360; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44327.8]
  assign _T_368 = io_in_a_bits_param == 3'h0; // @[Monitor.scala 106:31:freechips.rocketchip.system.DefaultRV32Config.fir@44346.8]
  assign _T_370 = _T_368 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44348.8]
  assign _T_371 = ~_T_370; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44349.8]
  assign _T_372 = io_in_a_bits_mask == _T_66; // @[Monitor.scala 107:30:freechips.rocketchip.system.DefaultRV32Config.fir@44354.8]
  assign _T_374 = _T_372 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44356.8]
  assign _T_375 = ~_T_374; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44357.8]
  assign _T_380 = io_in_a_bits_opcode == 3'h0; // @[Monitor.scala 111:25:freechips.rocketchip.system.DefaultRV32Config.fir@44371.6]
  assign _T_410 = _T_134 | _T_149; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44402.8]
  assign _T_411 = _T_410 | _T_154; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44403.8]
  assign _T_412 = _T_330 & _T_411; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44404.8]
  assign _T_421 = _T_328 | _T_412; // @[Parameters.scala 553:30:freechips.rocketchip.system.DefaultRV32Config.fir@44413.8]
  assign _T_424 = _T_421 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44416.8]
  assign _T_425 = ~_T_424; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44417.8]
  assign _T_440 = io_in_a_bits_opcode == 3'h1; // @[Monitor.scala 119:25:freechips.rocketchip.system.DefaultRV32Config.fir@44453.6]
  assign _T_496 = ~_T_66; // @[Monitor.scala 124:33:freechips.rocketchip.system.DefaultRV32Config.fir@44526.8]
  assign _T_497 = io_in_a_bits_mask & _T_496; // @[Monitor.scala 124:31:freechips.rocketchip.system.DefaultRV32Config.fir@44527.8]
  assign _T_498 = _T_497 == 4'h0; // @[Monitor.scala 124:40:freechips.rocketchip.system.DefaultRV32Config.fir@44528.8]
  assign _T_500 = _T_498 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44530.8]
  assign _T_501 = ~_T_500; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44531.8]
  assign _T_502 = io_in_a_bits_opcode == 3'h2; // @[Monitor.scala 127:25:freechips.rocketchip.system.DefaultRV32Config.fir@44537.6]
  assign _T_504 = io_in_a_bits_size <= 4'h2; // @[Parameters.scala 93:42:freechips.rocketchip.system.DefaultRV32Config.fir@44540.8]
  assign _T_528 = _T_155 | _T_149; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44564.8]
  assign _T_529 = _T_528 | _T_154; // @[Parameters.scala 552:42:freechips.rocketchip.system.DefaultRV32Config.fir@44565.8]
  assign _T_530 = _T_504 & _T_529; // @[Parameters.scala 551:56:freechips.rocketchip.system.DefaultRV32Config.fir@44566.8]
  assign _T_541 = _T_530 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44577.8]
  assign _T_542 = ~_T_541; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44578.8]
  assign _T_549 = io_in_a_bits_param <= 3'h4; // @[Bundles.scala 140:33:freechips.rocketchip.system.DefaultRV32Config.fir@44597.8]
  assign _T_551 = _T_549 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44599.8]
  assign _T_552 = ~_T_551; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44600.8]
  assign _T_557 = io_in_a_bits_opcode == 3'h3; // @[Monitor.scala 135:25:freechips.rocketchip.system.DefaultRV32Config.fir@44614.6]
  assign _T_604 = io_in_a_bits_param <= 3'h3; // @[Bundles.scala 147:30:freechips.rocketchip.system.DefaultRV32Config.fir@44674.8]
  assign _T_606 = _T_604 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44676.8]
  assign _T_607 = ~_T_606; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44677.8]
  assign _T_612 = io_in_a_bits_opcode == 3'h5; // @[Monitor.scala 143:25:freechips.rocketchip.system.DefaultRV32Config.fir@44691.6]
  assign _T_651 = _T_328 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44731.8]
  assign _T_652 = ~_T_651; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44732.8]
  assign _T_659 = io_in_a_bits_param <= 3'h1; // @[Bundles.scala 160:28:freechips.rocketchip.system.DefaultRV32Config.fir@44751.8]
  assign _T_661 = _T_659 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44753.8]
  assign _T_662 = ~_T_661; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44754.8]
  assign _T_671 = io_in_d_bits_opcode <= 3'h6; // @[Bundles.scala 44:24:freechips.rocketchip.system.DefaultRV32Config.fir@44778.6]
  assign _T_673 = _T_671 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44780.6]
  assign _T_674 = ~_T_673; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44781.6]
  assign _T_678 = io_in_d_bits_source[4:3] == 2'h0; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@44789.6]
  assign _T_686 = io_in_d_bits_source[4:3] == 2'h1; // @[Parameters.scala 55:32:freechips.rocketchip.system.DefaultRV32Config.fir@44797.6]
  assign _T_691 = io_in_d_bits_source == 5'h10; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@44802.6]
  assign _T_692 = io_in_d_bits_source == 5'h11; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@44803.6]
  assign _T_693 = io_in_d_bits_source == 5'h12; // @[Parameters.scala 47:9:freechips.rocketchip.system.DefaultRV32Config.fir@44804.6]
  assign _T_695 = _T_678 | _T_686; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44812.6]
  assign _T_696 = _T_695 | _T_691; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44813.6]
  assign _T_697 = _T_696 | _T_692; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44814.6]
  assign _T_698 = _T_697 | _T_693; // @[Parameters.scala 924:46:freechips.rocketchip.system.DefaultRV32Config.fir@44815.6]
  assign _T_700 = io_in_d_bits_opcode == 3'h6; // @[Monitor.scala 307:25:freechips.rocketchip.system.DefaultRV32Config.fir@44817.6]
  assign _T_702 = _T_698 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44820.8]
  assign _T_703 = ~_T_702; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44821.8]
  assign _T_704 = io_in_d_bits_size >= 4'h2; // @[Monitor.scala 309:27:freechips.rocketchip.system.DefaultRV32Config.fir@44826.8]
  assign _T_706 = _T_704 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44828.8]
  assign _T_707 = ~_T_706; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44829.8]
  assign _T_708 = io_in_d_bits_param == 2'h0; // @[Monitor.scala 310:28:freechips.rocketchip.system.DefaultRV32Config.fir@44834.8]
  assign _T_710 = _T_708 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44836.8]
  assign _T_711 = ~_T_710; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44837.8]
  assign _T_712 = ~io_in_d_bits_corrupt; // @[Monitor.scala 311:15:freechips.rocketchip.system.DefaultRV32Config.fir@44842.8]
  assign _T_714 = _T_712 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44844.8]
  assign _T_715 = ~_T_714; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44845.8]
  assign _T_716 = ~io_in_d_bits_denied; // @[Monitor.scala 312:15:freechips.rocketchip.system.DefaultRV32Config.fir@44850.8]
  assign _T_718 = _T_716 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44852.8]
  assign _T_719 = ~_T_718; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44853.8]
  assign _T_720 = io_in_d_bits_opcode == 3'h4; // @[Monitor.scala 315:25:freechips.rocketchip.system.DefaultRV32Config.fir@44859.6]
  assign _T_731 = io_in_d_bits_param <= 2'h2; // @[Bundles.scala 104:26:freechips.rocketchip.system.DefaultRV32Config.fir@44883.8]
  assign _T_733 = _T_731 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44885.8]
  assign _T_734 = ~_T_733; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44886.8]
  assign _T_735 = io_in_d_bits_param != 2'h2; // @[Monitor.scala 320:28:freechips.rocketchip.system.DefaultRV32Config.fir@44891.8]
  assign _T_737 = _T_735 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44893.8]
  assign _T_738 = ~_T_737; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44894.8]
  assign _T_748 = io_in_d_bits_opcode == 3'h5; // @[Monitor.scala 325:25:freechips.rocketchip.system.DefaultRV32Config.fir@44917.6]
  assign _T_768 = _T_716 | io_in_d_bits_corrupt; // @[Monitor.scala 331:30:freechips.rocketchip.system.DefaultRV32Config.fir@44958.8]
  assign _T_770 = _T_768 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44960.8]
  assign _T_771 = ~_T_770; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44961.8]
  assign _T_777 = io_in_d_bits_opcode == 3'h0; // @[Monitor.scala 335:25:freechips.rocketchip.system.DefaultRV32Config.fir@44976.6]
  assign _T_794 = io_in_d_bits_opcode == 3'h1; // @[Monitor.scala 343:25:freechips.rocketchip.system.DefaultRV32Config.fir@45011.6]
  assign _T_812 = io_in_d_bits_opcode == 3'h2; // @[Monitor.scala 351:25:freechips.rocketchip.system.DefaultRV32Config.fir@45047.6]
  assign _T_844 = io_in_a_ready & io_in_a_valid; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@45113.4]
  assign _T_851 = ~io_in_a_bits_opcode[2]; // @[Edges.scala 93:28:freechips.rocketchip.system.DefaultRV32Config.fir@45120.4]
  assign _T_855 = _T_853 - 10'h1; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45124.4]
  assign _T_856 = _T_853 == 10'h0; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45125.4]
  assign _T_869 = ~_T_856; // @[Monitor.scala 386:22:freechips.rocketchip.system.DefaultRV32Config.fir@45141.4]
  assign _T_870 = io_in_a_valid & _T_869; // @[Monitor.scala 386:19:freechips.rocketchip.system.DefaultRV32Config.fir@45142.4]
  assign _T_871 = io_in_a_bits_opcode == _T_864; // @[Monitor.scala 387:32:freechips.rocketchip.system.DefaultRV32Config.fir@45144.6]
  assign _T_873 = _T_871 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45146.6]
  assign _T_874 = ~_T_873; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45147.6]
  assign _T_875 = io_in_a_bits_param == _T_865; // @[Monitor.scala 388:32:freechips.rocketchip.system.DefaultRV32Config.fir@45152.6]
  assign _T_877 = _T_875 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45154.6]
  assign _T_878 = ~_T_877; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45155.6]
  assign _T_879 = io_in_a_bits_size == _T_866; // @[Monitor.scala 389:32:freechips.rocketchip.system.DefaultRV32Config.fir@45160.6]
  assign _T_881 = _T_879 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45162.6]
  assign _T_882 = ~_T_881; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45163.6]
  assign _T_883 = io_in_a_bits_source == _T_867; // @[Monitor.scala 390:32:freechips.rocketchip.system.DefaultRV32Config.fir@45168.6]
  assign _T_885 = _T_883 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45170.6]
  assign _T_886 = ~_T_885; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45171.6]
  assign _T_887 = io_in_a_bits_address == _T_868; // @[Monitor.scala 391:32:freechips.rocketchip.system.DefaultRV32Config.fir@45176.6]
  assign _T_889 = _T_887 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45178.6]
  assign _T_890 = ~_T_889; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45179.6]
  assign _T_892 = _T_844 & _T_856; // @[Monitor.scala 393:20:freechips.rocketchip.system.DefaultRV32Config.fir@45186.4]
  assign _T_893 = io_in_d_ready & io_in_d_valid; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@45194.4]
  assign _T_895 = 27'hfff << io_in_d_bits_size; // @[package.scala 207:77:freechips.rocketchip.system.DefaultRV32Config.fir@45196.4]
  assign _T_897 = ~_T_895[11:0]; // @[package.scala 207:46:freechips.rocketchip.system.DefaultRV32Config.fir@45198.4]
  assign _T_903 = _T_901 - 10'h1; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45204.4]
  assign _T_904 = _T_901 == 10'h0; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45205.4]
  assign _T_918 = ~_T_904; // @[Monitor.scala 538:22:freechips.rocketchip.system.DefaultRV32Config.fir@45222.4]
  assign _T_919 = io_in_d_valid & _T_918; // @[Monitor.scala 538:19:freechips.rocketchip.system.DefaultRV32Config.fir@45223.4]
  assign _T_920 = io_in_d_bits_opcode == _T_912; // @[Monitor.scala 539:29:freechips.rocketchip.system.DefaultRV32Config.fir@45225.6]
  assign _T_922 = _T_920 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45227.6]
  assign _T_923 = ~_T_922; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45228.6]
  assign _T_924 = io_in_d_bits_param == _T_913; // @[Monitor.scala 540:29:freechips.rocketchip.system.DefaultRV32Config.fir@45233.6]
  assign _T_926 = _T_924 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45235.6]
  assign _T_927 = ~_T_926; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45236.6]
  assign _T_928 = io_in_d_bits_size == _T_914; // @[Monitor.scala 541:29:freechips.rocketchip.system.DefaultRV32Config.fir@45241.6]
  assign _T_930 = _T_928 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45243.6]
  assign _T_931 = ~_T_930; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45244.6]
  assign _T_932 = io_in_d_bits_source == _T_915; // @[Monitor.scala 542:29:freechips.rocketchip.system.DefaultRV32Config.fir@45249.6]
  assign _T_934 = _T_932 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45251.6]
  assign _T_935 = ~_T_934; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45252.6]
  assign _T_936 = io_in_d_bits_sink == _T_916; // @[Monitor.scala 543:29:freechips.rocketchip.system.DefaultRV32Config.fir@45257.6]
  assign _T_938 = _T_936 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45259.6]
  assign _T_939 = ~_T_938; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45260.6]
  assign _T_940 = io_in_d_bits_denied == _T_917; // @[Monitor.scala 544:29:freechips.rocketchip.system.DefaultRV32Config.fir@45265.6]
  assign _T_942 = _T_940 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45267.6]
  assign _T_943 = ~_T_942; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45268.6]
  assign _T_945 = _T_893 & _T_904; // @[Monitor.scala 546:20:freechips.rocketchip.system.DefaultRV32Config.fir@45275.4]
  assign _T_957 = _T_955 - 10'h1; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45298.4]
  assign a_first = _T_955 == 10'h0; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45299.4]
  assign _T_975 = _T_973 - 10'h1; // @[Edges.scala 231:28:freechips.rocketchip.system.DefaultRV32Config.fir@45320.4]
  assign d_first = _T_973 == 10'h0; // @[Edges.scala 232:25:freechips.rocketchip.system.DefaultRV32Config.fir@45321.4]
  assign _GEN_57 = {io_in_d_bits_source, 2'h0}; // @[Monitor.scala 629:69:freechips.rocketchip.system.DefaultRV32Config.fir@45340.4]
  assign _T_983 = {{1'd0}, _GEN_57}; // @[Monitor.scala 629:69:freechips.rocketchip.system.DefaultRV32Config.fir@45340.4]
  assign _T_984 = inflight_opcodes >> _T_983; // @[Monitor.scala 629:44:freechips.rocketchip.system.DefaultRV32Config.fir@45341.4]
  assign _T_988 = 16'h10 - 16'h1; // @[Monitor.scala 606:57:freechips.rocketchip.system.DefaultRV32Config.fir@45345.4]
  assign _GEN_58 = {{60'd0}, _T_988}; // @[Monitor.scala 629:97:freechips.rocketchip.system.DefaultRV32Config.fir@45346.4]
  assign _T_989 = _T_984 & _GEN_58; // @[Monitor.scala 629:97:freechips.rocketchip.system.DefaultRV32Config.fir@45346.4]
  assign _T_990 = {{1'd0}, _T_989[75:1]}; // @[Monitor.scala 629:152:freechips.rocketchip.system.DefaultRV32Config.fir@45347.4]
  assign _T_991 = {io_in_d_bits_source, 3'h0}; // @[Monitor.scala 633:65:freechips.rocketchip.system.DefaultRV32Config.fir@45351.4]
  assign _T_992 = inflight_sizes >> _T_991; // @[Monitor.scala 633:40:freechips.rocketchip.system.DefaultRV32Config.fir@45352.4]
  assign _T_996 = 16'h100 - 16'h1; // @[Monitor.scala 606:57:freechips.rocketchip.system.DefaultRV32Config.fir@45356.4]
  assign _GEN_60 = {{136'd0}, _T_996}; // @[Monitor.scala 633:91:freechips.rocketchip.system.DefaultRV32Config.fir@45357.4]
  assign _T_997 = _T_992 & _GEN_60; // @[Monitor.scala 633:91:freechips.rocketchip.system.DefaultRV32Config.fir@45357.4]
  assign _T_998 = {{1'd0}, _T_997[151:1]}; // @[Monitor.scala 633:144:freechips.rocketchip.system.DefaultRV32Config.fir@45358.4]
  assign _T_1002 = _T_844 & a_first; // @[Monitor.scala 643:27:freechips.rocketchip.system.DefaultRV32Config.fir@45383.4]
  assign _T_1004 = 32'h1 << io_in_a_bits_source; // @[OneHot.scala 58:35:freechips.rocketchip.system.DefaultRV32Config.fir@45386.6]
  assign _T_1005 = {io_in_a_bits_opcode, 1'h0}; // @[Monitor.scala 645:53:freechips.rocketchip.system.DefaultRV32Config.fir@45388.6]
  assign _T_1006 = _T_1005 | 4'h1; // @[Monitor.scala 645:61:freechips.rocketchip.system.DefaultRV32Config.fir@45389.6]
  assign _T_1007 = {io_in_a_bits_size, 1'h0}; // @[Monitor.scala 646:49:freechips.rocketchip.system.DefaultRV32Config.fir@45391.6]
  assign _T_1008 = _T_1007 | 5'h1; // @[Monitor.scala 646:57:freechips.rocketchip.system.DefaultRV32Config.fir@45392.6]
  assign _GEN_62 = {io_in_a_bits_source, 2'h0}; // @[Monitor.scala 647:72:freechips.rocketchip.system.DefaultRV32Config.fir@45394.6]
  assign _T_1009 = {{1'd0}, _GEN_62}; // @[Monitor.scala 647:72:freechips.rocketchip.system.DefaultRV32Config.fir@45394.6]
  assign a_opcodes_set_interm = _T_1002 ? _T_1006 : 4'h0; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  assign _GEN_63 = {{255'd0}, a_opcodes_set_interm}; // @[Monitor.scala 647:47:freechips.rocketchip.system.DefaultRV32Config.fir@45395.6]
  assign _T_1010 = _GEN_63 << _T_1009; // @[Monitor.scala 647:47:freechips.rocketchip.system.DefaultRV32Config.fir@45395.6]
  assign _T_1011 = {io_in_a_bits_source, 3'h0}; // @[Monitor.scala 648:68:freechips.rocketchip.system.DefaultRV32Config.fir@45397.6]
  assign a_sizes_set_interm = _T_1002 ? _T_1008 : 5'h0; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  assign _GEN_64 = {{255'd0}, a_sizes_set_interm}; // @[Monitor.scala 648:43:freechips.rocketchip.system.DefaultRV32Config.fir@45398.6]
  assign _T_1012 = _GEN_64 << _T_1011; // @[Monitor.scala 648:43:freechips.rocketchip.system.DefaultRV32Config.fir@45398.6]
  assign _T_1013 = inflight >> io_in_a_bits_source; // @[Monitor.scala 649:26:freechips.rocketchip.system.DefaultRV32Config.fir@45400.6]
  assign _T_1015 = ~_T_1013[0]; // @[Monitor.scala 649:17:freechips.rocketchip.system.DefaultRV32Config.fir@45402.6]
  assign _T_1017 = _T_1015 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45404.6]
  assign _T_1018 = ~_T_1017; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45405.6]
  assign _GEN_15 = _T_1002 ? _T_1004 : 32'h0; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  assign _GEN_18 = _T_1002 ? _T_1010 : 259'h0; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  assign _GEN_19 = _T_1002 ? _T_1012 : 260'h0; // @[Monitor.scala 643:72:freechips.rocketchip.system.DefaultRV32Config.fir@45385.4]
  assign _T_1021 = _T_893 & d_first; // @[Monitor.scala 660:27:freechips.rocketchip.system.DefaultRV32Config.fir@45419.4]
  assign _T_1023 = ~_T_700; // @[Monitor.scala 660:75:freechips.rocketchip.system.DefaultRV32Config.fir@45421.4]
  assign _T_1024 = _T_1021 & _T_1023; // @[Monitor.scala 660:72:freechips.rocketchip.system.DefaultRV32Config.fir@45422.4]
  assign _T_1025 = 32'h1 << io_in_d_bits_source; // @[OneHot.scala 58:35:freechips.rocketchip.system.DefaultRV32Config.fir@45424.6]
  assign _GEN_66 = {{255'd0}, _T_988}; // @[Monitor.scala 662:76:freechips.rocketchip.system.DefaultRV32Config.fir@45431.6]
  assign _T_1031 = _GEN_66 << _T_983; // @[Monitor.scala 662:76:freechips.rocketchip.system.DefaultRV32Config.fir@45431.6]
  assign _GEN_67 = {{255'd0}, _T_996}; // @[Monitor.scala 663:72:freechips.rocketchip.system.DefaultRV32Config.fir@45438.6]
  assign _T_1037 = _GEN_67 << _T_991; // @[Monitor.scala 663:72:freechips.rocketchip.system.DefaultRV32Config.fir@45438.6]
  assign _GEN_20 = _T_1024 ? _T_1025 : 32'h0; // @[Monitor.scala 660:91:freechips.rocketchip.system.DefaultRV32Config.fir@45423.4]
  assign _GEN_21 = _T_1024 ? _T_1031 : 271'h0; // @[Monitor.scala 660:91:freechips.rocketchip.system.DefaultRV32Config.fir@45423.4]
  assign _GEN_22 = _T_1024 ? _T_1037 : 271'h0; // @[Monitor.scala 660:91:freechips.rocketchip.system.DefaultRV32Config.fir@45423.4]
  assign _T_1038 = io_in_d_valid & d_first; // @[Monitor.scala 665:26:freechips.rocketchip.system.DefaultRV32Config.fir@45441.4]
  assign _T_1041 = _T_1038 & _T_1023; // @[Monitor.scala 665:71:freechips.rocketchip.system.DefaultRV32Config.fir@45444.4]
  assign _T_1042 = inflight >> io_in_d_bits_source; // @[Monitor.scala 666:25:freechips.rocketchip.system.DefaultRV32Config.fir@45446.6]
  assign _T_1044 = io_in_a_bits_source == io_in_d_bits_source; // @[Monitor.scala 666:93:freechips.rocketchip.system.DefaultRV32Config.fir@45448.6]
  assign _T_1045 = io_in_a_valid & _T_1044; // @[Monitor.scala 666:68:freechips.rocketchip.system.DefaultRV32Config.fir@45449.6]
  assign _T_1046 = io_in_a_bits_size == io_in_d_bits_size; // @[Monitor.scala 666:142:freechips.rocketchip.system.DefaultRV32Config.fir@45450.6]
  assign _T_1047 = _T_1045 & _T_1046; // @[Monitor.scala 666:119:freechips.rocketchip.system.DefaultRV32Config.fir@45451.6]
  assign _T_1048 = _T_1047 & a_first; // @[Monitor.scala 666:166:freechips.rocketchip.system.DefaultRV32Config.fir@45452.6]
  assign _T_1049 = _T_1042[0] | _T_1048; // @[Monitor.scala 666:49:freechips.rocketchip.system.DefaultRV32Config.fir@45453.6]
  assign _T_1051 = _T_1049 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45455.6]
  assign _T_1052 = ~_T_1051; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45456.6]
  assign a_opcode_lookup = _T_990[3:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45338.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45339.4 Monitor.scala 629:21:freechips.rocketchip.system.DefaultRV32Config.fir@45348.4]
  assign _GEN_25 = 3'h2 == a_opcode_lookup[2:0] ? 3'h1 : 3'h0; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  assign _GEN_26 = 3'h3 == a_opcode_lookup[2:0] ? 3'h1 : _GEN_25; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  assign _GEN_27 = 3'h4 == a_opcode_lookup[2:0] ? 3'h1 : _GEN_26; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  assign _GEN_28 = 3'h5 == a_opcode_lookup[2:0] ? 3'h2 : _GEN_27; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  assign _GEN_29 = 3'h6 == a_opcode_lookup[2:0] ? 3'h4 : _GEN_28; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  assign _GEN_30 = 3'h7 == a_opcode_lookup[2:0] ? 3'h4 : _GEN_29; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  assign _T_1054 = io_in_d_bits_opcode == _GEN_30; // @[Monitor.scala 667:37:freechips.rocketchip.system.DefaultRV32Config.fir@45462.6]
  assign _GEN_37 = 3'h6 == a_opcode_lookup[2:0] ? 3'h5 : _GEN_28; // @[Monitor.scala 667:96:freechips.rocketchip.system.DefaultRV32Config.fir@45464.6]
  assign _GEN_38 = 3'h7 == a_opcode_lookup[2:0] ? 3'h4 : _GEN_37; // @[Monitor.scala 667:96:freechips.rocketchip.system.DefaultRV32Config.fir@45464.6]
  assign _T_1056 = io_in_d_bits_opcode == _GEN_38; // @[Monitor.scala 667:96:freechips.rocketchip.system.DefaultRV32Config.fir@45464.6]
  assign _T_1057 = _T_1054 | _T_1056; // @[Monitor.scala 667:71:freechips.rocketchip.system.DefaultRV32Config.fir@45465.6]
  assign _GEN_41 = 3'h2 == io_in_a_bits_opcode ? 3'h1 : 3'h0; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  assign _GEN_42 = 3'h3 == io_in_a_bits_opcode ? 3'h1 : _GEN_41; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  assign _GEN_43 = 3'h4 == io_in_a_bits_opcode ? 3'h1 : _GEN_42; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  assign _GEN_44 = 3'h5 == io_in_a_bits_opcode ? 3'h2 : _GEN_43; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  assign _GEN_45 = 3'h6 == io_in_a_bits_opcode ? 3'h4 : _GEN_44; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  assign _GEN_46 = 3'h7 == io_in_a_bits_opcode ? 3'h4 : _GEN_45; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  assign _T_1058 = io_in_d_bits_opcode == _GEN_46; // @[Monitor.scala 668:60:freechips.rocketchip.system.DefaultRV32Config.fir@45466.6]
  assign _GEN_53 = 3'h6 == io_in_a_bits_opcode ? 3'h5 : _GEN_44; // @[Monitor.scala 668:124:freechips.rocketchip.system.DefaultRV32Config.fir@45467.6]
  assign _GEN_54 = 3'h7 == io_in_a_bits_opcode ? 3'h4 : _GEN_53; // @[Monitor.scala 668:124:freechips.rocketchip.system.DefaultRV32Config.fir@45467.6]
  assign _T_1059 = io_in_d_bits_opcode == _GEN_54; // @[Monitor.scala 668:124:freechips.rocketchip.system.DefaultRV32Config.fir@45467.6]
  assign _T_1060 = _T_1058 | _T_1059; // @[Monitor.scala 668:99:freechips.rocketchip.system.DefaultRV32Config.fir@45468.6]
  assign _T_1061 = io_in_a_valid & _T_1060; // @[Monitor.scala 668:34:freechips.rocketchip.system.DefaultRV32Config.fir@45469.6]
  assign _T_1062 = _T_1057 | _T_1061; // @[Monitor.scala 668:15:freechips.rocketchip.system.DefaultRV32Config.fir@45470.6]
  assign _T_1064 = _T_1062 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45472.6]
  assign _T_1065 = ~_T_1064; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45473.6]
  assign a_size_lookup = _T_998[7:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45349.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45350.4 Monitor.scala 633:19:freechips.rocketchip.system.DefaultRV32Config.fir@45359.4]
  assign _GEN_68 = {{4'd0}, io_in_d_bits_size}; // @[Monitor.scala 670:34:freechips.rocketchip.system.DefaultRV32Config.fir@45478.6]
  assign _T_1066 = _GEN_68 == a_size_lookup; // @[Monitor.scala 670:34:freechips.rocketchip.system.DefaultRV32Config.fir@45478.6]
  assign _T_1068 = io_in_a_valid & _T_1046; // @[Monitor.scala 670:72:freechips.rocketchip.system.DefaultRV32Config.fir@45480.6]
  assign _T_1069 = _T_1066 | _T_1068; // @[Monitor.scala 670:53:freechips.rocketchip.system.DefaultRV32Config.fir@45481.6]
  assign _T_1071 = _T_1069 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45483.6]
  assign _T_1072 = ~_T_1071; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45484.6]
  assign _T_1074 = _T_1038 & a_first; // @[Monitor.scala 672:36:freechips.rocketchip.system.DefaultRV32Config.fir@45491.4]
  assign _T_1075 = _T_1074 & io_in_a_valid; // @[Monitor.scala 672:47:freechips.rocketchip.system.DefaultRV32Config.fir@45492.4]
  assign _T_1077 = _T_1075 & _T_1044; // @[Monitor.scala 672:65:freechips.rocketchip.system.DefaultRV32Config.fir@45494.4]
  assign _T_1079 = _T_1077 & _T_1023; // @[Monitor.scala 672:116:freechips.rocketchip.system.DefaultRV32Config.fir@45496.4]
  assign _T_1080 = ~io_in_d_ready; // @[Monitor.scala 673:15:freechips.rocketchip.system.DefaultRV32Config.fir@45498.6]
  assign _T_1081 = _T_1080 | io_in_a_ready; // @[Monitor.scala 673:32:freechips.rocketchip.system.DefaultRV32Config.fir@45499.6]
  assign _T_1083 = _T_1081 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45501.6]
  assign _T_1084 = ~_T_1083; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45502.6]
  assign a_set = _GEN_15[18:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45332.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45333.4 Monitor.scala 644:13:freechips.rocketchip.system.DefaultRV32Config.fir@45387.6]
  assign d_clr = _GEN_20[18:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45411.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45412.4 Monitor.scala 661:13:freechips.rocketchip.system.DefaultRV32Config.fir@45425.6]
  assign _T_1085 = a_set != d_clr; // @[Monitor.scala 677:20:freechips.rocketchip.system.DefaultRV32Config.fir@45508.4]
  assign _T_1086 = |a_set; // @[Monitor.scala 677:40:freechips.rocketchip.system.DefaultRV32Config.fir@45509.4]
  assign _T_1087 = ~_T_1086; // @[Monitor.scala 677:33:freechips.rocketchip.system.DefaultRV32Config.fir@45510.4]
  assign _T_1088 = _T_1085 | _T_1087; // @[Monitor.scala 677:30:freechips.rocketchip.system.DefaultRV32Config.fir@45511.4]
  assign _T_1090 = _T_1088 | reset; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45513.4]
  assign _T_1091 = ~_T_1090; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45514.4]
  assign _T_1092 = inflight | a_set; // @[Monitor.scala 680:27:freechips.rocketchip.system.DefaultRV32Config.fir@45519.4]
  assign _T_1093 = ~d_clr; // @[Monitor.scala 680:38:freechips.rocketchip.system.DefaultRV32Config.fir@45520.4]
  assign _T_1094 = _T_1092 & _T_1093; // @[Monitor.scala 680:36:freechips.rocketchip.system.DefaultRV32Config.fir@45521.4]
  assign a_opcodes_set = _GEN_18[75:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45334.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45335.4 Monitor.scala 647:21:freechips.rocketchip.system.DefaultRV32Config.fir@45396.6]
  assign _T_1095 = inflight_opcodes | a_opcodes_set; // @[Monitor.scala 681:43:freechips.rocketchip.system.DefaultRV32Config.fir@45523.4]
  assign d_opcodes_clr = _GEN_21[75:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45413.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45414.4 Monitor.scala 662:21:freechips.rocketchip.system.DefaultRV32Config.fir@45432.6]
  assign _T_1096 = ~d_opcodes_clr; // @[Monitor.scala 681:62:freechips.rocketchip.system.DefaultRV32Config.fir@45524.4]
  assign _T_1097 = _T_1095 & _T_1096; // @[Monitor.scala 681:60:freechips.rocketchip.system.DefaultRV32Config.fir@45525.4]
  assign a_sizes_set = _GEN_19[151:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45336.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45337.4 Monitor.scala 648:19:freechips.rocketchip.system.DefaultRV32Config.fir@45399.6]
  assign _T_1098 = inflight_sizes | a_sizes_set; // @[Monitor.scala 682:39:freechips.rocketchip.system.DefaultRV32Config.fir@45527.4]
  assign d_sizes_clr = _GEN_22[151:0]; // @[:freechips.rocketchip.system.DefaultRV32Config.fir@45415.4 :freechips.rocketchip.system.DefaultRV32Config.fir@45416.4 Monitor.scala 663:19:freechips.rocketchip.system.DefaultRV32Config.fir@45439.6]
  assign _T_1099 = ~d_sizes_clr; // @[Monitor.scala 682:56:freechips.rocketchip.system.DefaultRV32Config.fir@45528.4]
  assign _T_1100 = _T_1098 & _T_1099; // @[Monitor.scala 682:54:freechips.rocketchip.system.DefaultRV32Config.fir@45529.4]
  assign _T_1102 = |inflight; // @[Monitor.scala 687:26:freechips.rocketchip.system.DefaultRV32Config.fir@45534.4]
  assign _T_1103 = ~_T_1102; // @[Monitor.scala 687:16:freechips.rocketchip.system.DefaultRV32Config.fir@45535.4]
  assign _T_1104 = plusarg_reader_out == 32'h0; // @[Monitor.scala 687:39:freechips.rocketchip.system.DefaultRV32Config.fir@45536.4]
  assign _T_1105 = _T_1103 | _T_1104; // @[Monitor.scala 687:30:freechips.rocketchip.system.DefaultRV32Config.fir@45537.4]
  assign _T_1106 = _T_1101 < plusarg_reader_out; // @[Monitor.scala 687:59:freechips.rocketchip.system.DefaultRV32Config.fir@45538.4]
  assign _T_1107 = _T_1105 | _T_1106; // @[Monitor.scala 687:47:freechips.rocketchip.system.DefaultRV32Config.fir@45539.4]
  assign _T_1109 = _T_1107 | reset; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45541.4]
  assign _T_1110 = ~_T_1109; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45542.4]
  assign _T_1112 = _T_1101 + 32'h1; // @[Monitor.scala 689:26:freechips.rocketchip.system.DefaultRV32Config.fir@45548.4]
  assign _T_1115 = _T_844 | _T_893; // @[Monitor.scala 690:27:freechips.rocketchip.system.DefaultRV32Config.fir@45552.4]
  assign _GEN_69 = io_in_a_valid & _T_128; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44045.10]
  assign _GEN_85 = io_in_a_valid & _T_221; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44179.10]
  assign _GEN_103 = io_in_a_valid & _T_318; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44329.10]
  assign _GEN_115 = io_in_a_valid & _T_380; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44419.10]
  assign _GEN_125 = io_in_a_valid & _T_440; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44501.10]
  assign _GEN_135 = io_in_a_valid & _T_502; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44580.10]
  assign _GEN_145 = io_in_a_valid & _T_557; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44657.10]
  assign _GEN_155 = io_in_a_valid & _T_612; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44734.10]
  assign _GEN_167 = io_in_d_valid & _T_700; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44823.10]
  assign _GEN_177 = io_in_d_valid & _T_720; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44865.10]
  assign _GEN_189 = io_in_d_valid & _T_748; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44923.10]
  assign _GEN_201 = io_in_d_valid & _T_777; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44982.10]
  assign _GEN_207 = io_in_d_valid & _T_794; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45017.10]
  assign _GEN_213 = io_in_d_valid & _T_812; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45053.10]
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  _T_853 = _RAND_0[9:0];
  _RAND_1 = {1{`RANDOM}};
  _T_864 = _RAND_1[2:0];
  _RAND_2 = {1{`RANDOM}};
  _T_865 = _RAND_2[2:0];
  _RAND_3 = {1{`RANDOM}};
  _T_866 = _RAND_3[3:0];
  _RAND_4 = {1{`RANDOM}};
  _T_867 = _RAND_4[4:0];
  _RAND_5 = {1{`RANDOM}};
  _T_868 = _RAND_5[27:0];
  _RAND_6 = {1{`RANDOM}};
  _T_901 = _RAND_6[9:0];
  _RAND_7 = {1{`RANDOM}};
  _T_912 = _RAND_7[2:0];
  _RAND_8 = {1{`RANDOM}};
  _T_913 = _RAND_8[1:0];
  _RAND_9 = {1{`RANDOM}};
  _T_914 = _RAND_9[3:0];
  _RAND_10 = {1{`RANDOM}};
  _T_915 = _RAND_10[4:0];
  _RAND_11 = {1{`RANDOM}};
  _T_916 = _RAND_11[0:0];
  _RAND_12 = {1{`RANDOM}};
  _T_917 = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  inflight = _RAND_13[18:0];
  _RAND_14 = {3{`RANDOM}};
  inflight_opcodes = _RAND_14[75:0];
  _RAND_15 = {5{`RANDOM}};
  inflight_sizes = _RAND_15[151:0];
  _RAND_16 = {1{`RANDOM}};
  _T_955 = _RAND_16[9:0];
  _RAND_17 = {1{`RANDOM}};
  _T_973 = _RAND_17[9:0];
  _RAND_18 = {1{`RANDOM}};
  _T_1101 = _RAND_18[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (reset) begin
      _T_853 <= 10'h0;
    end else if (_T_844) begin
      if (_T_856) begin
        if (_T_851) begin
          _T_853 <= _T_31[11:2];
        end else begin
          _T_853 <= 10'h0;
        end
      end else begin
        _T_853 <= _T_855;
      end
    end
    if (_T_892) begin
      _T_864 <= io_in_a_bits_opcode;
    end
    if (_T_892) begin
      _T_865 <= io_in_a_bits_param;
    end
    if (_T_892) begin
      _T_866 <= io_in_a_bits_size;
    end
    if (_T_892) begin
      _T_867 <= io_in_a_bits_source;
    end
    if (_T_892) begin
      _T_868 <= io_in_a_bits_address;
    end
    if (reset) begin
      _T_901 <= 10'h0;
    end else if (_T_893) begin
      if (_T_904) begin
        if (io_in_d_bits_opcode[0]) begin
          _T_901 <= _T_897[11:2];
        end else begin
          _T_901 <= 10'h0;
        end
      end else begin
        _T_901 <= _T_903;
      end
    end
    if (_T_945) begin
      _T_912 <= io_in_d_bits_opcode;
    end
    if (_T_945) begin
      _T_913 <= io_in_d_bits_param;
    end
    if (_T_945) begin
      _T_914 <= io_in_d_bits_size;
    end
    if (_T_945) begin
      _T_915 <= io_in_d_bits_source;
    end
    if (_T_945) begin
      _T_916 <= io_in_d_bits_sink;
    end
    if (_T_945) begin
      _T_917 <= io_in_d_bits_denied;
    end
    if (reset) begin
      inflight <= 19'h0;
    end else begin
      inflight <= _T_1094;
    end
    if (reset) begin
      inflight_opcodes <= 76'h0;
    end else begin
      inflight_opcodes <= _T_1097;
    end
    if (reset) begin
      inflight_sizes <= 152'h0;
    end else begin
      inflight_sizes <= _T_1100;
    end
    if (reset) begin
      _T_955 <= 10'h0;
    end else if (_T_844) begin
      if (a_first) begin
        if (_T_851) begin
          _T_955 <= _T_31[11:2];
        end else begin
          _T_955 <= 10'h0;
        end
      end else begin
        _T_955 <= _T_957;
      end
    end
    if (reset) begin
      _T_973 <= 10'h0;
    end else if (_T_893) begin
      if (d_first) begin
        if (io_in_d_bits_opcode[0]) begin
          _T_973 <= _T_897[11:2];
        end else begin
          _T_973 <= 10'h0;
        end
      end else begin
        _T_973 <= _T_975;
      end
    end
    if (reset) begin
      _T_1101 <= 32'h0;
    end else if (_T_1115) begin
      _T_1101 <= 32'h0;
    end else begin
      _T_1101 <= _T_1112;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_163) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries AcquireBlock type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44045.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_163) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44046.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_197) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries AcquireBlock from a client which does not support Probe (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44090.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_197) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44091.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquireBlock carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44097.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44098.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_204) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquireBlock smaller than a beat (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44105.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_204) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44106.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquireBlock address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44112.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44113.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_211) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquireBlock carries invalid grow param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44120.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_211) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44121.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_216) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquireBlock contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44129.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_216) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44130.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_69 & _T_220) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquireBlock is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44137.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_69 & _T_220) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44138.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_163) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries AcquirePerm type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44179.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_163) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44180.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_197) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries AcquirePerm from a client which does not support Probe (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44224.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_197) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44225.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquirePerm carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44231.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44232.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_204) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquirePerm smaller than a beat (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44239.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_204) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44240.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquirePerm address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44246.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44247.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_211) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquirePerm carries invalid grow param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44254.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_211) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44255.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_308) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquirePerm requests NtoB (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44262.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_308) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44263.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_216) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquirePerm contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44271.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_216) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44272.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_85 & _T_220) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel AcquirePerm is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44279.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_85 & _T_220) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44280.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_103 & _T_361) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries Get type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44329.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_103 & _T_361) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44330.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_103 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Get carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44336.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_103 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44337.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_103 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Get address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44343.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_103 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44344.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_103 & _T_371) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Get carries invalid param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44351.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_103 & _T_371) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44352.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_103 & _T_375) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Get contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44359.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_103 & _T_375) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44360.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_103 & _T_220) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Get is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44367.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_103 & _T_220) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44368.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_115 & _T_425) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries PutFull type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44419.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_115 & _T_425) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44420.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_115 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutFull carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44426.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_115 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44427.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_115 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutFull address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44433.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_115 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44434.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_115 & _T_371) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutFull carries invalid param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44441.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_115 & _T_371) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44442.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_115 & _T_375) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutFull contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44449.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_115 & _T_375) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44450.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_125 & _T_425) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries PutPartial type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44501.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_125 & _T_425) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44502.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_125 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutPartial carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44508.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_125 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44509.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_125 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutPartial address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44515.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_125 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44516.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_125 & _T_371) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutPartial carries invalid param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44523.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_125 & _T_371) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44524.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_125 & _T_501) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel PutPartial contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44533.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_125 & _T_501) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44534.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_135 & _T_542) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries Arithmetic type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44580.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_135 & _T_542) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44581.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_135 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44587.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_135 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44588.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_135 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44594.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_135 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44595.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_135 & _T_552) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44602.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_135 & _T_552) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44603.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_135 & _T_375) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44610.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_135 & _T_375) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44611.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_145 & _T_542) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries Logical type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44657.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_145 & _T_542) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44658.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_145 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Logical carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44664.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_145 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44665.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_145 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Logical address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44671.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_145 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44672.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_145 & _T_607) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Logical carries invalid opcode param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44679.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_145 & _T_607) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44680.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_145 & _T_375) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Logical contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44687.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_145 & _T_375) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44688.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_155 & _T_652) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel carries Hint type unsupported by manager (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44734.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_155 & _T_652) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44735.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_155 & _T_200) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Hint carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44741.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_155 & _T_200) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44742.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_155 & _T_207) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Hint address not aligned to size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44748.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_155 & _T_207) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44749.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_155 & _T_662) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Hint carries invalid opcode param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44756.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_155 & _T_662) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44757.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_155 & _T_375) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Hint contains invalid mask (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44764.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_155 & _T_375) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44765.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_155 & _T_220) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel Hint is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44772.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_155 & _T_220) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@44773.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (io_in_d_valid & _T_674) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel has invalid opcode (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44783.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (io_in_d_valid & _T_674) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44784.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_167 & _T_703) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel ReleaseAck carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44823.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_167 & _T_703) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44824.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_167 & _T_707) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44831.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_167 & _T_707) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44832.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_167 & _T_711) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44839.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_167 & _T_711) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44840.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_167 & _T_715) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel ReleaseAck is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44847.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_167 & _T_715) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44848.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_167 & _T_719) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel ReleaseAck is denied (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44855.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_167 & _T_719) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44856.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_177 & _T_703) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel Grant carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44865.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_177 & _T_703) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44866.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_177 & _T_163) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel Grant carries invalid sink ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44872.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_177 & _T_163) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44873.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_177 & _T_707) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel Grant smaller than a beat (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44880.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_177 & _T_707) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44881.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_177 & _T_734) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel Grant carries invalid cap param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44888.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_177 & _T_734) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44889.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_177 & _T_738) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel Grant carries toN param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44896.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_177 & _T_738) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44897.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_177 & _T_715) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel Grant is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44904.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_177 & _T_715) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44905.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_189 & _T_703) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel GrantData carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44923.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_189 & _T_703) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44924.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_189 & _T_163) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel GrantData carries invalid sink ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44930.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_189 & _T_163) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44931.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_189 & _T_707) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel GrantData smaller than a beat (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44938.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_189 & _T_707) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44939.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_189 & _T_734) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel GrantData carries invalid cap param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44946.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_189 & _T_734) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44947.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_189 & _T_738) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel GrantData carries toN param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44954.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_189 & _T_738) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44955.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_189 & _T_771) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44963.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_189 & _T_771) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44964.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_201 & _T_703) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44982.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_201 & _T_703) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44983.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_201 & _T_711) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel AccessAck carries invalid param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44990.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_201 & _T_711) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44991.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_201 & _T_715) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel AccessAck is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44998.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_201 & _T_715) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@44999.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_207 & _T_703) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45017.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_207 & _T_703) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45018.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_207 & _T_711) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel AccessAckData carries invalid param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45025.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_207 & _T_711) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45026.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_207 & _T_771) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45034.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_207 & _T_771) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45035.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_213 & _T_703) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel HintAck carries invalid source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45053.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_213 & _T_703) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45054.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_213 & _T_711) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel HintAck carries invalid param (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45061.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_213 & _T_711) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45062.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_213 & _T_715) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel HintAck is corrupt (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45069.10]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_GEN_213 & _T_715) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45070.10]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_870 & _T_874) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel opcode changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45149.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_870 & _T_874) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45150.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_870 & _T_878) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel param changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45157.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_870 & _T_878) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45158.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_870 & _T_882) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel size changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45165.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_870 & _T_882) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45166.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_870 & _T_886) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel source changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45173.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_870 & _T_886) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45174.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_870 & _T_890) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel address changed with multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45181.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_870 & _T_890) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45182.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_919 & _T_923) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel opcode changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45230.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_919 & _T_923) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45231.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_919 & _T_927) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel param changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45238.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_919 & _T_927) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45239.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_919 & _T_931) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel size changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45246.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_919 & _T_931) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45247.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_919 & _T_935) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel source changed within multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45254.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_919 & _T_935) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45255.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_919 & _T_939) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel sink changed with multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45262.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_919 & _T_939) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45263.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_919 & _T_943) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel denied changed with multibeat operation (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45270.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_919 & _T_943) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45271.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1002 & _T_1018) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' channel re-used a source ID (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45407.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_1002 & _T_1018) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45408.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1041 & _T_1052) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel acknowledged for nothing inflight (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45458.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_1041 & _T_1052) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45459.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1041 & _T_1065) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel contains improper opcode response (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45475.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_1041 & _T_1065) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45476.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1041 & _T_1072) begin
          $fwrite(32'h80000002,"Assertion failed: 'D' channel contains improper response size (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45486.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_1041 & _T_1072) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45487.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1079 & _T_1084) begin
          $fwrite(32'h80000002,"Assertion failed: ready check\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45504.8]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_1079 & _T_1084) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45505.8]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1091) begin
          $fwrite(32'h80000002,"Assertion failed: 'A' and 'D' concurrent, despite minlatency 2 (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:51 assert(cond, message)\n"); // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45516.6]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_1091) begin
          $fatal; // @[Monitor.scala 51:11:freechips.rocketchip.system.DefaultRV32Config.fir@45517.6]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1110) begin
          $fwrite(32'h80000002,"Assertion failed: TileLink timeout expired (connected at CrossingHelper.scala:17:14)\n    at Monitor.scala:44 assert(cond, message)\n"); // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45544.6]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef STOP_COND
      if (`STOP_COND) begin
    `endif
        if (_T_1110) begin
          $fatal; // @[Monitor.scala 44:11:freechips.rocketchip.system.DefaultRV32Config.fir@45545.6]
        end
    `ifdef STOP_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
