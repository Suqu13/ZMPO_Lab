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
#define SUM_W "Weights sum: "
#define SUM_V "Values sum: "
using namespace std;

int main() {

    cout << "\n" << DEF_SEPARATOR << endl;
    cout << DEF_BACKPACK_CAPACITY;
    int maxCapacity = IO_module::inputPositiveInt();
    cout << DEF_POPULATION_SIZE;
    int popSize = IO_module::inputPositiveInt();
    cout << DEF_MUTATION_PROBABILITY;
    double mutProb = IO_module::inputPositiveDouble();
    cout << DEF_CROSSING_PROBABILITY;
    double crossProb = IO_module::inputPositiveDouble();
    cout << DEF_ITERATIONS_NUMBER;
    int iterations = IO_module::inputPositiveInt();
    cout << DEF_SEPARATOR << "\n" << endl;

    vector<int> newVec;
    vector<CItem *> itemVector = {
//            new CItem("item_1", 2, 4),
//            new CItem("item_2", 9, 1),
//            new CItem("item_3", 1, 10),
//            new CItem("item_4", 8, 12),
//            new CItem("item_5", 4, 13),
//            new CItem("item_6", 20, 100),
//            new CItem("item_7", 4, 19),
//            new CItem("item_8", 32, 13),
//            new CItem("item_9", 6, 22),
//            new CItem("item_10", 3, 8)
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
    vector<CItem *> bestItems =  geneticAlgorithm.runGeneticAlgorithm(iterations);

    cout << "\n" << DEF_SEPARATOR << endl;
    int weightSum = 0;
    int valSum = 0;

    cout << DEF_BEST_SOLUTION << endl;

    for (auto &bestItem : bestItems) {
        cout << *bestItem << endl;
        weightSum += bestItem->getWeight();
        valSum += bestItem->getValue();
    }
    cout << SUM_W << weightSum << endl;
    cout << SUM_V << valSum << endl;

    cout << DEF_SEPARATOR << "\n" << endl;
}
