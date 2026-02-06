cmake_minimum_required(VERSION 3.28)
project(bistroMatic VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

#include_directories(src/app src/Command src/Operands src/Parser)

add_subdirectory(src)