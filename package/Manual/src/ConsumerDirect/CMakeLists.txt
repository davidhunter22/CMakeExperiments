cmake_minimum_required(VERSION 4.1)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(Consumer)

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)

find_package(fmt CONFIG REQUIRED)

add_executable(Consumer main.cpp)

# This is the stuff the include and link to the external library
set(ProducerBaseDir ${CMAKE_BINARY_DIR}/../install)
target_include_directories(Consumer PUBLIC ${ProducerBaseDir}/include)
target_link_directories(Consumer PUBLIC ${ProducerBaseDir}/lib)
target_link_libraries(Consumer PUBLIC HelloWorld)
target_link_libraries(Consumer PUBLIC fmt::fmt)
