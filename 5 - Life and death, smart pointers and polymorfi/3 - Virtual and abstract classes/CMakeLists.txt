cmake_minimum_required(VERSION 3.5)

project(3_-_Virtual_and_abstract_classes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(3_-_Virtual_and_abstract_classes main.cpp material.cpp surface.cpp)
