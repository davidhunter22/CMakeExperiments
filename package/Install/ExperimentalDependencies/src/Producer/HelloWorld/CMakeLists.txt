add_library(HelloWorld SHARED HelloWorld.cpp)

generate_export_header(HelloWorld)

# target_sources(HelloWorld PUBLIC 
#    FILE_SET HEADERS 
#    BASE_DIRS 
#        ${CMAKE_SOURCE_DIR} 
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> 
#        $<INSTALL_INTERFACE:${CMAKE_BINARY_DIR}>
#    FILES HelloWorld.h ${CMAKE_CURRENT_BINARY_DIR}/helloworld_export.h)

target_sources(HelloWorld PUBLIC 
   FILE_SET HEADERS 
   BASE_DIRS 
       ${CMAKE_SOURCE_DIR} 
   FILES HelloWorld.h)

target_sources(HelloWorld PUBLIC 
   FILE_SET generated_export_headers 
   TYPE HEADERS
   BASE_DIRS $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/HelloWorld>
   FILES ${CMAKE_BINARY_DIR}/HelloWorld/helloworld_export.h)

# target_include_directories(HelloWorld PUBLIC ${CMAKE_BINARY_DIR}/HelloWorld)

target_compile_options(HelloWorld PRIVATE "/utf-8")
target_link_libraries(HelloWorld PUBLIC fmt::fmt)
