/*!
 * \file   instability_handler.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   19 sept. 2015
 */

#ifndef _LIB_INSTABILITY_HANDLER_HXX_
#define _LIB_INSTABILITY_HANDLER_HXX_

#include<functional>
#include"cadna/macros.hxx"
#include"cadna/global.hxx"

namespace cadna{

  //! a simple alias
  using instability_handler = std::function<void(const instability_id)>;
  
  CADNA_VISIBILITY_EXPORT void
  set_instability_handler(const instability_handler);
  
} // end of namespace cadna

#endif /* _LIB_INSTABILITY_HANDLER_HXX_ */
