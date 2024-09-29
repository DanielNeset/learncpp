cmake_minimum_required(VERSION 3.5)

project(1_-_Handle_objects_of_subclasses)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(1_-_Handle_objects_of_subclasses main.cpp material.cpp)
