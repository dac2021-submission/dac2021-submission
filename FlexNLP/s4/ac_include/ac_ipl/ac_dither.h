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
#ifndef _INCLUDED_AC_DITHER_H_
#define _INCLUDED_AC_DITHER_H_

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

// The design can only accept ac_int (greyscale) or RGB_1PPC (color) inputs/outputs. T_info
// contains a "match" enum that helps to trigger a static_assert if the user doesn't use the
// correct types. T_info also has certain type-specific information.

// Generic T_info struct. Is later specialized to deal with different types.
template <class T1, class T2, int pSumW, int pSumI, ac_q_mode pSumQ, ac_o_mode pSumO>
struct T_info {
  enum {
    match = false
  };
};

// T_info, specialized for greyscale inputs/outputs.
template <int W1, int W2, int pSumW, int pSumI, ac_q_mode pSumQ, ac_o_mode pSumO>
struct T_info<ac_int<W1, false>, ac_int<W2, false>, pSumW, pSumI, pSumQ, pSumO> {
  enum {
    match = true,
    IN_CDEPTH = W1,  // Input color-depth
    OUT_CDEPTH = W2, // Output color-depth
  };
  // pSumType is used for storage of partial sums, and has nothing to do with internal calculations. Hence
  // we may use the default rounding/saturation modes for it (AC_TRN and AC_WRAP)
  typedef ac_fixed<pSumW, pSumI, true> pSumType;
  typedef ac_fixed<pSumW, pSumI, true, pSumQ, pSumO> pSumType_RS; // pSumType_RS has rounding and saturation set to the user-specified values.
  typedef ac_int<2*pSumW, false> buff2XType; // We use an intermediate, twice-wide buffer for singleport implementations.
};

// T_info, specialized for color inputs/outputs.
template <unsigned W1, unsigned W2, int pSumW, int pSumI, ac_q_mode pSumQ, ac_o_mode pSumO>
struct T_info<ac_ipl::RGB_1PPC<W1>, ac_ipl::RGB_1PPC<W2>, pSumW, pSumI, pSumQ, pSumO> {
  enum {
    match = true,
    IN_CDEPTH = W1,  // Input color-depth
    OUT_CDEPTH = W2, // Output color-depth
  };
  // These typedefs are defined in a manner similar to that found in the greyscale pSumStruct above.
  typedef ac_ipl::RGB_imd<ac_fixed<pSumW, pSumI, true> > pSumType;
  typedef ac_ipl::RGB_imd<ac_fixed<pSumW, pSumI, true, pSumQ, pSumO> > pSumType_RS;
  typedef ac_ipl::RGB_imd<ac_int<2*pSumW, false> > buff2XType;
};

// Mandatory template parameters:
// IN_TYPE: Input Pixel Type
// OUT_TYPE: Output Pixel Type
// W_MAX: Max. Supported Width
// H_MAX: Max. Supported Height
// Optional template parameters:
// use_sp: Lets the user specify whether they want singleport memories or not
// pSumW and pSumI: Word and Integer width of intermediate computation variable
// pSumQ and pSumO: Quantization and overflow modes of the intermediate computation variable, respectively
template <class IN_TYPE, class OUT_TYPE, unsigned W_MAX, unsigned H_MAX, bool use_sp = false, int pSumW = 32, int pSumI = 16, ac_q_mode pSumQ = AC_TRN, ac_o_mode pSumO = AC_SAT>
class ac_dither
{
public:
  typedef T_info<IN_TYPE, OUT_TYPE, pSumW, pSumI, pSumQ, pSumO> stDef;
  // Make sure that the user uses the correct input/output types.
  static_assert(stDef::match, "Input and output must either be unsigned ac_int or RGB_1PPC datatypes.");
  // Find input/output color depths.
  enum {
    IN_CDEPTH  = stDef::IN_CDEPTH,
    OUT_CDEPTH = stDef::OUT_CDEPTH,
  };
  // The dithering function is always associated with lossy quantization, and the color depths should correspond to the intended usage.
  static_assert(IN_CDEPTH >= OUT_CDEPTH, "Output color depth must not exceed input color depth.");

