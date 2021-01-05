cmake_minimum_required(VERSION 3.17)
project(pthread)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
include_directories(Files)

add_executable(pthread main.cpp src/pthreads_summator_lib.cpp src/pthreads_summator_lib.h src/generate_files.cpp src/generate_files.h)