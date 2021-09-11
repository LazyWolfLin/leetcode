cmake_minimum_required(VERSION 3.16)

project(leetcode)

enable_testing()

# build googletest
add_subdirectory(third_party/googletest)
include(GoogleTest)

add_subdirectory(src)