cmake_minimum_required(VERSION 3.12)
project(List_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(List_2 main.cpp inter/CMenu.cpp inter/CMenu.h inter/CMenuItem.h inter/CMenuCommand.cpp inter/CMenuCommand.h inter/CCommand.cpp inter/CCommand.h src/main.cpp handlers/CComHandler.h handlers/CComHandler.cpp handlers/CTabHandler.cpp handlers/CTabHandler.h commands/Comm_0.cpp commands/Comm_0.h commands/Comm_1.cpp commands/Comm_1.h commands/Comm_2.cpp commands/Comm_2.h commands/Comm_3.cpp commands/Comm_3.h commands/Comm_4.cpp commands/Comm_4.h)
add_executable(Test test/CTable_test.cpp ctab/CTable.cpp)