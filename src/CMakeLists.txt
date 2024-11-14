add_executable(AT_exe main.cpp)

target_link_libraries(AT_exe PRIVATE calc_lib interface_lib parser_lib stack_lib)