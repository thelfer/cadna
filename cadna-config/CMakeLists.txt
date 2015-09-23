include_directories("${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_BINARY_DIR}/cadna-config")

configure_file(${PROJECT_SOURCE_DIR}/cadna-config/cadna-config.hxx.in
               ${PROJECT_BINARY_DIR}/cadna-config/cadna-config.hxx)

add_executable(cadna-config cadna-config.cxx)

install(TARGETS cadna-config DESTINATION bin)
