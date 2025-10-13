source_group( " "  REGULAR_EXPRESSION .*)

include_directories(${CMAKE_SOURCE_DIR})

add_library(B STATIC B.cpp B.hpp)

target_link_libraries(B PRIVATE A)

