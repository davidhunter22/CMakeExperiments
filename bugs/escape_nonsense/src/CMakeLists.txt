cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 26)
source_group( " "  REGULAR_EXPRESSION .*)

project(hello_world)

add_executable(hello_world HelloWorld.cpp Foo.txt Foo.out)

set_target_properties(hello_world PROPERTIES CXX_SCAN_FOR_MODULES true)

# set(filename flurb)
#
# add_custom_command(
#     TARGET hello_world
#     COMMAND  wsl --cd ${CMAKE_CURRENT_SOURCE_DIR} sed s=\/\/\ @@protoc_insertion_point\(includes\)=\#include\ \"${filename}.h\"= Foo.txt > ${CMAKE_CURRENT_SOURCE_DIR}/Foo.out
#     COMMENT  Stuff
#     VERBATIM)
