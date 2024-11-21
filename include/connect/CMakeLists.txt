add_library(connect_lib STATIC connect.h connect.cpp)

target_link_libraries(connect_lib PUBLIC converter_lib)
target_link_libraries(connect_lib PUBLIC parser_lib)
target_link_libraries(connect_lib PUBLIC calc_lib)

target_include_directories(connect_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})