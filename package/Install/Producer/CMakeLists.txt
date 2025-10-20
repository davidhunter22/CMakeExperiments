cmake_minimum_required(VERSION 4.1)

include(CMakePrintHelpers)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../install)
set(CMAKE_CXX_STANDARD   23)

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)

project(Producer LANGUAGES CXX)

find_package(cityhash CONFIG REQUIRED)

add_subdirectory(HelloWorld)
add_subdirectory(GoodbyeWorld)

install(
    TARGETS HelloWorld GoodbyeWorld
    FILE_SET HEADERS
    FILE_SET stuff
)