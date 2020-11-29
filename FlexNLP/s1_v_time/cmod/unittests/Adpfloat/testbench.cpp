/*
 * Copyright (c) 2016-2018, Harvard University.  All rights reserved.
*/
#include <stdio.h>
#include <systemc.h>
#include <nvhls_int.h>
#include <nvhls_types.h>
#include <nvhls_vector.h>
#include <mc_scverify.h>
#include <match_scverify.h>
#include "AdpfloatSpec.h"
#include "AdpfloatUtils.h"
#include "SM6Spec.h"
#include "AxiSpec.h"
#include <bitset>

#include <testbench/nvhls_rand.h>

#include <ac_int.h>
#include <ac_fixed.h>
#include <ac_float.h>
#include <ac_math.h>
#include <ac_math/ac_sigmoid_pwl.h>
#include <ac_math/ac_tanh_pwl.h>
#include <ac_math/ac_div.h>
#include <ac_math/ac_pow_pwl.h>



CCS_MAIN (int argc, char *argv[]) {
  nvhls::set_random_seed();
  AdpfloatType<8, 3> adpfloat;
  
  cout << adpfloat << endl;

  spec::AdpfloatBiasType adpbias = 7;
  cout << "float_max " << adpfloat.max_value(adpbias) << endl;
  cout << "float_min " << adpfloat.min_value(adpbias) << endl;
  
  AdpfloatType<8, 3> adpfloat_a, adpfloat_b, adpfloat_c;
  NVINTW(32) mul;
  
  adpfloat_a.set_value(1.569, adpbias);
  adpfloat_b.set_value(-5.335, adpbias);
  adpfloat_c.set_value(0, adpbias);
  CCS_DESIGN(adpfloat_mul)(adpfloat_a, adpfloat_b, mul);
  cout << mul << endl;
  CCS_DESIGN(adpfloat_mul)(adpfloat_c, adpfloat_b, mul);
  cout << mul << endl;  
  
  adpfloat_a.set_value(-31, adpbias);
  adpfloat_b.set_value(-31, adpbias);
  adpfloat_c.set_value(0, adpbias);
  CCS_DESIGN(adpfloat_mul)(adpfloat_a, adpfloat_b, mul);
  cout << mul << endl;
  CCS_DESIGN(adpfloat_mul)(adpfloat_c, adpfloat_b, mul);
  cout << mul << endl;  

  cout << nvhls::index_width<9>::val << endl;
  cout << nvhls::index_width<8>::val << endl;
  cout << nvhls::index_width<7>::val << endl;
  //cout << "float_min " << adpfloat.max_value();

  
  NVINT8 test = -1;
  
  cout << std::bitset<8>(test.to_int()) << endl;
  AdpfloatType<8,3> test_float(test);

  cout << test_float << endl;
  
  adpbias = 7; // exp + adpbias + offset(-10)
  AdpfloatType<8, 3> adpfloat_d;
  NVINT16 fixed = nvhls::get_rand<16>();
  //fixed = 0xffff;
  const int Frac = 12; 
  float ref_fixed = fixed;
  ref_fixed = ref_fixed / (1 << Frac);
  cout << "ref_fixed: " << ref_fixed << endl;
  adpfloat_d.set_value_fixed<16, Frac>(fixed, adpbias); // need CCS design later on 
  cout << "adpfloat/adpbias: " << adpfloat_d << " " << adpbias + spec::kAdpfloatOffset << endl;
  cout << "adpfloat.tofloat: " << adpfloat_d.to_float(adpbias) << endl;
  auto auto_ac_float = adpfloat_d.to_ac_float(adpbias);
  
  cout << "adpfloat.to_acfloat: " << auto_ac_float << endl;
  adpfloat_d.set_value_ac_float(auto_ac_float, adpbias);
  cout << "adpfloat.set_value_ac_float: " << adpfloat_d << endl;
  
  NVINT16 fixed_out = adpfloat_d.to_fixed<16, Frac>(adpbias);
  ref_fixed = fixed_out;
  ref_fixed = ref_fixed / (1 << Frac);
  
  cout << "to fixed: " << ref_fixed << endl;
  
  NVINT8 shift = -1;
  NVINT8 x = -50;
  x = x >> shift;
  cout << "Right shift by -1 = " << x << endl;
  
  
  cout << " Test Adpfloat addition " << endl;
  NVUINT8 a_scalar = nvhls::get_rand<8>();
  NVUINT8 b_scalar = nvhls::get_rand<8>();  
  AdpfloatType<8, 3> a_add(a_scalar);
  AdpfloatType<8, 3> b_add(b_scalar);  
  
  cout << "a, b: " << a_add << ", " << b_add << endl;
  AdpfloatType<8, 3> out_add, out_max, out_mean;
  adpfloat_add(a_add, b_add, out_add);
  adpfloat_max(a_add, b_add, out_max);
  adpfloat_mean(a_add, b_add, out_mean);
  cout << "a, b, sum, max, mean " << a_add.to_float(adpbias) << ", " << b_add.to_float(adpbias) << ", " << out_add.to_float(adpbias) 
       << ", " <<  out_max.to_float(adpbias) << ", " << out_mean.to_float(adpbias) << endl;
 
  std::cout << "NBITS: " << nvhls::log2_floor<spec::kVectorSize>::val << endl;
  std::cout << "Simulation PASSED." << std::endl;   
 
  CCS_RETURN(0);
}
