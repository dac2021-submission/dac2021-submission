////////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
// 
// Copyright (c) 2003-2018 Mentor Graphics Corp.
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

#ifndef _INCLUDED_AC_PIXELS_H_
#define _INCLUDED_AC_PIXELS_H_

// One of the functions (ac_rgb_2_yuv422) has a default template parameter, the use of which
// is only supported by C++11 or later compiler standards. Inform the user if they are not using
// those standards.

#if !(__cplusplus >= 201103L)
#error Please use C++11 or a later standard for compilation.
#endif

// structures, functions and coefficients for image pixel manipulation

#include <ac_int.h>
#include <ac_channel.h>
#include <ac_fixed.h>

#ifndef __SYNTHESIS__
#include <string>
#include <iostream>
#endif

namespace ac_ipl
{

  // RGB format - 1 Pixel Per Clock
  template <unsigned CDEPTH>
  struct RGB_1PPC {
    enum {
      CDEPTH_ = CDEPTH,
      PPC = 1
    };

    ac_int<CDEPTH,false> G; // TDATA = ZeroPad + R + B + G
    ac_int<CDEPTH,false> B;
    ac_int<CDEPTH,false> R;
    bool                 TUSER; // Start-of-Frame
    bool                 TLAST; // End-of-Line

    RGB_1PPC() {}

    // Initialize color components of RGB_1PPC to a single data value. Initializing the TUSER and TLAST flags is left upto the user.
    template <class T> RGB_1PPC(T p) : R(p), G(p), B(p) {}

    // Use constructor to copy one RGB_1PPC object to another RGB_1PPC object of a different color depth.
    template <unsigned CDEPTH2> RGB_1PPC(RGB_1PPC<CDEPTH2> p) : R(p.R), G(p.G), B(p.B), TUSER(p.TUSER), TLAST(p.TLAST) {}

    // Comparison function, used to enable "==" and "!=" operator overloading.
    bool cmp(const RGB_1PPC<CDEPTH> &op2) const {
      return R == op2.R && G == op2.G && B == op2.B && TUSER == op2.TUSER && TLAST == op2.TLAST;
    }

    // See whether two RGB_1PPC objects have the same elements.
    bool operator == (const RGB_1PPC<CDEPTH> &op2) const {
      return cmp(op2);
    }

    // See whether two RGB_1PPC objects do not have the same elements.
    bool operator != (const RGB_1PPC<CDEPTH> &op2) const {
      return !cmp(op2);
    }

#ifndef __SYNTHESIS__
    // Prints out type information for RGB_1PPC datatype. Is modeled after the type_name() functions in AC datatypes.
    static std::string type_name()
    {
      std::string r = "RGB_1PPC<";
      r += ac_int<32, false>(CDEPTH).to_string(AC_DEC);
      r += ">";
      return r;
    }
#endif
  };

  // RGB format - 2 Pixels Per Clock
  template <unsigned CDEPTH>
  struct RGB_2PPC {
    enum {
      CDEPTH_ = CDEPTH,
      PPC = 2
    };

    ac_int<CDEPTH,false> G0; // TDATA = ZeroPad + R1 + B1 + G1 + R0 + B0 + G0
    ac_int<CDEPTH,false> B0;
    ac_int<CDEPTH,false> R0;
    ac_int<CDEPTH,false> G1;
    ac_int<CDEPTH,false> B1;
    ac_int<CDEPTH,false> R1;
    bool                 TUSER; // Start-of-Frame
    bool                 TLAST; // End-of-Line

    RGB_2PPC() {}

    // Initialize color components of RGB_2PPC to a single data value. Initializing the TUSER and TLAST flags is left upto the user.
    template <class T> RGB_2PPC(T p) : R0(p), G0(p), B0(p), R1(p), G1(p), B1(p) {}

    // Copy one RGB_2PPC object to another RGB_2PPC object with a different bitwidth, using a constructor.
    template <unsigned CDEPTH2> RGB_2PPC(RGB_2PPC<CDEPTH2> p) : R0(p.R0), G0(p.G0), B0(p.B0), R1(p.R1), G1(p.G1), B1(p.B1), TUSER(p.TUSER), TLAST(p.TLAST) {}

