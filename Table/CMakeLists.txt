cmake_minimum_required(VERSION 3.17)
project(Table)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(Table main.cpp Tests/table.cpp Tests/table.hpp Tests/test.cpp)
target_link_libraries(Table gtest gtest_main)