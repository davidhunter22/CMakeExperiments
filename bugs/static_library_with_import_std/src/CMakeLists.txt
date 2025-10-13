# Import std with Cmake 4.2 ( actuall main branch at some point during development) did not work

cmake_minimum_required(VERSION 4.1)

project(hello_world)

add_library(hello_world STATIC HelloWorld.cpp)

target_compile_features(hello_world PUBLIC cxx_std_23)