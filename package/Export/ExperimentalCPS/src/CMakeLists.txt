cmake_minimum_required(VERSION 3.26)

# variable_watch(BLURB)

include(CMakePrintHelpers)
include(${CMAKE_SOURCE_DIR}/print_target_properties.cmake)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS "On")

project(HelloWorld LANGUAGES CXX)

find_package(Microsoft.GSL CONFIG REQUIRED)
 
add_subdirectory(HelloWorld)
add_subdirectory(GoodbyeWorld)

# The new CPS way

set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_INFO b80be207-778e-46ba-8080-b23bba22639e)

install(
  TARGETS HelloWorld GoodbyeWorld
  EXPORT HelloGoodbyeWorld
  FILE_SET HEADERS 
  FILE_SET stuff
  )

install(
  PACKAGE_INFO HelloGoodbyeWorld
  EXPORT HelloGoodbyeWorld
  )

get_target_property(FOO GoodbyeWorld HEADER_SET_stuff)

message(STATUS FOO=${FOO})

print_target_properties(GoodbyeWorld)
# print_target_properties(HelloGoodbyeWorld)

# cmake_print_properties(
#     TARGETS GoodbyeWorld
#     PROPERTIES FILE_SET_HEADERS)


set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json print_target_properties.cmake)
