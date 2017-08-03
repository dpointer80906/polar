cmake_minimum_required(VERSION 3.7)
project(Coord)

set(CMAKE_CXX_STANDARD 11)

set(LIB vertices-0.1.0)

set(INCL_DIR /Users/dpointer/include/)
set(LIB_DIR /Users/dpointer/lib/)
include_directories(${INCL_DIR})
set(SRC_FILES src/Point.cpp src/Polar.cpp src/Vertices.cpp)
set(H_FILES src/Point.h src/Polar.h src/Vertices.h)

add_executable(testRunner test/testRunner.cpp ${SRC_FILES})
add_library(${LIB} SHARED ${SRC_FILES})

install(TARGETS ${LIB} DESTINATION ${LIB_DIR})
install(FILES ${H_FILES} DESTINATION ${INCL_DIR})

add_custom_target(install_${LIB}
        $(MAKE) install
        DEPENDS ${LIB}
        COMMENT "Installing ${LIB}")
