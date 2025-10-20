add_library(HelloWorld STATIC HelloWorld.cpp)

target_sources(HelloWorld PUBLIC 
   FILE_SET HEADERS BASE_DIRS ${CMAKE_SOURCE_DIR} 
   FILES HelloWorld.h)

target_link_libraries(HelloWorld PUBLIC fmt::fmt)

target_compile_options(HelloWorld PRIVATE "/utf-8")
