cmake_minimum_required(VERSION 3.17)
project(ClassProject)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(ClassProject main.cpp Tests/rational.cpp Tests/rational.hpp Tests/test.cpp)
target_link_libraries(ClassProject gtest gtest_main)