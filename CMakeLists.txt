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

add_executable(cosine Circle/cos.c)
add_executable(print main.c)
add_executable(Shit Circle/c003.c)
add_executable(test Circle/test.c)
add_executable(str Circle/str.c)
add_executable(None practice/type.c)
add_executable(punctuation practice/punctuation.c)
add_executable(type_trans practice/type_trans.c)
add_executable(single practice/single_word.c)
add_executable(printf practice/printf.c)
add_executable(scanf practice/Scanf.c)
add_executable(scanf02 practice/scanf02.c)
add_executable(scanf03 practice/scanf03.c)
add_executable(array01 practice/array/arry01.c)
add_executable(array practice/array/array.c)
add_executable(array02 practice/array/array02.c)
add_executable(array03 practice/array/array03.c)
add_executable(array04 practice/array/array04.c)
add_executable(array05 practice/array/array05.c)
add_executable(array06 practice/array/array06.c)
add_executable(array07 practice/array/array07.c)
add_executable(array08 practice/array/array08.c)
add_executable(array09 practice/array/array09.c)
add_executable(array10 practice/array/array10.c)
add_executable(array11 practice/array/array11.c)
add_executable(array12 practice/array/array12.c)
add_executable(array13 practice/array/array13.c)
add_executable(array14 practice/array/array14.c)
add_executable(array15 practice/array/array15.c)
add_executable(array16 practice/array/array16.c)
add_executable(array17 practice/array/array17.c)
add_executable(array18 practice/array/array18.c)
add_executable(array19 practice/array/array19.c)
add_executable(func01 Function/func01.c)
add_executable(func02 Function/func02.c)
add_executable(func03 Function/func03.c)
add_executable(func04 Function/func04.c)
add_executable(func05 Function/func05.c)
add_executable(func06 Function/func06.c)
add_executable(func07 Function/func07.c)
add_executable(func08 Function/func08.c)
add_executable(func09 Function/func09.c)
add_executable(func10 Function/func10.c)
add_executable(func11 Function/func11.c)
add_executable(func12 Function/func12.c)
add_executable(func13 Function/func13.c)
add_executable(func14 Function/func14.c)
add_executable(func15 Function/func15.c)



