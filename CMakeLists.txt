cmake_minimum_required(VERSION 3.7)
project(Coord)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/testPoint.cpp src/Point.cpp src/Polar.cpp src/Polar.h src/Vertices.cpp src/Vertices.h src/testPolar.cpp)
add_executable(Coord ${SOURCE_FILES})