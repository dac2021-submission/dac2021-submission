module MulAddRecFNToRaw_preMul( // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210711.2]
  input  [1:0]  io_op, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  input  [32:0] io_a, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  input  [32:0] io_b, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  input  [32:0] io_c, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output [23:0] io_mulAddA, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output [23:0] io_mulAddB, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output [47:0] io_mulAddC, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isSigNaNAny, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isNaNAOrB, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isInfA, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isZeroA, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isInfB, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isZeroB, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_signProd, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isNaNC, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isInfC, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_isZeroC, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output [9:0]  io_toPostMul_sExpSum, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_doSubMags, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_CIsDominant, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output [4:0]  io_toPostMul_CDom_CAlignDist, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output [25:0] io_toPostMul_highAlignedSigC, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
  output        io_toPostMul_bit0AlignedSigC // @[:freechips.rocketchip.system.DefaultRV32Config.fir@210712.4]
);
  wire  rawA_isZero; // @[rawFloatFromRecFN.scala 51:54:freechips.rocketchip.system.DefaultRV32Config.fir@210717.4]
  wire  _T_4; // @[rawFloatFromRecFN.scala 52:54:freechips.rocketchip.system.DefaultRV32Config.fir@210719.4]
  wire  rawA_isNaN; // @[rawFloatFromRecFN.scala 55:33:freechips.rocketchip.system.DefaultRV32Config.fir@210723.4]
  wire  _T_8; // @[rawFloatFromRecFN.scala 56:36:freechips.rocketchip.system.DefaultRV32Config.fir@210726.4]
  wire  rawA_sign; // @[rawFloatFromRecFN.scala 58:25:freechips.rocketchip.system.DefaultRV32Config.fir@210730.4]
  wire [9:0] rawA_sExp; // @[rawFloatFromRecFN.scala 59:27:freechips.rocketchip.system.DefaultRV32Config.fir@210732.4]
  wire  _T_12; // @[rawFloatFromRecFN.scala 60:39:freechips.rocketchip.system.DefaultRV32Config.fir@210734.4]
  wire [24:0] rawA_sig; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210737.4]
  wire  rawB_isZero; // @[rawFloatFromRecFN.scala 51:54:freechips.rocketchip.system.DefaultRV32Config.fir@210741.4]
  wire  _T_20; // @[rawFloatFromRecFN.scala 52:54:freechips.rocketchip.system.DefaultRV32Config.fir@210743.4]
  wire  rawB_isNaN; // @[rawFloatFromRecFN.scala 55:33:freechips.rocketchip.system.DefaultRV32Config.fir@210747.4]
  wire  _T_24; // @[rawFloatFromRecFN.scala 56:36:freechips.rocketchip.system.DefaultRV32Config.fir@210750.4]
  wire  rawB_sign; // @[rawFloatFromRecFN.scala 58:25:freechips.rocketchip.system.DefaultRV32Config.fir@210754.4]
  wire [9:0] rawB_sExp; // @[rawFloatFromRecFN.scala 59:27:freechips.rocketchip.system.DefaultRV32Config.fir@210756.4]
  wire  _T_28; // @[rawFloatFromRecFN.scala 60:39:freechips.rocketchip.system.DefaultRV32Config.fir@210758.4]
  wire [24:0] rawB_sig; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210761.4]
  wire  rawC_isZero; // @[rawFloatFromRecFN.scala 51:54:freechips.rocketchip.system.DefaultRV32Config.fir@210765.4]
  wire  _T_36; // @[rawFloatFromRecFN.scala 52:54:freechips.rocketchip.system.DefaultRV32Config.fir@210767.4]
  wire  rawC_isNaN; // @[rawFloatFromRecFN.scala 55:33:freechips.rocketchip.system.DefaultRV32Config.fir@210771.4]
  wire  _T_40; // @[rawFloatFromRecFN.scala 56:36:freechips.rocketchip.system.DefaultRV32Config.fir@210774.4]
  wire  rawC_sign; // @[rawFloatFromRecFN.scala 58:25:freechips.rocketchip.system.DefaultRV32Config.fir@210778.4]
  wire [9:0] rawC_sExp; // @[rawFloatFromRecFN.scala 59:27:freechips.rocketchip.system.DefaultRV32Config.fir@210780.4]
  wire  _T_44; // @[rawFloatFromRecFN.scala 60:39:freechips.rocketchip.system.DefaultRV32Config.fir@210782.4]
  wire [24:0] rawC_sig; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210785.4]
  wire  _T_48; // @[MulAddRecFN.scala 98:30:freechips.rocketchip.system.DefaultRV32Config.fir@210787.4]
  wire  signProd; // @[MulAddRecFN.scala 98:42:freechips.rocketchip.system.DefaultRV32Config.fir@210789.4]
  wire [10:0] _T_50; // @[MulAddRecFN.scala 101:19:freechips.rocketchip.system.DefaultRV32Config.fir@210790.4]
  wire [10:0] sExpAlignedProd; // @[MulAddRecFN.scala 101:32:freechips.rocketchip.system.DefaultRV32Config.fir@210793.4]
  wire  _T_53; // @[MulAddRecFN.scala 103:30:freechips.rocketchip.system.DefaultRV32Config.fir@210794.4]
  wire  doSubMags; // @[MulAddRecFN.scala 103:42:freechips.rocketchip.system.DefaultRV32Config.fir@210796.4]
  wire [10:0] _GEN_0; // @[MulAddRecFN.scala 107:42:freechips.rocketchip.system.DefaultRV32Config.fir@210797.4]
  wire [10:0] sNatCAlignDist; // @[MulAddRecFN.scala 107:42:freechips.rocketchip.system.DefaultRV32Config.fir@210799.4]
  wire [9:0] posNatCAlignDist; // @[MulAddRecFN.scala 108:42:freechips.rocketchip.system.DefaultRV32Config.fir@210800.4]
  wire  _T_57; // @[MulAddRecFN.scala 109:35:freechips.rocketchip.system.DefaultRV32Config.fir@210801.4]
  wire  _T_58; // @[MulAddRecFN.scala 109:69:freechips.rocketchip.system.DefaultRV32Config.fir@210802.4]
  wire  isMinCAlign; // @[MulAddRecFN.scala 109:50:freechips.rocketchip.system.DefaultRV32Config.fir@210803.4]
  wire  _T_60; // @[MulAddRecFN.scala 111:60:freechips.rocketchip.system.DefaultRV32Config.fir@210805.4]
  wire  _T_61; // @[MulAddRecFN.scala 111:39:freechips.rocketchip.system.DefaultRV32Config.fir@210806.4]
  wire  CIsDominant; // @[MulAddRecFN.scala 111:23:freechips.rocketchip.system.DefaultRV32Config.fir@210807.4]
  wire  _T_62; // @[MulAddRecFN.scala 115:34:freechips.rocketchip.system.DefaultRV32Config.fir@210808.4]
  wire [6:0] _T_64; // @[MulAddRecFN.scala 115:16:freechips.rocketchip.system.DefaultRV32Config.fir@210810.4]
  wire [6:0] CAlignDist; // @[MulAddRecFN.scala 113:12:freechips.rocketchip.system.DefaultRV32Config.fir@210811.4]
  wire [24:0] _T_65; // @[MulAddRecFN.scala 121:28:freechips.rocketchip.system.DefaultRV32Config.fir@210812.4]
  wire [24:0] _T_66; // @[MulAddRecFN.scala 121:16:freechips.rocketchip.system.DefaultRV32Config.fir@210813.4]
  wire [52:0] _T_68; // @[Bitwise.scala 72:12:freechips.rocketchip.system.DefaultRV32Config.fir@210815.4]
  wire [77:0] _T_70; // @[MulAddRecFN.scala 123:11:freechips.rocketchip.system.DefaultRV32Config.fir@210817.4]
  wire [77:0] mainAlignedSigC; // @[MulAddRecFN.scala 123:17:freechips.rocketchip.system.DefaultRV32Config.fir@210818.4]
  wire [26:0] _T_71; // @[MulAddRecFN.scala 125:30:freechips.rocketchip.system.DefaultRV32Config.fir@210819.4]
  wire  _T_74; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210823.4]
  wire  _T_76; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210826.4]
  wire  _T_78; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210829.4]
  wire  _T_80; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210832.4]
  wire  _T_82; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210835.4]
  wire  _T_84; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210838.4]
  wire  _T_86; // @[primitives.scala 124:57:freechips.rocketchip.system.DefaultRV32Config.fir@210841.4]
  wire [6:0] _T_92; // @[primitives.scala 125:20:freechips.rocketchip.system.DefaultRV32Config.fir@210848.4]
  wire [32:0] _T_94; // @[primitives.scala 77:58:freechips.rocketchip.system.DefaultRV32Config.fir@210850.4]
  wire [5:0] _T_110; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210866.4]
  wire [6:0] _GEN_1; // @[MulAddRecFN.scala 125:68:freechips.rocketchip.system.DefaultRV32Config.fir@210867.4]
  wire [6:0] _T_111; // @[MulAddRecFN.scala 125:68:freechips.rocketchip.system.DefaultRV32Config.fir@210867.4]
  wire  reduced4CExtra; // @[MulAddRecFN.scala 133:11:freechips.rocketchip.system.DefaultRV32Config.fir@210868.4]
  wire  _T_114; // @[MulAddRecFN.scala 137:39:freechips.rocketchip.system.DefaultRV32Config.fir@210871.4]
  wire  _T_115; // @[MulAddRecFN.scala 137:47:freechips.rocketchip.system.DefaultRV32Config.fir@210872.4]
  wire  _T_116; // @[MulAddRecFN.scala 137:44:freechips.rocketchip.system.DefaultRV32Config.fir@210873.4]
  wire  _T_118; // @[MulAddRecFN.scala 138:39:freechips.rocketchip.system.DefaultRV32Config.fir@210875.4]
  wire  _T_119; // @[MulAddRecFN.scala 138:44:freechips.rocketchip.system.DefaultRV32Config.fir@210876.4]
  wire  _T_120; // @[MulAddRecFN.scala 136:16:freechips.rocketchip.system.DefaultRV32Config.fir@210877.4]
  wire [74:0] _T_121; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210878.4]
  wire [75:0] alignedSigC; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210879.4]
  wire  _T_124; // @[common.scala 81:49:freechips.rocketchip.system.DefaultRV32Config.fir@210885.4]
  wire  _T_125; // @[common.scala 81:46:freechips.rocketchip.system.DefaultRV32Config.fir@210886.4]
  wire  _T_127; // @[common.scala 81:49:freechips.rocketchip.system.DefaultRV32Config.fir@210888.4]
  wire  _T_128; // @[common.scala 81:46:freechips.rocketchip.system.DefaultRV32Config.fir@210889.4]
  wire  _T_129; // @[MulAddRecFN.scala 149:32:freechips.rocketchip.system.DefaultRV32Config.fir@210890.4]
  wire  _T_131; // @[common.scala 81:49:freechips.rocketchip.system.DefaultRV32Config.fir@210892.4]
  wire  _T_132; // @[common.scala 81:46:freechips.rocketchip.system.DefaultRV32Config.fir@210893.4]
  wire [10:0] _T_137; // @[MulAddRecFN.scala 161:53:freechips.rocketchip.system.DefaultRV32Config.fir@210908.4]
  wire [10:0] _T_138; // @[MulAddRecFN.scala 161:12:freechips.rocketchip.system.DefaultRV32Config.fir@210909.4]
  assign rawA_isZero = io_a[31:29] == 3'h0; // @[rawFloatFromRecFN.scala 51:54:freechips.rocketchip.system.DefaultRV32Config.fir@210717.4]
  assign _T_4 = io_a[31:30] == 2'h3; // @[rawFloatFromRecFN.scala 52:54:freechips.rocketchip.system.DefaultRV32Config.fir@210719.4]
  assign rawA_isNaN = _T_4 & io_a[29]; // @[rawFloatFromRecFN.scala 55:33:freechips.rocketchip.system.DefaultRV32Config.fir@210723.4]
  assign _T_8 = ~io_a[29]; // @[rawFloatFromRecFN.scala 56:36:freechips.rocketchip.system.DefaultRV32Config.fir@210726.4]
  assign rawA_sign = io_a[32]; // @[rawFloatFromRecFN.scala 58:25:freechips.rocketchip.system.DefaultRV32Config.fir@210730.4]
  assign rawA_sExp = {1'b0,$signed(io_a[31:23])}; // @[rawFloatFromRecFN.scala 59:27:freechips.rocketchip.system.DefaultRV32Config.fir@210732.4]
  assign _T_12 = ~rawA_isZero; // @[rawFloatFromRecFN.scala 60:39:freechips.rocketchip.system.DefaultRV32Config.fir@210734.4]
  assign rawA_sig = {1'h0,_T_12,io_a[22:0]}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210737.4]
  assign rawB_isZero = io_b[31:29] == 3'h0; // @[rawFloatFromRecFN.scala 51:54:freechips.rocketchip.system.DefaultRV32Config.fir@210741.4]
  assign _T_20 = io_b[31:30] == 2'h3; // @[rawFloatFromRecFN.scala 52:54:freechips.rocketchip.system.DefaultRV32Config.fir@210743.4]
  assign rawB_isNaN = _T_20 & io_b[29]; // @[rawFloatFromRecFN.scala 55:33:freechips.rocketchip.system.DefaultRV32Config.fir@210747.4]
  assign _T_24 = ~io_b[29]; // @[rawFloatFromRecFN.scala 56:36:freechips.rocketchip.system.DefaultRV32Config.fir@210750.4]
  assign rawB_sign = io_b[32]; // @[rawFloatFromRecFN.scala 58:25:freechips.rocketchip.system.DefaultRV32Config.fir@210754.4]
  assign rawB_sExp = {1'b0,$signed(io_b[31:23])}; // @[rawFloatFromRecFN.scala 59:27:freechips.rocketchip.system.DefaultRV32Config.fir@210756.4]
  assign _T_28 = ~rawB_isZero; // @[rawFloatFromRecFN.scala 60:39:freechips.rocketchip.system.DefaultRV32Config.fir@210758.4]
  assign rawB_sig = {1'h0,_T_28,io_b[22:0]}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210761.4]
  assign rawC_isZero = io_c[31:29] == 3'h0; // @[rawFloatFromRecFN.scala 51:54:freechips.rocketchip.system.DefaultRV32Config.fir@210765.4]
  assign _T_36 = io_c[31:30] == 2'h3; // @[rawFloatFromRecFN.scala 52:54:freechips.rocketchip.system.DefaultRV32Config.fir@210767.4]
  assign rawC_isNaN = _T_36 & io_c[29]; // @[rawFloatFromRecFN.scala 55:33:freechips.rocketchip.system.DefaultRV32Config.fir@210771.4]
  assign _T_40 = ~io_c[29]; // @[rawFloatFromRecFN.scala 56:36:freechips.rocketchip.system.DefaultRV32Config.fir@210774.4]
  assign rawC_sign = io_c[32]; // @[rawFloatFromRecFN.scala 58:25:freechips.rocketchip.system.DefaultRV32Config.fir@210778.4]
  assign rawC_sExp = {1'b0,$signed(io_c[31:23])}; // @[rawFloatFromRecFN.scala 59:27:freechips.rocketchip.system.DefaultRV32Config.fir@210780.4]
  assign _T_44 = ~rawC_isZero; // @[rawFloatFromRecFN.scala 60:39:freechips.rocketchip.system.DefaultRV32Config.fir@210782.4]
  assign rawC_sig = {1'h0,_T_44,io_c[22:0]}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210785.4]
  assign _T_48 = rawA_sign ^ rawB_sign; // @[MulAddRecFN.scala 98:30:freechips.rocketchip.system.DefaultRV32Config.fir@210787.4]
  assign signProd = _T_48 ^ io_op[1]; // @[MulAddRecFN.scala 98:42:freechips.rocketchip.system.DefaultRV32Config.fir@210789.4]
  assign _T_50 = $signed(rawA_sExp) + $signed(rawB_sExp); // @[MulAddRecFN.scala 101:19:freechips.rocketchip.system.DefaultRV32Config.fir@210790.4]
  assign sExpAlignedProd = $signed(_T_50) - 11'she5; // @[MulAddRecFN.scala 101:32:freechips.rocketchip.system.DefaultRV32Config.fir@210793.4]
  assign _T_53 = signProd ^ rawC_sign; // @[MulAddRecFN.scala 103:30:freechips.rocketchip.system.DefaultRV32Config.fir@210794.4]
  assign doSubMags = _T_53 ^ io_op[0]; // @[MulAddRecFN.scala 103:42:freechips.rocketchip.system.DefaultRV32Config.fir@210796.4]
  assign _GEN_0 = {{1{rawC_sExp[9]}},rawC_sExp}; // @[MulAddRecFN.scala 107:42:freechips.rocketchip.system.DefaultRV32Config.fir@210797.4]
  assign sNatCAlignDist = $signed(sExpAlignedProd) - $signed(_GEN_0); // @[MulAddRecFN.scala 107:42:freechips.rocketchip.system.DefaultRV32Config.fir@210799.4]
  assign posNatCAlignDist = sNatCAlignDist[9:0]; // @[MulAddRecFN.scala 108:42:freechips.rocketchip.system.DefaultRV32Config.fir@210800.4]
  assign _T_57 = rawA_isZero | rawB_isZero; // @[MulAddRecFN.scala 109:35:freechips.rocketchip.system.DefaultRV32Config.fir@210801.4]
  assign _T_58 = $signed(sNatCAlignDist) < 11'sh0; // @[MulAddRecFN.scala 109:69:freechips.rocketchip.system.DefaultRV32Config.fir@210802.4]
  assign isMinCAlign = _T_57 | _T_58; // @[MulAddRecFN.scala 109:50:freechips.rocketchip.system.DefaultRV32Config.fir@210803.4]
  assign _T_60 = posNatCAlignDist <= 10'h18; // @[MulAddRecFN.scala 111:60:freechips.rocketchip.system.DefaultRV32Config.fir@210805.4]
  assign _T_61 = isMinCAlign | _T_60; // @[MulAddRecFN.scala 111:39:freechips.rocketchip.system.DefaultRV32Config.fir@210806.4]
  assign CIsDominant = _T_44 & _T_61; // @[MulAddRecFN.scala 111:23:freechips.rocketchip.system.DefaultRV32Config.fir@210807.4]
  assign _T_62 = posNatCAlignDist < 10'h4a; // @[MulAddRecFN.scala 115:34:freechips.rocketchip.system.DefaultRV32Config.fir@210808.4]
  assign _T_64 = _T_62 ? posNatCAlignDist[6:0] : 7'h4a; // @[MulAddRecFN.scala 115:16:freechips.rocketchip.system.DefaultRV32Config.fir@210810.4]
  assign CAlignDist = isMinCAlign ? 7'h0 : _T_64; // @[MulAddRecFN.scala 113:12:freechips.rocketchip.system.DefaultRV32Config.fir@210811.4]
  assign _T_65 = ~rawC_sig; // @[MulAddRecFN.scala 121:28:freechips.rocketchip.system.DefaultRV32Config.fir@210812.4]
  assign _T_66 = doSubMags ? _T_65 : rawC_sig; // @[MulAddRecFN.scala 121:16:freechips.rocketchip.system.DefaultRV32Config.fir@210813.4]
  assign _T_68 = doSubMags ? 53'h1fffffffffffff : 53'h0; // @[Bitwise.scala 72:12:freechips.rocketchip.system.DefaultRV32Config.fir@210815.4]
  assign _T_70 = {_T_66,_T_68}; // @[MulAddRecFN.scala 123:11:freechips.rocketchip.system.DefaultRV32Config.fir@210817.4]
  assign mainAlignedSigC = $signed(_T_70) >>> CAlignDist; // @[MulAddRecFN.scala 123:17:freechips.rocketchip.system.DefaultRV32Config.fir@210818.4]
  assign _T_71 = {rawC_sig, 2'h0}; // @[MulAddRecFN.scala 125:30:freechips.rocketchip.system.DefaultRV32Config.fir@210819.4]
  assign _T_74 = |_T_71[3:0]; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210823.4]
  assign _T_76 = |_T_71[7:4]; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210826.4]
  assign _T_78 = |_T_71[11:8]; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210829.4]
  assign _T_80 = |_T_71[15:12]; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210832.4]
  assign _T_82 = |_T_71[19:16]; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210835.4]
  assign _T_84 = |_T_71[23:20]; // @[primitives.scala 121:54:freechips.rocketchip.system.DefaultRV32Config.fir@210838.4]
  assign _T_86 = |_T_71[26:24]; // @[primitives.scala 124:57:freechips.rocketchip.system.DefaultRV32Config.fir@210841.4]
  assign _T_92 = {_T_86,_T_84,_T_82,_T_80,_T_78,_T_76,_T_74}; // @[primitives.scala 125:20:freechips.rocketchip.system.DefaultRV32Config.fir@210848.4]
  assign _T_94 = -33'sh100000000 >>> CAlignDist[6:2]; // @[primitives.scala 77:58:freechips.rocketchip.system.DefaultRV32Config.fir@210850.4]
  assign _T_110 = {_T_94[14],_T_94[15],_T_94[16],_T_94[17],_T_94[18],_T_94[19]}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210866.4]
  assign _GEN_1 = {{1'd0}, _T_110}; // @[MulAddRecFN.scala 125:68:freechips.rocketchip.system.DefaultRV32Config.fir@210867.4]
  assign _T_111 = _T_92 & _GEN_1; // @[MulAddRecFN.scala 125:68:freechips.rocketchip.system.DefaultRV32Config.fir@210867.4]
  assign reduced4CExtra = |_T_111; // @[MulAddRecFN.scala 133:11:freechips.rocketchip.system.DefaultRV32Config.fir@210868.4]
  assign _T_114 = &mainAlignedSigC[2:0]; // @[MulAddRecFN.scala 137:39:freechips.rocketchip.system.DefaultRV32Config.fir@210871.4]
  assign _T_115 = ~reduced4CExtra; // @[MulAddRecFN.scala 137:47:freechips.rocketchip.system.DefaultRV32Config.fir@210872.4]
  assign _T_116 = _T_114 & _T_115; // @[MulAddRecFN.scala 137:44:freechips.rocketchip.system.DefaultRV32Config.fir@210873.4]
  assign _T_118 = |mainAlignedSigC[2:0]; // @[MulAddRecFN.scala 138:39:freechips.rocketchip.system.DefaultRV32Config.fir@210875.4]
  assign _T_119 = _T_118 | reduced4CExtra; // @[MulAddRecFN.scala 138:44:freechips.rocketchip.system.DefaultRV32Config.fir@210876.4]
  assign _T_120 = doSubMags ? _T_116 : _T_119; // @[MulAddRecFN.scala 136:16:freechips.rocketchip.system.DefaultRV32Config.fir@210877.4]
  assign _T_121 = mainAlignedSigC[77:3]; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210878.4]
  assign alignedSigC = {_T_121,_T_120}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@210879.4]
  assign _T_124 = ~rawA_sig[22]; // @[common.scala 81:49:freechips.rocketchip.system.DefaultRV32Config.fir@210885.4]
  assign _T_125 = rawA_isNaN & _T_124; // @[common.scala 81:46:freechips.rocketchip.system.DefaultRV32Config.fir@210886.4]
  assign _T_127 = ~rawB_sig[22]; // @[common.scala 81:49:freechips.rocketchip.system.DefaultRV32Config.fir@210888.4]
  assign _T_128 = rawB_isNaN & _T_127; // @[common.scala 81:46:freechips.rocketchip.system.DefaultRV32Config.fir@210889.4]
  assign _T_129 = _T_125 | _T_128; // @[MulAddRecFN.scala 149:32:freechips.rocketchip.system.DefaultRV32Config.fir@210890.4]
  assign _T_131 = ~rawC_sig[22]; // @[common.scala 81:49:freechips.rocketchip.system.DefaultRV32Config.fir@210892.4]
  assign _T_132 = rawC_isNaN & _T_131; // @[common.scala 81:46:freechips.rocketchip.system.DefaultRV32Config.fir@210893.4]
  assign _T_137 = $signed(sExpAlignedProd) - 11'sh18; // @[MulAddRecFN.scala 161:53:freechips.rocketchip.system.DefaultRV32Config.fir@210908.4]
  assign _T_138 = CIsDominant ? $signed({{1{rawC_sExp[9]}},rawC_sExp}) : $signed(_T_137); // @[MulAddRecFN.scala 161:12:freechips.rocketchip.system.DefaultRV32Config.fir@210909.4]
  assign io_mulAddA = rawA_sig[23:0]; // @[MulAddRecFN.scala 144:16:freechips.rocketchip.system.DefaultRV32Config.fir@210880.4]
  assign io_mulAddB = rawB_sig[23:0]; // @[MulAddRecFN.scala 145:16:freechips.rocketchip.system.DefaultRV32Config.fir@210881.4]
  assign io_mulAddC = alignedSigC[48:1]; // @[MulAddRecFN.scala 146:16:freechips.rocketchip.system.DefaultRV32Config.fir@210883.4]
  assign io_toPostMul_isSigNaNAny = _T_129 | _T_132; // @[MulAddRecFN.scala 148:30:freechips.rocketchip.system.DefaultRV32Config.fir@210895.4]
  assign io_toPostMul_isNaNAOrB = rawA_isNaN | rawB_isNaN; // @[MulAddRecFN.scala 151:28:freechips.rocketchip.system.DefaultRV32Config.fir@210897.4]
  assign io_toPostMul_isInfA = _T_4 & _T_8; // @[MulAddRecFN.scala 152:28:freechips.rocketchip.system.DefaultRV32Config.fir@210898.4]
  assign io_toPostMul_isZeroA = io_a[31:29] == 3'h0; // @[MulAddRecFN.scala 153:28:freechips.rocketchip.system.DefaultRV32Config.fir@210899.4]
  assign io_toPostMul_isInfB = _T_20 & _T_24; // @[MulAddRecFN.scala 154:28:freechips.rocketchip.system.DefaultRV32Config.fir@210900.4]
  assign io_toPostMul_isZeroB = io_b[31:29] == 3'h0; // @[MulAddRecFN.scala 155:28:freechips.rocketchip.system.DefaultRV32Config.fir@210901.4]
  assign io_toPostMul_signProd = _T_48 ^ io_op[1]; // @[MulAddRecFN.scala 156:28:freechips.rocketchip.system.DefaultRV32Config.fir@210902.4]
  assign io_toPostMul_isNaNC = _T_36 & io_c[29]; // @[MulAddRecFN.scala 157:28:freechips.rocketchip.system.DefaultRV32Config.fir@210903.4]
  assign io_toPostMul_isInfC = _T_36 & _T_40; // @[MulAddRecFN.scala 158:28:freechips.rocketchip.system.DefaultRV32Config.fir@210904.4]
  assign io_toPostMul_isZeroC = io_c[31:29] == 3'h0; // @[MulAddRecFN.scala 159:28:freechips.rocketchip.system.DefaultRV32Config.fir@210905.4]
  assign io_toPostMul_sExpSum = _T_138[9:0]; // @[MulAddRecFN.scala 160:28:freechips.rocketchip.system.DefaultRV32Config.fir@210910.4]
  assign io_toPostMul_doSubMags = _T_53 ^ io_op[0]; // @[MulAddRecFN.scala 162:28:freechips.rocketchip.system.DefaultRV32Config.fir@210911.4]
  assign io_toPostMul_CIsDominant = _T_44 & _T_61; // @[MulAddRecFN.scala 163:30:freechips.rocketchip.system.DefaultRV32Config.fir@210912.4]
  assign io_toPostMul_CDom_CAlignDist = CAlignDist[4:0]; // @[MulAddRecFN.scala 164:34:freechips.rocketchip.system.DefaultRV32Config.fir@210914.4]
  assign io_toPostMul_highAlignedSigC = alignedSigC[74:49]; // @[MulAddRecFN.scala 165:34:freechips.rocketchip.system.DefaultRV32Config.fir@210916.4]
  assign io_toPostMul_bit0AlignedSigC = alignedSigC[0]; // @[MulAddRecFN.scala 167:34:freechips.rocketchip.system.DefaultRV32Config.fir@210918.4]
endmodule
