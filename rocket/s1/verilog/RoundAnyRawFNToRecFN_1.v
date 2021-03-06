module RoundAnyRawFNToRecFN_1( // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212200.2]
  input         io_in_isZero, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212201.4]
  input         io_in_sign, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212201.4]
  input  [7:0]  io_in_sExp, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212201.4]
  input  [32:0] io_in_sig, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212201.4]
  input  [2:0]  io_roundingMode, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212201.4]
  output [32:0] io_out, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212201.4]
  output [4:0]  io_exceptionFlags // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212201.4]
);
  wire  roundingMode_near_even; // @[RoundAnyRawFNToRecFN.scala 88:53:freechips.rocketchip.system.DefaultRV32Config.fir@212204.4]
  wire  roundingMode_min; // @[RoundAnyRawFNToRecFN.scala 90:53:freechips.rocketchip.system.DefaultRV32Config.fir@212206.4]
  wire  roundingMode_max; // @[RoundAnyRawFNToRecFN.scala 91:53:freechips.rocketchip.system.DefaultRV32Config.fir@212207.4]
  wire  roundingMode_near_maxMag; // @[RoundAnyRawFNToRecFN.scala 92:53:freechips.rocketchip.system.DefaultRV32Config.fir@212208.4]
  wire  roundingMode_odd; // @[RoundAnyRawFNToRecFN.scala 93:53:freechips.rocketchip.system.DefaultRV32Config.fir@212209.4]
  wire  _T; // @[RoundAnyRawFNToRecFN.scala 96:27:freechips.rocketchip.system.DefaultRV32Config.fir@212210.4]
  wire  _T_1; // @[RoundAnyRawFNToRecFN.scala 96:66:freechips.rocketchip.system.DefaultRV32Config.fir@212211.4]
  wire  _T_2; // @[RoundAnyRawFNToRecFN.scala 96:63:freechips.rocketchip.system.DefaultRV32Config.fir@212212.4]
  wire  roundMagUp; // @[RoundAnyRawFNToRecFN.scala 96:42:freechips.rocketchip.system.DefaultRV32Config.fir@212213.4]
  wire [8:0] _GEN_0; // @[RoundAnyRawFNToRecFN.scala 102:25:freechips.rocketchip.system.DefaultRV32Config.fir@212214.4]
  wire [9:0] _T_3; // @[RoundAnyRawFNToRecFN.scala 102:25:freechips.rocketchip.system.DefaultRV32Config.fir@212214.4]
  wire [9:0] sAdjustedExp; // @[RoundAnyRawFNToRecFN.scala 104:31:freechips.rocketchip.system.DefaultRV32Config.fir@212216.4]
  wire  _T_7; // @[RoundAnyRawFNToRecFN.scala 115:60:freechips.rocketchip.system.DefaultRV32Config.fir@212219.4]
  wire [26:0] adjustedSig; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212220.4]
  wire [26:0] _T_14; // @[RoundAnyRawFNToRecFN.scala 162:40:freechips.rocketchip.system.DefaultRV32Config.fir@212239.4]
  wire  _T_15; // @[RoundAnyRawFNToRecFN.scala 162:56:freechips.rocketchip.system.DefaultRV32Config.fir@212240.4]
  wire [26:0] _T_16; // @[RoundAnyRawFNToRecFN.scala 163:42:freechips.rocketchip.system.DefaultRV32Config.fir@212241.4]
  wire  _T_17; // @[RoundAnyRawFNToRecFN.scala 163:62:freechips.rocketchip.system.DefaultRV32Config.fir@212242.4]
  wire  common_inexact; // @[RoundAnyRawFNToRecFN.scala 164:36:freechips.rocketchip.system.DefaultRV32Config.fir@212243.4]
  wire  _T_19; // @[RoundAnyRawFNToRecFN.scala 167:38:freechips.rocketchip.system.DefaultRV32Config.fir@212244.4]
  wire  _T_20; // @[RoundAnyRawFNToRecFN.scala 167:67:freechips.rocketchip.system.DefaultRV32Config.fir@212245.4]
  wire  _T_21; // @[RoundAnyRawFNToRecFN.scala 169:29:freechips.rocketchip.system.DefaultRV32Config.fir@212246.4]
  wire  _T_22; // @[RoundAnyRawFNToRecFN.scala 168:31:freechips.rocketchip.system.DefaultRV32Config.fir@212247.4]
  wire [26:0] _T_23; // @[RoundAnyRawFNToRecFN.scala 172:32:freechips.rocketchip.system.DefaultRV32Config.fir@212248.4]
  wire [25:0] _T_25; // @[RoundAnyRawFNToRecFN.scala 172:49:freechips.rocketchip.system.DefaultRV32Config.fir@212250.4]
  wire  _T_26; // @[RoundAnyRawFNToRecFN.scala 173:49:freechips.rocketchip.system.DefaultRV32Config.fir@212251.4]
  wire  _T_27; // @[RoundAnyRawFNToRecFN.scala 174:30:freechips.rocketchip.system.DefaultRV32Config.fir@212252.4]
  wire  _T_28; // @[RoundAnyRawFNToRecFN.scala 173:64:freechips.rocketchip.system.DefaultRV32Config.fir@212253.4]
  wire [25:0] _T_30; // @[RoundAnyRawFNToRecFN.scala 173:25:freechips.rocketchip.system.DefaultRV32Config.fir@212255.4]
  wire [25:0] _T_31; // @[RoundAnyRawFNToRecFN.scala 173:21:freechips.rocketchip.system.DefaultRV32Config.fir@212256.4]
  wire [25:0] _T_32; // @[RoundAnyRawFNToRecFN.scala 172:61:freechips.rocketchip.system.DefaultRV32Config.fir@212257.4]
  wire [26:0] _T_34; // @[RoundAnyRawFNToRecFN.scala 178:30:freechips.rocketchip.system.DefaultRV32Config.fir@212259.4]
  wire  _T_36; // @[RoundAnyRawFNToRecFN.scala 179:42:freechips.rocketchip.system.DefaultRV32Config.fir@212261.4]
  wire [25:0] _T_38; // @[RoundAnyRawFNToRecFN.scala 179:24:freechips.rocketchip.system.DefaultRV32Config.fir@212263.4]
  wire [25:0] _GEN_1; // @[RoundAnyRawFNToRecFN.scala 178:47:freechips.rocketchip.system.DefaultRV32Config.fir@212264.4]
  wire [25:0] _T_39; // @[RoundAnyRawFNToRecFN.scala 178:47:freechips.rocketchip.system.DefaultRV32Config.fir@212264.4]
  wire [25:0] _T_40; // @[RoundAnyRawFNToRecFN.scala 171:16:freechips.rocketchip.system.DefaultRV32Config.fir@212265.4]
  wire [2:0] _T_42; // @[RoundAnyRawFNToRecFN.scala 183:69:freechips.rocketchip.system.DefaultRV32Config.fir@212267.4]
  wire [9:0] _GEN_2; // @[RoundAnyRawFNToRecFN.scala 183:40:freechips.rocketchip.system.DefaultRV32Config.fir@212268.4]
  wire [10:0] _T_43; // @[RoundAnyRawFNToRecFN.scala 183:40:freechips.rocketchip.system.DefaultRV32Config.fir@212268.4]
  wire [8:0] common_expOut; // @[RoundAnyRawFNToRecFN.scala 185:37:freechips.rocketchip.system.DefaultRV32Config.fir@212269.4]
  wire [22:0] common_fractOut; // @[RoundAnyRawFNToRecFN.scala 189:27:freechips.rocketchip.system.DefaultRV32Config.fir@212272.4]
  wire  commonCase; // @[RoundAnyRawFNToRecFN.scala 235:64:freechips.rocketchip.system.DefaultRV32Config.fir@212300.4]
  wire  inexact; // @[RoundAnyRawFNToRecFN.scala 238:43:freechips.rocketchip.system.DefaultRV32Config.fir@212304.4]
  wire [8:0] _T_75; // @[RoundAnyRawFNToRecFN.scala 251:18:freechips.rocketchip.system.DefaultRV32Config.fir@212317.4]
  wire [8:0] _T_76; // @[RoundAnyRawFNToRecFN.scala 251:14:freechips.rocketchip.system.DefaultRV32Config.fir@212318.4]
  wire [8:0] expOut; // @[RoundAnyRawFNToRecFN.scala 250:24:freechips.rocketchip.system.DefaultRV32Config.fir@212319.4]
  wire [22:0] fractOut; // @[RoundAnyRawFNToRecFN.scala 278:12:freechips.rocketchip.system.DefaultRV32Config.fir@212341.4]
  wire [9:0] _T_101; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212345.4]
  wire [1:0] _T_103; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212348.4]
  assign roundingMode_near_even = io_roundingMode == 3'h0; // @[RoundAnyRawFNToRecFN.scala 88:53:freechips.rocketchip.system.DefaultRV32Config.fir@212204.4]
  assign roundingMode_min = io_roundingMode == 3'h2; // @[RoundAnyRawFNToRecFN.scala 90:53:freechips.rocketchip.system.DefaultRV32Config.fir@212206.4]
  assign roundingMode_max = io_roundingMode == 3'h3; // @[RoundAnyRawFNToRecFN.scala 91:53:freechips.rocketchip.system.DefaultRV32Config.fir@212207.4]
  assign roundingMode_near_maxMag = io_roundingMode == 3'h4; // @[RoundAnyRawFNToRecFN.scala 92:53:freechips.rocketchip.system.DefaultRV32Config.fir@212208.4]
  assign roundingMode_odd = io_roundingMode == 3'h6; // @[RoundAnyRawFNToRecFN.scala 93:53:freechips.rocketchip.system.DefaultRV32Config.fir@212209.4]
  assign _T = roundingMode_min & io_in_sign; // @[RoundAnyRawFNToRecFN.scala 96:27:freechips.rocketchip.system.DefaultRV32Config.fir@212210.4]
  assign _T_1 = ~io_in_sign; // @[RoundAnyRawFNToRecFN.scala 96:66:freechips.rocketchip.system.DefaultRV32Config.fir@212211.4]
  assign _T_2 = roundingMode_max & _T_1; // @[RoundAnyRawFNToRecFN.scala 96:63:freechips.rocketchip.system.DefaultRV32Config.fir@212212.4]
  assign roundMagUp = _T | _T_2; // @[RoundAnyRawFNToRecFN.scala 96:42:freechips.rocketchip.system.DefaultRV32Config.fir@212213.4]
  assign _GEN_0 = {{1{io_in_sExp[7]}},io_in_sExp}; // @[RoundAnyRawFNToRecFN.scala 102:25:freechips.rocketchip.system.DefaultRV32Config.fir@212214.4]
  assign _T_3 = $signed(_GEN_0) + 9'shc0; // @[RoundAnyRawFNToRecFN.scala 102:25:freechips.rocketchip.system.DefaultRV32Config.fir@212214.4]
  assign sAdjustedExp = {1'b0,$signed(_T_3[8:0])}; // @[RoundAnyRawFNToRecFN.scala 104:31:freechips.rocketchip.system.DefaultRV32Config.fir@212216.4]
  assign _T_7 = |io_in_sig[6:0]; // @[RoundAnyRawFNToRecFN.scala 115:60:freechips.rocketchip.system.DefaultRV32Config.fir@212219.4]
  assign adjustedSig = {io_in_sig[32:7],_T_7}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212220.4]
  assign _T_14 = adjustedSig & 27'h2; // @[RoundAnyRawFNToRecFN.scala 162:40:freechips.rocketchip.system.DefaultRV32Config.fir@212239.4]
  assign _T_15 = |_T_14; // @[RoundAnyRawFNToRecFN.scala 162:56:freechips.rocketchip.system.DefaultRV32Config.fir@212240.4]
  assign _T_16 = adjustedSig & 27'h1; // @[RoundAnyRawFNToRecFN.scala 163:42:freechips.rocketchip.system.DefaultRV32Config.fir@212241.4]
  assign _T_17 = |_T_16; // @[RoundAnyRawFNToRecFN.scala 163:62:freechips.rocketchip.system.DefaultRV32Config.fir@212242.4]
  assign common_inexact = _T_15 | _T_17; // @[RoundAnyRawFNToRecFN.scala 164:36:freechips.rocketchip.system.DefaultRV32Config.fir@212243.4]
  assign _T_19 = roundingMode_near_even | roundingMode_near_maxMag; // @[RoundAnyRawFNToRecFN.scala 167:38:freechips.rocketchip.system.DefaultRV32Config.fir@212244.4]
  assign _T_20 = _T_19 & _T_15; // @[RoundAnyRawFNToRecFN.scala 167:67:freechips.rocketchip.system.DefaultRV32Config.fir@212245.4]
  assign _T_21 = roundMagUp & common_inexact; // @[RoundAnyRawFNToRecFN.scala 169:29:freechips.rocketchip.system.DefaultRV32Config.fir@212246.4]
  assign _T_22 = _T_20 | _T_21; // @[RoundAnyRawFNToRecFN.scala 168:31:freechips.rocketchip.system.DefaultRV32Config.fir@212247.4]
  assign _T_23 = adjustedSig | 27'h3; // @[RoundAnyRawFNToRecFN.scala 172:32:freechips.rocketchip.system.DefaultRV32Config.fir@212248.4]
  assign _T_25 = _T_23[26:2] + 25'h1; // @[RoundAnyRawFNToRecFN.scala 172:49:freechips.rocketchip.system.DefaultRV32Config.fir@212250.4]
  assign _T_26 = roundingMode_near_even & _T_15; // @[RoundAnyRawFNToRecFN.scala 173:49:freechips.rocketchip.system.DefaultRV32Config.fir@212251.4]
  assign _T_27 = ~_T_17; // @[RoundAnyRawFNToRecFN.scala 174:30:freechips.rocketchip.system.DefaultRV32Config.fir@212252.4]
  assign _T_28 = _T_26 & _T_27; // @[RoundAnyRawFNToRecFN.scala 173:64:freechips.rocketchip.system.DefaultRV32Config.fir@212253.4]
  assign _T_30 = _T_28 ? 26'h1 : 26'h0; // @[RoundAnyRawFNToRecFN.scala 173:25:freechips.rocketchip.system.DefaultRV32Config.fir@212255.4]
  assign _T_31 = ~_T_30; // @[RoundAnyRawFNToRecFN.scala 173:21:freechips.rocketchip.system.DefaultRV32Config.fir@212256.4]
  assign _T_32 = _T_25 & _T_31; // @[RoundAnyRawFNToRecFN.scala 172:61:freechips.rocketchip.system.DefaultRV32Config.fir@212257.4]
  assign _T_34 = adjustedSig & 27'h7fffffc; // @[RoundAnyRawFNToRecFN.scala 178:30:freechips.rocketchip.system.DefaultRV32Config.fir@212259.4]
  assign _T_36 = roundingMode_odd & common_inexact; // @[RoundAnyRawFNToRecFN.scala 179:42:freechips.rocketchip.system.DefaultRV32Config.fir@212261.4]
  assign _T_38 = _T_36 ? 26'h1 : 26'h0; // @[RoundAnyRawFNToRecFN.scala 179:24:freechips.rocketchip.system.DefaultRV32Config.fir@212263.4]
  assign _GEN_1 = {{1'd0}, _T_34[26:2]}; // @[RoundAnyRawFNToRecFN.scala 178:47:freechips.rocketchip.system.DefaultRV32Config.fir@212264.4]
  assign _T_39 = _GEN_1 | _T_38; // @[RoundAnyRawFNToRecFN.scala 178:47:freechips.rocketchip.system.DefaultRV32Config.fir@212264.4]
  assign _T_40 = _T_22 ? _T_32 : _T_39; // @[RoundAnyRawFNToRecFN.scala 171:16:freechips.rocketchip.system.DefaultRV32Config.fir@212265.4]
  assign _T_42 = {1'b0,$signed(_T_40[25:24])}; // @[RoundAnyRawFNToRecFN.scala 183:69:freechips.rocketchip.system.DefaultRV32Config.fir@212267.4]
  assign _GEN_2 = {{7{_T_42[2]}},_T_42}; // @[RoundAnyRawFNToRecFN.scala 183:40:freechips.rocketchip.system.DefaultRV32Config.fir@212268.4]
  assign _T_43 = $signed(sAdjustedExp) + $signed(_GEN_2); // @[RoundAnyRawFNToRecFN.scala 183:40:freechips.rocketchip.system.DefaultRV32Config.fir@212268.4]
  assign common_expOut = _T_43[8:0]; // @[RoundAnyRawFNToRecFN.scala 185:37:freechips.rocketchip.system.DefaultRV32Config.fir@212269.4]
  assign common_fractOut = _T_40[22:0]; // @[RoundAnyRawFNToRecFN.scala 189:27:freechips.rocketchip.system.DefaultRV32Config.fir@212272.4]
  assign commonCase = ~io_in_isZero; // @[RoundAnyRawFNToRecFN.scala 235:64:freechips.rocketchip.system.DefaultRV32Config.fir@212300.4]
  assign inexact = commonCase & common_inexact; // @[RoundAnyRawFNToRecFN.scala 238:43:freechips.rocketchip.system.DefaultRV32Config.fir@212304.4]
  assign _T_75 = io_in_isZero ? 9'h1c0 : 9'h0; // @[RoundAnyRawFNToRecFN.scala 251:18:freechips.rocketchip.system.DefaultRV32Config.fir@212317.4]
  assign _T_76 = ~_T_75; // @[RoundAnyRawFNToRecFN.scala 251:14:freechips.rocketchip.system.DefaultRV32Config.fir@212318.4]
  assign expOut = common_expOut & _T_76; // @[RoundAnyRawFNToRecFN.scala 250:24:freechips.rocketchip.system.DefaultRV32Config.fir@212319.4]
  assign fractOut = io_in_isZero ? 23'h0 : common_fractOut; // @[RoundAnyRawFNToRecFN.scala 278:12:freechips.rocketchip.system.DefaultRV32Config.fir@212341.4]
  assign _T_101 = {io_in_sign,expOut}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212345.4]
  assign _T_103 = {1'h0,inexact}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212348.4]
  assign io_out = {_T_101,fractOut}; // @[RoundAnyRawFNToRecFN.scala 284:12:freechips.rocketchip.system.DefaultRV32Config.fir@212347.4]
  assign io_exceptionFlags = {3'h0,_T_103}; // @[RoundAnyRawFNToRecFN.scala 285:23:freechips.rocketchip.system.DefaultRV32Config.fir@212352.4]
endmodule
