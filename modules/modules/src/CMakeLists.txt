cmake_minimum_required(VERSION 3.28)

project(ModuleExperiments)

set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

set_property(GLOBAL PROPERTY USE_FOLDERS "On")

if (MSVC)
    source_group( " "  REGULAR_EXPRESSION .*)
endif()

add_subdirectory(module)
add_subdirectory(main)