  ac_dither() {
    maxValRatio = inDivType(inMaxVal)/outDivType(outMaxVal);
  }

  // Dimension types are bitwidth-constrained according to the max dimensions possible.
  typedef ac_int<ac::nbits<W_MAX>::val, false> widthInType;
  typedef ac_int<ac::nbits<H_MAX>::val, false> heightInType;

#pragma hls_pipeline_init_interval 1
#pragma hls_design interface
  void CCS_BLOCK(run) (
    ac_channel<IN_TYPE>  &streamIn,  // Pixel input stream
    ac_channel<OUT_TYPE> &streamOut, // Pixel output stream
    const widthInType    widthIn,    // Input width
    const heightInType   heightIn    // Input height
  ) {
    AC_ASSERT(use_dp || widthIn%2 == 0, "Input width must be even to allow usage of singleport memory.");

    // Cofficients used for diffusing the quantization error to the next row {3/16, 5/16, 1/16}
    const ac_fixed<4, 0, false> windowCoeffs[3] = {0.1875, 0.3125, 0.0625};
    // Store the coefficient used for diffusing quantization error to the pixel to the right. (7/16)
    const ac_fixed<4, 0, false> nextPixCoeff = 0.4375;

#pragma hls_pipeline_init_interval 1
    ROW_LOOP: for (unsigned i = 0; i < H_MAX; i++) {
      pSumType_RS ShiftReg[3];
      // Shift register is initialized to zero at the beginning of every new row, to clear out junk partial sums.
#pragma hls_unroll yes
      SHIFT_REG_ZERO_INIT: for (unsigned j = 0; j < 3; j++) {
        ShiftReg[j] = 0;
      }
      // When the design is on the top row, it has no diffused quantization errors from previous rows to
      // read. Hence, the design does not read from RAM.
      bool noRAMRead = (i == 0);
      // When the design is on the bottom row, it has no need to write sums of diffused quantization errors for the next row.
      // Hence, the design does not write to RAM.
      bool noRAMWrite = (i == heightIn - 1);
      // pSumPrevPix: Stores the partial sum of diffused quantization errors from the quantization of the previous pixel.
      pSumType_RS pSumPrevPix = 0;
      pSumType delayReg = 0; // Used to delay writes by one loop cycle when writing to a singleport memory and hence carry out contiguous reads/writes one after another.
      buff2XType buff2X;
#pragma hls_pipeline_init_interval 1
      COL_LOOP: for (unsigned j = 0; j < W_MAX + 1; j++) {
        // An extra iteration is added at the end of COL_LOOP (i.e. when j == widthIn) to make sure that the last partial sum gets loaded to RAM.
        // The if-else condition below makes sure that this loading to RAM is the only thing that happens at the end of COL_LOOP.
        if (j != widthIn) {
          // pSumPrevRow: Stores the partial sum of diffused quantization errors from the quantization of the previous row of pixels.
          pSumType pSumPrevRow;
          if (use_dp) { // If using dualport
            if (!noRAMRead) {
              pSumPrevRow = lineBuffer_DP[j]; // Dualport memory read
            } else {
              pSumPrevRow = 0; // No value to read -> zero contribution from previous row.
            }
          } else { // If using singleport
            if (j%2 == 0) {
              if (!noRAMRead) {
                buff2X = lineBuffer_SP[j >> 1]; // Singleport RAM Read on even loop iterations.
              } else {
                buff2X = 0; // No value to read -> zero contribution from previous row.
              }
              pSumPrevRow = getSlc(buff2X, 0);
              setSlc(delayReg, 0, buff2X);
            } else {
              pSumPrevRow = getSlc(buff2X, 1);
              setSlc(delayReg, 1, buff2X);
              if (j > 2 && !noRAMWrite) {
                lineBuffer_SP[(j - 3) >> 1] = buff2X; // Singleport RAM Write on odd loop iterations.
              }
            }
          }
          // Read from input channel
          IN_TYPE pixIn = streamIn.read();
          // pixInter: stores the accumulation of diffused quantization errors from the pixel's neighbors.
          // quantError: Quantization error
          pSumType_RS pixInter, quantError;
          // Add all the diffused quantization errors.
          pixInter = pSumPrevPix + pixIn + pSumPrevRow;
          OUT_TYPE pixOut;
          // The quantize function carries out the quantization for the output RGB values and calculates the quantization error.
          quantize(pixInter, pixOut, quantError);
          // Initialize TUSER and TLAST for output pixel stream.
          setPixFlags(pixIn, pixOut);
          // Write output to the streamOut port.
          streamOut.write(pixOut);
          // Update pSumPrevPix for the next pixel
          pSumPrevPix = quantError*nextPixCoeff;
          if (!noRAMWrite) {
            // Shift register elements
            ShiftReg[0] = ShiftReg[1];
            ShiftReg[1] = ShiftReg[2];
            // Multiply quantization error with coefficients, accumulate the product in the shift register.
#pragma hls_unroll yes
            MAC_LOOP: for (unsigned k = 0; k < 3; k++) {
              if (k == 2) {
                ShiftReg[k] = quantError*windowCoeffs[k];
              } else {
                ShiftReg[k] = ShiftReg[k] + quantError*windowCoeffs[k];
              }
            }
            if (j != 0) {
              if (use_dp) {
                lineBuffer_DP[j - 1] = ShiftReg[0];
              } else {
                delayReg = ShiftReg[0];
              }
            }
          }
        } else if (!noRAMWrite) { // Extra iteration.
          if (use_dp) {
            lineBuffer_DP[j - 1] = ShiftReg[1];
          } else {
            buff2X = buff2XConcat(ShiftReg[0], ShiftReg[1]);
            lineBuffer_SP[(widthIn >> 1) - 1] = buff2X;
          }
        }
        if (j == widthIn) { break; } // Account for extra iteration added to complete writing to RAM.
      }
      if (i == heightIn - 1) { break; }
    }
  }

private:
  typedef ac_fixed<pSumW, pSumI, true> acFiType;
  typedef ac_fixed<pSumW, pSumI, true, pSumQ, pSumO> acFiType_RS;
  typedef typename stDef::pSumType pSumType;
  typedef typename stDef::pSumType_RS pSumType_RS;
  typedef typename stDef::buff2XType buff2XType;