    bool cmp(const RGB_2PPC<CDEPTH> &op2) const {
      return R0 == op2.R0 && G0 == op2.G0 && B0 == op2.B0 && R1 == op2.R1 && G1 == op2.G1 && B1 == op2.B1 && TUSER == op2.TUSER && TLAST == op2.TLAST;
    }

    // See whether two RGB_2PPC objects have the same elements.
    bool operator == (const RGB_2PPC<CDEPTH> &op2) const {
      return cmp(op2);
    }

    // See whether two RGB_2PPC objects do not have the same elements.
    bool operator != (const RGB_2PPC<CDEPTH> &op2) const {
      return !cmp(op2);
    }

#ifndef __SYNTHESIS__
    // Prints out type information for RGB_2PPC datatype. Is modeled after the type_name() functions in AC datatypes.
    static std::string type_name()
    {
      std::string r = "RGB_2PPC<";
      r += ac_int<32, false>(CDEPTH).to_string(AC_DEC);
      r += ">";
      return r;
    }
#endif
  };

  // RGB format - Meant for intermediate ("imd") calculations that may require datatypes other than unsigned ac_ints.
  template <class T_imd>
  struct RGB_imd {
    T_imd R;
    T_imd G;
    T_imd B;

    RGB_imd() {}

    template <class T> RGB_imd(T p) : R(p), G(p), B(p) { }

    // Copy one RGB_imd object to another RGB_imd object with a different internal type.
    template <class T> RGB_imd(RGB_imd<T> p) : R(p.R), G(p.G), B(p.B) { }

    // Copy RGB components of an RGB_1PPC object to RGB_imd object.
    template <unsigned CDEPTH> RGB_imd(RGB_1PPC<CDEPTH> p) : R(p.R), G(p.G), B(p.B) { }

    // Add two RGB_imd objects together.
    template<class T>
    const RGB_imd<typename ac::rt_2T<T_imd, T>::plus> operator + (const RGB_imd<T> p) const {
      RGB_imd<typename ac::rt_2T<T_imd, T>::plus> res;
      res.R = R + p.R;
      res.G = G + p.G;
      res.B = B + p.B;
      return res;
    }

    // Add RGB_imd object and RGB_1PPC object together. The RGB_1PPC object must always be on the
    // RHS of the addition operation.
    // e.g. RGB_imd_obj1 = RGB_imd_obj2 + RGB_1PPC_obj;
    template<unsigned CDEPTH>
    const RGB_imd<typename ac::rt_2T<T_imd, ac_int<CDEPTH, false> >::plus> operator + (const RGB_1PPC<CDEPTH> p) const {
      RGB_imd<typename ac::rt_2T<T_imd, ac_int<CDEPTH, false> >::plus> res;
      res.R = R + p.R;
      res.G = G + p.G;
      res.B = B + p.B;
      return res;
    }

    // Add scalar value to RGB_imd datatype. Note that the return type is not derived, but is
    // instead the same as the type of LHS (i.e. RGB_imd<T_imd>). This is done to avoid compiler
    // errors.
    // The scalar value must always be on the right hand side of the addition operation.
    // e.g. RGB_imd_obj1 = RGB_imd_obj2 + 2;
    template<class T>
    const RGB_imd<T_imd> operator + (const T p) const {
      RGB_imd<T_imd> res;
      res.R = R + p;
      res.G = G + p;
      res.B = B + p;
      return res;
    }

    // Addition assignment operator for addition of RGB_imd value.
    template<class T>
    RGB_imd<T_imd>& operator += (RGB_imd<T> p) {
      R += p.R;
      G += p.G;
      B += p.B;
      return *this;
    }

    // Addition assignment operator for addition of scalar data.
    template<class T>
    RGB_imd<T_imd>& operator += (T p) {
      R += p;
      G += p;
      B += p;
      return *this;
    }

    // Subtract one RGB_imd object from another.
    template<class T>
    const RGB_imd<typename ac::rt_2T<T_imd, T>::plus> operator - (const RGB_imd<T> p) const {
      RGB_imd<typename ac::rt_2T<T_imd, T>::plus> res;
      res.R = R - p.R;
      res.G = G - p.G;
      res.B = B - p.B;
      return res;
    }

    // Multiply the RGB components of an RGB_imd object with a single data value.
    template <class T>
    const RGB_imd<T_imd> operator * (const T p) const {
      RGB_imd<T_imd> res;
      res.R = R*p;
      res.G = G*p;
      res.B = B*p;
      return res;
    }

