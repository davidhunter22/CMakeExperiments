cmake_minimum_required(VERSION 4.1)

set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_INFO b80be207-778e-46ba-8080-b23bba22639e)

include(CMakePrintHelpers)
include(GenerateExportHeader)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../install)
set(CMAKE_CXX_STANDARD   23)

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)

project(Producer LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(HelloWorld)
add_subdirectory(GoodbyeWorld)

install(
    TARGETS HelloWorld GoodbyeWorld
    EXPORT HelloWorldExport
    FILE_SET HEADERS
    FILE_SET stuff
    FILE_SET generated_export_headers
)

install(
  PACKAGE_INFO HelloGoodbyeWorld
  EXPORT HelloWorldExport
)