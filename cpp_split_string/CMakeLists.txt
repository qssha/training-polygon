cmake_minimum_required(VERSION 3.14)

project(SPLIT_STRING)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_CTEST_ARGUMENTS --verbose)

enable_testing()

add_test(NAME basic_tests COMMAND test_split_string)

#set_tests_properties(basic_tests PROPERTIES ENVIRONMENT "GTEST_COLOR=1")

get_property(test_names DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY TESTS)

set_property(TEST ${test_names} PROPERTY ENVIRONMENT "GTEST_COLOR=1")
set_property(TEST ${test_names} PROPERTY TIMEOUT 10)



