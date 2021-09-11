# Common
include_directories(common)
aux_source_directory(common common_files)
add_library(leetcode ${common_files})
set_target_properties(leetcode
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# Solution
aux_source_directory(solutions solution_files)

foreach(T_FILE_NAME ${solution_files})
    # use file name as executable name
    string(REGEX REPLACE "solutions\/" "" solution ${T_FILE_NAME})
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
        leetcode
        gtest_main
    )

    # add test
    gtest_discover_tests(${solution})
endforeach()