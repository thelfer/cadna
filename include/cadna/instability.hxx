/*!
 * \file   instability.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   12 sept. 2015
 */

#ifndef _LIB_CADNA_INSTABILITY_HXX_
#define _LIB_CADNA_INSTABILITY_HXX_

#include "cadna/macros.hxx"
#include "cadna/global.hxx"

namespace cadna{

  /*!
   * \brief function called when an instability is detected
   * \param[in] id : instability id
   */
  CADNA_VISIBILITY_EXPORT void
  instability(const instability_id) noexcept;

} // end of namespace cadna

#endif /* _LIB_CADNA_INSTABILITY_HXX_ */
