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
#ifndef _INCLUDED_AC_CTC_H_
#define _INCLUDED_AC_CTC_H_

#include <ac_int.h>
#include <ac_fixed.h>
#include <ac_ipl/ac_pixels.h>
#include <ac_channel.h>
#include <ac_math/ac_div.h>
#include <mc_scverify.h>

#ifndef __SYNTHESIS__
#include <iostream>
#endif

// The design uses static_asserts, which are only supported by C++11 or later compiler standards.
// The #error directive below informs the user if they're not using those standards.
#if !(__cplusplus >= 201103L)
#error Please use C++11 or a later standard for compilation.
#endif

// Mandatory template parameters:
// CDEPTH: Input/Output color depth.
// W_MAX/H_MAX: Max. supported image width/height.
// TEMP_MAX: Max. supported color temperature.
// Optional template parameters:
// R_WP, G_WP, B_WP: User defined white point of video. If all values are 0, the design deduces video white point from
// previously processed input frames.
template <unsigned CDEPTH, unsigned W_MAX, unsigned H_MAX, unsigned TEMP_MAX, unsigned R_WP = 0, unsigned G_WP = 0, unsigned B_WP = 0>
class ac_ctc
{
public:
  // Define IO datatype
  typedef ac_ipl::RGB_1PPC<CDEPTH> IO_TYPE;
  // Dimension and temperature input types are bitwidth-constrained according to the max dimensions/temperature possible.
  typedef ac_int<ac::nbits<W_MAX>::val, false> widthInType;
  typedef ac_int<ac::nbits<H_MAX>::val, false> heightInType;
  typedef ac_int<ac::nbits<TEMP_MAX>::val, false> tempInType;

  ac_ctc() {
    static_assert(TEMP_MAX <= temp_limit_u, "TEMP_MAX must not exceed upper temperature limit supported by design LUTs.");
    static_assert((R_WP == 0 && G_WP == 0 && B_WP == 0) || userSuppliedWP, "Mixing of zero and non-zero values for user-supplied white point is not allowed.");
    static_assert(R_WP <= 255 && G_WP <= 255 && B_WP <= 255, "All user defined white point values must not exceed 255.");
    
    if (userSuppliedWP) {
      RGB_WP.R = R_WP;
      RGB_WP.G = G_WP;
      RGB_WP.B = B_WP;
    } else {
      RGB_WP = 255;
    }
  }

#pragma hls_pipeline_init_interval 1
#pragma hls_design interface
  void CCS_BLOCK(run) (
    ac_channel<IO_TYPE> &streamIn,  // Pixel input stream
    ac_channel<IO_TYPE> &streamOut, // Pixel output stream
    const widthInType   widthIn,    // Input width
    const heightInType  heightIn,   // Input height
    const tempInType    tempIn      // Input color temperature
  ) {
    AC_ASSERT(tempIn <= TEMP_MAX, "Input color temperature must not exceed maximum supported color temperature.");
    AC_ASSERT(tempIn >= temp_limit_l, "Input color temperature must not fall below minimum supported by design.");

    // Normalize the input color temperature and use the normalized temperature to index into the coefficient LUTs.
    const ac_int<ac::nbits<size_table - 1>::val, false> index = (tempIn - temp_limit_l)/temp_inc;
    T_coeff coeff_R_val = coeff_R[index], coeff_G_val = coeff_G[index], coeff_B_val = coeff_B[index];
    ac_ipl::RGB_imd<ac_fixed<n_f_b + 8, 8, false> > ratio;

    if (!userSuppliedWP) {
      RGB_WP.R = RGB_WP.R == 0 ? 1 : RGB_WP.R;
      RGB_WP.G = RGB_WP.G == 0 ? 1 : RGB_WP.G;
      RGB_WP.B = RGB_WP.B == 0 ? 1 : RGB_WP.B;
      ac_math::ac_div(coeff_R_val, RGB_WP.R, ratio.R);
      ac_math::ac_div(coeff_G_val, RGB_WP.G, ratio.G);
      ac_math::ac_div(coeff_B_val, RGB_WP.B, ratio.B);
    } else {
      ratio.R = ac_fixed<n_f_b + 8, 8, false>(coeff_R_val)/RGB_WP.R;
      ratio.G = ac_fixed<n_f_b + 8, 8, false>(coeff_G_val)/RGB_WP.G;
      ratio.B = ac_fixed<n_f_b + 8, 8, false>(coeff_B_val)/RGB_WP.B;
    }
    
    ac_int<CDEPTH + 2, false> maxRGBSum = 0, RGBSum;

#pragma hls_pipeline_init_interval 1
    CTC_LOOP: for (unsigned i = 0; i < H_MAX*W_MAX; i++) {
      IO_TYPE pixIn = streamIn.read(), pixOut;
      // Multiply input RGB values with the relevant ratios.
      pixOut.R = (ac_fixed<CDEPTH, CDEPTH, false, AC_RND, AC_SAT>(ratio.R*pixIn.R)).to_int();
      pixOut.G = (ac_fixed<CDEPTH, CDEPTH, false, AC_RND, AC_SAT>(ratio.G*pixIn.G)).to_int();
      pixOut.B = (ac_fixed<CDEPTH, CDEPTH, false, AC_RND, AC_SAT>(ratio.B*pixIn.B)).to_int();
      // TUSER and TLAST flags are copied to the output as-is.
      pixOut.TUSER = pixIn.TUSER;
      pixOut.TLAST = pixIn.TLAST;
      if (!userSuppliedWP) {
        RGBSum = pixIn.R + pixIn.G + pixIn.B;
        if (RGBSum >= maxRGBSum) {
          RGB_WP.R = pixIn.R >> shiftBy;
          RGB_WP.G = pixIn.G >> shiftBy;
          RGB_WP.B = pixIn.B >> shiftBy;
          maxRGBSum = RGBSum;
        }
      }
      streamOut.write(pixOut);
      if (i == widthIn*heightIn - 1) { break; }
    }
    
    std::cout << "maxRGBSum = " << maxRGBSum << std::endl;
    std::cout << "RGB_WP = " << RGB_WP << std::endl;
  }

private:
  ac_ipl::RGB_imd<ac_fixed<8, 8, false> > RGB_WP;
  
