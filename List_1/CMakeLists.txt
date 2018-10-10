cmake_minimum_required(VERSION 3.12)
project(List_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(List_1 src/main.cpp src/CTable.cpp src/CTable.h src/Menu.cpp src/Menu.h src/Utilities.cpp src/Utilities.h)
add_executable(Test test/CTable_test.cpp src/CTable.cpp src/Menu.cpp)