cmake_minimum_required(VERSION 3.12)
project(eight_queens)

set(CMAKE_CXX_STANDARD 14)

add_executable(eight_queens main.cpp Queen.cpp Queen.h)