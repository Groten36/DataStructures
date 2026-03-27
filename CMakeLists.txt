cmake_minimum_required(VERSION 3.28.3)
project(DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructures main.cpp
        DynamicArray.cpp
        DynamicArray.h
        Stack.cpp
        Stack.h)

target_compile_options(DataStructures PRIVATE
    -Wall
    -Wextra
    -Werror
)
