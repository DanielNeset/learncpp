cmake_minimum_required(VERSION 3.5)

project(2_-_heap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(2_-_heap main.cpp)
add_executable(2_-_heap2 uniquepointer.cpp)
add_executable(2_-_heap3 moveoperation.cpp)
add_executable(2_-_heap4 makeunique.cpp)
