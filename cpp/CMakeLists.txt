cmake_minimum_required(VERSION 3.16)

project(leetcode)

# build googletest
add_subdirectory(third_party/googletest)
include(GoogleTest)

# Test
enable_testing()

aux_source_directory(./src/solution solution_files)
foreach(T_FILE_NAME ${solution_files})
    # use file name as executable name
    string(REGEX REPLACE "\.\/src\/solution\/" "" solution ${T_FILE_NAME})
    string(REGEX REPLACE ".cpp" "" solution ${solution})

    # add target
    add_executable(${solution} ${T_FILE_NAME})
    set_target_properties(${solution}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    )
    target_link_libraries(
        ${solution}
        gtest_main
    )

    # add test
    gtest_discover_tests(${solution})
endforeach()