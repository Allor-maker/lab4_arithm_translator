add_library(stack_lib STATIC stack.h stack.cpp)

target_include_directories(stack_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})