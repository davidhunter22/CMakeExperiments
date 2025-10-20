add_library(HelloWorld STATIC HelloWorld.cpp)

# target_sources(HelloWorld PUBLIC FILE_SET HEADERS BASE_DIRS HelloWorld FILES HelloWorld.h)

target_sources(HelloWorld PUBLIC FILE_SET HEADERS FILES HelloWorld.h)

target_link_libraries(HelloWorld PUBLIC cityhash)

target_compile_options(HelloWorld PRIVATE "/utf-8")
