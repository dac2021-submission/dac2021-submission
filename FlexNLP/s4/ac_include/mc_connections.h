//////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
//
// Copyright (c) 2019-2020 Mentor Graphics Corp.
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

#pragma once

#if __cplusplus < 201103L
#error "The standard C++11 (201103L) or newer is required"
#endif

#ifndef HLS_CATAPULT
#ifdef __CONNECTIONS__CONNECTIONS_H__
#warning "Warning: HLS_CATAPULT should be defined before including connections.h"
#else
#define HLS_CATAPULT
#endif
#endif

#ifndef __SYNTHESIS__
#if !defined(IEEE_1666_SYSTEMC) && !defined(SC_INCLUDE_DYNAMIC_PROCESSES)
#define SC_INCLUDE_DYNAMIC_PROCESSES
#endif
#endif

#include <systemc.h>
#include <connections/connections.h>


// Helpers for object naming ctors:
#define CTOR_S1(n)              n(#n)
#define CTOR_S2(n, a2)          n(#n, a2)
#define CTOR_S3(n, a2, a3)      n(#n, a2, a3)
#define CTOR_S4(n, a2, a3, a4)  n(#n, a2, a3, a4)

#define INIT_S1(n)              n{#n}
#define INIT_S2(n, a2)          n{#n, a2}

#ifndef __SYNTHESIS__
#define LOG(x)  std::cout << sc_time_stamp() << " " << name() << " " << x << std::endl
#else
#define LOG(x)  // empty
#endif

// sc_trace helpers
extern sc_trace_file* trace_file_ptr;

template <class T>
struct sc_object_tracer
{
  sc_object_tracer(T& obj)
  {
    sc_trace(trace_file_ptr, obj, obj.name());
  }
};

template <class T>
struct sc_var_tracer
{
  sc_var_tracer(T& obj, const std::string& nm)
  {
    sc_trace(trace_file_ptr, obj, nm);
  }
};

#ifndef __SYNTHESIS__
#define SC_SIG(T,N) sc_signal<T> N{#N}  ; sc_object_tracer<sc_signal<T>> N ## _tracer { N }
#define SC_VAR(T,N) T N ; sc_var_tracer<T> N ## _tracer { N, std::string(name()) + std::string(".") + #N }
#define SC_VAR_NM(T,N, NM) T N ; sc_var_tracer<T> N ## _tracer { N, std::string(NM) + std::string(".") + #N }
#else
#define SC_SIG(T,N) sc_signal<T> N{#N}  
#define SC_VAR(T,N) T N 
#define SC_VAR_NM(T,N, NM) T N 
#endif

/**
 * Example of how to enable tracing for user defined structs:

struct MyType
{
    int info {0};
    bool flag {false};

    inline friend void sc_trace(sc_trace_file *tf, const MyType & v, const std::string& NAME ) {
      sc_trace(tf,v.info, NAME + ".info");
      sc_trace(tf,v.flag, NAME + ".flag");
    }
};

**/

static inline void trace_hierarchy(sc_object* obj, sc_trace_file* file_ptr)
{
#ifdef CONNECTIONS_SIM_ONLY
  if (Connections::sc_trace_marker* p = dynamic_cast<Connections::sc_trace_marker*>(obj))
    p->set_trace(file_ptr);

  std::vector<sc_object*> children = obj->get_child_objects();
  for ( unsigned i = 0; i < children.size(); i++ )
    if ( children[i] )
      trace_hierarchy( children[i], file_ptr);
#endif
}

// Logging Connections channel data
class channel_logs
{
public:
  bool enabled{false};
  std::string log_dir;
  int log_num{0};
  std::ofstream* log_stream {0};
  std::ofstream* log_names {0};

  channel_logs() {}

  int enable(std::string fname_base = "") {
    if ( fname_base.empty() ) {
      fname_base = "channel_logs";
    }
    std::ostringstream nm_stream, nm_names;
    nm_stream << fname_base << "_data.txt";
    log_stream = new std::ofstream(nm_stream.str(), std::ofstream::out);
    if ( !(log_stream && log_stream->is_open()) ) {
        std::cerr << "Cannot open file '" << nm_stream.str() << "'" << std::endl;
        return 1;
    }
    nm_names << fname_base << "_names.txt";
    log_names = new std::ofstream(nm_names.str(), std::ofstream::out);
    if ( !(log_names && log_names->is_open()) ) {
        std::cerr << "Cannot open file '" << nm_names.str() << "'" << std::endl;
        return 1;
    }
    return 0;
  } 

