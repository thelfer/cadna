/*!
 * \file   backtrace.cxx
 * \brief    
 * \author THOMAS HELFER
 * \date   27 sept. 2015
 */

#include<vector>
#include<string>
#include"cadna/macros.hxx"

namespace cadna{

  /*!
   * a small structure containing the node
   * of a stack strace
   */
  struct backtrace_node{
    backtrace_node();
    backtrace_node(backtrace_node&&);
    backtrace_node(const backtrace_node&);
    backtrace_node& operator=(backtrace_node&&);
    backtrace_node& operator=(const backtrace_node&);
    /*!
     * constructor
     * \param[in] l : library
     * \param[in] f : function
     * \param[in] o : offset
     */
    backtrace_node(std::string,std::string,std::string);
    //! library in which the current function is defined
    std::string library;
    //! current function
    std::string function;
    //! current function offset
    std::string offset;
  };

  /*!
   * \return the current stack if this is possible, an empty vector
   * otherwise. 
   * \note The C++ function names are demangled if this
   * functionnality is available.
   */
  CADNA_VISIBILITY_EXPORT std::vector<backtrace_node>
  backtrace(void);
  
} // end of namespace cadna
