#include "cadna/numeric_type.hxx"

extern "C" {

  using double_st = cadna::numeric_type<double>;

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_new_double_st(const double* v){
    return double_st{*v};
  }
  
  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_add(const double_st* x,
		    const double_st* y){
    return *x+*y;
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_add1(const double_st* x,
		     const double* y){
    return *x+*y;
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_add2(const double* x,
		     const double_st* y){
    return *x+*y;
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_add4(const double_st* x,
		     const int* y){
    return *x+*y;
  }
  
  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_add5(const int* x,
		     const double_st* y){
    return *x+*y;
  }
  
  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_sub(const double_st* x,
		    const double_st* y){
    return *x-*y;
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_sub1(const double_st* x,
		     const double* y){
    return *x-*y;
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_sub2(const double* x,
		     const double_st* y){
    return *x-*y;
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_sub4(const double_st* x,
		     const int* y){
    return *x-*y;
  }
  
  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_sub5(const int* x,
		     const double_st* y){
    return *x-*y;
  }
  
  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_mul(const double_st* x,
		    const double_st* y){
    return (*x)*(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_mul2(const double_st* x,
		     const double* y){
    return (*x)*(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_mul3(const double* x,
		     const double_st* y){
    return (*x)*(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_mul4(const double_st* x,
		     const int* y){
    return (*x)*(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_mul5(const int* x,
		     const double_st* y){
    return (*x)*(*y);
  }
  
  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_div(const double_st* x,
		    const double_st* y){
    return (*x)/(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_div2(const double_st* x,
		     const double* y){
    return (*x)/(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_div3(const double* x,
		     const double_st* y){
    return (*x)/(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_div4(const double_st* x,
		     const int* y){
    return (*x)/(*y);
  }

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_div5(const int* x,
		     const double_st* y){
    return (*x)/(*y);
  }

  CADNA_VISIBILITY_EXPORT int
  cadna_fortran_numerical_noise(const double_st *v){
    return cadna::numericalnoise(*v);
  }
  
} // end of extern "C"
