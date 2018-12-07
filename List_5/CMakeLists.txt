cmake_minimum_required(VERSION 3.13)
project(List_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/GeneticAlgorithm)
include_directories(src/KnapsackProblem)
include_directories(tools)

add_executable(List_5
        src/GeneticAlgorithm/CGeneticAlgorithm.cpp
        src/GeneticAlgorithm/CGeneticAlgorithm.h
        src/GeneticAlgorithm/CIndividual.cpp
        src/GeneticAlgorithm/CIndividual.h
        src/KnapsackProblem/CItem.cpp
        src/KnapsackProblem/CItem.h
        src/KnapsackProblem/CKnapsackProblem.cpp
        src/KnapsackProblem/CKnapsackProblem.h
        tools/IO_module.cpp
        tools/IO_module.h
        main.cpp)
