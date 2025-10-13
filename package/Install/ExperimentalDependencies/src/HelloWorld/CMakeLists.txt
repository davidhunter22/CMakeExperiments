source_group( " "  REGULAR_EXPRESSION .*)

add_library(HelloWorld STATIC HelloWorld.cpp)

target_sources(HelloWorld PUBLIC FILE_SET HEADERS FILES HelloWorld.h)

set_target_properties(HelloWorld PROPERTIES CMAKE_CXX_STANDARD 23)

target_link_libraries(HelloWorld PUBLIC Microsoft.GSL::GSL)
