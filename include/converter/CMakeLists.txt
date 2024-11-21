add_library(converter_lib STATIC converter.h converter.cpp)
target_link_libraries(converter_lib PUBLIC parser_lib)

target_include_directories(converter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})