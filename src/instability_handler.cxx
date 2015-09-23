/*!
 * \file   instability_handler.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   19 sept. 2015
 */

#include<map>
#include<mutex>
#include<cstdlib>
#include<iostream>
#include<stdexcept>
#include"cadna/instability_handler.hxx"

namespace cadna{

  void call_instability_handlers(const instability_id id) noexcept;
  
  static std::map<handler_id,instability_handler> handlers;
  static handler_id max_handlers_id = 0u;
  
  handler_id
  add_instability_handler(const instability_handler h){
    static std::mutex m;
    std::lock_guard<std::mutex> lock(m);
    if(!h){
      throw(std::runtime_error("set_instability_handler : "
			       "uninitialized handler"));
    }
    if(!handlers.insert({max_handlers_id,h}).second){
      throw(std::runtime_error("set_instability_handler : "
			       "internal error"));
    }
    return max_handlers_id++;
  }

  void remove_instability_handler(const handler_id id){
    static std::mutex m;
    std::lock_guard<std::mutex> lock(m);
    const auto p = handlers.find(id);
    if(p==handlers.end()){
      throw(std::runtime_error("set_instability_handler : "
			       "unknown handler id"));
    }
    handlers.erase(p);
  }
  
  void
  call_instability_handlers(const instability_id id) noexcept{
    try{
      for(auto& h : handlers){
	(h.second)(id);
      }
    } catch(std::exception& e){
      std::cerr << "call_instability_handlers : an handler "
		<< "has thrown an exception: this is forbidden\n"
		<< e.what() << std::endl;
      ::exit(EXIT_FAILURE);
    } catch(...){
      std::cerr << "call_instability_handlers : an handler "
		<< "has thrown an exception: this is forbidden"
		<< std::endl;
      ::exit(EXIT_FAILURE);
    }
  }

} // end of namespace cadna