    // Multiply two RGB_imd objects together.
    template<class T>
    const RGB_imd<typename ac::rt_2T<T_imd, T>::mult> operator * (const RGB_imd<T> p) const {
      RGB_imd<typename ac::rt_2T<T_imd, T>::mult> res;
      res.R = R * p.R;
      res.G = G * p.G;
      res.B = B * p.B;
      return res;
    }

    // Comparison function, used to enable "==" and "!=" operator overloading.
    template<class T>
    bool cmp(const RGB_imd<T> &op2) const {
      return R == op2.R && G == op2.G && B == op2.B;
    }

    // See whether two RGB_imd objects have the same elements.
    template<class T>
    bool operator == (const RGB_imd<T> &op2) const {
      return cmp(op2);
    }

    // See whether two RGB_imd objects do not have the same elements.
    template<class T>
    bool operator != (const RGB_imd<T> &op2) const {
      return !cmp(op2);
    }

#ifndef __SYNTHESIS__
    // Prints out type information for the RGB_imd datatype. Is modeled after the type_name() functions in AC datatypes.
    static std::string type_name()
    {
      std::string r = "RGB_imd<";
      r += T_imd::type_name();
      r += ">";
      return r;
    }
#endif
  };

  // YUV - 1 Pixel Per Clock
  template <unsigned CDEPTH>
  struct YUV_1PPC {
    ac_int<CDEPTH,false> Y; // TDATA = ZeroPad + Cr + Cb + Y
    ac_int<CDEPTH,false> Cb;
    ac_int<CDEPTH,false> Cr;
    bool                 TUSER; // Start-of-Frame
    bool                 TLAST; // End-of-Line
  };

  // YUV 4:2:2 - 2 Pixels Per Clock
  template <unsigned CDEPTH>
  struct YUV422_2PPC {
    ac_int<CDEPTH,false> Y0; // TDATA = ZeroPad + Cr0 + Y1 + Cb0 + Y0
    ac_int<CDEPTH,false> Cb0;
    ac_int<CDEPTH,false> Y1;
    ac_int<CDEPTH,false> Cr0;
    bool                 TUSER; // Start-of-Frame
    bool                 TLAST; // End-of-Line
  };

  // YUV 4:4:4 - 2 Pixels Per Clock
  template <unsigned CDEPTH>
  struct YUV444_2PPC {
    ac_int<CDEPTH,false> Y0; // TDATA = ZeroPad + Cr1 + Cb1 + Y1 + Cr0 + Cb0 + Y0
    ac_int<CDEPTH,false> Cb0;
    ac_int<CDEPTH,false> Cr0;
    ac_int<CDEPTH,false> Y1;
    ac_int<CDEPTH,false> Cb1;
    ac_int<CDEPTH,false> Cr1;
    bool                 TUSER; // Start-of-Frame
    bool                 TLAST; // End-of-Line
  };

  // RGB -> YUV (Implied 1 Pixel Per Clock)
  template <unsigned CDEPTH>
  inline YUV_1PPC<CDEPTH> ac_rgb_2_yuv(const RGB_1PPC<CDEPTH> rgbin)
  {
    ac_fixed<16,1,true> RGB2YUV_BT601[3][3] = {
      { 0.299,  0.587,  0.114    },
      {-0.168935, -0.331655,  0.50059  },
      { 0.499813, -0.418531, -0.08128  }
    };
    YUV_1PPC<CDEPTH> yuv;
    ac_fixed<16,8,true> tmp;
    tmp  = RGB2YUV_BT601[0][0]*rgbin.R + RGB2YUV_BT601[0][1]*rgbin.G + RGB2YUV_BT601[0][2]*rgbin.B +   0;
    yuv.Y = tmp.to_uint();
    tmp  = RGB2YUV_BT601[1][0]*rgbin.R + RGB2YUV_BT601[1][1]*rgbin.G + RGB2YUV_BT601[1][2]*rgbin.B + 128;
    yuv.Cb = tmp.to_uint();
    tmp  = RGB2YUV_BT601[2][0]*rgbin.R + RGB2YUV_BT601[2][1]*rgbin.G + RGB2YUV_BT601[2][2]*rgbin.B + 128;
    yuv.Cr = tmp.to_uint();
    yuv.TUSER = rgbin.TUSER;
    yuv.TLAST = rgbin.TLAST;
    return yuv;
  }

