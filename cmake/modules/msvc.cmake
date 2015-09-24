include(cmake/modules/OptimizeForArchitecture.cmake)

cadna_enable_cxx_compiler_flag(COMPILER_CXXFLAGS "MD")
cadna_enable_cxx_compiler_flag(COMPILER_CXXFLAGS "EHsc")

cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "W4")
#4251 : warning about export of STL classes
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4251")
#4710 : warning function not being inlined
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4710")
#4514 : warning inline function was not used and was removed
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4514")
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4275")
#4250 : inheritance via dominance
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4250")
#4127 : conditional expression is constant
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4127")
#4244 : conversion
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4244")
#4996 : conversion
cadna_enable_cxx_compiler_flag(COMPILER_WARNINGS  "wd4996")

# remove a warning about deprecated symbol
set(COMPILER_FLAGS "-D_CRT_SECURE_NO_WARNINGS ${COMPILER_FLAGS}")
set(COMPILER_FLAGS "-D_SCL_SECURE_NO_WARNINGS ${COMPILER_FLAGS}")
set(OPTIMISATION_FLAGS "/O2 -DNDEBUG ${OPTIMISATION_FLAGS}")

# optimise build
OptimizeForArchitecture()