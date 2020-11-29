////////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
// 
// Copyright (c) 2019 Mentor Graphics Corp.
//       All Rights Reserved
// 
// This document contains information that is proprietary to Mentor Graphics
// Corp. The original recipient of this document may duplicate this  
// document in whole or in part for internal business purposes only, provided  
// that this entire notice appears in all copies. In duplicating any part of  
// this document, the recipient agrees to make every reasonable effort to  
// prevent the unauthorized use and distribution of the proprietary information.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __AC_BLACKBOX_H
#define __AC_BLACKBOX_H

#ifdef __AC_NAMESPACE
namespace __AC_NAMESPACE {
#endif

/* -------------------------------------------

//
// Example usage of ac_blackbox :
//

#include <ac_int.h>
#include <ac_blackbox.h>

class adder {
  public:
    adder() { }

#   pragma design interface ccore blackbox
    void run ( ac_int<8> a, ac_int<8> b, ac_int<8> &z ) {

      ac_blackbox()
          .entity("adder")
          .architecture("bb")
          .vhdl_files("adder.vhd")
          .verilog_files("adder.v")
          .outputs("z")
          .area(102.5)
          .delay(0.50)
          .end();

      z = a + b;
    }
};

*/

class ac_blackbox {
public:
    //
    // Category: Usage
    // ---------------

    // Defines the blackbox class object.  Must be placed at the start of
    // the class based interface function entry point.  The pragma design
    // interface specification also *requires* the blackbox keyword.
    ac_blackbox() : d(0) { }

    // Defines the end of the blackbox specification.  *required*
    void end() { }

    //
    // Category: Netlist / Reporting
    // -----------------------------

    // Defines the name of the module in RTL. Default is the typename 
    // of the class.
    ac_blackbox &entity(const char *name) { (void*)name; return *this; }

    //  Defines the library containing the RTL module, only needed for VHDL
    ac_blackbox &library(const char *name) { (void*)name; return *this; }

    //  Defines the component package containing the RTL module, only needed for
    //  VHDL modules with parameters.  Default for parameterized module
    //  is <entity>_pkg.
    ac_blackbox &package(const char *name) { (void*)name; return *this; }

    // Defines the name of the architecture in the RTL, only needed for VHDL
    ac_blackbox &architecture(const char *name) { (void*)name; return *this; }

    // Defines one or more files that contain the VHDL RTL code.  Path
    // relative to the C module source file.
    ac_blackbox &vhdl_files(const char *files) { (void*)files; return *this; }

    // Defines one or more files that contain the Verilog RTL code.  Path 
    // relative to the C module source file.
    ac_blackbox &verilog_files(const char *files) { (void*)files; return *this; }

    // Defines which of the ports on the black box are outputs.  Items not in
    // this list are assumed to be inputs.  Must match an argument name in 
    // the run function or Catapult will generate an error.
    ac_blackbox &outputs(const char *ports) { (void*)ports; return *this; }

    // Defines the area of the component
    ac_blackbox &area(const float &value) { (void)value; return *this; }

    // All inputs registered, default true
    ac_blackbox &inputs_registered(const bool &value) { (void)value; return *this; }

    // Defines HDL parameter, call method for each parameter
    ac_blackbox &parameter(const char *name, const int &value) { (void*)name; (void)value; return *this; }

    //
    // Category: Timing
    // ----------------

    // Defines the timing units in the library.  Allowed values are the same
    // as the available units in the library.  The timing units will be 
    // internally normalized to ns for Catapult's synthesis.
    ac_blackbox &timing_units(const char *value) { (void*)value; return *this; }

    // Defines the combinational delay of combinational components or output
    // delay of sequential components.
    ac_blackbox &delay(const float &value) { (void)value; return *this; }

    // Defines the input delay of sequential components.
    ac_blackbox &input_delay(const float &value) { (void)value; return *this; }

    // Defines the minimum clock period that is allowed when using the blackbox 
    // module.
    ac_blackbox &min_clock_period(const float &value) { (void)value; return *this; }

    // Defines the latency of the sequential component. Number of register stages.
    // Internally this is converted to SeqDelay accounting for the input_register
    // setting.  If the input_register setting is true, then SeqDelay=latency-1
    // otherwise SeqDelay=latency
    ac_blackbox &latency(const unsigned int &value) { (void)value; return *this; }

    // Defines the initiation interval for sequential components (Default calculated
    // SeqDelay+1)
    ac_blackbox &init_delay(const unsigned int &value) { (void)value; return *this; }

    // Defines the clock-to-clock delay of the registers for sequential components
    // (excluding setup time).
    ac_blackbox &register_to_register_delay(const float &value) { (void)value; return *this; }

    //
    // Category: Clock
    // ---------------

    // Defines the name of the clock port.  Multi-clock blackbox designs are not
    // supported in this flow.
    ac_blackbox &clock_name(const char *name) { (void*)name; return *this; }

    // Defines if the design is sensitive to the positive edge of the clock.
    // default is true (posedge)
    ac_blackbox &posedge_clock(const bool &value) { (void)value; return *this; }

    // Defines the name of the synchronous reset port. Only one synchronous reset
    // port is allowed.
    ac_blackbox &sync_reset_name(const char *name) { (void*)name; return *this; }

    // Defines if the synchronous reset is active high or active low.
    // default is true (active high)
    ac_blackbox &active_high_sync_reset(const bool &value) { (void)value; return *this; }

    // Defines the name of the asynchronous reset port. Only one asynchronous 
    // reset is allowed.
    ac_blackbox &async_reset_name(const char *name) { (void*)name; return *this; }

    // Defines if the asynchronous reset is sensitive to the posedge or negedge.
    // default is false (negedge)
    ac_blackbox &posedge_async_reset(const bool &value) { (void)value; return *this; }

    // Defines the name of the enable port. Only one enable port is allowed.
    ac_blackbox &enable_name(const char *name) { (void*)name; return *this; }

    // Defines if the enable is active high or active low
    // default is true (active high)
    ac_blackbox &active_high_enable(const bool &value) { (void)value; return *this; }

    //
    // Category: Handshake
    // -------------------

    // Defines the output port from the design that reports if the design is 
    // idle and the clock can be gated. Idle is always active high.
    ac_blackbox &idle_name(const char *name) { (void*)name; return *this; }

    // Defines if the HDL definition has state which prevents sharing the
    // instance. Default is false.  If true start_name is required.
    ac_blackbox &has_state(const bool &value) { (void)value; return *this; }

    // Defines the start port in the HDL model.  Required for has_state true.
    ac_blackbox &start_name(const char *name) { (void*)name; return *this; }

private:
    void *const d;
};

#ifdef __AC_NAMESPACE
}
#endif

#endif
