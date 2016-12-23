#include<cstdint>
#include "cadna/numeric_type.hxx"

#define DEFINE_CADNA_FORTRAN_OPERTOR_DECL(TYPE,OP)			\
  CADNA_VISIBILITY_EXPORT TYPE						\
  cadna_fortran_ ## TYPE ## _ ## OP (const TYPE*,const TYPE*);		\
  CADNA_VISIBILITY_EXPORT TYPE						\
  cadna_fortran_ ## TYPE ## _ ## OP ## 1(const TYPE*,const double*);	\
  CADNA_VISIBILITY_EXPORT TYPE						\
  cadna_fortran_ ## TYPE ## _ ## OP ## 2(const double*,const TYPE*);	\
  CADNA_VISIBILITY_EXPORT TYPE						\
  cadna_fortran_ ## TYPE ## _ ## OP ## 3(const TYPE*,const int*);	\
  CADNA_VISIBILITY_EXPORT TYPE						\
  cadna_fortran_ ## TYPE ## _ ## OP ## 4(const int*,const TYPE*)

#define DEFINE_CADNA_FORTRAN_OPERTOR_INPL(TYPE,OP,OP2)			        \
  TYPE cadna_fortran_ ## TYPE ## _ ## OP (const TYPE* x,const TYPE* y){         \
    return (*x) OP2 (*y);                                                       \
  }									        \
  TYPE cadna_fortran_ ## TYPE ## _ ## OP ## 1(const TYPE*   x,const double* y){ \
    return (*x) OP2 (*y);                                                       \
  }									        \
  TYPE cadna_fortran_ ## TYPE ## _ ## OP ## 2(const double* x,const TYPE* y){   \
    return (*x) OP2 (*y);                                                       \
  }									        \
  TYPE cadna_fortran_ ## TYPE ## _ ## OP ## 3(const TYPE*   x,const int* y){    \
    return (*x) OP2 (*y);                                                       \
  }									        \
  TYPE cadna_fortran_ ## TYPE ## _ ## OP ## 4(const int*    x,const TYPE* y){   \
    return (*x) OP2 (*y);                                                       \
  }

extern "C" {

  using double_st = cadna::numeric_type<double>;

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_double_st_new(const double*);

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_double_st_new2(const float*);

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_double_st_new3(const int32_t*);

  CADNA_VISIBILITY_EXPORT double_st 
  cadna_fortran_double_st_new4(const int64_t*);

  CADNA_VISIBILITY_EXPORT void 
  cadna_fortran_double_st_assign(double_st *,
				  const double*);

  CADNA_VISIBILITY_EXPORT void 
  cadna_fortran_double_st_assign2(double_st *,
				  const float*);

  CADNA_VISIBILITY_EXPORT void 
  cadna_fortran_double_st_assign3(double_st *,
				  const int32_t*);

  CADNA_VISIBILITY_EXPORT void 
  cadna_fortran_double_st_assign4(double_st *,
				  const int64_t*);
  
  CADNA_VISIBILITY_EXPORT int
  cadna_fortran_double_st_numerical_noise(const double_st *);

  CADNA_VISIBILITY_EXPORT int
  cadna_fortran_double_st_computedzero(const double_st *);

  CADNA_VISIBILITY_EXPORT int
  nb_significant_digit(const double_st*);

  CADNA_VISIBILITY_EXPORT int
  approx_digit(const double_st*);
    
  DEFINE_CADNA_FORTRAN_OPERTOR_DECL(double_st,add);
  DEFINE_CADNA_FORTRAN_OPERTOR_DECL(double_st,sub);
  DEFINE_CADNA_FORTRAN_OPERTOR_DECL(double_st,mul);
  DEFINE_CADNA_FORTRAN_OPERTOR_DECL(double_st,div);

  double_st cadna_fortran_double_st_new(const double* v){
    return double_st{*v};
  }

  double_st cadna_fortran_double_st_new2(const float* v){
    return double_st{*v};
  }
 
  double_st cadna_fortran_double_st_new3(const int32_t* v){
    return double_st{*v};
  }

  double_st cadna_fortran_double_st_new4(const int64_t* v){
    return double_st{*v};
  }  

  void cadna_fortran_double_st_assign(double_st* self,
				       const double* src){
    *self = *src;
  }

  void cadna_fortran_double_st_assign2(double_st* self,
				       const float* src){
    *self = *src;
  }
 
  void cadna_fortran_double_st_assign3(double_st* self,
				       const int32_t* src){
    *self = *src;
  }

  void cadna_fortran_double_st_assign4(double_st* self,
				       const int64_t* src){
    *self = *src;
  }  
  
  int cadna_fortran_double_st_numerical_noise(const double_st *v){
    // convert to int as bool is not supported in C
    return cadna::numericalnoise(*v) ? 1 :0;
  }

  int cadna_fortran_double_st_computedzero(const double_st *v){
    // convert to int as bool is not supported in C
    return cadna::computedzero(*v) ? 1 :0;
  }
  
  int nb_significant_digit(const double_st* v){
    return nb_significant_digit(*v);
  }

  int approx_digit(const double_st* v){
    return approx_digit(*v);
  }
  
  DEFINE_CADNA_FORTRAN_OPERTOR_INPL(double_st,add,+)
  DEFINE_CADNA_FORTRAN_OPERTOR_INPL(double_st,sub,-)
  DEFINE_CADNA_FORTRAN_OPERTOR_INPL(double_st,mul,*)
  DEFINE_CADNA_FORTRAN_OPERTOR_INPL(double_st,div,/)

} // end of extern "C"
