add_library(interface_lib STATIC interface.h interface.cpp)

target_include_directories(interface_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})