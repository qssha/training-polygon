cmake_minimum_required(VERSION 3.14)
project(SPLIT_STRING)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_LIB split_string.cpp)
add_library(split_string SHARED ${SOURCE_LIB})

