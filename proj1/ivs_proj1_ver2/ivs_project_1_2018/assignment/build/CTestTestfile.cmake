# CMake generated Testfile for 
# Source directory: /home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment
# Build directory: /home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(NonEmptyQueue.Insert "/home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.Insert")
add_test(NonEmptyQueue.RemoveAllForward "/home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.RemoveAllForward")
add_test(NonEmptyQueue.RemoveAllBackward "/home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.RemoveAllBackward")
add_test(NonEmptyQueue.Find "/home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build/tdd_test" "--gtest_filter=NonEmptyQueue.Find")
add_test(EmptyQueue.Insert "/home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build/tdd_test" "--gtest_filter=EmptyQueue.Insert")
add_test(EmptyQueue.Remove "/home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build/tdd_test" "--gtest_filter=EmptyQueue.Remove")
add_test(EmptyQueue.Find "/home/boris/Desktop/ivs_proj1_ver2/ivs_project_1_2018/assignment/build/tdd_test" "--gtest_filter=EmptyQueue.Find")
subdirs("googletest-build")
