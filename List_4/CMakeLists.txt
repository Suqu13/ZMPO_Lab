cmake_minimum_required(VERSION 3.12)
project(List_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ListTest main.cpp)
add_executable(List_4 main.cpp src/KnapsackProblem/CKnapsackProblem.cpp src/KnapsackProblem/CKnapsackProblem.h src/KnapsackProblem/CItem.cpp src/KnapsackProblem/CItem.h src/CIndividual.cpp src/CIndividual.h src/GeneticAlgorithm/CGeneticAlgorithm.cpp src/GeneticAlgorithm/CGeneticAlgorithm.h)