cmake_minimum_required(VERSION 3.1)

project(oppussing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(coating_test covering_test.cpp covering.cpp surface.cpp)

