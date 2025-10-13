cmake_minimum_required(VERSION 3.25)

project(hello_world)

set(CMAKE_CXX_STANDARD 23)

set_property(GLOBAL PROPERTY USE_FOLDERS "On")


add_subdirectory(HelloWorldLib)
add_subdirectory(HelloWorldApp)

