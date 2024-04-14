cmake_minimum_required(VERSION 3.27)
project(CS316)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS316 section5/main.cpp
        section5/test.cpp
        section6/ClientData.cpp
        section6/ClientData.h
        section6/Fig14_10.cpp
        section6/Fig14_11.cpp
        section6/Fig14_12.cpp
        section5/test2.cpp
        section7/writting_to_file.cpp
        section7/reading_from_file.cpp
        section7_g2/writting_to_file.cpp
        section7_g2/reading_from_file.cpp)
