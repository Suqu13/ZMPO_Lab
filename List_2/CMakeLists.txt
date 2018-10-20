cmake_minimum_required(VERSION 3.12)
project(List_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(List_2 main.cpp inter/CMenu.cpp inter/CMenu.h inter/CMenuItem.cpp inter/CMenuItem.h inter/CMenuCommand.cpp inter/CMenuCommand.h inter/CCommand.cpp inter/CCommand.h)
add_executable(Test test/CTable_test.cpp ctab/CTable.cpp)