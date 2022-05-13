# CMake generated Testfile for 
# Source directory: /home/olga/tp_labs/lab05
# Build directory: /home/olga/tp_labs/lab05/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit_tests "/home/olga/tp_labs/lab05/cmake-build-debug/tests")
set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "/home/olga/tp_labs/lab05/CMakeLists.txt;42;add_test;/home/olga/tp_labs/lab05/CMakeLists.txt;0;")
subdirs("banking")
