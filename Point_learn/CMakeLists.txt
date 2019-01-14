project(MyClion C CXX)

#set(CMAKE_C_STANDARD 99)
SET(CMAKE_BUILE_TYPE DEBUG)
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")


#加在add_executable(...)之前就好了
include_directories(
        # kernel headers
        "./include/"
)
cmake_minimum_required(VERSION 3.6)   # CMake version check
#project(simple_example)               # Create project "simple_example"
#set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

#set(SOURCE_FILES main.cpp)            # Add main.cpp file of project root directory as source file
#add_executable(simple_example ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable

add_executable(case01 case01.c)
add_executable(case011 case01_1.cpp)
add_executable(case02 case02.cpp)
add_executable(case03 case03.cpp)
add_executable(case04 case04.cpp)
add_executable(case05 case05.cpp)
add_executable(case06 case06.cpp)
add_executable(case07 case07.cpp)
add_executable(case08 case08.cpp)

