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
  /*!
   * \brief add an instability handler
   * \return the id associated with the handler
   */
  CADNA_VISIBILITY_EXPORT handler_id
  add_instability_handler(const instability_handler);
  /*!
   * \brief remove the specified hander
   * \param[in] id : handler id
   */
  CADNA_VISIBILITY_EXPORT void
  remove_instability_handler(const handler_id);
  
} // end of namespace cadna

#endif /* _LIB_INSTABILITY_HANDLER_HXX_ */
