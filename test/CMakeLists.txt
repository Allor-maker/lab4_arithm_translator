file(GLOB TEST_SOURCES "*.cpp") 

add_executable(CalculatorTests ${TEST_SOURCES})

add_subdirectory(${CMAKE_SOURCE_DIR}/gtest ${CMAKE_BINARY_DIR}/gtest)

target_link_libraries(CalculatorTests PRIVATE calc interface parser stack gtest gtest_main)

# Указываем путь для поиска заголовков
target_include_directories(CalculatorTests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Добавляем команду для автоматического запуска тестов после сборки
add_test(CalculatorTests CalculatorTests)