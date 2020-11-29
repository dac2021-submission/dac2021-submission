/**************************************************************************
 *                                                                        *
 *  Algorithmic C (tm) Image Processing Library                           *
 *                                                                        *
 *  Software Version: 3.2                                                 *
 *                                                                        *
 *  Release Date    : Mon Apr  6 17:58:59 PDT 2020                        *
 *  Release Type    : Production Release                                  *
 *  Release Build   : 3.2.3                                               *
 *                                                                        *
 *  Copyright , Mentor Graphics Corporation,                     *
 *                                                                        *
 *  All Rights Reserved.                                                  *
 *  
 **************************************************************************
 *  Licensed under the Apache License, Version 2.0 (the "License");       *
 *  you may not use this file except in compliance with the License.      * 
 *  You may obtain a copy of the License at                               *
 *                                                                        *
 *      http://www.apache.org/licenses/LICENSE-2.0                        *
 *                                                                        *
 *  Unless required by applicable law or agreed to in writing, software   * 
 *  distributed under the License is distributed on an "AS IS" BASIS,     * 
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or       *
 *  implied.                                                              * 
 *  See the License for the specific language governing permissions and   * 
 *  limitations under the License.                                        *
 **************************************************************************
 *                                                                        *
 *  The most recent version of this package is available at github.       *
 *                                                                        *
 *************************************************************************/
#ifndef _INCLUDED_AC_IMHIST_H_
#define _INCLUDED_AC_IMHIST_H_

#include <ac_int.h>
#include <ac_fixed.h>
#include <ac_ipl/ac_pixels.h>
#include <ac_channel.h>
#include <mc_scverify.h>

// The design uses static_asserts, which are only supported by C++11 or later compiler standards.
// The #error directive below informs the user if they're not using those standards.
#if !(__cplusplus >= 201103L)
#error Please use C++11 or a later standard for compilation.
#endif

// The design can only accept ac_int (greyscale) or RGB_1PPC (color) inputs. imhistTypeInfo 
// contains a "match" enum that helps to trigger a static_assert if the user doesn't use the 
// correct types. imhistTypeInfo also has certain type-specific information.

// Generic imhistTypeInfo struct. Is later specialized to deal with different types.
template <unsigned W_MAX, unsigned H_MAX, class T>
struct imhistTypeInfo {
  enum {
    match = false
  };
};

// imhistTypeInfo, specialized for greyscale inputs/outputs.
template <unsigned W_MAX, unsigned H_MAX, int W>
struct imhistTypeInfo<W_MAX, H_MAX, ac_int<W, false> > {
  enum {
    match = true,
    IN_CDEPTH = W, // Input color-depth
  };
  // Max. count possible = Max number of input pixels possible = W_MAX*H_MAX
  typedef ac_int<ac::nbits<W_MAX*H_MAX>::val, false> histArrType;
};

// imhistTypeInfo, specialized for color inputs.
template <unsigned W_MAX, unsigned H_MAX, unsigned W>
struct imhistTypeInfo<W_MAX, H_MAX, ac_ipl::RGB_1PPC<W> > {
  enum {
    match = true,
    IN_CDEPTH = W, // Input color-depth
  };
  // Max. count possible = Max number of input pixels possible = W_MAX*H_MAX
  typedef ac_ipl::RGB_imd<ac_int<ac::nbits<W_MAX*H_MAX>::val, false> > histArrType;
};

// Template parameters:
// IN_TYPE: Input Pixel Type
// OUT_BW: Bitwidth of output
// W_MAX: Max. Supported Width
// H_MAX: Max. Supported Height
template <class IN_TYPE, int OUT_BW, unsigned W_MAX, unsigned H_MAX>
class ac_imhist
{
public:
  typedef imhistTypeInfo<W_MAX, H_MAX, IN_TYPE> stDef;
  // Make sure that the user uses the correct input/output types.
  static_assert(stDef::match, "Input must either be unsigned ac_int or RGB_1PPC.");

  ac_imhist() { }

  // Define output and dimension types.
  typedef ac_int<OUT_BW, false> OUT_TYPE;
  // Dimension types are bitwidth-constrained according to the max dimensions possible.
  typedef ac_int<ac::nbits<W_MAX>::val, false> widthInType;
  typedef ac_int<ac::nbits<H_MAX>::val, false> heightInType;

#pragma hls_pipeline_init_interval 2
#pragma hls_design interface
  void CCS_BLOCK(run) (
    ac_channel<IN_TYPE>  &streamIn,  // Pixel input stream
    ac_channel<OUT_TYPE> &streamOut, // Pixel output stream
    const widthInType    widthIn,    // Input width 
    const heightInType   heightIn    // Input height
  ) {
    // Initialize all histogram counts to zero.
#pragma hls_pipeline_init_interval 2
    INIT_ARR: for (unsigned i = 0; i < OUT_SIZE; i++) {
      histArr[i] = 0;
    }

    // Read all input pixel and update the histogram count array accordingly.
#pragma hls_pipeline_init_interval 2
    READ_INPUT: for (unsigned i = 0; i < W_MAX*H_MAX; i++) {
      IN_TYPE pixIn = streamIn.read();
      updateArr(pixIn);
      if (i == widthIn*heightIn - 1) { break; }
    }

    // Read histogram count array and write the counts to the output channel.
#pragma hls_pipeline_init_interval 2
    WRITE_OUTPUT: for (unsigned i = 0; i < OUT_SIZE; i++) {
      // IN_TYPE is a dummy input and will be optimized away. It is used to enable template-based overloading
      // of the writeOut function. 
      IN_TYPE dummyIn;
      OUT_TYPE histOut = writeOut(dummyIn, i);
      streamOut.write(histOut);
    }
  }

private:
  // Find input color depth.
  enum { IN_CDEPTH  = stDef::IN_CDEPTH };

  // This function updates the histogram count array for greyscale inputs.
  void updateArr(const ac_int<IN_CDEPTH, false> pixIn) {
    histArr[pixIn]++; // Index into array based on the input intensity levels and increment the value found there.
  }

  // This function updates the histogram count array for color inputs.
  void updateArr(const ac_ipl::RGB_1PPC<IN_CDEPTH> pixIn) {
    // Update histogram values separately for each color component, based on color values.
    histArr[pixIn.R].R++;
    histArr[pixIn.G].G++;
    histArr[pixIn.B].B++;
  }

  // This function writes the histogram output to the temporary output variable (histOut), for greyscale inputs.
  OUT_TYPE writeOut(const ac_int<IN_CDEPTH, false> dummyIn, const unsigned i) {
    OUT_TYPE histOut;
    histOut = histArr[i];
    return histOut;
  }

  // This function does the same, but for color inputs.
  OUT_TYPE writeOut(const ac_ipl::RGB_1PPC<IN_CDEPTH> dummyIn, const unsigned i) {
    OUT_TYPE histOut;
    histOut = histArr[i].R + histArr[i].G + histArr[i].B; // Accumulate histogram counts across color components.
    return histOut;
  }

  // size of output array = number of intensity levels possible = 2^IN_CDEPTH.
  enum { OUT_SIZE = 1 << IN_CDEPTH };

  // If the input image is greyscale, then the histogram count array will be an array of ac_int values.
  // If the input image is color, then the histogram count array will be an array of RGB_imd values.
  // The stDef templatized struct allows us to choose between the two array types based on the input type.
  typedef typename stDef::histArrType histArrType;
  histArrType histArr[OUT_SIZE];
};

#endif
