cmake_minimum_required(VERSION 3.17)
project(Minesweeper2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Minesweeper2 board.cpp board.h game.cpp game.h io.cpp io.h main.cpp)