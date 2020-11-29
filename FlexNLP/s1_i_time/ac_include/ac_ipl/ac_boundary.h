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

//***************************************************************************
// File: ac_boundary.h
//
// Description: Provides a class used to perform the boundary processing when 
//      at the left, right, top, or bottom of an image, or any 1-d or 2-d 
//      array of values.
//
// Boundary Processing Modes
//    AC_REPLICATE  - replicate the first and last row (or column) as many
//                    times as needed
//         Example: Input   |  -1 |  -1 |   1 |   2 |   3 |
//                  Output  |   1 |   1 |   1 |   2 |   3 |
//
//    AC_MIRROR_101 - mirror (reflect) at edge of boundary
//         Example: Input   |  -1 |  -1 |   1 |   2 |   3 |
//                  Output  |   3 |   2 |   1 |   2 |   3 |
//                    
//    AC_MIRROR     - mirror (reflect) the image at boundary value
//                    column[-1] = column[1], column[-2] = column[2]
//         Example: Input   |  -1 |  -1 |   1 |   2 |   3
//                  Output  |   2 |   1 |   1 |   2 |   3 |
//
//    AC_CONSTANT   - fill with constant value (template parameter)
//         Example: Input   |  -1 |  -1 |   1 |   2 |   3 |
//                  Output  |  99 |  99 |   1 |   2 |   3 |
//
//    AC_NOPAD      - ??
//         Example: Input
//                  Output
//
// Class Templates
//    T             - typename specifies internal data type
//    WIN_SIZE      - integer size of input/output register arrays
//    BOUNDARY_MODE - enum specifying the type of boundary processing
//    BOUNDS_CONST  - integer value used for constant bounds
//
// Usage:
//
// Notes:
//
// Revision History:
//
//***************************************************************************

#ifndef _INCLUDED_AC_BOUNDARY_H_
#define _INCLUDED_AC_BOUNDARY_H_

#include <ac_array.h>
#include <ac_int.h>
#include <cassert>

namespace ac_modes{
  enum ac_window_mode {
    AC_REPLICATE  = 1<<0,
    AC_MIRROR_101 = 1<<1,
    AC_MIRROR     = 1<<2,
    AC_CONSTANT   = 1<<3,
    AC_NOPAD      = 1<<4
  };
}
using namespace ac_modes;

//=========================================================================
// Class: ac_boundary
//
//	apply_bounds class member function has two inputs of type ac_array
//    din   - input window contents
//    dout  - output window contents after applying boundary
//    lower - bit field that indicates left or top boundary
//    upper - bit field that indicates right or bottom boundary
//
//-------------------------------------------------------------------------

template<typename T, int WIN_SIZE, int BOUNDARY_MODE = ac_modes::AC_REPLICATE, int AC_BOUNDS_CONST=0>
class ac_boundary
{
public:
  // Constructor: (new empty)
  ac_boundary() {
    assert(WIN_SIZE <= 11 && WIN_SIZE & 1); // Make sure usage falls within specializations
  }

public: // Class Member Functions
  void apply_bounds(ac_int<WIN_SIZE,false> lower, ac_int<WIN_SIZE,false> upper, ac_array<T,WIN_SIZE> din, ac_array<T,WIN_SIZE> &dout);
};

//=========================================================================
// Specialized Class: ac_boundary (w/WIN_SIZE=3)
//  All case statements are 3 bits
//
//-------------------------------------------------------------------------

template<typename T, int BOUNDARY_MODE, int AC_BOUNDS_CONST>
class ac_boundary<T,3,BOUNDARY_MODE,AC_BOUNDS_CONST>
{
public:
  // Constructors (new empty)
  ac_boundary() { }

public: // Class Member Functions

