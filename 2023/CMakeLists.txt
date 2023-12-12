cmake_minimum_required(VERSION 3.25)
project(AdventOfCode2023)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_executable(
        AdventOfCode2023

        src/main.cpp
        src/advent_of_code_23.hpp
        src/day01/day01.cpp
        src/day02/day02.cpp


)