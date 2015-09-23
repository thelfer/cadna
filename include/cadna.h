// Copyright 2015 J.-M. Chesneaux, P. Eberhart, F. Jezequel, J.-L. Lamotte

// This file is part of CADNA.

// CADNA is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// CADNA is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License
// along with CADNA.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _LIB_CADNA_HXX_
#define _LIB_CADNA_HXX_

#include"cadna/numeric_type.hxx"

using double_st = cadna::numeric_type<double>;
using float_st  = cadna::numeric_type<float>;

inline void cadna_init(int a1, unsigned int a2,
		       unsigned int a3,
		       unsigned int a4){
  cadna::init(a1,a2,a3,a4);
}
  
inline void cadna_init(int a1, unsigned int a2){
  cadna::init(a1,a2);
}
  
inline void cadna_init(int a){
  cadna::init(a);
}
  
inline void cadna_end(){}
  
inline void enable(unsigned int a) {
  cadna::enable(a);
}

inline void disable(unsigned int a){
  cadna::disable(a);
}
  
inline const char* strp(const double_st& v){
  return cadna::internal_strp(v);
}
  
inline const char* strp(const float_st& v){
  return cadna::internal_strp(v);
} // end of 

inline void cadna_set_rnd_arr(void) noexcept{
  cadna::set_rnd_arr();
}

inline void cadna_set_rnd_plinf(void) noexcept{
  cadna::set_rnd_plinf();
}

inline void cadna_set_rnd_moinf(void) noexcept{
  cadna::set_rnd_moinf();
}
  
inline void cadna_set_rnd_zero(void) noexcept{
  cadna::set_rnd_zero();
}
  
#endif  /*  _LIB_CADNA_HXX_ */