  enum {
    userSuppliedWP = R_WP > 0 && G_WP > 0 && B_WP > 0,
    shiftBy = CDEPTH - 8,
    n_f_b = 16,
  };

  // Each coefficient in the LUT varies from the last one in the sense that the temperature associated
  // increments by the value specified through the temp_inc variable. e.g. If the temperature associated
  // with the second LUT coefficient is 1100 K and temp_inc = 100, the third LUT coefficient will have a
  // temperature = 1100 + 100 = 1200 K, the fourth will have T = 1200 + 100 = 1300 K and so on.
  enum {
    temp_limit_l = 1000,
    temp_limit_u = 13700,
    temp_inc = 100,
    size_table = (temp_limit_u - temp_limit_l)/temp_inc + 1,
  };

  typedef ac_fixed<8, 8, false> T_coeff;

  const T_coeff coeff_R[size_table] = {
    255, // T = 1000 K
    255, // T = 1100 K
    255, // T = 1200 K
    255, // T = 1300 K
    255, // T = 1400 K
    255, // T = 1500 K
    255, // T = 1600 K
    255, // T = 1700 K
    255, // T = 1800 K
    255, // T = 1900 K
    255, // T = 2000 K
    255, // T = 2100 K
    255, // T = 2200 K
    255, // T = 2300 K
    255, // T = 2400 K
    255, // T = 2500 K
    255, // T = 2600 K
    255, // T = 2700 K
    255, // T = 2800 K
    255, // T = 2900 K
    255, // T = 3000 K
    255, // T = 3100 K
    255, // T = 3200 K
    255, // T = 3300 K
    255, // T = 3400 K
    255, // T = 3500 K
    255, // T = 3600 K
    255, // T = 3700 K
    255, // T = 3800 K
    255, // T = 3900 K
    255, // T = 4000 K
    255, // T = 4100 K
    255, // T = 4200 K
    255, // T = 4300 K
    255, // T = 4400 K
    255, // T = 4500 K
    255, // T = 4600 K
    255, // T = 4700 K
    255, // T = 4800 K
    255, // T = 4900 K
    255, // T = 5000 K
    255, // T = 5100 K
    255, // T = 5200 K
    255, // T = 5300 K
    255, // T = 5400 K
    255, // T = 5500 K
    255, // T = 5600 K
    255, // T = 5700 K
    255, // T = 5800 K
    255, // T = 5900 K
    255, // T = 6000 K
    255, // T = 6100 K
    255, // T = 6200 K
    255, // T = 6300 K
    255, // T = 6400 K
    255, // T = 6500 K
    255, // T = 6600 K
    254, // T = 6700 K
    250, // T = 6800 K
    246, // T = 6900 K
    243, // T = 7000 K
    240, // T = 7100 K
    237, // T = 7200 K
    234, // T = 7300 K
    232, // T = 7400 K
    230, // T = 7500 K
    228, // T = 7600 K
    226, // T = 7700 K
    224, // T = 7800 K
    223, // T = 7900 K
    221, // T = 8000 K
    220, // T = 8100 K
    218, // T = 8200 K
    217, // T = 8300 K
    216, // T = 8400 K
    215, // T = 8500 K
    214, // T = 8600 K
    213, // T = 8700 K
    212, // T = 8800 K
    211, // T = 8900 K
    210, // T = 9000 K
    209, // T = 9100 K
    208, // T = 9200 K
    207, // T = 9300 K
    206, // T = 9400 K
    205, // T = 9500 K
    205, // T = 9600 K
    204, // T = 9700 K
    203, // T = 9800 K
    202, // T = 9900 K
    202, // T = 10000 K
    201, // T = 10100 K
    200, // T = 10200 K
    200, // T = 10300 K
    199, // T = 10400 K
    199, // T = 10500 K
    198, // T = 10600 K
    197, // T = 10700 K
    197, // T = 10800 K
    196, // T = 10900 K
    196, // T = 11000 K
    195, // T = 11100 K
    195, // T = 11200 K
    194, // T = 11300 K
    194, // T = 11400 K
    193, // T = 11500 K
    193, // T = 11600 K
    192, // T = 11700 K
    192, // T = 11800 K
    192, // T = 11900 K
    191, // T = 12000 K
    191, // T = 12100 K
    190, // T = 12200 K
    190, // T = 12300 K
    189, // T = 12400 K
    189, // T = 12500 K
    189, // T = 12600 K
    188, // T = 12700 K
    188, // T = 12800 K
    188, // T = 12900 K
    187, // T = 13000 K
    187, // T = 13100 K
    187, // T = 13200 K
    186, // T = 13300 K
    186, // T = 13400 K
    186, // T = 13500 K
    185, // T = 13600 K
    185  // T = 13700 K
  };

