cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include_directories(${PROJECT_SOURCE_DIR}/include)
#link_directories(${PROJECT_SOURCE_DIR}/src)

add_executable (test_split_string test_split_string.cpp)
target_link_libraries (test_split_string
                       split_string
                       gtest
                       )
