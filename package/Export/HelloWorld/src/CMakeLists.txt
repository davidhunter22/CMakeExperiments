cmake_minimum_required(VERSION 4.1)

include(CMakePrintHelpers)

set_property(GLOBAL PROPERTY USE_FOLDERS "On")
source_group( " "  REGULAR_EXPRESSION .*)

project(HelloWorld LANGUAGES CXX)

add_library(HelloWorld STATIC HelloWorld.cpp Config.cmake.in)

target_sources(HelloWorld PUBLIC FILE_SET HEADERS FILES HelloWorld.h)

set_target_properties(HelloWorld PROPERTIES CMAKE_CXX_STANDARD 23)

cmake_print_variables(CMAKE_INSTALL CMAKE_INSTALL_INCLUDEDIR)

# Installation

include(GNUInstallDirs)

target_include_directories(HelloWorld
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

install(TARGETS HelloWorld
    EXPORT HelloWorldTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT HelloWorldTargets
    FILE HelloWorldTargets.cmake
    NAMESPACE HelloWorld::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloWorld
)

# include the package config helpers and generate the file below
include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/HelloWorldConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloWorld
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/HelloWorldConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HelloWorld
)