  void quantize(const acFiType_RS pixInter_, ac_int<OUT_CDEPTH, false> &pixOut_, acFiType_RS &quantError_) {
    ac_fixed<IN_CDEPTH, IN_CDEPTH, false, AC_RND, AC_SAT> pixInter2 = pixInter_; // Map intermediate pixel values to the range of values supported by the input color depth.
    // Extract OUT_CDEPTH no. of MSBs to determine the output pixel value.
    pixOut_.template set_slc(0, pixInter2.template slc<OUT_CDEPTH>(IN_CDEPTH - OUT_CDEPTH));
    // Find the closest input pixel value that corresponds to the output.
    ac_int<IN_CDEPTH, false> closestInPixVal = (ac_fixed<IN_CDEPTH, IN_CDEPTH, false, AC_RND>(pixOut_*maxValRatio)).to_int();
    quantError_ = pixInter_ - closestInPixVal; // Find quantization error.
  }

  void quantize(const ac_ipl::RGB_imd<acFiType_RS> pixInter, ac_ipl::RGB_1PPC<OUT_CDEPTH> &pixOut, ac_ipl::RGB_imd<acFiType_RS> &quantError) {
    quantize(pixInter.R, pixOut.R, quantError.R);
    quantize(pixInter.G, pixOut.G, quantError.G);
    quantize(pixInter.B, pixOut.B, quantError.B);
  }

  pSumType getSlc(const ac_int<2*pSumW, false> tbuf, const ac_int<1, false> selSlc) {
    pSumType valSlc;
    valSlc.template set_slc(0, tbuf.template slc<pSumW>(selSlc*pSumW));
    return valSlc;
  }

