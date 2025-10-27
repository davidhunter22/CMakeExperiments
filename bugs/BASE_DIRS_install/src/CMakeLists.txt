cmake_minimum_required(VERSION 4.1)

include(GenerateExportHeader)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../install)
set(CMAKE_CXX_STANDARD   23)

project(Producer LANGUAGES CXX)

add_subdirectory(HelloWorld)

install(
    TARGETS HelloWorld
    EXPORT HelloWorldExport
    FILE_SET HEADERS
    FILE_SET generated_export_headers  
)

set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_DEPENDENCIES  1942b4fa-b2c5-4546-9385-83f254070067)

install(EXPORT HelloWorldExport
    FILE HelloWorldConfig.cmake
    NAMESPACE HelloWorld::
    DESTINATION cmake
    EXPORT_PACKAGE_DEPENDENCIES
)
