cmake_minimum_required(VERSION 3.12)
project(List_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(List_2 main.cpp src/ctab/CTable.h src/ctab/CTable.cpp src/ctab/Utilities.h src/ctab/Utilities.cpp src/inter/CMenu.cpp src/inter/CMenu.h src/inter/CMenuItem.h src/inter/CMenuCommand.cpp src/inter/CMenuCommand.h src/inter/CCommand.cpp src/inter/CCommand.h src/handlers/CTabHandler.cpp src/handlers/CTabHandler.h src/commands/Comm_0.cpp src/commands/Comm_0.h src/commands/Comm_1.cpp src/commands/Comm_1.h src/commands/Comm_2.cpp src/commands/Comm_2.h src/commands/Comm_3.cpp src/commands/Comm_3.h src/commands/Comm_4.cpp src/commands/Comm_4.h src/commands/Comm_5.cpp src/commands/Comm_5.h src/commands/Comm_6.cpp src/commands/Comm_6.h src/commands/Comm_7.cpp src/commands/Comm_7.h src/commands/Comm_8.cpp src/commands/Comm_8.cpp src/commands/Comm_8.h src/commands/Comm_9.cpp src/commands/Comm_9.h src/inter/CMenuItem.cpp)
add_executable(test test/CTable_test.cpp src/ctab/CTable.cpp lib/catch.hpp)