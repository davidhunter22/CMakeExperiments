source_group( " "  REGULAR_EXPRESSION .*)

include_directories(${CMAKE_SOURCE_DIR})

# add_library(C SHARED C.cpp C.hpp)

add_executable(C C.cpp C.hpp)

target_link_libraries(C PUBLIC B)

