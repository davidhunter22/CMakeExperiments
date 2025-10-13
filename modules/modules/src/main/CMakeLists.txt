add_executable(module_main main.cpp)

if (MSVC)
    source_group( " "  REGULAR_EXPRESSION .*)
endif()

target_link_libraries(module_main PRIVATE module)
