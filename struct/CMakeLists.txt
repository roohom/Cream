project(MyClion C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_BUILE_TYPE DEBUG)
SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")


#加在add_executable(...)之前就好了
include_directories(
        # kernel headers
        "./include/"
)
cmake_minimum_required(VERSION 3.6)

add_executable(struct01 struct01.c)
add_executable(struct02 struct02.c)
add_executable(struct03 struct03.c)
add_executable(struct04 struct04.c)
add_executable(struct05 timeUpdate.c)
add_executable(struct06 struct06.c)
add_executable(struct07 struct07.c)
add_executable(struct08 practice01.c)
