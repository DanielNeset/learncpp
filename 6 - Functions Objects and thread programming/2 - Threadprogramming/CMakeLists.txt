cmake_minimum_required(VERSION 3.5)

project(2_-_Threadprogramming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(2_-_Threadprogramming main.cpp)
add_executable(2_-_Threadprogramming2 example2.cpp)
add_executable(2_-_Threadprogramming3 example3mutex.cpp)
add_executable(2_-_Threadprogramming4 singelton.cpp)
add_executable(2_-_Threadprogramming5 referencesingelton.cpp)
add_executable(2_-_Threadprogramming6 asynchronous.cpp)
target_link_libraries(2_-_Threadprogramming6 ${Boost_LIBRARIES})
add_executable(2_-_Threadprogramming7 networkapp.cpp)
target_link_libraries(2_-_Threadprogramming7 ${Boost_LIBRARIES})