  const T_coeff coeff_G[size_table] = {
    68,  // T = 1000 K
    77,  // T = 1100 K
    86,  // T = 1200 K
    94,  // T = 1300 K
    101, // T = 1400 K
    108, // T = 1500 K
    115, // T = 1600 K
    121, // T = 1700 K
    126, // T = 1800 K
    132, // T = 1900 K
    137, // T = 2000 K
    142, // T = 2100 K
    146, // T = 2200 K
    151, // T = 2300 K
    155, // T = 2400 K
    159, // T = 2500 K
    163, // T = 2600 K
    167, // T = 2700 K
    170, // T = 2800 K
    174, // T = 2900 K
    177, // T = 3000 K
    180, // T = 3100 K
    184, // T = 3200 K
    187, // T = 3300 K
    190, // T = 3400 K
    193, // T = 3500 K
    195, // T = 3600 K
    198, // T = 3700 K
    201, // T = 3800 K
    203, // T = 3900 K
    206, // T = 4000 K
    208, // T = 4100 K
    211, // T = 4200 K
    213, // T = 4300 K
    215, // T = 4400 K
    218, // T = 4500 K
    220, // T = 4600 K
    222, // T = 4700 K
    224, // T = 4800 K
    226, // T = 4900 K
    228, // T = 5000 K
    230, // T = 5100 K
    232, // T = 5200 K
    234, // T = 5300 K
    236, // T = 5400 K
    237, // T = 5500 K
    239, // T = 5600 K
    241, // T = 5700 K
    243, // T = 5800 K
    244, // T = 5900 K
    246, // T = 6000 K
    248, // T = 6100 K
    249, // T = 6200 K
    251, // T = 6300 K
    253, // T = 6400 K
    254, // T = 6500 K
    255, // T = 6600 K
    249, // T = 6700 K
    246, // T = 6800 K
    244, // T = 6900 K
    242, // T = 7000 K
    240, // T = 7100 K
    239, // T = 7200 K
    237, // T = 7300 K
    236, // T = 7400 K
    235, // T = 7500 K
    234, // T = 7600 K
    233, // T = 7700 K
    232, // T = 7800 K
    231, // T = 7900 K
    230, // T = 8000 K
    229, // T = 8100 K
    228, // T = 8200 K
    227, // T = 8300 K
    227, // T = 8400 K
    226, // T = 8500 K
    225, // T = 8600 K
    225, // T = 8700 K
    224, // T = 8800 K
    223, // T = 8900 K
    223, // T = 9000 K
    222, // T = 9100 K
    222, // T = 9200 K
    221, // T = 9300 K
    221, // T = 9400 K
    220, // T = 9500 K
    220, // T = 9600 K
    219, // T = 9700 K
    219, // T = 9800 K
    218, // T = 9900 K
    218, // T = 10000 K
    218, // T = 10100 K
    217, // T = 10200 K
    217, // T = 10300 K
    217, // T = 10400 K
    216, // T = 10500 K
    216, // T = 10600 K
    215, // T = 10700 K
    215, // T = 10800 K
    215, // T = 10900 K
    214, // T = 11000 K
    214, // T = 11100 K
    214, // T = 11200 K
    213, // T = 11300 K
    213, // T = 11400 K
    213, // T = 11500 K
    213, // T = 11600 K
    212, // T = 11700 K
    212, // T = 11800 K
    212, // T = 11900 K
    211, // T = 12000 K
    211, // T = 12100 K
    211, // T = 12200 K
    211, // T = 12300 K
    210, // T = 12400 K
    210, // T = 12500 K
    210, // T = 12600 K
    210, // T = 12700 K
    210, // T = 12800 K
    209, // T = 12900 K
    209, // T = 13000 K
    209, // T = 13100 K
    209, // T = 13200 K
    208, // T = 13300 K
    208, // T = 13400 K
    208, // T = 13500 K
    208, // T = 13600 K
    208  // T = 13700 K
  };

