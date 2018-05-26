cmake_minimum_required(VERSION 3.9)
project(openbeard)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++1z -O0 -DDEBUG=1")
set(SOURCE_FILES main.cpp libopenbeard/OpenBeardFunc.h libopenbeard/OpenBeardFunc.cpp)

add_executable(openbeard main.cpp ${SOURCE_FILES})
