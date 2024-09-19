cmake_minimum_required(VERSION 3.5)

project(example_in_c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

add_executable(example_in_c main.c)
