cmake_minimum_required(VERSION 4.1)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(Consumer)

find_package(Microsoft.GSL CONFIG REQUIRED)

source_group( " "  REGULAR_EXPRESSION .*)

include(${CMAKE_BINARY_DIR}/../Producer/HelloGoodbyeWorldTargets.cmake)

add_executable(Consumer main.cpp)

target_link_libraries(Consumer PUBLIC HelloWorld)

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)

