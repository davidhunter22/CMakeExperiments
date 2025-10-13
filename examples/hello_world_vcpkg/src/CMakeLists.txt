cmake_minimum_required(VERSION 4.1)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(hello_world)

find_package(Microsoft.GSL CONFIG REQUIRED)

add_executable(hello_world HelloWorld.cpp)

target_link_libraries(hello_world PUBLIC Microsoft.GSL::GSL)
