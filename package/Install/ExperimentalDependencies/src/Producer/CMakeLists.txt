cmake_minimum_required(VERSION 4.1)

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
    FILE_SET generated_export_header
)

set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_DEPENDENCIES  1942b4fa-b2c5-4546-9385-83f254070067)

# Add the fmt dependency to the generated pakage even if not used
export(SETUP HelloWorldExport PACKAGE_DEPENDENCY doctest ENABLED ON)

install(EXPORT HelloWorldExport
    FILE HelloWorldConfig.cmake
    NAMESPACE HelloWorld::
    DESTINATION cmake/HelloWorld
    EXPORT_PACKAGE_DEPENDENCIES
)
