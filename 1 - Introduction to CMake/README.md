## CMake in c++

Cmake is a tool one can use to help find libs and be used cross platform. A example of a CmakeList.txt, this makes a runnable file called hello.

```
cmake_minimum_required(VERSION 3.5)

project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(hello main.cpp)
```

One can also build the CMake in terminal bu using cmake, then make. It is common to do build inside a build folder in case there are extra files and folders.
If you like to have multiple executable files, one can add another `add_executable()` to the Cmake file. You can also put both the files inside the `add_executable()` if you want them to be compiled to one built final file.
