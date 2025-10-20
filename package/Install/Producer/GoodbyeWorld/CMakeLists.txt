add_library(GoodbyeWorld STATIC GoodbyeWorld.cpp)

target_sources(GoodbyeWorld PUBLIC FILE_SET stuff TYPE HEADERS FILES GoodbyeWorld.h)

target_link_libraries(GoodbyeWorld PUBLIC HelloWorld)

target_include_directories(HelloWorld PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