  // RGB -> YUV 4:4:4 (Implied 2 Pixel Per Clock)
  template <unsigned CDEPTH>
  inline YUV444_2PPC<CDEPTH> ac_rgb_2_yuv444(const RGB_2PPC<CDEPTH> rgbin)
  {
    ac_fixed<16,1,true> RGB2YUV_BT601[3][3] = {
      { 0.299,  0.587,  0.114    },
      {-0.168935, -0.331655,  0.50059  },
      { 0.499813, -0.418531, -0.08128  }
    };
    YUV444_2PPC<CDEPTH> yuv;
    ac_fixed<16,8,true> tmp;
    tmp  = RGB2YUV_BT601[0][0]*rgbin.R0 + RGB2YUV_BT601[0][1]*rgbin.G0 + RGB2YUV_BT601[0][2]*rgbin.B0 +   0;
    yuv.Y0  = tmp.to_uint();
    tmp  = RGB2YUV_BT601[1][0]*rgbin.R0 + RGB2YUV_BT601[1][1]*rgbin.G0 + RGB2YUV_BT601[1][2]*rgbin.B0 + 128;
    yuv.Cb0 = tmp.to_uint();
    tmp  = RGB2YUV_BT601[2][0]*rgbin.R0 + RGB2YUV_BT601[2][1]*rgbin.G0 + RGB2YUV_BT601[2][2]*rgbin.B0 + 128;
    yuv.Cr0 = tmp.to_uint();
    tmp  = RGB2YUV_BT601[0][0]*rgbin.R1 + RGB2YUV_BT601[0][1]*rgbin.G1 + RGB2YUV_BT601[0][2]*rgbin.B1 +   0;
    yuv.Y1  = tmp.to_uint();
    tmp  = RGB2YUV_BT601[1][0]*rgbin.R1 + RGB2YUV_BT601[1][1]*rgbin.G1 + RGB2YUV_BT601[1][2]*rgbin.B1 + 128;
    yuv.Cb1 = tmp.to_uint();
    tmp  = RGB2YUV_BT601[2][0]*rgbin.R1 + RGB2YUV_BT601[2][1]*rgbin.G1 + RGB2YUV_BT601[2][2]*rgbin.B1 + 128;
    yuv.Cr1 = tmp.to_uint();
    yuv.TUSER = rgbin.TUSER;
    yuv.TLAST = rgbin.TLAST;
    return yuv;
  }


  // RGB -> YUV 4:2:2 (Implied 2 Pixel Per Clock)
  template <unsigned CDEPTH, bool average=true>
  inline YUV422_2PPC<CDEPTH> ac_rgb_2_yuv422(const RGB_2PPC<CDEPTH> rgbin)
  {
    ac_fixed<16,1,true> RGB2YUV_BT601[3][3] = {
      { 0.299,  0.587,  0.114    },
      {-0.168935, -0.331655,  0.50059  },
      { 0.499813, -0.418531, -0.08128  }
    };
    YUV444_2PPC<CDEPTH> yuv444;
    YUV422_2PPC<CDEPTH> yuv;
    yuv444 = ac_rgb_2_yuv444(rgbin);
    yuv.Y0 = yuv444.Y0;
    yuv.Y1 = yuv444.Y1;
    if (average) {
      yuv.Cb0 = (yuv444.Cb0 + yuv444.Cb1) >> 2;
      yuv.Cr0 = (yuv444.Cr0 + yuv444.Cr1) >> 2;
    } else {
      yuv.Cb0 = yuv444.Cb0;
      yuv.Cr0 = yuv444.Cr0;
    }
    yuv.TUSER = rgbin.TUSER;
    yuv.TLAST = rgbin.TLAST;
    return yuv;
  }

