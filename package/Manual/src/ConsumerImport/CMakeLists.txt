cmake_minimum_required(VERSION 4.1)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(Consumer)

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)

find_package(fmt CONFIG REQUIRED)

add_executable(Consumer main.cpp)


# Imported target

add_library(HelloWorldLib STATIC IMPORTED)

set(ProducerBaseDir ${CMAKE_BINARY_DIR}/../install)
set_target_properties(HelloWorldLib PROPERTIES IMPORTED_LOCATION ${ProducerBaseDir}/lib/HelloWorld.lib)
target_include_directories(HelloWorldLib INTERFACE ${ProducerBaseDir}/include)

target_link_libraries(Consumer PUBLIC HelloWorldLib)

target_link_libraries(Consumer PUBLIC fmt::fmt)

