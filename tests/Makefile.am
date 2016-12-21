AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CXXFLAGS = -O3 -g -Wunused -frounding-math -std=c++11

testdir = $(pkgdatadir)/tests
test_PROGRAMS = test-numeric-type  \
		test-typetraits    \
		test-cmath         \
		test-complex       \
		test1 test2 test3  \
		test4 test5 test6  \
		test7 test8        \
		instability

LDADD = -L$(top_builddir)/src/ -lcadna_cxx

test_numeric_type_SOURCES = test-numeric-type.cxx
test_typetraits_SOURCES = test-typetraits.cxx
test_cmath_SOURCES   = test-cmath.cxx
test_complex_SOURCES = test-complex.cxx
test1_SOURCES = test1.cxx
test2_SOURCES = test2.cxx
test3_SOURCES = test3.cxx
test4_SOURCES = test4.cxx
test5_SOURCES = test5.cxx
test6_SOURCES = test6.cxx
test7_SOURCES = test7.cxx
test8_SOURCES = test8.cxx
instability_SOURCES=instability.cxx

TESTS=$(test_PROGRAMS)

EXTRA_DIST = CMakeLists.txt
