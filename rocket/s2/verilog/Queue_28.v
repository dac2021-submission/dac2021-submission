module Queue_28( // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78855.2]
  input         clock, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78856.4]
  input         reset, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78857.4]
  output        io_enq_ready, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
  input         io_enq_valid, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
  input  [3:0]  io_enq_bits_mask, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
  input  [31:0] io_enq_bits_data, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
  input         io_deq_ready, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
  output        io_deq_valid, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
  output [3:0]  io_deq_bits_mask, // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
  output [31:0] io_deq_bits_data // @[:freechips.rocketchip.system.DefaultRV32Config.fir@78858.4]
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg [3:0] ram_mask [0:15]; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [3:0] ram_mask__T_15_data; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [3:0] ram_mask__T_15_addr; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [3:0] ram_mask__T_5_data; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [3:0] ram_mask__T_5_addr; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire  ram_mask__T_5_mask; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire  ram_mask__T_5_en; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  reg [31:0] ram_data [0:15]; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [31:0] ram_data__T_15_data; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [3:0] ram_data__T_15_addr; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [31:0] ram_data__T_5_data; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire [3:0] ram_data__T_5_addr; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire  ram_data__T_5_mask; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  wire  ram_data__T_5_en; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  reg [3:0] _T; // @[Counter.scala 29:33:freechips.rocketchip.system.DefaultRV32Config.fir@78861.4]
  reg [3:0] _T_1; // @[Counter.scala 29:33:freechips.rocketchip.system.DefaultRV32Config.fir@78862.4]
  reg  maybe_full; // @[Decoupled.scala 212:27:freechips.rocketchip.system.DefaultRV32Config.fir@78863.4]
  wire  ptr_match; // @[Decoupled.scala 214:33:freechips.rocketchip.system.DefaultRV32Config.fir@78864.4]
  wire  _T_2; // @[Decoupled.scala 215:28:freechips.rocketchip.system.DefaultRV32Config.fir@78865.4]
  wire  empty; // @[Decoupled.scala 215:25:freechips.rocketchip.system.DefaultRV32Config.fir@78866.4]
  wire  full; // @[Decoupled.scala 216:24:freechips.rocketchip.system.DefaultRV32Config.fir@78867.4]
  wire  do_enq; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@78868.4]
  wire  do_deq; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@78871.4]
  wire [3:0] _T_8; // @[Counter.scala 39:22:freechips.rocketchip.system.DefaultRV32Config.fir@78880.6]
  wire [3:0] _T_11; // @[Counter.scala 39:22:freechips.rocketchip.system.DefaultRV32Config.fir@78886.6]
  wire  _T_12; // @[Decoupled.scala 227:16:freechips.rocketchip.system.DefaultRV32Config.fir@78889.4]
  assign ram_mask__T_15_addr = _T_1;
  assign ram_mask__T_15_data = ram_mask[ram_mask__T_15_addr]; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  assign ram_mask__T_5_data = io_enq_bits_mask;
  assign ram_mask__T_5_addr = _T;
  assign ram_mask__T_5_mask = 1'h1;
  assign ram_mask__T_5_en = io_enq_ready & io_enq_valid;
  assign ram_data__T_15_addr = _T_1;
  assign ram_data__T_15_data = ram_data[ram_data__T_15_addr]; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
  assign ram_data__T_5_data = io_enq_bits_data;
  assign ram_data__T_5_addr = _T;
  assign ram_data__T_5_mask = 1'h1;
  assign ram_data__T_5_en = io_enq_ready & io_enq_valid;
  assign ptr_match = _T == _T_1; // @[Decoupled.scala 214:33:freechips.rocketchip.system.DefaultRV32Config.fir@78864.4]
  assign _T_2 = ~maybe_full; // @[Decoupled.scala 215:28:freechips.rocketchip.system.DefaultRV32Config.fir@78865.4]
  assign empty = ptr_match & _T_2; // @[Decoupled.scala 215:25:freechips.rocketchip.system.DefaultRV32Config.fir@78866.4]
  assign full = ptr_match & maybe_full; // @[Decoupled.scala 216:24:freechips.rocketchip.system.DefaultRV32Config.fir@78867.4]
  assign do_enq = io_enq_ready & io_enq_valid; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@78868.4]
  assign do_deq = io_deq_ready & io_deq_valid; // @[Decoupled.scala 40:37:freechips.rocketchip.system.DefaultRV32Config.fir@78871.4]
  assign _T_8 = _T + 4'h1; // @[Counter.scala 39:22:freechips.rocketchip.system.DefaultRV32Config.fir@78880.6]
  assign _T_11 = _T_1 + 4'h1; // @[Counter.scala 39:22:freechips.rocketchip.system.DefaultRV32Config.fir@78886.6]
  assign _T_12 = do_enq != do_deq; // @[Decoupled.scala 227:16:freechips.rocketchip.system.DefaultRV32Config.fir@78889.4]
  assign io_enq_ready = ~full; // @[Decoupled.scala 232:16:freechips.rocketchip.system.DefaultRV32Config.fir@78896.4]
  assign io_deq_valid = ~empty; // @[Decoupled.scala 231:16:freechips.rocketchip.system.DefaultRV32Config.fir@78894.4]
  assign io_deq_bits_mask = ram_mask__T_15_data; // @[Decoupled.scala 233:15:freechips.rocketchip.system.DefaultRV32Config.fir@78899.4]
  assign io_deq_bits_data = ram_data__T_15_data; // @[Decoupled.scala 233:15:freechips.rocketchip.system.DefaultRV32Config.fir@78898.4]
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
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 16; initvar = initvar+1)
    ram_mask[initvar] = _RAND_0[3:0];
  _RAND_1 = {1{`RANDOM}};
  for (initvar = 0; initvar < 16; initvar = initvar+1)
    ram_data[initvar] = _RAND_1[31:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_2 = {1{`RANDOM}};
  _T = _RAND_2[3:0];
  _RAND_3 = {1{`RANDOM}};
  _T_1 = _RAND_3[3:0];
  _RAND_4 = {1{`RANDOM}};
  maybe_full = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if(ram_mask__T_5_en & ram_mask__T_5_mask) begin
      ram_mask[ram_mask__T_5_addr] <= ram_mask__T_5_data; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
    end
    if(ram_data__T_5_en & ram_data__T_5_mask) begin
      ram_data[ram_data__T_5_addr] <= ram_data__T_5_data; // @[Decoupled.scala 209:16:freechips.rocketchip.system.DefaultRV32Config.fir@78860.4]
    end
    if (reset) begin
      _T <= 4'h0;
    end else if (do_enq) begin
      _T <= _T_8;
    end
    if (reset) begin
      _T_1 <= 4'h0;
    end else if (do_deq) begin
      _T_1 <= _T_11;
    end
    if (reset) begin
      maybe_full <= 1'h0;
    end else if (_T_12) begin
      maybe_full <= do_enq;
    end
  end
endmodule
