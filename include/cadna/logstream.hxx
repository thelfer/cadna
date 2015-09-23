/*!
 * \file   logstream.hxx
 * \brief    
 * \author THOMAS HELFER
 * \date   23 sept. 2015
 */

#ifndef _LIB_CADNA_LOGSTREAM_HXX_
#define _LIB_CADNA_LOGSTREAM_HXX_

#include<iosfwd>
#include"cadna/global.hxx"

namespace cadna{

  /*!
   * \brief add a new instability handler which reports the detection
   * of an instability to the given stream. The user is in charge of
   * managing the life time of the stream.
   * \param[in,out] o : output stream
   */
  CADNA_VISIBILITY_EXPORT handler_id
  add_logstream(std::ostream&);
  
} // end of namespace cadna

#endif /* _LIB_CADNA_LOGSTREAM_HXX_ */
