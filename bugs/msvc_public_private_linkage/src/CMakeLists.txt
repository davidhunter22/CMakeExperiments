cmake_minimum_required(VERSION 3.30)

project(msvc_linkage_issue)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/out")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/out")

add_subdirectory(A)
add_subdirectory(B)
add_subdirectory(C)