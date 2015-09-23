/*!
 * \file   instability.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   19 sept. 2015
 */

#include<stdexcept>
#include"cadna/instability.hxx"

namespace cadna{

  static unsigned long&
  get_counter(const instability_id id){
    switch(id){
    case instability_id::MATH_INSTABILITY:
      return counter.math_count;
    case instability_id::CANCEL_INSTABILITY:
      return counter.cancel_count;
    case instability_id::DIV_INSTABILITY:
      return counter.div_count;
    case instability_id::MUL_INSTABILITY:
      return counter.mul_count;
    case instability_id::POWER_INSTABILITY:
      return counter.power_count;
    case instability_id::INTRINSIC_INSTABILITY:
      return counter.intrinsic_count;
    case instability_id::BRANCHING_INSTABILITY:
      return counter.branching_count;
    }
    throw(std::runtime_error("cadna::get_counter : internal "
			     "error, unsupported instability id"));
  }
  
  // call_instability_handlers is implemented in instability_handler
  void call_instability_handlers(const instability_id) noexcept;
  
  void instability(const instability_id id) noexcept
  {
    // #pragma message "_cadan_power_tag ?"
    unsigned long& unstab = get_counter(id);
    call_instability_handlers(id);
#ifdef _OPENMP
#pragma omp atomic
#endif //_OPENMP
    unstab++;
#ifdef _OPENMP
#pragma omp atomic
#endif //_OPENMP
    _instability_detected++;
    if (_max_instability<0) return;    
    if (_instability_detected==_max_instability) {
      config.div_tag=0; 
      config.mul_tag=0;  
      config.math_tag=0; 
      config.intrinsic_tag=0; 
      config.cancel_tag=0; 
      config.branching_tag=0;
      config.div_change=1; 
      config.mul_change=1;  
      config.power_change=1;  
      config.branching_change=1;
      config.cancel_change=1; 
      config.intrinsic_change=1; 
      config.math_change=1;
      _max_instability=-2;
    }
  } 
}  // end of namespace cadna