  // YUV -> RGB (Implied 1 Pixel Per Clock)
  template <unsigned CDEPTH>
  inline RGB_1PPC<CDEPTH> ac_yuv_2_rgb(const YUV_1PPC<CDEPTH> yuvin)
  {
    ac_fixed<16,2,true> YUV2RGB_BT601[3][3] = {
      { 1.0,  0.0,  1.403    },
      { 1.0, -0.344, -0.714    },
      { 1.0,  1.770,  0.0      }
    };
    RGB_1PPC<CDEPTH> rgb;
    ac_fixed<16,8,true> tmp;
    ac_fixed<16,8,true> tmpY = yuvin.Y;
    ac_fixed<16,8,true> tmpU = yuvin.Cb-128;
    ac_fixed<16,8,true> tmpV = yuvin.Cr-128;
    tmp  = YUV2RGB_BT601[0][0]*tmpY + YUV2RGB_BT601[0][1]*tmpU + YUV2RGB_BT601[0][2]*tmpV;
    rgb.R = tmp.to_uint();
    tmp  = YUV2RGB_BT601[1][0]*tmpY + YUV2RGB_BT601[1][1]*tmpU + YUV2RGB_BT601[1][2]*tmpV;
    rgb.G = tmp.to_uint();
    tmp  = YUV2RGB_BT601[2][0]*tmpY + YUV2RGB_BT601[2][1]*tmpU + YUV2RGB_BT601[2][2]*tmpV;
    rgb.B = tmp.to_uint();
    rgb.TUSER = yuvin.TUSER;
    rgb.TLAST = yuvin.TLAST;
    return rgb;
  }

  // YUV 4:2:2 -> RGB (Implied 2 Pixel Per Clock)
  template <unsigned CDEPTH>
  inline RGB_2PPC<CDEPTH> ac_yuv422_2_rgb(const YUV422_2PPC<CDEPTH> yuvin)
  {
    ac_fixed<16,2,true> YUV2RGB_BT601[3][3] = {
      { 1.0,  0.0,  1.403    },
      { 1.0, -0.344, -0.714    },
      { 1.0,  1.770,  0.0      }
    };
    RGB_2PPC<CDEPTH> rgb;
    ac_fixed<16,8,true> tmp;
    ac_fixed<16,8,true> tmpY0 = yuvin.Y0;
    ac_fixed<16,8,true> tmpU = yuvin.Cb0-128;
    ac_fixed<16,8,true> tmpV = yuvin.Cr0-128;
    ac_fixed<16,8,true> tmpY1 = yuvin.Y1;
    tmp  = YUV2RGB_BT601[0][0]*tmpY0 + YUV2RGB_BT601[0][1]*tmpU + YUV2RGB_BT601[0][2]*tmpV;
    rgb.R0 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[1][0]*tmpY0 + YUV2RGB_BT601[1][1]*tmpU + YUV2RGB_BT601[1][2]*tmpV;
    rgb.G0 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[2][0]*tmpY0 + YUV2RGB_BT601[2][1]*tmpU + YUV2RGB_BT601[2][2]*tmpV;
    rgb.B0 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[0][0]*tmpY1 + YUV2RGB_BT601[0][1]*tmpU + YUV2RGB_BT601[0][2]*tmpV;
    rgb.R1 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[1][0]*tmpY1 + YUV2RGB_BT601[1][1]*tmpU + YUV2RGB_BT601[1][2]*tmpV;
    rgb.G1 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[2][0]*tmpY1 + YUV2RGB_BT601[2][1]*tmpU + YUV2RGB_BT601[2][2]*tmpV;
    rgb.B1 = tmp.to_uint();
    rgb.TUSER = yuvin.TUSER;
    rgb.TLAST = yuvin.TLAST;
    return rgb;
  }

