cmake_minimum_required(VERSION 3.12)
project(List_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(test src/test/test_run.cpp src/test/catch.hpp src/CTab/CTable.cpp src/CTab/CTable.h)
add_executable(List_3 main.cpp
        lib/interface/CCommand.cpp
        lib/interface/CCommand.h lib/interface/CMenu.cpp
        lib/interface/CMenu.h lib/interface/CMenuItem.cpp
        lib/interface/CMenuItem.h lib/interface/CMenuCommand.cpp
        lib/interface/CMenuCommand.h lib/interface/CCommandWithVector.cpp
        lib/interface/CCommandWithVector.h lib/helpers/CTabHandler.cpp
        lib/helpers/CTabHandler.h lib/helpers/CInitializer.cpp
        lib/helpers/CInitializer.h lib/utilities/Utilities.cpp
        lib/utilities/Utilities.h src/CTab/CTable.cpp
        src/CTab/CTable.h src/CTab/CTab_commands/CloneCTable.cpp
        src/CTab/CTab_commands/CloneCTable.h src/CTab/CTab_commands/CreateDefaultCTables.cpp
        src/CTab/CTab_commands/CreateDefaultCTables.h src/CTab/CTab_commands/CreateSpecificCTables.cpp
        src/CTab/CTab_commands/CreateSpecificCTables.h src/CTab/CTab_commands/InsertValueIntoCTable.cpp
        src/CTab/CTab_commands/InsertValueIntoCTable.h src/CTab/CTab_commands/RemoveAllCTable.cpp
        src/CTab/CTab_commands/RemoveAllCTable.h src/CTab/CTab_commands/RemoveSingleCTable.cpp
        src/CTab/CTab_commands/RemoveSingleCTable.h src/CTab/CTab_commands/SetCTableName.cpp
        src/CTab/CTab_commands/SetCTableName.h src/CTab/CTab_commands/SetLengthOfCTable.cpp
        src/CTab/CTab_commands/SetLengthOfCTable.h src/CTab/CTab_commands/ShowAll.cpp
        src/CTab/CTab_commands/ShowAll.h src/CTab/CTab_commands/ShowOne.cpp
        src/CTab/CTab_commands/ShowOne.h lib/helpers/CMenuAnalyzer.cpp
        lib/helpers/CMenuAnalyzer.h lib/helpers/CMenuSerializer.cpp
        lib/helpers/CMenuSerializer.h lib/utilities/io_Txt_File.cpp
        lib/utilities/io_Txt_File.h lib/helpers/Validator.cpp
        lib/helpers/Validator.h src/Genetic_Al/GeneticAlgorithm/CGeneticAlgorithm.h
        src/Genetic_Al/GeneticAlgorithm/CIndividual.h
        src/Genetic_Al/KnapsackProblem/CKnapsackProblem.h
        src/Genetic_Al/KnapsackProblem/CKnapsackProblem.cpp
        src/Genetic_Al/KnapsackProblem/CItem.cpp src/Genetic_Al/KnapsackProblem/CItem.h src/Genetic_Al_commands/GeneticAlgorithm_command.h src/Genetic_Al_commands/AddItem.cpp src/Genetic_Al_commands/AddItem.h src/Genetic_Al_commands/RemoveItem.cpp src/Genetic_Al_commands/RemoveItem.h src/Genetic_Al_commands/RemoveItemVector.cpp src/Genetic_Al_commands/RemoveItemVector.h src/Genetic_Al_commands/ShowItems.cpp src/Genetic_Al_commands/ShowItems.h src/Genetic_Al/KnapsackProblem/CKnapsackProblem.cpp src/Genetic_Al/GeneticAlgorithm/Individual.cpp)