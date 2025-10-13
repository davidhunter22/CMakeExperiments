project(module CXX)

add_library(module)

if (MSVC)
    source_group( " "  REGULAR_EXPRESSION .*)
endif()

target_sources(module
  PRIVATE
    Module.cpp
    ModulePartition1.cpp
    ModulePartition2.cpp
)

target_sources(module
  PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    Module.ixx
    ModulePartition1.ixx
    ModulePartition2.ixx
)

