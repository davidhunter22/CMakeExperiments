add_library(HelloWorld SHARED HelloWorld.cpp)

generate_export_header(HelloWorld)

target_sources(HelloWorld PUBLIC 
   FILE_SET HEADERS 
   BASE_DIRS ${CMAKE_SOURCE_DIR} 
   FILES HelloWorld.h)

target_sources(HelloWorld PUBLIC 
   FILE_SET generated_export_header TYPE HEADERS 
   BASE_DIRS ${CMAKE_BINARY_DIR}
   FILES ${CMAKE_CURRENT_BINARY_DIR}/helloworld_export.h)

target_link_libraries(HelloWorld PUBLIC fmt::fmt)


target_compile_options(HelloWorld PRIVATE "/utf-8")




