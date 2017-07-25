cmake_minimum_required(VERSION 3.7)
project(Coord)

set(CMAKE_CXX_STANDARD 11)

set(INCL_DIR_LOCAL /Users/dpointer/include/)
include_directories(${INCL_DIR_LOCAL})

add_executable(testRunner test/testRunner.cpp src/Point.cpp src/Polar.cpp src/Vertices.cpp)