  // YUV 4:4:4 -> RGB (Implied 2 Pixel Per Clock)
  template <unsigned CDEPTH>
  inline RGB_2PPC<CDEPTH> ac_yuv422_2_rgb(const YUV444_2PPC<CDEPTH> yuvin)
  {
    ac_fixed<16,2,true> YUV2RGB_BT601[3][3] = {
      { 1.0,  0.0,  1.403    },
      { 1.0, -0.344, -0.714    },
      { 1.0,  1.770,  0.0      }
    };
    RGB_2PPC<CDEPTH> rgb;
    ac_fixed<16,8,true> tmp;
    ac_fixed<16,8,true> tmpY0 = yuvin.Y0;
    ac_fixed<16,8,true> tmpU0 = yuvin.Cb0-128;
    ac_fixed<16,8,true> tmpV0 = yuvin.Cr0-128;
    ac_fixed<16,8,true> tmpU1 = yuvin.Cb1-128;
    ac_fixed<16,8,true> tmpV1 = yuvin.Cr1-128;
    ac_fixed<16,8,true> tmpY1 = yuvin.Y1;
    tmp  = YUV2RGB_BT601[0][0]*tmpY0 + YUV2RGB_BT601[0][1]*tmpU0 + YUV2RGB_BT601[0][2]*tmpV0;
    rgb.R0 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[1][0]*tmpY0 + YUV2RGB_BT601[1][1]*tmpU0 + YUV2RGB_BT601[1][2]*tmpV0;
    rgb.G0 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[2][0]*tmpY0 + YUV2RGB_BT601[2][1]*tmpU0 + YUV2RGB_BT601[2][2]*tmpV0;
    rgb.B0 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[0][0]*tmpY1 + YUV2RGB_BT601[0][1]*tmpU1 + YUV2RGB_BT601[0][2]*tmpV1;
    rgb.R1 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[1][0]*tmpY1 + YUV2RGB_BT601[1][1]*tmpU1 + YUV2RGB_BT601[1][2]*tmpV1;
    rgb.G1 = tmp.to_uint();
    tmp  = YUV2RGB_BT601[2][0]*tmpY1 + YUV2RGB_BT601[2][1]*tmpU1 + YUV2RGB_BT601[2][2]*tmpV1;
    rgb.B1 = tmp.to_uint();
    rgb.TUSER = yuvin.TUSER;
    rgb.TLAST = yuvin.TLAST;
    return rgb;
  }

};

//Printing out ac_pixels objects.
#ifndef __SYNTHESIS__
//Print out an RGB_1PPC struct.
template<unsigned CDEPTH>
std::ostream &operator << (std::ostream &os, const ac_ipl::RGB_1PPC<CDEPTH> &input)
{
  // Print out RGB_1PPC struct in an "{R, G, B}" format
  os << "{" << input.R << ", " << input.G << ", " << input.B << "}";
  return os;
}

//Print out an RGB_2PPC struct.
template<unsigned CDEPTH>
std::ostream &operator << (std::ostream &os, const ac_ipl::RGB_2PPC<CDEPTH> &input)
{
  // Print out RGB_2PPC struct in an "{{R0, G0, B0}, {R1, G1, B1}}" format
  os << "{{" << input.R0 << ", " << input.G0 << ", " << input.B0 << "}, {" << input.R1 << ", " << input.G1 << ", " << input.B1 << "}}";
  return os;
}

//Print out an RGB_imd struct.
template<class T_imd>
std::ostream &operator << (std::ostream &os, const ac_ipl::RGB_imd<T_imd> &input)
{
  // Print out RGB_imd struct in an "{R, G, B}" format
  os << "{" << input.R << ", " << input.G << ", " << input.B << "}";
  return os;
}

//Print out a YUV_1PPC struct.
template<unsigned CDEPTH>
std::ostream &operator << (std::ostream &os, const ac_ipl::YUV_1PPC<CDEPTH> &input)
{
  // Print out YUV_1PPC struct in an "{Y, Cb, Cr}" format
  os << "{" << input.Y << ", " << input.Cb << ", " << input.Cr << "}";
  return os;
}

//Print out a YUV422_2PPC struct
template<unsigned CDEPTH>
std::ostream &operator << (std::ostream &os, const ac_ipl::YUV422_2PPC<CDEPTH> &input)
{
  // Print out YUV422_2PPC struct in an "{Y0, Cb0, Y1, Cr0}" format
  os << "{" << input.Y0 << ", " << input.Cb0 << ", " << input.Y1 <<  ", " << input.Cr0 << "}";
  return os;
}

//Print out a YUV444_2PPC struct
template<unsigned CDEPTH>
std::ostream &operator << (std::ostream &os, const ac_ipl::YUV444_2PPC<CDEPTH> &input)
{
  // Print out YUV444_2PPC struct in an "{{Y0, Cb0, Cr0}, {Y1, Cb1, Cr1}}" format
  os << "{{" << input.Y0 << ", " << input.Cb0 << ", " << input.Cr0 << "}, {" << input.Y1 << ", " << input.Cb1 << ", " << input.Cr1 << "}}";
  return os;
}
#endif // #ifndef __SYNTHESIS__

#endif // #ifndef _INCLUDED_AC_PIXELS_H_
