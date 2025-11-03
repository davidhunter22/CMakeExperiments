add_library(GoodbyeWorld SHARED GoodbyeWorld.cpp)

generate_export_header(GoodbyeWorld)

target_sources(GoodbyeWorld PUBLIC 
   FILE_SET stuff 
   TYPE HEADERS
   BASE_DIRS ${CMAKE_SOURCE_DIR}
   FILES GoodbyeWorld.h)

target_sources(GoodbyeWorld PUBLIC 
   FILE_SET generated_export_headers  
   TYPE HEADERS
   BASE_DIRS ${CMAKE_BINARY_DIR}
   FILES ${CMAKE_CURRENT_BINARY_DIR}/goodbyeworld_export.h)  

# # Would be nice to ge rid of this line
target_include_directories(GoodbyeWorld PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

target_link_libraries(GoodbyeWorld PUBLIC HelloWorld)