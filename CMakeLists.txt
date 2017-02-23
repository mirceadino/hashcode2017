cmake_minimum_required(VERSION 3.6)
project(hashcode2017)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/solution_random.cpp src/global.h src/domain.cpp)
add_executable(hashcode2017 ${SOURCE_FILES})
