cmake_minimum_required(VERSION 3.6)
project(hashcode2017)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/solution_random.cpp src/solution_trending_today.cpp src/solution_videos_worth_spreading.cpp src/global.h src/domain.cpp)
add_executable(hashcode2017 ${SOURCE_FILES})
