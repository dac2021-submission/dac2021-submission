module INToRecFN( // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212354.2]
  input         io_signedIn, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212355.4]
  input  [31:0] io_in, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212355.4]
  input  [2:0]  io_roundingMode, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212355.4]
  output [32:0] io_out, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212355.4]
  output [4:0]  io_exceptionFlags // @[:freechips.rocketchip.system.DefaultRV32Config.fir@212355.4]
);
  wire  roundAnyRawFNToRecFN_io_in_isZero; // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
  wire  roundAnyRawFNToRecFN_io_in_sign; // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
  wire [7:0] roundAnyRawFNToRecFN_io_in_sExp; // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
  wire [32:0] roundAnyRawFNToRecFN_io_in_sig; // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
  wire [2:0] roundAnyRawFNToRecFN_io_roundingMode; // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
  wire [32:0] roundAnyRawFNToRecFN_io_out; // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
  wire [4:0] roundAnyRawFNToRecFN_io_exceptionFlags; // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
  wire  intAsRawFloat_sign; // @[rawFloatFromIN.scala 50:29:freechips.rocketchip.system.DefaultRV32Config.fir@212359.4]
  wire [31:0] _T_3; // @[rawFloatFromIN.scala 51:31:freechips.rocketchip.system.DefaultRV32Config.fir@212361.4]
  wire [31:0] _T_4; // @[rawFloatFromIN.scala 51:24:freechips.rocketchip.system.DefaultRV32Config.fir@212362.4]
  wire [63:0] _T_5; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212363.4]
  wire [4:0] _T_39; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212397.4]
  wire [4:0] _T_40; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212398.4]
  wire [4:0] _T_41; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212399.4]
  wire [4:0] _T_42; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212400.4]
  wire [4:0] _T_43; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212401.4]
  wire [4:0] _T_44; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212402.4]
  wire [4:0] _T_45; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212403.4]
  wire [4:0] _T_46; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212404.4]
  wire [4:0] _T_47; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212405.4]
  wire [4:0] _T_48; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212406.4]
  wire [4:0] _T_49; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212407.4]
  wire [4:0] _T_50; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212408.4]
  wire [4:0] _T_51; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212409.4]
  wire [4:0] _T_52; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212410.4]
  wire [4:0] _T_53; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212411.4]
  wire [4:0] _T_54; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212412.4]
  wire [4:0] _T_55; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212413.4]
  wire [4:0] _T_56; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212414.4]
  wire [4:0] _T_57; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212415.4]
  wire [4:0] _T_58; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212416.4]
  wire [4:0] _T_59; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212417.4]
  wire [4:0] _T_60; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212418.4]
  wire [4:0] _T_61; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212419.4]
  wire [4:0] _T_62; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212420.4]
  wire [4:0] _T_63; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212421.4]
  wire [4:0] _T_64; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212422.4]
  wire [4:0] _T_65; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212423.4]
  wire [4:0] _T_66; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212424.4]
  wire [4:0] _T_67; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212425.4]
  wire [4:0] _T_68; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212426.4]
  wire [4:0] _T_69; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212427.4]
  wire [62:0] _GEN_0; // @[rawFloatFromIN.scala 55:22:freechips.rocketchip.system.DefaultRV32Config.fir@212428.4]
  wire [62:0] _T_70; // @[rawFloatFromIN.scala 55:22:freechips.rocketchip.system.DefaultRV32Config.fir@212428.4]
  wire [4:0] _T_75; // @[rawFloatFromIN.scala 63:39:freechips.rocketchip.system.DefaultRV32Config.fir@212439.4]
  wire [6:0] _T_76; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212440.4]
  RoundAnyRawFNToRecFN_1 roundAnyRawFNToRecFN ( // @[INToRecFN.scala 59:15:freechips.rocketchip.system.DefaultRV32Config.fir@212444.4]
    .io_in_isZero(roundAnyRawFNToRecFN_io_in_isZero),
    .io_in_sign(roundAnyRawFNToRecFN_io_in_sign),
    .io_in_sExp(roundAnyRawFNToRecFN_io_in_sExp),
    .io_in_sig(roundAnyRawFNToRecFN_io_in_sig),
    .io_roundingMode(roundAnyRawFNToRecFN_io_roundingMode),
    .io_out(roundAnyRawFNToRecFN_io_out),
    .io_exceptionFlags(roundAnyRawFNToRecFN_io_exceptionFlags)
  );
  assign intAsRawFloat_sign = io_signedIn & io_in[31]; // @[rawFloatFromIN.scala 50:29:freechips.rocketchip.system.DefaultRV32Config.fir@212359.4]
  assign _T_3 = 32'h0 - io_in; // @[rawFloatFromIN.scala 51:31:freechips.rocketchip.system.DefaultRV32Config.fir@212361.4]
  assign _T_4 = intAsRawFloat_sign ? _T_3 : io_in; // @[rawFloatFromIN.scala 51:24:freechips.rocketchip.system.DefaultRV32Config.fir@212362.4]
  assign _T_5 = {32'h0,_T_4}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212363.4]
  assign _T_39 = _T_5[1] ? 5'h1e : 5'h1f; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212397.4]
  assign _T_40 = _T_5[2] ? 5'h1d : _T_39; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212398.4]
  assign _T_41 = _T_5[3] ? 5'h1c : _T_40; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212399.4]
  assign _T_42 = _T_5[4] ? 5'h1b : _T_41; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212400.4]
  assign _T_43 = _T_5[5] ? 5'h1a : _T_42; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212401.4]
  assign _T_44 = _T_5[6] ? 5'h19 : _T_43; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212402.4]
  assign _T_45 = _T_5[7] ? 5'h18 : _T_44; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212403.4]
  assign _T_46 = _T_5[8] ? 5'h17 : _T_45; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212404.4]
  assign _T_47 = _T_5[9] ? 5'h16 : _T_46; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212405.4]
  assign _T_48 = _T_5[10] ? 5'h15 : _T_47; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212406.4]
  assign _T_49 = _T_5[11] ? 5'h14 : _T_48; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212407.4]
  assign _T_50 = _T_5[12] ? 5'h13 : _T_49; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212408.4]
  assign _T_51 = _T_5[13] ? 5'h12 : _T_50; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212409.4]
  assign _T_52 = _T_5[14] ? 5'h11 : _T_51; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212410.4]
  assign _T_53 = _T_5[15] ? 5'h10 : _T_52; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212411.4]
  assign _T_54 = _T_5[16] ? 5'hf : _T_53; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212412.4]
  assign _T_55 = _T_5[17] ? 5'he : _T_54; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212413.4]
  assign _T_56 = _T_5[18] ? 5'hd : _T_55; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212414.4]
  assign _T_57 = _T_5[19] ? 5'hc : _T_56; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212415.4]
  assign _T_58 = _T_5[20] ? 5'hb : _T_57; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212416.4]
  assign _T_59 = _T_5[21] ? 5'ha : _T_58; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212417.4]
  assign _T_60 = _T_5[22] ? 5'h9 : _T_59; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212418.4]
  assign _T_61 = _T_5[23] ? 5'h8 : _T_60; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212419.4]
  assign _T_62 = _T_5[24] ? 5'h7 : _T_61; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212420.4]
  assign _T_63 = _T_5[25] ? 5'h6 : _T_62; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212421.4]
  assign _T_64 = _T_5[26] ? 5'h5 : _T_63; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212422.4]
  assign _T_65 = _T_5[27] ? 5'h4 : _T_64; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212423.4]
  assign _T_66 = _T_5[28] ? 5'h3 : _T_65; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212424.4]
  assign _T_67 = _T_5[29] ? 5'h2 : _T_66; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212425.4]
  assign _T_68 = _T_5[30] ? 5'h1 : _T_67; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212426.4]
  assign _T_69 = _T_5[31] ? 5'h0 : _T_68; // @[Mux.scala 47:69:freechips.rocketchip.system.DefaultRV32Config.fir@212427.4]
  assign _GEN_0 = {{31'd0}, _T_5[31:0]}; // @[rawFloatFromIN.scala 55:22:freechips.rocketchip.system.DefaultRV32Config.fir@212428.4]
  assign _T_70 = _GEN_0 << _T_69; // @[rawFloatFromIN.scala 55:22:freechips.rocketchip.system.DefaultRV32Config.fir@212428.4]
  assign _T_75 = ~_T_69; // @[rawFloatFromIN.scala 63:39:freechips.rocketchip.system.DefaultRV32Config.fir@212439.4]
  assign _T_76 = {2'h2,_T_75}; // @[Cat.scala 29:58:freechips.rocketchip.system.DefaultRV32Config.fir@212440.4]
  assign io_out = roundAnyRawFNToRecFN_io_out; // @[INToRecFN.scala 72:23:freechips.rocketchip.system.DefaultRV32Config.fir@212451.4]
  assign io_exceptionFlags = roundAnyRawFNToRecFN_io_exceptionFlags; // @[INToRecFN.scala 73:23:freechips.rocketchip.system.DefaultRV32Config.fir@212452.4]
  assign roundAnyRawFNToRecFN_io_in_isZero = ~_T_70[31]; // @[INToRecFN.scala 69:44:freechips.rocketchip.system.DefaultRV32Config.fir@212448.4]
  assign roundAnyRawFNToRecFN_io_in_sign = io_signedIn & io_in[31]; // @[INToRecFN.scala 69:44:freechips.rocketchip.system.DefaultRV32Config.fir@212448.4]
  assign roundAnyRawFNToRecFN_io_in_sExp = {1'b0,$signed(_T_76)}; // @[INToRecFN.scala 69:44:freechips.rocketchip.system.DefaultRV32Config.fir@212448.4]
  assign roundAnyRawFNToRecFN_io_in_sig = {{1'd0}, _T_70[31:0]}; // @[INToRecFN.scala 69:44:freechips.rocketchip.system.DefaultRV32Config.fir@212448.4]
  assign roundAnyRawFNToRecFN_io_roundingMode = io_roundingMode; // @[INToRecFN.scala 70:44:freechips.rocketchip.system.DefaultRV32Config.fir@212449.4]
endmodule
