project(MyClion C)

set(CMAKE_C_STANDARD 99)
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

add_executable(ch1.1 CH1/ch1.1.c)
add_executable(ch1.2 CH1/ch1.2.c)
add_executable(ch2.1 CH2/ch2.1.c)
add_executable(ch2.2 CH2/ch2.2.c)
add_executable(ch2.3 CH2/ch2.3.c)
add_executable(ch2.4 CH2/ch2.4.c)
add_executable(ch3.1 CH3/ch3.1.c)
add_executable(ch3.2 CH3/ch3.2.c)
add_executable(ch3.3 CH3/ch3.3.c)

