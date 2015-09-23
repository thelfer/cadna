macro(cadna_project cadna_version_major cadna_version_minor cadna_version_patch)
  project("cadna")
  set(PACKAGE_NAME "cadna")
  set(VERSION "${cadna_version_major}.${cadna_version_minor}.${cadna_version_patch}")
  set(CADNA_VERSION "${VERSION}")
  set(CADNA_WEBSITE "http://www-pequan.lip6.fr/cadna")
  # the version number.
  set(CADNA_VERSION_MAJOR "${cadna_version_major}")
  set(CADNA_VERSION_MINOR "${cadna_version_minor}")
  set(CADNA_VERSION_PATCH "${cadna_version_patch}")
endmacro(cadna_project)

macro(install_header1 file)
    install(FILES ${file}
      DESTINATION "include")
endmacro(install_header1)

macro(install_header2 dir file)
    install(FILES ${dir}/${file}
      DESTINATION "include/${dir}")
endmacro(install_header2)

macro(install_header arg1)
  if(${ARGC} GREATER 1)
    install_header2(${arg1} ${ARGN})
  else(${ARGC} GREATER 1)
    install_header1(${arg1})
  endif(${ARGC} GREATER 1)
endmacro(install_header)

macro(cadna_library name)
  if(${ARGC} LESS 2)
    message(FATAL_ERROR "cadna_library : no source specified")
  endif(${ARGC} LESS 2)
  add_library(${name} SHARED ${ARGN})
  if(WIN32)
    install(TARGETS ${name} DESTINATION bin)
  else(WIN32)
    install(TARGETS ${name}
      DESTINATION lib${LIB_SUFFIX})
  endif(WIN32)
  if(enable-static)
    add_library(${name}-static STATIC ${ARGN})
    set_target_properties(${name}-static PROPERTIES OUTPUT_NAME "${name}")
    # Now the library target "${name}-static" will be named "${name}.lib"
    # with MS tools.
    # This conflicts with the "${name}.lib" import library corresponding
    # to "${name}.dll",
    # so we add a "lib" prefix (which is default on other platforms
    # anyway):
    set_target_properties(${name}-static PROPERTIES PREFIX "lib")
    # Help CMake 2.6.x and lower (not necessary for 2.8 and above, but
    # doesn't hurt):
    set_target_properties(${name}        PROPERTIES CLEAN_DIRECT_OUTPUT 1)
    set_target_properties(${name}-static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
    set_target_properties(${name}-static PROPERTIES COMPILE_FLAGS "-D${name}_EXPORTS -DCADNA_STATIC_BUILD")
    if(WIN32)
      install(TARGETS ${name}-static DESTINATION bin)
    else(WIN32)
      install(TARGETS ${name}-static DESTINATION lib${LIB_SUFFIX})
    endif(WIN32)
  endif(enable-static)
endmacro(cadna_library)
