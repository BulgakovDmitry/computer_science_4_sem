# CMake generated Testfile for 
# Source directory: /home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler
# Build directory: /home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check_program_termination_test "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/frontend/tests/end_to_end/check_program_termination.sh")
set_tests_properties(check_program_termination_test PROPERTIES  WORKING_DIRECTORY "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/build" _BACKTRACE_TRIPLES "/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/CMakeLists.txt;12;add_test;/home/dima/Desktop/coding/coding_seminars/computer_science_4_sem/my_compiler/CMakeLists.txt;0;")
subdirs("frontend")
