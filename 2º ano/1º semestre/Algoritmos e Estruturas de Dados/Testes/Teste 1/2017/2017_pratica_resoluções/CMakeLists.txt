cmake_minimum_required(VERSION 3.10)
project(aeda1718_ci01)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1718_ci01 Test.cpp Car.cpp Car.h Garage.h)

target_link_libraries(aeda1718_ci01 gtest gtest_main)