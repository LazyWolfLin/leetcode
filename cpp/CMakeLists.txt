cmake_minimum_required(VERSION 3.10.0)
project(leetcode VERSION 0.1.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

# build googletest
add_subdirectory(deps/googletest)
include(GoogleTest)

# Common
aux_source_directory(src/common common_files)
add_library(leetcode ${common_files})
target_include_directories(leetcode PUBLIC src/common/)

# Solution
aux_source_directory(src/solutions solution_files)
add_executable(solutions ${solution_files})
target_link_libraries(solutions leetcode gtest_main)
gtest_discover_tests(solutions)
