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


add_executable(ch4.1 ch4.1.c)
add_executable(ch4.2 ch4.2.c)
add_executable(ch4.3 ch4.3.c)
add_executable(ch4.4 ch4.4.c)
add_executable(ch4.6 ch4.6.c)
