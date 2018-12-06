#include <iostream>
#include <random>
#include "src/GeneticAlgorithm/CGeneticAlgorithm.h"
#include "tools/IO_module.h"

#define DEF_SEPARATOR "********************************************"
#define DEF_BACKPACK_CAPACITY "Provide a backpack capacity: "
#define DEF_POPULATION_SIZE "Provide a population size: "
#define DEF_MUTATION_PROBABILITY "Provide a mutation probability: "
#define DEF_CROSSING_PROBABILITY "Provide a crossing probability: "
#define DEF_ITERATIONS_NUMBER "Provide a iterations number: "
#define DEF_BEST_SOLUTION "The best solution!"
#define DEF_BEST_SOLUTION_NOT_FOUND "The solution has been not found, try again with a bigger population!"
using namespace std;

int main() {

    cout << "\n" << DEF_SEPARATOR << endl;
    cout << DEF_BACKPACK_CAPACITY;
    int maxCapacity = IO_module::inputPositiveInt();
    cout << DEF_POPULATION_SIZE;
    //int popSize = -1;
    int popSize = IO_module::inputPositiveInt();
    cout << DEF_MUTATION_PROBABILITY;
    double mutProb = IO_module::inputPositiveDouble();
    cout << DEF_CROSSING_PROBABILITY;
    double crossProb = IO_module::inputPositiveDouble();
    cout << DEF_ITERATIONS_NUMBER;
    int iterations = IO_module::inputPositiveInt();
    cout << DEF_SEPARATOR << "\n" << endl;


    //pop = 20
    //mut & prob -> self
    //iter = 100
    //maxCap = 25
    vector<int > newVec;
    vector<CItem *> itemVector = {
            new CItem("item_0", 10, 7),
            new CItem("item_1", 7, 5),
            new CItem("item_2", 5, 4),
            new CItem("item_3", 3, 3),
            new CItem("item_4", 6, 6),
            new CItem("item_5", 8, 7),
            new CItem("item_6", 3, 2),
            new CItem("item_7", 2, 1)
    };

    CKnapsackProblem *cKnapsackProblem;
    cKnapsackProblem = new CKnapsackProblem(itemVector, maxCapacity);
    CGeneticAlgorithm geneticAlgorithm(popSize, mutProb, crossProb, cKnapsackProblem);
    CIndividual *bestSolution = geneticAlgorithm.runGeneticAlgorithm(iterations);

    cout << "\n" << DEF_SEPARATOR << endl;
    if (bestSolution->evaluateFitness(cKnapsackProblem) != 0) {
        cout << DEF_BEST_SOLUTION << endl;
        vector<CItem *> bestItems = cKnapsackProblem->getSolution(bestSolution);
        for (int i = 0; i < bestItems.size(); ++i) {
            cout << *bestItems.at(i) << endl;
        }
    } else {
        cout << DEF_BEST_SOLUTION_NOT_FOUND << endl;
    }
    cout << DEF_SEPARATOR << "\n" << endl;

    itemVector.clear();
    delete bestSolution;
}