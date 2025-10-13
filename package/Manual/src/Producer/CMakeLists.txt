cmake_minimum_required(VERSION 4.1)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

include(CMakePrintHelpers)

set_property(GLOBAL PROPERTY USE_FOLDERS "On")

project(HelloWorld LANGUAGES CXX)

find_package(Microsoft.GSL CONFIG REQUIRED)

add_subdirectory(HelloWorld)
add_subdirectory(GoodbyeWorld)

target_include_directories(HelloWorld PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(
    TARGETS HelloWorld GoodbyeWorld
    FILE_SET HEADERS
    FILE_SET stuff
)