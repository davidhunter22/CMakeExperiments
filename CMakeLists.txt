cmake_minimum_required(VERSION 3.25)

message( STATUS "CMAKE_CXX_COMPILER_ID=${CMAKE_CXX_COMPILER_ID}")
message( STATUS "CMAKE_CXX_COMPILER_VERSION=${CMAKE_CXX_COMPILER_VERSION}")

# For VS project this is currently /std:c++latest
set(CMAKE_CXX_STANDARD 23)

# Generate a compile_commands.json containing machine readable compile/link command for use by other tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# We want to be able to group together projects into sub folders in the Visual Studio IDE
#   If you don't want to see sub folders and prefer everything at the top level set the to "Off"
set_property(GLOBAL PROPERTY USE_FOLDERS "On")

# By default we don't want the Visual Studio default "sources" and "headers" folders, the following put's everything directly in the project
source_group( " "  REGULAR_EXPRESSION .*)

project(cmake_experiments)

add_executable(cmake_experiments Main.cpp MSBuild.props A.props)


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(STATUS "Adding flags for Clang libc++ standard library module")
    target_compile_options(cmake_experiments PUBLIC -fmodules)

    message(STATUS "Adding flags for Clang libc++ standard library")
    target_compile_options(cmake_experiments PUBLIC -stdlib=libc++)
    target_link_options   (cmake_experiments PUBLIC -stdlib=libc++)
endif()


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # Add a user properties sheet
    set_target_properties(cmake_experiments PROPERTIES VS_USER_PROPS "${CMAKE_SOURCE_DIR}/MSBuild.props;${CMAKE_SOURCE_DIR}/A.props")

    # Adding a second property sheet fails see https://gitlab.kitware.com/cmake/cmake/-/issues/25003
    # set_target_properties(cmake_experiments PROPERTIES VS_USER_PROPS "${CMAKE_SOURCE_DIR}/A.props")

    # Build STD modules
    # See https://developercommunity.visualstudio.com/t/C-modules:-basic-example-wont-compile/1589437 for -sanatize=address blowing up when compiling std.ixx
    # See also https://developercommunity.visualstudio.com/t/Visual-Studio-always-scans-for-module-de/10385275 for my whinings
    set_target_properties(cmake_experiments PROPERTIES VS_GLOBAL_BuildStlModules "true")


    # ASAN address sanitizer
    # target_compile_options(cmake_experiments PUBLIC "-fsanitize=address")
    # This should map to <PropertyGroup><EnableASAN>false</EnableASAN></PropertyGroup> in the generated .vxcprojfile
    set_target_properties(cmake_experiments PROPERTIES VS_GLOBAL_EnableASAN "false")
endif()