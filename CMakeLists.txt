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
        section7_g2/reading_from_file.cpp
        section6/Fig14_13.cpp
        section8_g1/var_object.cpp
        section8_g2/test_data.cpp
        quiz/quiz5.cpp
        quiz/quiz3.cpp
        section9/sec9.cpp
)
