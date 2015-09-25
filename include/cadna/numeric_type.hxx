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

#ifndef _LIB_CADNA_NUMERIC_TYPE_HXX_
#define _LIB_CADNA_NUMERIC_TYPE_HXX_

#include<iosfwd>
#include<limits>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<type_traits>
#include<initializer_list>

#include "cadna/macros.hxx"
#include "cadna/random.hxx"
#include "cadna/instability.hxx"

namespace cadna{

  constexpr const int DIGIT_NOT_COMPUTED = -1;
  constexpr const int  RELIABLE_RESULT   = 255;

  template<typename T1,typename T2>
  struct promote{
    static_assert(std::numeric_limits<T1>::is_specialized,
		  "std::numeric_limits<T1> is not specialized");
    static_assert(std::numeric_limits<T2>::is_specialized,
		  "std::numeric_limits<T2> is not specialized");
    static constexpr bool value = ((std::numeric_limits<T1>::max_exponent10 < std::numeric_limits<T2>::max_exponent10 ) || 
				   ((std::numeric_limits<T1>::max_exponent10 == std::numeric_limits<T2>::max_exponent10)&&
				    (std::numeric_limits<T1>::digits <= std::numeric_limits<T2>::digits)));
    using type = typename std::conditional<value,T2,T1>::type;
  };

  template<typename T1,typename T2>
  using promote_t = typename promote<T1,T2>::type;
  
  template<typename T>
  using is_cxx_fundamental_type =
    std::integral_constant<bool,std::is_integral<T>::value || std::is_floating_point<T>::value>;
  
  template<typename T>
  struct default_accuracy;
  
  template<>
  struct CADNA_VISIBILITY_EXPORT default_accuracy<double>
  {
    static constexpr const int    value = 15;
    static constexpr const double thresold = 1.e-30;
  };
  
  template<>
  struct CADNA_VISIBILITY_EXPORT default_accuracy<float>
  {
    static constexpr const int value = 7;
    static constexpr const double thresold = 1.e-14;
  };
  
  struct invalid_initialiser_list_size
    : public std::invalid_argument
  {
    invalid_initialiser_list_size(const size_t)
      : std::invalid_argument("invalid_initialiser_list_size")
    {}
  };
    
  template<typename T>
  struct numeric_type
  {
    static_assert(std::is_floating_point<T>::value,
		  "numeric_type : template parameter "
		  "must a standard floating point type");
    using value_type = T;
    value_type x,y,z;
    mutable int accuracy = default_accuracy<value_type>::value;
    //! default constructor
    constexpr numeric_type(void)
      : x(value_type{0}),y(value_type{0}),z(value_type{0})
    {}
    template<typename T2>
    numeric_type(const numeric_type<T2>& v)
      : x(v.x), y(v.y), z(v.z),
	accuracy(std::min(v.accuracy,default_accuracy<value_type>::value))
    {}
    template<typename T2,
	     typename = typename std::enable_if<is_cxx_fundamental_type<T2>::value,
						bool>::type>
    constexpr numeric_type(const T2& a)
      : x(a),y(a),z(a)
    {}
    template<typename T2,
	     typename = typename std::enable_if<is_cxx_fundamental_type<T2>::value,
						bool>::type>
    constexpr numeric_type(const T2& a, const T2& b, const T2& c)
      : x(a),y(b),z(c),accuracy(DIGIT_NOT_COMPUTED)
    {}
    template<typename T2,
	     typename = typename std::enable_if<is_cxx_fundamental_type<T2>::value,
						bool>::type>
    CADNA_CONSTEXPR numeric_type(const std::initializer_list<T2>& v)
      : accuracy(DIGIT_NOT_COMPUTED)
    {
      if(v.size()==1u){
	this->x=this->y=this->z=*(v.begin());
      } else if(v.size()==3u){
	this->x = *(v.begin());
	this->y = *(v.begin()+1);
	this->z = *(v.begin()+2);
      } else{
	throw(invalid_initialiser_list_size(v.size()));
      }
    }
    constexpr numeric_type(numeric_type&&)      = default;
    constexpr numeric_type(const numeric_type&) = default;
    CADNA_CONSTEXPR numeric_type&
    operator=(numeric_type&&) = default;
    CADNA_CONSTEXPR numeric_type&
    operator=(const numeric_type&) = default;
    // assignement to standard C++ types
    template<typename T2>
    CADNA_CONSTEXPR typename std::enable_if<is_cxx_fundamental_type<T2>::value,
					    numeric_type&>::type
    operator=(const T2&) CADNA_ALWAYS_INLINE;
    // assignement to other numeric_type<T>
    template<typename T2>
    CADNA_CONSTEXPR numeric_type&
    operator=(const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  }; // end of struct numeric_type

