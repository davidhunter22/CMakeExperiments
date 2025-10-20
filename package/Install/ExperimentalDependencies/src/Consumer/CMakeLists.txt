cmake_minimum_required(VERSION 4.1)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(Consumer)

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)


# set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/../install)
#find_package(fmt CONFIG REQUIRED)
#find_package(doctest CONFIG REQUIRED)

find_package(HelloWorld CONFIG REQUIRED PATHS ${CMAKE_BINARY_DIR}/../install/cmake)



add_executable(Consumer main.cpp)


target_link_libraries(Consumer PUBLIC HelloWorld::HelloWorld)

# target_link_libraries(Consumer PUBLIC fmt::fmt)