  void apply_bounds(ac_int<3,false> lower, ac_int<3,false> upper, ac_array<T,3> din, ac_array<T,3> &dout) {
    ac_array<T,3> win = din;

    if (BOUNDARY_MODE & ac_modes::AC_REPLICATE) { // replicate boundary
      switch (lower) {
        case 0b010:
          win[0] = win[1];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b010:
          win[2] = win[1];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR_101) {
      switch (lower) {
        case 0b010:
          win[0] = win[2];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b010:
          win[2] = win[0];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR) {
      switch (lower) {
        case 0b010:
          win[0] = win[1];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b010:
          win[2] = win[1];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_CONSTANT) { // replicate boundary
      switch (lower) {
        case 0b010:
          win[0] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b010:
          win[2] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
    } else { // replicate boundary
      switch (lower) {
        case 0b010:
          win[0] = win[1];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b010:
          win[2] = win[1];
          break;
        default:
          break;
      }
    }
    dout = win;
  }
};

//=========================================================================
// Specialized Class: ac_boundary (w/WIN_SIZE=5)
//  All case statements are 5 bits
//
//-------------------------------------------------------------------------

template<typename T, int BOUNDARY_MODE, int AC_BOUNDS_CONST>
class ac_boundary<T,5,BOUNDARY_MODE,AC_BOUNDS_CONST>
{
public:
  // Constructor: (new empty)
  ac_boundary() { }

public: // Class Member Functions

  void apply_bounds(ac_int<5,false> lower, ac_int<5,false> upper, ac_array<T,5> din, ac_array<T,5> &dout) {
    ac_array<T,5> win = din;

    if (BOUNDARY_MODE & ac_modes::AC_REPLICATE) {  // replicate boundary
      switch (lower) {
        case 0b01000:
          win[0] = win[1];
          break;
        case 0b00100:
          win[0] = win[2];
          win[1] = win[2];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00100:
          win[4] = win[2];
          win[3] = win[2];
          break;
        case 0b00010:
          win[4] = win[3];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR_101) {
      switch (lower) {
        case 0b01000:
          win[0] = win[2];
          break;
        case 0b00100:
          win[0] = win[4];
          win[1] = win[3];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00100:
          win[4] = win[0];
          win[3] = win[1];
          break;
        case 0b00010:
          win[4] = win[2];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR) {
      switch (lower) {
        case 0b01000:
          win[0] = win[1];
          break;
        case 0b00100:
          win[0] = win[3];
          win[1] = win[2];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00100:
          win[4] = win[1];
          win[3] = win[2];
          break;
        case 0b00010:
          win[4] = win[3];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_CONSTANT) { // replicate boundary
      switch (lower) {
        case 0b01000:
          win[0] = AC_BOUNDS_CONST;
          break;
        case 0b00100:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00100:
          win[4] = AC_BOUNDS_CONST;
          win[3] = AC_BOUNDS_CONST;
          break;
        case 0b00010:
          win[4] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
    } else { // replicate boundary
      switch (lower) {
        case 0b01000:
          win[0] = win[1];
          break;
        case 0b00100:
          win[0] = win[2];
          win[1] = win[2];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00100:
          win[4] = win[2];
          win[3] = win[2];
          break;
        case 0b00010:
          win[4] = win[3];
          break;
        default:
          break;
      }
    }
    dout = win;
  }
};

//=========================================================================
// Specialized Class: ac_boundary (w/WIN_SIZE=7)
//  All case statements are 7 bits
//
//-------------------------------------------------------------------------

template<typename T, int BOUNDARY_MODE, int AC_BOUNDS_CONST>
class ac_boundary<T,7,BOUNDARY_MODE,AC_BOUNDS_CONST>
{
public:
  // Constructor: (new empty)
  ac_boundary() { }

public: // Class Member Functions

  void apply_bounds(ac_int<7,false> lower, ac_int<7,false> upper, ac_array<T,7> din, ac_array<T,7> &dout) {
    ac_array<T,7> win = din;

    if (BOUNDARY_MODE & ac_modes::AC_REPLICATE) { // replicate boundary
      switch (lower) {
        case 0b0100000:
          win[0] = win[1];
          break;
        case 0b0010000:
          win[0] = win[2];
          win[1] = win[2];
          break;
        case 0b0001000:
          win[0] = win[3];
          win[1] = win[3];
          win[2] = win[3];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b0001000:
          win[6] = win[3];
          win[5] = win[3];
          win[4] = win[3];
          break;
        case 0b0000100:
          win[6] = win[4];
          win[5] = win[4];
          break;
        case 0b0000010:
          win[6] = win[5];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR_101) {
      switch (lower) {
        case 0b0100000:
          win[0] = win[2];
          break;
        case 0b0010000:
          win[0] = win[4];
          win[1] = win[3];
          break;
        case 0b0001000:
          win[0] = win[6];
          win[1] = win[5];
          win[2] = win[4];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b0001000:
          win[6] = win[0];
          win[5] = win[1];
          win[4] = win[2];
          break;
        case 0b0000100:
          win[6] = win[2];
          win[5] = win[3];
          break;
        case 0b0000010:
          win[6] = win[4];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR) {
      switch (lower) {
        case 0b0100000:
          win[0] = win[1];
          break;
        case 0b0010000:
          win[0] = win[3];
          win[1] = win[2];
          break;
        case 0b0001000:
          win[0] = win[5];
          win[1] = win[4];
          win[2] = win[3];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b0001000:
          win[6] = win[1];
          win[5] = win[2];
          win[4] = win[3];
          break;
        case 0b0000100:
          win[6] = win[3];
          win[5] = win[4];
          break;
        case 0b0000010:
          win[6] = win[5];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_CONSTANT) { // replicate boundary
      switch (lower) {
        case 0b0100000:
          win[0] = AC_BOUNDS_CONST;
          break;
        case 0b0010000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          break;
        case 0b0001000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          win[2] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b0001000:
          win[6] = AC_BOUNDS_CONST;
          win[5] = AC_BOUNDS_CONST;
          win[4] = AC_BOUNDS_CONST;
          break;
        case 0b0000100:
          win[6] = AC_BOUNDS_CONST;
          win[5] = AC_BOUNDS_CONST;
          break;
        case 0b0000010:
          win[6] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
    } else { // replicate boundary
      switch (lower) {
        case 0b0100000:
          win[0] = win[1];
          break;
        case 0b0010000:
          win[0] = win[2];
          win[1] = win[2];
          break;
        case 0b0001000:
          win[0] = win[3];
          win[1] = win[3];
          win[2] = win[3];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b0001000:
          win[6] = win[3];
          win[5] = win[3];
          win[4] = win[3];
          break;
        case 0b0000100:
          win[6] = win[4];
          win[5] = win[4];
          break;
        case 0b0000010:
          win[6] = win[5];
          break;
        default:
          break;
      }
    }
    dout = win;
  }
};

//=========================================================================
// Specialized Class: ac_boundary (w/WIN_SIZE=9)
//  All case statements are 9 bits
//
//-------------------------------------------------------------------------

template<typename T, int BOUNDARY_MODE, int AC_BOUNDS_CONST>
class ac_boundary<T,9,BOUNDARY_MODE,AC_BOUNDS_CONST>
{
public:
  // Constructor: (new empty)
  ac_boundary() { }

public: // Class Member Functions

  void apply_bounds(ac_int<9,false> lower, ac_int<9,false> upper, ac_array<T,9> din, ac_array<T,9> &dout) {
    ac_array<T,9> win = din;

    if (BOUNDARY_MODE & ac_modes::AC_REPLICATE) { // replicate boundary
      switch (lower) {
        case 0b010000000:
          win[0] = win[1];
          break;
        case 0b001000000:
          win[0] = win[2];
          win[1] = win[2];
          break;
        case 0b000100000:
          win[0] = win[3];
          win[1] = win[3];
          win[2] = win[3];
          break;
        case 0b000010000:
          win[0] = win[4];
          win[1] = win[4];
          win[2] = win[4];
          win[3] = win[4];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b000010000:
          win[8] = win[4];
          win[7] = win[4];
          win[6] = win[4];
          win[5] = win[4];
          break;
        case 0b000001000:
          win[8] = win[5];
          win[7] = win[5];
          win[6] = win[5];
          break;
        case 0b000000100:
          win[8] = win[6];
          win[7] = win[6];
          break;
        case 0b000000010:
          win[8] = win[7];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR_101) {
      switch (lower) {
        case 0b010000000:
          win[0] = win[2];
          break;
        case 0b001000000:
          win[0] = win[4];
          win[1] = win[3];
          break;
        case 0b000100000:
          win[0] = win[6];
          win[1] = win[5];
          win[2] = win[4];
          break;
        case 0b000010000:
          win[0] = win[8];
          win[1] = win[7];
          win[2] = win[6];
          win[3] = win[5];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b000010000:
          win[8] = win[0];
          win[7] = win[1];
          win[6] = win[2];
          win[5] = win[3];
          break;
        case 0b000001000:
          win[8] = win[2];
          win[7] = win[3];
          win[6] = win[4];
          break;
        case 0b000000100:
          win[8] = win[4];
          win[7] = win[5];
          break;
        case 0b000000010:
          win[8] = win[6];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR) {
      switch (lower) {
        case 0b010000000:
          win[0] = win[1];
          break;
        case 0b001000000:
          win[0] = win[3];
          win[1] = win[2];
          break;
        case 0b000100000:
          win[0] = win[5];
          win[1] = win[4];
          win[2] = win[3];
          break;
        case 0b000010000:
          win[0] = win[7];
          win[1] = win[6];
          win[2] = win[5];
          win[3] = win[4];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b000010000:
          win[8] = win[1];
          win[7] = win[2];
          win[6] = win[3];
          win[5] = win[4];
          break;
        case 0b000001000:
          win[8] = win[3];
          win[7] = win[4];
          win[6] = win[5];
          break;
        case 0b000000100:
          win[8] = win[5];
          win[7] = win[6];
          break;
        case 0b000000010:
          win[8] = win[7];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_CONSTANT) { // replicate boundary
      switch (lower) {
        case 0b010000000:
          win[0] = AC_BOUNDS_CONST;
          break;
        case 0b001000000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          break;
        case 0b000100000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          win[2] = AC_BOUNDS_CONST;
          break;
        case 0b000010000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          win[2] = AC_BOUNDS_CONST;
          win[3] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b000010000:
          win[8] = AC_BOUNDS_CONST;
          win[7] = AC_BOUNDS_CONST;
          win[6] = AC_BOUNDS_CONST;
          win[5] = AC_BOUNDS_CONST;
          break;
        case 0b000001000:
          win[8] = AC_BOUNDS_CONST;
          win[7] = AC_BOUNDS_CONST;
          win[6] = AC_BOUNDS_CONST;
          break;
        case 0b000000100:
          win[8] = AC_BOUNDS_CONST;
          win[7] = AC_BOUNDS_CONST;
          break;
        case 0b000000010:
          win[8] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
    } else { // replicate boundary
      switch (lower) {
        case 0b010000000:
          win[0] = win[1];
          break;
        case 0b001000000:
          win[0] = win[2];
          win[1] = win[2];
          break;
        case 0b000100000:
          win[0] = win[3];
          win[1] = win[3];
          win[2] = win[3];
          break;
        case 0b000010000:
          win[0] = win[4];
          win[1] = win[4];
          win[2] = win[4];
          win[3] = win[4];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b000010000:
          win[8] = win[4];
          win[7] = win[4];
          win[6] = win[4];
          win[5] = win[4];
          break;
        case 0b000001000:
          win[8] = win[5];
          win[7] = win[5];
          win[6] = win[5];
          break;
        case 0b000000100:
          win[8] = win[6];
          win[7] = win[6];
          break;
        case 0b000000010:
          win[8] = win[7];
          break;
        default:
          break;
      }
    }
    dout = win;
  }
};


//=========================================================================
// Specialized Class: ac_boundary (w/WIN_SIZE=11)
//  All case statements are 11 bits
//
//-------------------------------------------------------------------------

template<typename T, int BOUNDARY_MODE, int AC_BOUNDS_CONST>
class ac_boundary<T,11,BOUNDARY_MODE,AC_BOUNDS_CONST>
{
public:
  // Constructor: (new empty)
  ac_boundary() { }

public: // Class Member Functions

  void apply_bounds(ac_int<11,false> lower, ac_int<11,false> upper, ac_array<T,11> din, ac_array<T,11> &dout) {
    ac_array<T,11> win = din;

    if (BOUNDARY_MODE & ac_modes::AC_REPLICATE) { // replicate boundary
      switch (lower) {
        case 0b01000000000:
          win[0] = win[1];
          break;
        case 0b00100000000:
          win[0] = win[2];
          win[1] = win[2];
          break;
        case 0b00010000000:
          win[0] = win[3];
          win[1] = win[3];
          win[2] = win[3];
          break;
        case 0b00001000000:
          win[0] = win[4];
          win[1] = win[4];
          win[2] = win[4];
          win[3] = win[4];
          break;
        case 0b00000100000:
          win[0] = win[5];
          win[1] = win[5];
          win[2] = win[5];
          win[3] = win[5];
          win[4] = win[5];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00000100000:
          win[10] = win[5];
          win[9] = win[5];
          win[8] = win[5];
          win[7] = win[5];
          win[6] = win[5];
          break;
        case 0b00000010000:
          win[10] = win[6];
          win[9] = win[6];
          win[8] = win[6];
          win[7] = win[6];
          break;
        case 0b00000001000:
          win[10] = win[7];
          win[9] = win[7];
          win[8] = win[7];
          break;
        case 0b00000000100:
          win[10] = win[8];
          win[9] = win[8];
          break;
        case 0b00000000010:
          win[10] = win[9];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR_101) {
      switch (lower) {
        case 0b01000000000:
          win[0] = win[2];
          break;
        case 0b00100000000:
          win[0] = win[4];
          win[1] = win[3];
          break;
        case 0b00010000000:
          win[0] = win[6];
          win[1] = win[5];
          win[2] = win[4];
          break;
        case 0b00001000000:
          win[0] = win[8];
          win[1] = win[7];
          win[2] = win[6];
          win[3] = win[5];
          break;
        case 0b00000100000:
          win[0] = win[10];
          win[1] = win[9];
          win[2] = win[8];
          win[3] = win[7];
          win[4] = win[6];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00000100000:
          win[10] = win[0];
          win[9] = win[1];
          win[8] = win[2];
          win[7] = win[3];
          win[6] = win[4];
          break;
        case 0b00000010000:
          win[10] = win[2];
          win[9] = win[3];
          win[8] = win[4];
          win[7] = win[5];
          break;
        case 0b00000001000:
          win[10] = win[4];
          win[9] = win[5];
          win[8] = win[6];
          break;
        case 0b00000000100:
          win[10] = win[6];
          win[9] = win[7];
          break;
        case 0b00000000010:
          win[10] = win[8];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_MIRROR) {
      switch (lower) {
        case 0b01000000000:
          win[0] = win[1];
          break;
        case 0b00100000000:
          win[0] = win[3];
          win[1] = win[2];
          break;
        case 0b00010000000:
          win[0] = win[5];
          win[1] = win[4];
          win[2] = win[3];
          break;
        case 0b00001000000:
          win[0] = win[7];
          win[1] = win[6];
          win[2] = win[5];
          win[3] = win[4];
          break;
        case 0b00000100000:
          win[0] = win[9];
          win[1] = win[8];
          win[2] = win[7];
          win[3] = win[6];
          win[4] = win[5];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00000100000:
          win[10] = win[1];
          win[9] = win[2];
          win[8] = win[3];
          win[7] = win[4];
          win[6] = win[5];
          break;
        case 0b00000010000:
          win[10] = win[3];
          win[9] = win[4];
          win[8] = win[5];
          win[7] = win[6];
          break;
        case 0b00000001000:
          win[10] = win[5];
          win[9] = win[6];
          win[8] = win[7];
          break;
        case 0b00000000100:
          win[10] = win[7];
          win[9] = win[8];
          break;
        case 0b00000000010:
          win[10] = win[9];
          break;
        default:
          break;
      }
    } else if (BOUNDARY_MODE & ac_modes::AC_CONSTANT) { // replicate boundary
      switch (lower) {
        case 0b01000000000:
          win[0] = AC_BOUNDS_CONST;
          break;
        case 0b00100000000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          break;
        case 0b00010000000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          win[2] = AC_BOUNDS_CONST;
          break;
        case 0b00001000000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          win[2] = AC_BOUNDS_CONST;
          win[3] = AC_BOUNDS_CONST;
          break;
        case 0b00000100000:
          win[0] = AC_BOUNDS_CONST;
          win[1] = AC_BOUNDS_CONST;
          win[2] = AC_BOUNDS_CONST;
          win[3] = AC_BOUNDS_CONST;
          win[4] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00000100000:
          win[10] = AC_BOUNDS_CONST;
          win[9] = AC_BOUNDS_CONST;
          win[8] = AC_BOUNDS_CONST;
          win[7] = AC_BOUNDS_CONST;
          win[6] = AC_BOUNDS_CONST;
          break;
        case 0b00000010000:
          win[10] = AC_BOUNDS_CONST;
          win[9] = AC_BOUNDS_CONST;
          win[8] = AC_BOUNDS_CONST;
          win[7] = AC_BOUNDS_CONST;
          break;
        case 0b00000001000:
          win[10] = AC_BOUNDS_CONST;
          win[9] = AC_BOUNDS_CONST;
          win[8] = AC_BOUNDS_CONST;
          break;
        case 0b00000000100:
          win[10] = AC_BOUNDS_CONST;
          win[9] = AC_BOUNDS_CONST;
          break;
        case 0b00000000010:
          win[10] = AC_BOUNDS_CONST;
          break;
        default:
          break;
      }
    } else { // replicate boundary
      switch (lower) {
        case 0b01000000000:
          win[0] = win[1];
          break;
        case 0b00100000000:
          win[0] = win[2];
          win[1] = win[2];
          break;
        case 0b00010000000:
          win[0] = win[3];
          win[1] = win[3];
          win[2] = win[3];
          break;
        case 0b00001000000:
          win[0] = win[4];
          win[1] = win[4];
          win[2] = win[4];
          win[3] = win[4];
          break;
        case 0b00000100000:
          win[0] = win[5];
          win[1] = win[5];
          win[2] = win[5];
          win[3] = win[5];
          win[4] = win[5];
          break;
        default:
          break;
      }
      switch (upper) {
        case 0b00000100000:
          win[10] = win[5];
          win[9] = win[5];
          win[8] = win[5];
          win[7] = win[5];
          win[6] = win[5];
          break;
        case 0b00000010000:
          win[10] = win[6];
          win[9] = win[6];
          win[8] = win[6];
          win[7] = win[6];
          break;
        case 0b00000001000:
          win[10] = win[7];
          win[9] = win[7];
          win[8] = win[7];
          break;
        case 0b00000000100:
          win[10] = win[8];
          win[9] = win[8];
          break;
        case 0b00000000010:
          win[10] = win[9];
          break;
        default:
          break;
      }
    }
    dout = win;
  }
};

#endif