  // summation
  template<typename T>
  CADNA_INLINE numeric_type<T> operator++(numeric_type<T>&)                CADNA_ALWAYS_INLINE;
  template<typename T>
  CADNA_INLINE numeric_type<T> operator++(numeric_type<T>&,int)             CADNA_ALWAYS_INLINE;
  template<typename T>
  CADNA_CONSTEXPR numeric_type<T> operator+(const numeric_type<T>&)  CADNA_ALWAYS_INLINE;
  // decrement operators
  template<typename T>
  CADNA_INLINE numeric_type<T> operator--(numeric_type<T>&) CADNA_ALWAYS_INLINE;
  template<typename T>
  CADNA_INLINE numeric_type<T> operator--(numeric_type<T>&,int) CADNA_ALWAYS_INLINE;
  template<typename T>
  CADNA_CONSTEXPR numeric_type<T> operator-(const numeric_type<T>&)  CADNA_ALWAYS_INLINE; 
  // += with standard C++ types
  template<typename T,typename T2>
  CADNA_INLINE typename std::enable_if<is_cxx_fundamental_type<T2>::value,
				 numeric_type<T>&>::type
  operator+=(numeric_type<T>&,const T2&) CADNA_ALWAYS_INLINE;
  // += with other numeric_type<T>
  template<typename T,typename T2>
  CADNA_INLINE numeric_type<T>&
  operator+=(numeric_type<T>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  // -= with standard C++ types
  template<typename T,typename T2>
  CADNA_INLINE typename std::enable_if<is_cxx_fundamental_type<T2>::value,
				 numeric_type<T>&>::type
  operator-=(numeric_type<T>&,const T2&) CADNA_ALWAYS_INLINE;
  // -= with other numeric_type<T>
  template<typename T,typename T2>
  CADNA_INLINE numeric_type<T>&
  operator-=(numeric_type<T>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  // *= with standard C++ types
  template<typename T,typename T2>
  CADNA_INLINE typename std::enable_if<is_cxx_fundamental_type<T2>::value,
				 numeric_type<T>&>::type
  operator*=(numeric_type<T>&,const T2&) CADNA_ALWAYS_INLINE;
  // *= with other numeric_type<T>
  template<typename T,typename T2>
  CADNA_INLINE numeric_type<T>&
  operator*=(numeric_type<T>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  // /= with standard C++ types
  template<typename T,typename T2>
  CADNA_INLINE typename std::enable_if<is_cxx_fundamental_type<T2>::value,
				 numeric_type<T>&>::type
  operator/=(numeric_type<T>&,const T2&) CADNA_ALWAYS_INLINE;
  // /= with other numeric_type<T>
  template<typename T,typename T2>
  CADNA_INLINE numeric_type<T>&
  operator/=(numeric_type<T>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  
  template<typename T>
  CADNA_CONSTEXPR int
  nb_significant_digit(const numeric_type<T>&) CADNA_ALWAYS_INLINE;
  template<typename T>
  CADNA_CONSTEXPR int
  approx_digit(const numeric_type<T>&) CADNA_ALWAYS_INLINE;
  // The computedzero() function returns 1 if x is a stochastic
  // zero, O otherwise.
  template<typename T>
  CADNA_CONSTEXPR bool
  computedzero(const numeric_type<T>&) CADNA_ALWAYS_INLINE;
  template<typename T>
  CADNA_CONSTEXPR bool
  numericalnoise(const numeric_type<T>&) CADNA_ALWAYS_INLINE;
  
  CADNA_VISIBILITY_EXPORT
  std::ostream& operator<<(std::ostream&, const numeric_type<double>&);
  CADNA_VISIBILITY_EXPORT
  std::ostream& operator<<(std::ostream&, const numeric_type<float>&);

  CADNA_VISIBILITY_EXPORT
  std::istream& operator>>(std::istream&,numeric_type<double>&);
  CADNA_VISIBILITY_EXPORT
  std::istream& operator>>(std::istream&,numeric_type<float>&);

  CADNA_VISIBILITY_EXPORT
  const char* internal_strp(const numeric_type<double>&);
  
  CADNA_VISIBILITY_EXPORT
  const char* internal_strp(const numeric_type<float>&);
  
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator == (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator == (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE bool
  operator == (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator != (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator != (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE bool
  operator != (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator >= (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator >= (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE bool
  operator >= (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator > (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator > (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE bool
  operator > (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator <= (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator <= (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE bool
  operator <= (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator < (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 bool>::type
  operator < (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE bool
  operator < (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T1>>::type
  operator + (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T2>>::type
  operator + (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE numeric_type<promote_t<T1,T2>>
  operator + (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T1>>::type
  operator - (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T2>>::type
  operator - (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE numeric_type<promote_t<T1,T2>>
  operator - (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T1>>::type
  operator * (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T2>>::type
  operator * (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE numeric_type<promote_t<T1,T2>>
  operator * (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T1>>::type
  operator / (const numeric_type<T1>&,const T2&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				  is_cxx_fundamental_type<T2>::value),
				 numeric_type<T2>>::type
  operator / (const T1&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;
  template<typename T1,typename T2>
  CADNA_INLINE numeric_type<promote_t<T1,T2>>
  operator / (const numeric_type<T1>&,const numeric_type<T2>&) CADNA_ALWAYS_INLINE;

} // end of namespace cadna

#include "numeric_type.ixx"
#include "numeric_limits.hxx"
#include "cmath.hxx"
#include "to_string.hxx"

#endif /* _LIB_NUMERIC_TYPE_HXX_ */
