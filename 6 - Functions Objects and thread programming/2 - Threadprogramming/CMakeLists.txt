cmake_minimum_required(VERSION 3.5)

project(2_-_Threadprogramming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(2_-_Threadprogramming main.cpp)
add_executable(2_-_Threadprogramming2 example2.cpp)
add_executable(2_-_Threadprogramming3 example3mutex.cpp)
