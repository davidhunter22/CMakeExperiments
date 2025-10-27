add_library(HelloWorld SHARED HelloWorld.cpp)

include(CMakePrintHelpers)

generate_export_header(HelloWorld)

target_sources(HelloWorld PUBLIC 
   FILE_SET HEADERS 
   BASE_DIRS ${CMAKE_SOURCE_DIR}
   FILES HelloWorld.h)

cmake_print_variables(CMAKE_SOURCE_DIR)


target_sources(HelloWorld PUBLIC 
   FILE_SET generated_export_headers  
   TYPE HEADERS
   BASE_DIRS ${CMAKE_BINARY_DIR}
   FILES ${CMAKE_CURRENT_BINARY_DIR}/helloworld_export.h)  

# # Would be nice to ge rid of this line
target_include_directories(HelloWorld PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

# cmake_print_properties(
#     TARGETS HelloWorld 
#     PROPERTIES 
#         HEADER_SET HEADER_SETS HEADER_DIRS 
#         HEADER_DIRS_generated_export_headers
#         INCLUDE_DIRECTORIES 
#         INTERFACE_INCLUDE_DIRECTORIES
# )

