/*!
 * \file   instability_handler.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   19 sept. 2015
 */

#include<vector>
#include<stdexcept>
#include"cadna/instability_handler.hxx"

namespace cadna{

  static std::vector<instability_handler> handlers;
  
  void
  set_instability_handler(instability_handler h){
    if(!h){
      throw(std::runtime_error("set_instability_handler : "
			       "uninitialized handler"));
    }
    handlers.push_back(h);
  }

  void
  call_instability_handlers(const instability_id id){
    for(auto& h : handlers){
      h(id);
    }
  }
  
} // end of namespace cadna
