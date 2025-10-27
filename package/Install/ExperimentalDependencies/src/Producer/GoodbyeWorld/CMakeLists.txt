add_library(GoodbyeWorld SHARED GoodbyeWorld.cpp)

generate_export_header(GoodbyeWorld)

target_sources(GoodbyeWorld PUBLIC 
   FILE_SET stuff TYPE HEADERS
   BASE_DIRS ${CMAKE_SOURCE_DIR}
   FILES GoodbyeWorld.h)

#target_sources(GoodbyeWorld PUBLIC 
#   FILE_SET stuff TYPE HEADERS
#   BASE_DIRS ${CMAKE_SOURCE_DIR} $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> 
#   FILES GoodbyeWorld.h ${CMAKE_CURRENT_BINARY_DIR}/goodbyeworld_export.h)

target_link_libraries(GoodbyeWorld PUBLIC HelloWorld)