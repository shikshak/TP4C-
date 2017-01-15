cmake_minimum_required(VERSION 3.6)
project(TP4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES bin/analog.cpp bin/Fichier.cpp bin/Fichier.h)
add_executable(TP4 ${SOURCE_FILES})