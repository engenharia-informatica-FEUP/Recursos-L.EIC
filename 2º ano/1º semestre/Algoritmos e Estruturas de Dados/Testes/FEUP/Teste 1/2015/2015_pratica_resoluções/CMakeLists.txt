cmake_minimum_required(VERSION 3.10)
project(aeda1516_ci01)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1516_ci01 Test.cpp Escritorio.cpp Escritorio.h)

target_link_libraries(aeda1516_ci01 gtest gtest_main)