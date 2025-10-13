cmake_minimum_required(VERSION 3.28)

project(module CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(module)

target_sources(module
    PRIVATE

    PUBLIC 
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
        Module.ixx
        Module.cpp
        ModulePartition.ixx
        ModulePartition.cpp
)