  pSumType getSlc(const ac_ipl::RGB_imd<ac_int<2*pSumW, false> > tbuf, const ac_int<1, false> selSlc) {
    pSumType valSlc;
    valSlc.R.template set_slc(0, tbuf.R.template slc<pSumW>(selSlc*pSumW));
    valSlc.G.template set_slc(0, tbuf.G.template slc<pSumW>(selSlc*pSumW));
    valSlc.B.template set_slc(0, tbuf.B.template slc<pSumW>(selSlc*pSumW));
    return valSlc;
  }

  void setSlc(const acFiType val, const ac_int<1, false> selSlc, ac_int<2*pSumW, false> &tbuf) {
    tbuf.template set_slc(selSlc*pSumW, val.template slc<pSumW>(0));
  }

  void setSlc(const ac_ipl::RGB_imd<acFiType> val, const ac_int<1, false> selSlc, ac_ipl::RGB_imd<ac_int<2*pSumW, false> > &tbuf) {
    tbuf.R.template set_slc(selSlc*pSumW, val.R.template slc<pSumW>(0));
    tbuf.G.template set_slc(selSlc*pSumW, val.G.template slc<pSumW>(0));
    tbuf.B.template set_slc(selSlc*pSumW, val.B.template slc<pSumW>(0));
  }

  void setPixFlags(const ac_int<IN_CDEPTH, false> input, const ac_int<OUT_CDEPTH, false> output) { }

  void setPixFlags(const ac_ipl::RGB_1PPC<IN_CDEPTH> input, ac_ipl::RGB_1PPC<OUT_CDEPTH> &output) {
    output.TUSER = input.TUSER;
    output.TLAST = input.TLAST;
  }

  buff2XType buff2XConcat(const acFiType val1, const acFiType val2) {
    buff2XType valConcat;
    valConcat.template set_slc(0,     val1.template slc<pSumW>(0));
    valConcat.template set_slc(pSumW, val2.template slc<pSumW>(0));
    return valConcat;
  }

  buff2XType buff2XConcat(const ac_ipl::RGB_imd<acFiType> val1, const ac_ipl::RGB_imd<acFiType> val2) {
    buff2XType valConcat;
    valConcat.R.template set_slc(0,     val1.R.template slc<pSumW>(0));
    valConcat.G.template set_slc(0,     val1.G.template slc<pSumW>(0));
    valConcat.B.template set_slc(0,     val1.B.template slc<pSumW>(0));
    valConcat.R.template set_slc(pSumW, val2.R.template slc<pSumW>(0));
    valConcat.G.template set_slc(pSumW, val2.G.template slc<pSumW>(0));
    valConcat.B.template set_slc(pSumW, val2.B.template slc<pSumW>(0));
    return valConcat;
  }

  enum {
    use_dp = !use_sp,
    FBITS_ = 16,
    inMaxVal  = (1 << IN_CDEPTH)  - 1, // Max possible input val
    outMaxVal = (1 << OUT_CDEPTH) - 1, // Max possible output val
    IBITS = ac::nbits<inMaxVal/outMaxVal>::val, // Number of integer bits needed to store the inMaxVal/outMaxVal ratio.
    FBITS = inMaxVal%outMaxVal == 0 ? 0 : FBITS_, // Ratio will have fractional bits if max. input pixel value is not perfectly divisible by max. output pixel value.
  };

  typedef ac_fixed<FBITS + IBITS, IBITS, false> ratioType;
  typedef ac_fixed<FBITS_ + IN_CDEPTH,   IN_CDEPTH, false> inDivType;
  typedef ac_fixed<FBITS_ + OUT_CDEPTH, OUT_CDEPTH, false> outDivType;
  ratioType maxValRatio;
  pSumType lineBuffer_DP[W_MAX];
  buff2XType lineBuffer_SP[W_MAX/2];
};

#endif // #ifndef _INCLUDED_AC_DITHER_H_
