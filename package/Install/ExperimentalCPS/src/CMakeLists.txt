cmake_minimum_required(VERSION 3.26)

# variable_watch(BLURB)

include(CMakePrintHelpers)
include(${CMAKE_SOURCE_DIR}/print_target_properties.cmake)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS "On")

project(HelloWorld LANGUAGES CXX)

find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

add_subdirectory(HelloWorld)
add_subdirectory(GoodbyeWorld)

set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json print_target_properties.cmake)


# The new CPS way

set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_INFO b80be207-778e-46ba-8080-b23bba22639e)

# Needed for export(SETUP
set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_DEPENDENCIES 1942b4fa-b2c5-4546-9385-83f254070067)

# Install a named HEADER_SET called "stuff" as well as the reular HEADER header set
install(
  TARGETS HelloWorld GoodbyeWorld
  EXPORT HelloGoodbyeWorld
  FILE_SET HEADERS 
  FILE_SET stuff
  )

# Add the fmt dependency to the generated pakage even if not used
export(SETUP HelloGoodbyeWorld PACKAGE_DEPENDENCY doctest ENABLED ON)

install(
  PACKAGE_INFO HelloGoodbyeWorld
  EXPORT HelloGoodbyeWorld
  )

# Extract the value for the "stuff" HEADER_SET
get_target_property(FOO GoodbyeWorld HEADER_SET_stuff)

print_target_properties(GoodbyeWorld)
# print_target_properties(HelloGoodbyeWorld)


