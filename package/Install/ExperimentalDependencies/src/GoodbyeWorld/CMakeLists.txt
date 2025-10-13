source_group( " "  REGULAR_EXPRESSION .*)

add_library(GoodbyeWorld STATIC GoodbyeWorld.cpp)

target_sources(GoodbyeWorld PUBLIC FILE_SET stuff TYPE HEADERS FILES GoodbyeWorld.h)

set_target_properties(GoodbyeWorld PROPERTIES CMAKE_CXX_STANDARD 23)

target_link_libraries(GoodbyeWorld PUBLIC HelloWorld)