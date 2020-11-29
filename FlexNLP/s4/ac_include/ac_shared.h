////////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
//
// Copyright (c) 2003-2019 Mentor Graphics Corp.
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

#ifndef AC_SHARED_H
#define AC_SHARED_H

////////////////////////////////////////////////////////////////////////////////
//  Source:
//  Description:
//    Catapult built-in class to declare intention to share object between
//      different threads/processes/always-blocks.
//    It can be used as a replacement of its base type
////////////////////////////////////////////////////////////////////////////////

template <typename T>
class ac_shared {

  T      d;

public:

  ac_shared() {}
  ac_shared(const ac_shared &s) : d(s.d) {}
  ac_shared(const T &t) : d(t) {}
  template <typename T2>
    ac_shared(const T2 &t) : d(t) {}

  operator const T &() const   { return d; }
  operator       T &()         { return d; }

  const ac_shared &operator =(const ac_shared &s) { d = s.d; return *this; }
  const T &operator =(const T &t) { d = t; return d; }
  template <typename T2>
    const T &operator =(const T2 &t) { d = t; return d; }

};

template <typename T>
class ac_shared_d : public T {
public:

  ac_shared_d() {}
  ac_shared_d(const ac_shared_d &s) : T(s) {}
  ac_shared_d(const T &t) : T(t) {}
  template <typename T2>
    ac_shared_d(const T2 &t) : T(t) {}

  const ac_shared_d &operator =(const ac_shared_d &s) { T::operator =(s); return *this; }
  const T &operator =(const T &t) { T::operator =(t); return *this; }
  template <typename T2>
    const T &operator =(const T2 &t) { T::operator =(t); return *this; }

};

#endif // AC_SHARED_H
