cmake_minimum_required(VERSION 3.5)

project(Task_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})


add_executable(Task_2 main.cpp)
target_link_libraries(Task_2 ${Boost_LIBRARIES})
