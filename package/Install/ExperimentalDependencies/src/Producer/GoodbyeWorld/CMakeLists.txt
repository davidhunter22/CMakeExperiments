add_library(GoodbyeWorld STATIC GoodbyeWorld.cpp)

target_sources(GoodbyeWorld PUBLIC 
   FILE_SET stuff TYPE HEADERS BASE_DIRS ${CMAKE_SOURCE_DIR} 
   FILES GoodbyeWorld.h)

target_link_libraries(GoodbyeWorld PUBLIC HelloWorld)