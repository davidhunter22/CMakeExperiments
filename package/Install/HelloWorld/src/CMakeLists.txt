cmake_minimum_required(VERSION 4.1)

set(CMAKE_INSTALL_PREFIX "../install")

include(CMakePrintHelpers)

set_property(GLOBAL PROPERTY USE_FOLDERS "On")
source_group( " "  REGULAR_EXPRESSION .*)

project(HelloWorld LANGUAGES CXX)

add_library(HelloWorld STATIC HelloWorld.cpp Config.cmake.in)

target_sources(HelloWorld PUBLIC FILE_SET HEADERS FILES HelloWorld.h)

set_target_properties(HelloWorld PROPERTIES CMAKE_CXX_STANDARD 23)

cmake_print_variables(CMAKE_INSTALL CMAKE_INSTALL_INCLUDEDIR)

# Installation

target_include_directories(HelloWorld
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

# Install files, the EXPORT "names" this set of imports
install(TARGETS HelloWorld
    EXPORT HelloWorldExport
    FILE_SET HEADERS
)

# Create the CMake file that consumers will import
install(EXPORT HelloWorldExport
    FILE HelloWorldExport.cmake
    NAMESPACE HelloWorld::
    DESTINATION cmake
)

# Include the package config helpers and generate the file below
# This is done to allow find_package dependecies to be added
include(CMakePackageConfigHelpers)

# Create the config file from the template input file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/HelloWorldConfig.cmake"
  INSTALL_DESTINATION Foo
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/HelloWorldConfig.cmake" DESTINATION cmake)