  void log_hier_helper(sc_object* obj) {
#ifdef CONNECTIONS_SIM_ONLY
    if (Connections::sc_trace_marker* p = dynamic_cast<Connections::sc_trace_marker*>(obj))
    {
      std::string path_name;
      if (log_stream && log_names && p->set_log(log_stream, log_num, path_name))
        *log_names << log_num << " " << path_name << "\n";
    }

    std::vector<sc_object*> children = obj->get_child_objects();
    for ( unsigned i = 0; i < children.size(); i++ )
      if ( children[i] )
        log_hier_helper(children[i]);
#endif
  }
  
    
  void log_hierarchy(sc_object& sc_obj) {
    log_hier_helper(&sc_obj);
  } 

  ~channel_logs() {
    if (log_stream)
    {
      log_stream->close();
      delete(log_stream);
    }
  
    if (log_names)
    {
      log_names->close();
      delete(log_names);
    }
  }
};

namespace Connections
{ 
// Port scanner for wrapping modules
#ifdef CONNECTIONS_SIM_ONLY
class port_scanner
{
  public:
  bool is_descendent_of(sc_object* child, sc_object* ancestor)
  {
    sc_object* parent = child->get_parent_object();
  
    if (!parent)
      return false;
  
    if (parent == ancestor)
      return true;
  
    return is_descendent_of(parent, ancestor);
  }
  
  void scan_port(sc_object* obj, sc_object* wrap_object, std::ostream& os)
  {
    if (Connections::in_port_marker* p = dynamic_cast<Connections::in_port_marker*>(obj))
    {
      p->end_of_elaboration();
  
      if (p->bound_to && p->top_port)
      {
        if (!is_descendent_of(p->bound_to, wrap_object))
        {
           os << "In " << std::dec << p->w << " " << p->msg->name() << "\n";
        }
      }
    }
    
    if (Connections::out_port_marker* p = dynamic_cast<Connections::out_port_marker*>(obj))
    {
      p->end_of_elaboration();
  
      if (p->bound_to && p->top_port)
      {
        if (!is_descendent_of(p->bound_to, wrap_object))
        {
           os << "Out " << std::dec << p->w << " " << p->msg->name() << "\n";
        }
      }
    }
  }
  
  void scan_hierarchy(sc_object* obj, sc_object* wrap_object, std::ostream& os)
  {
    scan_port(obj, wrap_object, os);

    std::vector<sc_object*> children = obj->get_child_objects();
    for ( unsigned i = 0; i < children.size(); i++ )
      if ( children[i] )
        scan_hierarchy( children[i], wrap_object, os);
  }
  
  int scan(const char* name, const char* fname)
  {
    sc_start(1, SC_PS); // forces elaboration to complete
    sc_object* o = sc_find_object(name);
  
    if (!o)
      return 1;
  
    std::ofstream ofs(fname, std::ofstream::out);
    scan_hierarchy(o, o, ofs);
    ofs.close();
  
    return 0;
  }
};

__attribute__ ((noinline)) static int port_scan(const char* name, const char* fname)
{
  if (!name)
    return 0;
  (void)port_scan(0, 0); // to get rid of unused function warnings

  Connections::port_scanner p;
  return p.scan(name, fname);
}

#endif // CONNECTIONS_SIM_ONLY

#ifdef HLS_CATAPULT
typedef p2p_sync<SYN>::out<>   SyncOut;
typedef p2p_sync<SYN>::in<>    SyncIn;

class SyncChannel: public p2p_sync<SYN>::chan<>
#ifdef CONNECTIONS_SIM_ONLY
  , public sc_trace_marker 
#endif
{
 public:
  SC_CTOR(SyncChannel) {}

#ifdef CONNECTIONS_SIM_ONLY
  virtual void set_trace(sc_trace_file* fp)
  {
    sc_trace(fp, p2p_sync<SYN>::chan<>::vld, p2p_sync<SYN>::chan<>::vld.name());
    sc_trace(fp, p2p_sync<SYN>::chan<>::rdy, p2p_sync<SYN>::chan<>::rdy.name());
  }

  virtual bool set_log(std::ofstream* os, int& log_num, std::string& path_name) { return false; }
#endif
};
#endif // HLS_CATAPULT

} //Connections namespace
  
