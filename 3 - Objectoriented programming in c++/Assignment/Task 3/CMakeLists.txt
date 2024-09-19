cmake_minimum_required(VERSION 3.5)

project(Task_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(Task_3 main.cpp commodity.cpp)
