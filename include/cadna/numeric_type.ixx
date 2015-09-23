/*!
 * \file   numeric_type.ixx
 * \brief
 * \author THOMAS HELFER
 * \date   12 sept. 2015
 */

#ifndef _LIB_CADNA_NUMERIC_TYPE_IXX_
#define _LIB_CADNA_NUMERIC_TYPE_IXX_

namespace cadna{

  namespace internals{

    inline void bit_flip(float&,const unsigned int)  CADNA_ALWAYS_INLINE;
    inline void bit_flip(double&,const unsigned int) CADNA_ALWAYS_INLINE;
    
    void bit_flip(float& f,const unsigned int b){
      *((unsigned int*)&f)^=((unsigned int)b)<<31;
    }
    
    void bit_flip(double& d,const unsigned int b){
      *((unsigned long*)&d)^=((unsigned long)b)<<63;
    }

    template<typename T>
    static inline numeric_type<T>
    numeric_type_incre_operator_common(numeric_type<T>&) CADNA_ALWAYS_INLINE;

    template<typename T,typename Operator>
    numeric_type<T>
    numeric_type_prepost_operator_common(numeric_type<T>& v,Operator f){
      auto apply = [&f](T& vv,unsigned int& r){
	auto tmp = vv;
	bit_flip(tmp, r);
	vv = tmp;
	tmp = 1;
	bit_flip(tmp, r);
	f(vv,tmp);
	bit_flip(vv, r);
      };
      auto i=v;
      v.accuracy=cadna::DIGIT_NOT_COMPUTED;
      unsigned int random = _random_function();
      apply(v.x,random);
      random = _random_function();
      apply(v.y,random);
      random = 1^random;
      apply(v.z,random);
      if (config.cancel_tag){
	if (i.accuracy==cadna::DIGIT_NOT_COMPUTED || i.accuracy==cadna::RELIABLE_RESULT){
	  nb_significant_digit(i);
	}
	if (i.accuracy >=  nb_significant_digit(v)+_cancel_value){
	  instability(cadna::instability_id::CANCEL_INSTABILITY);
	}
      }
      return i;
    }

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
				   void>::type
    plusequal_minusequal_operator(numeric_type<T>&,const T2&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
				   void>::type
    plusequal_minusequal_operator(numeric_type<T>&,const numeric_type<T2>&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
			    void>::type
    plusequal_minusequal_operator(numeric_type<T>& v,const T2& a,Operator f){
      auto apply = [&a,&f](T& vv,unsigned int& r){
	auto tmp = vv;
	bit_flip(tmp, r);
	vv = tmp;
	tmp = a;
	bit_flip(tmp, r);
	f(vv,tmp);
	bit_flip(vv, r);
      };
      const auto i=v;
      v.accuracy=cadna::DIGIT_NOT_COMPUTED;
      unsigned int random = _random_function();
      apply(v.x,random);
      random = _random_function();
      apply(v.y,random);
      random = 1^random;
      apply(v.z,random);
      if (config.cancel_tag){
	if (i.accuracy==cadna::DIGIT_NOT_COMPUTED || i.accuracy==cadna::RELIABLE_RESULT){
	  nb_significant_digit(i);
	}
	if (i.accuracy >=  nb_significant_digit(v)+_cancel_value){
	  instability(cadna::instability_id::CANCEL_INSTABILITY);
	}
      }
    } // end of plusequal_minusequal_operator

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
			    void>::type
    plusequal_minusequal_operator(numeric_type<T>& v,
				  const numeric_type<T2>& a,Operator f){
      auto apply = [&f](T& vv,const T2& av,unsigned int& r){
	auto tmp = vv;
	bit_flip(tmp, r);
	vv = tmp;
	tmp = av;
	bit_flip(tmp, r);
	f(vv,tmp);
	bit_flip(vv, r);
      };
      const auto i=v;
      v.accuracy=cadna::DIGIT_NOT_COMPUTED;
      unsigned int random = _random_function();
      apply(v.x,a.x,random);
      random = _random_function();
      apply(v.y,a.y,random);
      random = 1^random;
      apply(v.z,a.z,random);
      if (config.cancel_tag){
	if (i.accuracy==cadna::DIGIT_NOT_COMPUTED || i.accuracy==cadna::RELIABLE_RESULT){
	  nb_significant_digit(i);
	}
	if (a.accuracy==cadna::DIGIT_NOT_COMPUTED || a.accuracy==cadna::RELIABLE_RESULT){
	  nb_significant_digit(a);
	}
	if ((i.accuracy < a.accuracy ? i.accuracy : a.accuracy) >=
	    nb_significant_digit(v)+_cancel_value){
	  instability(cadna::instability_id::CANCEL_INSTABILITY);
	}
      }
    } // end of plusequal_minusequal_operator

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
				   void>::type
    multequal_divequal_operator(numeric_type<T>&,const T2&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
			    void>::type
    multequal_divequal_operator(numeric_type<T>& v,const T2& a,Operator f){
      auto apply = [&a,&f](T& vv,unsigned int& r){
	auto tmp = vv;
	bit_flip(tmp, r);
	vv = tmp;
	tmp = a;
	f(vv,tmp);
	bit_flip(vv, r);
      };
      v.accuracy=cadna::DIGIT_NOT_COMPUTED;
      unsigned int random = _random_function();
      apply(v.x,random);
      random = _random_function();
      apply(v.y,random);
      random = 1^random;
      apply(v.z,random);
    } // end of multequal_divequal_operator

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
    numeric_type<T2>>::type
    plusminus_operator_leftscalar_base(const T&,const numeric_type<T2>&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
    numeric_type<T2>>::type
    plusminus_operator_leftscalar(const T&,const numeric_type<T2>&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
    numeric_type<T>>::type
    plusminus_operator_rightscalar_base(const numeric_type<T>&,const T&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
    numeric_type<T>>::type
    plusminus_operator_rightscalar(const numeric_type<T>&,const T&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
    numeric_type<promote_t<T,T2>>>::type
    plusminus_operator_base(const numeric_type<T>&,
		            const numeric_type<T2>&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
				    is_cxx_fundamental_type<T2>::value),
    numeric_type<T2>>::type
    plusminus_operator(const T&,const numeric_type<T2>&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
    numeric_type<T2>>::type
    plusminus_operator_leftscalar_base(const T& a,const numeric_type<T2>& b,Operator f){
      auto apply = [&a,&f](const T& bv,unsigned int& r){
	T2 tmp = a;
	bit_flip(tmp, r);
	T2 rv = tmp;
	tmp = bv;
	bit_flip(tmp, r);
	f(rv,tmp);
	bit_flip(rv, r);
	return rv;
      };
      numeric_type<T2> res;
      res.accuracy=cadna::DIGIT_NOT_COMPUTED;
      unsigned int random = _random_function();
      res.x = apply(b.x,random);
      random = _random_function();
      res.y = apply(b.y,random);
      random = 1^random;
      res.z = apply(b.z,random);
      return res;
    }

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
    numeric_type<T2>>::type
    plusminus_operator_leftscalar(const T& a,const numeric_type<T2>& b,Operator f){
      auto res = plusminus_operator_leftscalar_base(a,b,f);
      if (config.cancel_tag){
	if (b.accuracy==cadna::DIGIT_NOT_COMPUTED || b.accuracy==cadna::RELIABLE_RESULT)
	  nb_significant_digit(b);
	if (b.accuracy >= nb_significant_digit(res)+_cancel_value)
	  instability(cadna::instability_id::CANCEL_INSTABILITY);
      }
      return res;
    } // end of plusminus_operator_leftscalar

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
    numeric_type<T>>::type
    plusminus_operator_rightscalar_base(const numeric_type<T>& a,const T2& b,Operator f){
      auto apply = [&b,&f](const T& av,unsigned int& r){
	T tmp = av;
	bit_flip(tmp, r);
	T rv = tmp;
	tmp = b;
	bit_flip(tmp, r);
	f(rv,tmp);
	bit_flip(rv, r);
	return rv;
      };
      numeric_type<T> res;
      res.accuracy=cadna::DIGIT_NOT_COMPUTED;
      unsigned int random = _random_function();
      res.x = apply(a.x,random);
      random = _random_function();
      res.y = apply(a.y,random);
      random = 1^random;
      res.z = apply(a.z,random);
      return res;
    }

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
    numeric_type<T>>::type
    plusminus_operator_rightscalar(const numeric_type<T>& a,const T2& b,Operator f){
      auto res = plusminus_operator_rightscalar_base(a,b,f);
      if (config.cancel_tag){
	if (a.accuracy==cadna::DIGIT_NOT_COMPUTED || a.accuracy==cadna::RELIABLE_RESULT)
	  nb_significant_digit(a);
	if (a.accuracy >= 	nb_significant_digit(res)+_cancel_value)
	  instability(cadna::instability_id::CANCEL_INSTABILITY);
      }
      return res;
    }

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
    numeric_type<promote_t<T,T2>>>::type
    plusminus_operator_base(const numeric_type<T>& a,const numeric_type<T2>& b,Operator f){
      auto apply = [&b,&f](const T& av,const T2& bv,unsigned int& r){
	promote_t<T,T2> tmp = av;
	bit_flip(tmp, r);
	promote_t<T,T2> rv = tmp;
	tmp = bv;
	bit_flip(tmp, r);
	f(rv,tmp);
	bit_flip(rv, r);
	return rv;
      };
      numeric_type<promote_t<T,T2>> res;
      res.accuracy=cadna::DIGIT_NOT_COMPUTED;
      unsigned int random = _random_function();
      res.x = apply(a.x,b.x,random);
      random = _random_function();
      res.y = apply(a.y,b.y,random);
      random = 1^random;
      res.z = apply(a.z,b.z,random);
      return res;
    }

    template<typename T,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			     is_cxx_fundamental_type<T2>::value),
    numeric_type<promote_t<T,T2>>>::type
    plusminus_operator(const numeric_type<T>& a,const numeric_type<T2>& b,Operator f){
      auto res = plusminus_operator_base(a,b,f);
      if (config.cancel_tag){
	if (a.accuracy==cadna::DIGIT_NOT_COMPUTED || a.accuracy==cadna::RELIABLE_RESULT)
	  nb_significant_digit(a);
	if (b.accuracy==cadna::DIGIT_NOT_COMPUTED || b.accuracy==cadna::RELIABLE_RESULT)
	  nb_significant_digit(b);
	if ((a.accuracy < b.accuracy ? a.accuracy: b.accuracy) >=
	    nb_significant_digit(res)+_cancel_value)
	  instability(cadna::instability_id::CANCEL_INSTABILITY);
      }
      return res;
    }

    template<typename T1,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				    is_cxx_fundamental_type<T2>::value),
				   bool>::type
    comparison_operator(const numeric_type<T1>&,const T2&,Operator) CADNA_ALWAYS_INLINE;

    template<typename T1,typename T2,typename Operator>
    inline typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
				    is_cxx_fundamental_type<T2>::value),
				   bool>::type
    comparison_operator(const T1&,const numeric_type<T2>&,Operator)  CADNA_ALWAYS_INLINE;

    template<typename T1,typename T2,typename Operator>
    inline bool
    comparison_operator(const numeric_type<T1>&,
			const numeric_type<T2>&,Operator)  CADNA_ALWAYS_INLINE;

    template<typename T1,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			     is_cxx_fundamental_type<T2>::value),
			    bool>::type
    comparison_operator(const numeric_type<T1>& a,const T2& b,Operator f){
      auto res = plusminus_operator_rightscalar_base(a,b,[](T1& x,const T2& y){
	  x-=y;
	});
      const auto r = numericalnoise(res);
      if (config.branching_tag && r){
	instability(cadna::instability_id::BRANCHING_INSTABILITY);
      }
      return r || f(a.x+a.y+a.z,b+b+b);
    }

    template<typename T1,typename T2,typename Operator>
    typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			     is_cxx_fundamental_type<T2>::value),
			    bool>::type
    comparison_operator(const T1& a,const numeric_type<T2>& b,Operator f){
      auto res = plusminus_operator_leftscalar_base(a,b,[](T2& x,const T1& y){
	  x-=y;
	});
      const auto r=numericalnoise(res);
      if (config.branching_tag && r){
	instability(cadna::instability_id::BRANCHING_INSTABILITY);
      }
      return r || f(a+a+a,b.x+b.y+b.z);
    }

    template<typename T1,typename T2,typename Operator>
    bool comparison_operator(const numeric_type<T1>& a,const numeric_type<T2>& b,Operator f){
      auto res = plusminus_operator_base(a,b,[](promote_t<T1,T2>& x, const promote_t<T1,T2>& y){
	  x-=y;
	});
      const auto r=numericalnoise(res);
      if (config.branching_tag && r){
	instability(cadna::instability_id::BRANCHING_INSTABILITY);
      }
      return r || f(a.x+a.y+a.z,b.x+b.y+b.z);
    }
  } // end of namespace internals
  
  template<typename T>
  int approx_digit(const numeric_type<T>& v){
    constexpr const double cste = 3.241001342318910E-02;
    constexpr const double zero = 0;
    constexpr const double one  = 1;
    v.accuracy=RELIABLE_RESULT;
    const double xx=v.x+v.y+v.z;
    if (xx==zero) {
      if ((v.x != v.y ) || (v.x != v.z)){
	v.accuracy=0;
      }
    } else {
      const double ixx=3/xx;
      const double x0=v.x*ixx-one;
      const double x1=v.y*ixx-one;
      const double x2=v.z*ixx-one;
      if ((x0*x0+x1*x1+x2*x2) > cste){
	v.accuracy=0;
      }
    }
    return v.accuracy;
  } // end of numeric_type<T>::approx_digit

  template<typename T>
  int nb_significant_digit(const numeric_type<T>& v){
    constexpr const double cste  = 3.085466170416667;
    constexpr const double cste2 = 0.301029995663981195;
    constexpr const double zero  = 0;
    constexpr const double one   = 1;
    constexpr const double one_half = one/2;
    const double xx = v.x+v.y+v.z;
    v.accuracy=0;
    if (xx==zero){
      if ((v.x==v.y) && (v.x==v.z) ){
	v.accuracy=default_accuracy<T>::value;
      }
    } else {
      const double ixx=3/xx;
      const double x0=v.x*ixx-one;
      const double x1=v.y*ixx-one;
      const double x2=v.z*ixx-one;
      const double yy=(x0*x0+x1*x1+x2*x2)*cste;
      if (yy<=default_accuracy<T>::thresold){
	v.accuracy=default_accuracy<T>::value;
      } else {
	long exp=*((const unsigned long *)&yy);
	exp&=0x7FF0000000000000UL;
	exp>>=52;
	exp-=1023;
	const double yy2 = -exp*cste2;
	if (yy2>=zero){
	  v.accuracy=static_cast<int>((yy2+one)*one_half);
	}
      }
    }
    return v.accuracy;
  } // end of numeric_type<T>::nb_significant_digit()

  template<typename T>
  bool numericalnoise(const numeric_type<T>& v){
    constexpr const double cste = 3.241001342318910E-02;
    constexpr const double one  = 1;
    const double xx = v.x+v.y+v.z;
    const double ixx=3/xx;
    const double x0=v.x*ixx-one;
    const double x1=v.y*ixx-one;
    const double x2=v.z*ixx-one;
    return x0*x0+x1*x1+x2*x2 > cste;
  }

  template<typename T>
  bool computedzero(const numeric_type<T>& v){
    constexpr const double cste = 3.241001342318910E-02;
    constexpr const double zero = 0;
    constexpr const double one  = 1;
    const double xx = v.x+v.y+v.z;
    if (xx==zero){
      return true;
    }
    const double ixx = 3/xx;
    const double x0=v.x*ixx-one;
    const double x1=v.y*ixx-one;
    const double x2=v.z*ixx-one;
    return x0*x0+x1*x1+x2*x2 > cste ;
  } // end of numeric_type<T>::computedzero()

  template<typename T>
  template<typename T2>
  typename std::enable_if<is_cxx_fundamental_type<T2>::value,
			  numeric_type<T>&>::type
  numeric_type<T>::operator=(const T2& v){
    this->x=this->y=this->z=static_cast<T>(v);
    this->accuracy=default_accuracy<T>::value;
    return *this;
  }

  template<typename T>
  template<typename T2>
  numeric_type<T>&
  numeric_type<T>::operator=(const numeric_type<T2>& v){
    this->x=static_cast<T>(v.x);
    this->y=static_cast<T>(v.y);
    this->z=static_cast<T>(v.z);
    // #pragma message "Warning : This is inconsistent with the constructor, check required"
    // #pragma message "I expected 'std::min(v.accuracy,default_accuracy<T>::value)'"
    this->accuracy=DIGIT_NOT_COMPUTED;
    return *this;
  }

  template<typename T>
  numeric_type<T>&
  operator++(numeric_type<T>& v){
    cadna::internals::numeric_type_prepost_operator_common(v,[](T& xv,const T& yv){
	xv+=yv;
      });
    return v;
  } // end of numeric_type<T>::operator++()

  template<typename T>
  numeric_type<T>
  operator++(numeric_type<T>& v, int){
    return cadna::internals::numeric_type_prepost_operator_common(v,[](T& xv,const T& yv){
	xv+=yv;
      });
  } // end of numeric_type<T>::operator++()

  template<typename T>
  numeric_type<T>
  operator--(numeric_type<T>& v){
    cadna::internals::numeric_type_prepost_operator_common(v,[](T& xv,const T& yv){
	xv-=yv;
      });
    return v;
  } // end of numeric_type<T>::operator--()

  template<typename T>
  numeric_type<T>
  operator--(numeric_type<T>& v,int){
    return cadna::internals::numeric_type_prepost_operator_common(v,[](T& xv,const T& yv){
	xv-=yv;
      });
  } // end of numeric_type<T>::operator--()

  template<typename T>
  numeric_type<T>
  operator-(const numeric_type<T>& v){
    // #pragma message "In initial implementation this->accuracy was forgotten, seems a bug."
    numeric_type<T> r{-v.x,-v.y,-v.z};
    r.accuracy = v.accuracy;
    return r;
  }

  template<typename T>
  numeric_type<T>
  operator+(const numeric_type<T>& v){
    return v;
  }

  template<typename T,typename T2>
  typename std::enable_if<is_cxx_fundamental_type<T2>::value,
			  numeric_type<T>&>::type
  operator+=(numeric_type<T>& v,const T2& a){
    cadna::internals::plusequal_minusequal_operator(v,a,[](T& xv,const T&yv){
	xv+=yv;
      });
    return v;
  } // end of numeric_type<T>::operator+=

  template<typename T,typename T2>
  numeric_type<T>&
  operator+=(numeric_type<T>& v,const numeric_type<T2>& a){
    cadna::internals::plusequal_minusequal_operator(v,a,[](T& xv,const T&yv){
	xv+=yv;
      });
    return v;
  } // end of numeric_type<T>::operator+=

  template<typename T,typename T2>
  typename std::enable_if<is_cxx_fundamental_type<T2>::value,
			  numeric_type<T>&>::type
  operator-=(numeric_type<T>& v,const T2& a){
    cadna::internals::plusequal_minusequal_operator(v,a,[](T& xv,const T&yv){
	xv-=yv;
      });
    return v;
  } // end of numeric_type<T>::operator-=

  template<typename T,typename T2>
  numeric_type<T>&
  operator-=(numeric_type<T>& v,const numeric_type<T2>& a){
    cadna::internals::plusequal_minusequal_operator(v,a,[](T& xv,const T&yv){
	xv-=yv;
      });
    return v;
  } // end of numeric_type<T>::operator-=

  template<typename T,typename T2>
  typename std::enable_if<is_cxx_fundamental_type<T2>::value,
			  numeric_type<T>&>::type
  operator*=(numeric_type<T>& v, const T2& a){
    cadna::internals::multequal_divequal_operator(v,a,[](T& xv,const T&yv){
	xv*=yv;
      });
    return v;
  } // end of numeric_type<T>::operator*=

  template<typename T,typename T2>
  numeric_type<T>&
  operator*=(numeric_type<T>& v,const numeric_type<T2>& a){
    auto apply = [](T& vv,const T2& av,unsigned int& r){
      auto tmp = vv;
      cadna::internals::bit_flip(tmp, r);
      vv = tmp;
      tmp = av;
      vv*=tmp;
      cadna::internals::bit_flip(vv, r);
    };
    if(config.mul_tag) {
      if (v.accuracy==DIGIT_NOT_COMPUTED) approx_digit(v);
      if (v.accuracy==0){
	if (a.accuracy==DIGIT_NOT_COMPUTED) approx_digit(a);
	if (a.accuracy==0){
	  instability(instability_id::MUL_INSTABILITY);
	}
      }
    }
    v.accuracy=DIGIT_NOT_COMPUTED;
    unsigned int random = _random_function();
    apply(v.x,a.x,random);
    random = _random_function();
    apply(v.y,a.y,random);
    random = 1^random;
    apply(v.z,a.z,random);
    return v;
  } // end of numeric_type<T>::operator*=

  template<typename T,typename T2>
  typename std::enable_if<is_cxx_fundamental_type<T2>::value,
			  numeric_type<T>&>::type
  operator/=(numeric_type<T>& v,const T2& a){
    cadna::internals::multequal_divequal_operator(v,a,[](T& xv,const T&yv){
	xv/=yv;
      });
    return v;
  } // end of numeric_type<T>::operator/=

  template<typename T,typename T2>
  numeric_type<T>&
  operator/=(numeric_type<T>& v,const numeric_type<T2>& a){
    auto apply = [](T& vv,const T2& av,unsigned int& r){
      auto tmp = vv;
      cadna::internals::bit_flip(tmp, r);
      vv = tmp;
      tmp = av;
      vv/=tmp;
      cadna::internals::bit_flip(vv, r);
    };
    if(config.div_tag) {
      if (a.accuracy==DIGIT_NOT_COMPUTED) approx_digit(a);
      if (a.accuracy==0){
	instability(instability_id::DIV_INSTABILITY);
      }
    }
    v.accuracy=DIGIT_NOT_COMPUTED;
    unsigned int random = _random_function();
    apply(v.x,a.x,random);
    random = _random_function();
    apply(v.y,a.y,random);
    random = 1^random;
    apply(v.z,a.z,random);
    return v;
  } // end of numeric_type<T>::operator/=


  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
                          numeric_type<T2>>::type
  operator+(const T& a,const numeric_type<T2>& b){
    return cadna::internals::plusminus_operator_leftscalar(a,b,[](T2& x,const T& y){
	x+=y;
      });
  } // end of operator+

  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
                           numeric_type<T>>::type
  operator+(const numeric_type<T>& a,const T2& b){
    return cadna::internals::plusminus_operator_rightscalar(a,b,[](T& x,const T2& y){
	x+=y;
      });
  } // end of operator+

  template<typename T,typename T2>
  numeric_type<promote_t<T,T2>>
  operator+(const numeric_type<T>& a,const numeric_type<T2>& b){
    return cadna::internals::plusminus_operator(a,b,[](promote_t<T,T2>& x,const promote_t<T,T2>& y){
	x+=y;
      });
  } // end of operator+

  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
                          numeric_type<T2>>::type
  operator-(const T& a,const numeric_type<T2>& b){
    return cadna::internals::plusminus_operator_leftscalar(a,b,[](T2& x,const T& y){
	x-=y;
      });
  } // end of operator-

  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
                           numeric_type<T>>::type
  operator-(const numeric_type<T>& a,const T2& b){
    return cadna::internals::plusminus_operator_rightscalar(a,b,[](T& x,const T2& y){
	x-=y;
      });
  } // end of operator-

  template<typename T,typename T2>
  numeric_type<promote_t<T,T2>>
  operator-(const numeric_type<T>& a,const numeric_type<T2>& b){
    return cadna::internals::plusminus_operator(a,b,[](promote_t<T,T2>& x,const promote_t<T,T2>& y){
	x-=y;
      });
  } // end of operator-

  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
                           numeric_type<T2>>::type
  operator*(const T& a,const numeric_type<T2>& b){
    auto apply = [&a](const T2& bv,unsigned int& r){
      promote_t<T,T2> tmp = a;
      cadna::internals::bit_flip(tmp, r);
      promote_t<T,T2> rv = tmp;
      rv *= bv;
      cadna::internals::bit_flip(rv, r);
      return rv;
    };
    numeric_type<T2> res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    unsigned int random = _random_function();
    res.x = apply(b.x,random);
    random = _random_function();
    res.y = apply(b.y,random);
    random = 1^random;
    res.z = apply(b.z,random);
    return res;
  } // end of operator*

  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
                           numeric_type<T>>::type
  operator*(const numeric_type<T>& a,const T2& b){
    auto apply = [&b](const T& av,unsigned int& r){
      promote_t<T,T2> tmp = av;
      cadna::internals::bit_flip(tmp, r);
      promote_t<T,T2> rv = tmp;
      rv *= b;
      cadna::internals::bit_flip(rv, r);
      return rv;
    };
    numeric_type<T> res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    unsigned int random = _random_function();
    res.x = apply(a.x,random);
    random = _random_function();
    res.y = apply(a.y,random);
    random = 1^random;
    res.z = apply(a.z,random);
    return res;
  } // end of operator*

  template<typename T,typename T2>
  numeric_type<promote_t<T,T2>>
  operator*(const numeric_type<T>& a,const numeric_type<T2>& b){
    auto apply = [](const T& av,const T& bv,unsigned int& r){
      promote_t<T,T2> tmp = av;
      cadna::internals::bit_flip(tmp, r);
      promote_t<T,T2> rv = tmp;
      rv *= bv;
      cadna::internals::bit_flip(rv, r);
      return rv;
    };
    if(config.mul_tag) {
      if (b.accuracy==DIGIT_NOT_COMPUTED) approx_digit(b);
      if (b.accuracy==0){
	if (a.accuracy==DIGIT_NOT_COMPUTED) approx_digit(a);
	if (a.accuracy==0){
	  instability(instability_id::MUL_INSTABILITY);
	}
      }
    }
    numeric_type<promote_t<T,T2>> res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    auto random = _random_function();
    res.x = apply(a.x,b.x,random);
    random = _random_function();
    res.y = apply(a.y,b.y,random);
    random = 1^random;
    res.z = apply(a.z,b.z,random);
    return res;
  } // end of operator*

  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
    numeric_type<T2>>::type
  operator/(const T& a,const numeric_type<T2>& b){
    auto apply = [&a](const T2& bv,unsigned int& r){
      T2 tmp = a;
      cadna::internals::bit_flip(tmp, r);
      T2 rv = tmp;
      rv /= bv;
      cadna::internals::bit_flip(rv, r);
      return rv;
    };
    if(config.div_tag){
      if (b.accuracy==DIGIT_NOT_COMPUTED) approx_digit(b);
      if (b.accuracy==0){
	instability(instability_id::DIV_INSTABILITY);
      }
    }
    numeric_type<T2> res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    unsigned int random = _random_function();
    res.x = apply(b.x,random);
    random = _random_function();
    res.y = apply(b.y,random);
    random = 1^random;
    res.z = apply(b.z,random);
    return res;
  } // end of operator/

  template<typename T,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T>::value&&
			   is_cxx_fundamental_type<T2>::value),
                           numeric_type<T>>::type
  operator/(const numeric_type<T>& a,const T2& b){
    auto apply = [&b](const T& av,unsigned int& r){
      T tmp = av;
      cadna::internals::bit_flip(tmp, r);
      T rv = tmp;
      rv /= b;
      cadna::internals::bit_flip(rv, r);
      return rv;
    };
    numeric_type<T> res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    unsigned int random = _random_function();
    res.x = apply(a.x,random);
    random = _random_function();
    res.y = apply(a.y,random);
    random = 1^random;
    res.z = apply(a.z,random);
    return res;
  } // end of operator/

  template<typename T,typename T2>
  numeric_type<promote_t<T,T2>>
  operator/(const numeric_type<T>& a,const numeric_type<T2>& b){
    auto apply = [](const T& av,const T& bv,unsigned int& r){
      promote_t<T,T2> tmp = av;
      cadna::internals::bit_flip(tmp, r);
      promote_t<T,T2> rv = tmp;
      rv /= bv;
      cadna::internals::bit_flip(rv, r);
      return rv;
    };
    if(config.div_tag) {
      if (b.accuracy==DIGIT_NOT_COMPUTED) approx_digit(b);
      if (b.accuracy==0){
	instability(instability_id::DIV_INSTABILITY);
      }
    }
    numeric_type<promote_t<T,T2>> res;
    unsigned int random = _random_function();
    res.x = apply(a.x,b.x,random);
    random = _random_function();
    res.y = apply(a.y,b.y,random);
    random = 1^random;
    res.z = apply(a.z,b.z,random);
    return res;
  } // end of operator/

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator == (const numeric_type<T1>& a,const T2& b){
    auto res = cadna::internals::plusminus_operator_rightscalar_base(a,b,[](T1& x,const T2& y){
	x-=y;
      });
    return computedzero(res);
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator == (const T1& a,const numeric_type<T2>& b){
    auto res = cadna::internals::plusminus_operator_leftscalar_base(a,b,[](T2& x,const T1& y){
	x-=y;
      });
    return computedzero(res);
  }

  template<typename T1,typename T2>
  bool operator == (const numeric_type<T1>& a,const numeric_type<T2>& b){
    auto res = cadna::internals::plusminus_operator_base(a,b,[](promote_t<T1,T2>& x, const promote_t<T1,T2>& y){
	x-=y;
      });
    return computedzero(res);
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator != (const numeric_type<T1>& a,const T2& b){
    return !(a==b);
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator != (const T1& a,const numeric_type<T2>& b){
    return !(a==b);
  }

  template<typename T1,typename T2>
  bool operator != (const numeric_type<T1>& a,const numeric_type<T2>& b){
    return !(a==b);
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator >= (const numeric_type<T1>& a,const T2& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x>=y;
      });
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator >= (const T1& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x>=y;
      });
  }

  template<typename T1,typename T2>
  bool operator >= (const numeric_type<T1>& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x>=y;
      });
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),

			  bool>::type
  operator > (const numeric_type<T1>& a,const T2& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x>y;
      });
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator > (const T1& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x>y;
      });
  }

  template<typename T1,typename T2>
  bool operator > (const numeric_type<T1>& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x>y;
      });
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator <= (const numeric_type<T1>& a,const T2& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x<=y;
      });
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator <= (const T1& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x<=y;
      });
  }

  template<typename T1,typename T2>
  bool operator <= (const numeric_type<T1>& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x<=y;
      });
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator < (const numeric_type<T1>& a,const T2& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x<y;
      });
  }

  template<typename T1,typename T2>
  typename std::enable_if<(is_cxx_fundamental_type<T1>::value&&
			   is_cxx_fundamental_type<T2>::value),
			  bool>::type
  operator < (const T1& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x<y;
      });
  }

  template<typename T1,typename T2>
  bool operator < (const numeric_type<T1>& a,const numeric_type<T2>& b){
    return cadna::internals::comparison_operator(a,b,[](const T1& x, const T2& y){
	return x<y;
      });
  }

} // end of namespace cadna

#endif /* _LIB_NUMERIC_TYPE_IXX_ */
