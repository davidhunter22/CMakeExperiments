cmake_minimum_required(VERSION 4.1)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

include(CMakePrintHelpers)

set_property(GLOBAL PROPERTY USE_FOLDERS "On")


project(HelloWorld LANGUAGES CXX)

find_package(Microsoft.GSL CONFIG REQUIRED)

add_subdirectory(HelloWorld)
add_subdirectory(GoodbyeWorld)

# Installation

set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_DEPENDENCIES  1942b4fa-b2c5-4546-9385-83f254070067)

target_include_directories(HelloWorld
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

export(TARGETS HelloWorld GoodbyeWorld
    FILE HelloGoodbyeWorldTargets.cmake
)

# Add the fmt dependency to the generated pakage even if not used
#export(SETUP HelloWorldTargets PACKAGE_DEPENDENCY doctest ENABLED ON)
#
#install(EXPORT HelloWorldTargets
#    NAMESPACE HelloWorld::
#    DESTINATION cmake/HelloWorld
#    EXPORT_PACKAGE_DEPENDENCIES
#)
