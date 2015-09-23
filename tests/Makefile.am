AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CXXFLAGS = -O3 -g -Wunused -frounding-math -std=c++11

testdir = $(pkgdatadir)/tests
test_PROGRAMS = cadna_unit_test   \
		test1 test2 test3 \
		test4 test5 test6 \
		test7 test-complex

LDADD = -L$(top_builddir)/src/ -lcadna_cxx

cadna_unit_test_SOURCES = cadna_unit_test.cxx
test1_SOURCES = test1.cxx
test2_SOURCES = test2.cxx
test3_SOURCES = test3.cxx
test4_SOURCES = test4.cxx
test5_SOURCES = test5.cxx
test6_SOURCES = test6.cxx
test7_SOURCES = test7.cxx
test_complex_SOURCES = test-complex.cxx

TESTS=$(test_PROGRAMS)

EXTRA_DIST = CMakeLists.txt
