/*
 * Copyright (c) 2018, Harvard University.  All rights reserved.
*/

#ifndef __AXI_SPEC__
#define __AXI_SPEC__

#include <nvhls_int.h>
#include <nvhls_types.h>

#include "axi/AxiSplitter.h"
#include "axi/AxiSlaveToReadyValid.h"
#include "SM6Spec.h"

// 20190125 NOTE: AXI dataWidth is modified from standard 64 bits to 128 bits 
//                if the Vector size is 16 
namespace spec {
  namespace Axi {
    struct axiCfg {
      enum {
        dataWidth = VectorType::width, // 128
        useVariableBeatSize = 0,
        useMisalignedAddresses = 0,
        useLast = 1,
        useWriteStrobes = 1,
        useBurst = 1, useFixedBurst = 0, useWrapBurst = 0, maxBurstSize = 256,
        useQoS = 0, useLock = 0, useProt = 0, useCache = 0, useRegion = 0,
        aUserWidth = 0, wUserWidth = 0, bUserWidth = 0, rUserWidth = 0,
        addrWidth = 32,
        idWidth = 10,
        useWriteResponses = 1,
      };
    };
    struct rvaCfg {
      enum {
        dataWidth = VectorType::width, // 128
        addrWidth = 24,                  
        wstrbWidth = (dataWidth >> 3),
      };
    };
    
    typedef typename axi::axi4<axiCfg> axi4_;
    typedef AxiSlaveToReadyValid<axiCfg, rvaCfg> SlaveToRVA;
    // PE*n + GB
    typedef AxiSplitter<axiCfg, kNumPE+1> AxiSplitter;
  } 
}

#endif
