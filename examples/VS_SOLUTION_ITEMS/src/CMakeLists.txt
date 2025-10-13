cmake_minimum_required(VERSION 3.25)

project(hello_world)

add_executable(hello_world HelloWorld.cpp)

get_target_property(TARGET_TYPE hello_world TYPE)

message(STATUS "Target type ${TARGET_TYPE}")

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)