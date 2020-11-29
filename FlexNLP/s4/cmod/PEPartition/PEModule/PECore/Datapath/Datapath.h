/*
 * Copyright (c) 2016-2018, Harvard University.  All rights reserved.
*/
#ifndef __DATAPATH__
#define __DATAPATH__

//  Datapath that does computation on adpfloat 
#include <nvhls_int.h>
#include <nvhls_types.h>
#include "SM6Spec.h"
#include "AdpfloatSpec.h"
#include "AdpfloatUtils.h"

// Zero skipping 
void ProductSum(const spec::VectorType in_1, const spec::VectorType in_2, spec::AccumScalarType& out) {
  spec::AccumScalarType out_tmp = 0; 
  
  #pragma hls_unroll yes
  #pragma cluster addtree 
  #pragma cluster_type both  
  for (int j = 0; j < spec::kVectorSize; j++) {
    AdpfloatType<8,3> in_1_adpfloat(in_1[j]);
    AdpfloatType<8,3> in_2_adpfloat(in_2[j]);
    spec::AccumScalarType acc_tmp;
    adpfloat_mul(in_1_adpfloat, in_2_adpfloat, acc_tmp);
    out_tmp += acc_tmp;
  }
  out = out_tmp;
}


void Datapath(spec::VectorType weight_in[spec::kNumVectorLanes], 
              spec::VectorType input_in,
              spec::AccumVectorType& accum_out)
{
  spec::AccumVectorType accum_out_tmp;            
  #pragma hls_unroll yes 
  for (int i = 0; i < spec::kNumVectorLanes; i++) {
    ProductSum(weight_in[i], input_in, accum_out_tmp[i]);
  }
  
  accum_out = accum_out_tmp;
}





#endif
