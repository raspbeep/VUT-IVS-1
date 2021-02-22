# CMake generated Testfile for 
# Source directory: C:/Users/pavel/Desktop/IVS/assignment
# Build directory: C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(NonEmptyQueue.Insert "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=NonEmptyQueue.Insert")
set_tests_properties(NonEmptyQueue.Insert PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.RemoveAllBackward "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=NonEmptyQueue.RemoveAllBackward")
set_tests_properties(NonEmptyQueue.RemoveAllBackward PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.RemoveAllForward "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=NonEmptyQueue.RemoveAllForward")
set_tests_properties(NonEmptyQueue.RemoveAllForward PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.Find "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=NonEmptyQueue.Find")
set_tests_properties(NonEmptyQueue.Find PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(NonEmptyQueue.Length "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=NonEmptyQueue.Length")
set_tests_properties(NonEmptyQueue.Length PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Insert "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=EmptyQueue.Insert")
set_tests_properties(EmptyQueue.Insert PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Remove "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=EmptyQueue.Remove")
set_tests_properties(EmptyQueue.Remove PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Find "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=EmptyQueue.Find")
set_tests_properties(EmptyQueue.Find PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
add_test(EmptyQueue.Length "C:/Users/pavel/Desktop/IVS/assignment/out/build/x64-Debug (default)/tdd_test.exe" "--gtest_filter=EmptyQueue.Length")
set_tests_properties(EmptyQueue.Length PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/pavel/Desktop/IVS/assignment/GoogleTest.cmake;39;add_test;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;43;GTEST_ADD_TESTS;C:/Users/pavel/Desktop/IVS/assignment/CMakeLists.txt;0;")
subdirs("googletest-build")
