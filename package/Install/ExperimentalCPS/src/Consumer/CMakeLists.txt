cmake_minimum_required(VERSION 4.1)

set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_INFO b80be207-778e-46ba-8080-b23bba22639e)
set(CMAKE_EXPERIMENTAL_FIND_CPS_PACKAGE    e82e467b-f997-4464-8ace-b00808fff261)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../install)
set(CMAKE_CXX_STANDARD   23)

project(Consumer)



set_property(DIRECTORY APPEND PROPERTY VS_SOLUTION_ITEMS vcpkg.json)

#set(CPS_PREFIX_PATH ${CMAKE_BINARY_DIR}/../install)
set(HelloGoodbyeWorld_DIR "C:/Users/david/devel/CMakeExperiments/main/package/Install/ExperimentalCPS/build/VS17/install/cps")
message(STATUS HelloGoodbyeWorld_DIR=${HelloGoodbyeWorld_DIR})

find_package(HelloGoodbyeWorld REQUIRED) # PATHS ${CMAKE_BINARY_DIR}/../install)

add_executable(Consumer main.cpp)


target_link_libraries(Consumer PUBLIC GoodbyeWorld)

# target_link_libraries(Consumer PUBLIC fmt::fmt)

