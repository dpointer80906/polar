cmake_minimum_required(VERSION 3.7)
project(Coord)

set(CMAKE_CXX_STANDARD 11)

set(POINT_SOURCE_FILES src/Point.cpp src/testPoint.cpp)
add_executable(Point ${POINT_SOURCE_FILES})
set(POLAR_SOURCE_FILES src/Point.cpp src/Polar.cpp src/testPolar.cpp)
add_executable(Polar ${POLAR_SOURCE_FILES})