  const T_coeff coeff_B[size_table] = {
    0,   // T = 1000 K
    0,   // T = 1100 K
    0,   // T = 1200 K
    0,   // T = 1300 K
    0,   // T = 1400 K
    0,   // T = 1500 K
    0,   // T = 1600 K
    0,   // T = 1700 K
    0,   // T = 1800 K
    0,   // T = 1900 K
    14,  // T = 2000 K
    27,  // T = 2100 K
    39,  // T = 2200 K
    50,  // T = 2300 K
    61,  // T = 2400 K
    70,  // T = 2500 K
    79,  // T = 2600 K
    87,  // T = 2700 K
    95,  // T = 2800 K
    103, // T = 2900 K
    110, // T = 3000 K
    117, // T = 3100 K
    123, // T = 3200 K
    129, // T = 3300 K
    135, // T = 3400 K
    141, // T = 3500 K
    146, // T = 3600 K
    151, // T = 3700 K
    157, // T = 3800 K
    161, // T = 3900 K
    166, // T = 4000 K
    171, // T = 4100 K
    175, // T = 4200 K
    179, // T = 4300 K
    183, // T = 4400 K
    187, // T = 4500 K
    191, // T = 4600 K
    195, // T = 4700 K
    199, // T = 4800 K
    202, // T = 4900 K
    206, // T = 5000 K
    209, // T = 5100 K
    213, // T = 5200 K
    216, // T = 5300 K
    219, // T = 5400 K
    222, // T = 5500 K
    225, // T = 5600 K
    228, // T = 5700 K
    231, // T = 5800 K
    234, // T = 5900 K
    237, // T = 6000 K
    240, // T = 6100 K
    242, // T = 6200 K
    245, // T = 6300 K
    248, // T = 6400 K
    250, // T = 6500 K
    255, // T = 6600 K
    255, // T = 6700 K
    255, // T = 6800 K
    255, // T = 6900 K
    255, // T = 7000 K
    255, // T = 7100 K
    255, // T = 7200 K
    255, // T = 7300 K
    255, // T = 7400 K
    255, // T = 7500 K
    255, // T = 7600 K
    255, // T = 7700 K
    255, // T = 7800 K
    255, // T = 7900 K
    255, // T = 8000 K
    255, // T = 8100 K
    255, // T = 8200 K
    255, // T = 8300 K
    255, // T = 8400 K
    255, // T = 8500 K
    255, // T = 8600 K
    255, // T = 8700 K
    255, // T = 8800 K
    255, // T = 8900 K
    255, // T = 9000 K
    255, // T = 9100 K
    255, // T = 9200 K
    255, // T = 9300 K
    255, // T = 9400 K
    255, // T = 9500 K
    255, // T = 9600 K
    255, // T = 9700 K
    255, // T = 9800 K
    255, // T = 9900 K
    255, // T = 10000 K
    255, // T = 10100 K
    255, // T = 10200 K
    255, // T = 10300 K
    255, // T = 10400 K
    255, // T = 10500 K
    255, // T = 10600 K
    255, // T = 10700 K
    255, // T = 10800 K
    255, // T = 10900 K
    255, // T = 11000 K
    255, // T = 11100 K
    255, // T = 11200 K
    255, // T = 11300 K
    255, // T = 11400 K
    255, // T = 11500 K
    255, // T = 11600 K
    255, // T = 11700 K
    255, // T = 11800 K
    255, // T = 11900 K
    255, // T = 12000 K
    255, // T = 12100 K
    255, // T = 12200 K
    255, // T = 12300 K
    255, // T = 12400 K
    255, // T = 12500 K
    255, // T = 12600 K
    255, // T = 12700 K
    255, // T = 12800 K
    255, // T = 12900 K
    255, // T = 13000 K
    255, // T = 13100 K
    255, // T = 13200 K
    255, // T = 13300 K
    255, // T = 13400 K
    255, // T = 13500 K
    255, // T = 13600 K
    255  // T = 13700 K
  };
};
#endif
