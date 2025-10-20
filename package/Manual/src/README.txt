These are manual usages of a producer libry not using any EXPORT mechanism

ConsumerDirect : Do everything by hand in the CMake file no IMPORT targets 
ConsumerImport : Use an IMPORT target but other with all paths by hand. Use target_link_libraries with this target
ConsumerCmake  : Include a .cmake file that does everything