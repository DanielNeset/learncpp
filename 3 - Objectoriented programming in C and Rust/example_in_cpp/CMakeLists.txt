cmake_minimum_required(VERSION 3.5)

project(example_in_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(example_in_cpp main.cpp)
