/*!
 * \file   logstream.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   23 sept. 2015
 */

#include<ostream>
#include"cadna/backtrace.hxx"
#include"cadna/logstream.hxx"
#include"cadna/instability_handler.hxx"

namespace cadna{

  /*!
   * \brief a internal structure used to
   * report instability to a stream
   */
  struct InstabilityReport{
    /*!
     * \param[in] o : output stream
     */
    InstabilityReport(std::ostream& o)
      :log(o)
    {} // end of InstabilityReport
    void operator()(const instability_id id){
      const auto b = backtrace();
      log << "** cadna library : " << to_string(id)
	  << " instability detected\n";
      for(const auto& p:b){
	if(!p.function.empty()){
	  log << "- " << p.function;
	  if(!p.library.empty()){
	    log << " at " << p.library;
	  }
	  if(!p.offset.empty()){
	    log << " (" << p.offset << ")";
	  }
	  log << "\n";
	}
      }
      log << "\n";
    }
    std::ostream& log;
  };
  
  handler_id
  add_logstream(std::ostream& o){
    return add_instability_handler(InstabilityReport{o});
  }
  
}
