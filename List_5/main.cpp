#include <iostream>
#include <random>
#include "src/GeneticAlgorithm/CGeneticAlgorithm.h"
#include "tools/IO_module.h"

#define DEF_SEPARATOR "********************************************"
#define DEF_BACKPACK_CAPACITY "Provide a backpack capacity: "
#define DEF_POPULATION_SIZE "Provide a population size: "
#define DEF_MUTATION_PROBABILITY "Provide a mutation probability: "
#define DEF_CROSSING_PROBABILITY "Provide a crossing probability: "
#define DEF_TIME "Provide a time for algorithm: "
#define DEF_BEST_SOLUTION "The best solution!"
#define SUM_W "Weights sum: "
#define SUM_V "Values sum: "
using namespace std;

template<class T>
class CIndividual;

template<class T>
class CKnapsackProblem;

template<class T>
class CGeneticAlgorithm;


int main() {

//    cout << "\n" << DEF_SEPARATOR << endl;
//    cout << DEF_BACKPACK_CAPACITY;
//    int maxCapacity = IO_module::inputPositiveInt();
//    cout << DEF_POPULATION_SIZE;
//    int popSize = IO_module::inputPositiveInt();
//    cout << DEF_MUTATION_PROBABILITY;
//    double mutProb = IO_module::inputPositiveDoubleBet0_1();
//    cout << DEF_CROSSING_PROBABILITY;
//    double crossProb = IO_module::inputPositiveDoubleBet0_1();
//    cout << DEF_TIME_MEASURE;
//    int time = IO_module::inputPositiveInt();
//    cout << DEF_SEPARATOR << "\n" << endl;

    vector<CItem *> itemVector = {
            new CItem("item_1", 2, 4),
            new CItem("item_2", 9, 1),
            new CItem("item_3", 1, 10),
            new CItem("item_4", 8, 12),
            new CItem("item_5", 4, 13),
            new CItem("item_6", 20, 100),
            new CItem("item_7", 4, 19),
            new CItem("item_8", 32, 13),
            new CItem("item_9", 6, 22),
            new CItem("item_10", 3, 8)
//            new CItem("item_0", 10, 7),
//            new CItem("item_1", 7, 5),
//            new CItem("item_2", 5, 4),
//            new CItem("item_3", 3, 3),
//            new CItem("item_4", 6, 6),
//            new CItem("item_5", 8, 7),
//            new CItem("item_6", 3, 2),
//            new CItem("item_7", 2, 1)
    };
     int time = 3;
    CKnapsackProblem<double> *cKnapsackProblem;
    cKnapsackProblem = new CKnapsackProblem<double>(itemVector, 34);
    CGeneticAlgorithm<double> geneticAlgorithm(4, 0.2, 0.7, cKnapsackProblem);
    vector<CItem *> bestItems =  geneticAlgorithm.runGeneticAlgorithm(time);

    cout << "\n" << DEF_SEPARATOR << endl;
    double weightSum = 0;
    double valSum = 0;

    cout << DEF_BEST_SOLUTION << endl;

    for (int i = 0; i< bestItems.size(); i++) {
        cout << *bestItems.at(i) << endl;
        weightSum += (bestItems.at(i)->getWeight()) * (bestItems.at(i)->getFactor());
        valSum += (bestItems.at(i)->getValue()) * (bestItems.at(i)->getFactor());
    }
//    for (auto &bestItem  : bestItems) {
//        cout << *bestItem << endl;
//        weightSum += bestItem->getWeight();
//        valSum += bestItem->getValue();
//    }
    cout << SUM_W << weightSum << endl;
    cout << SUM_V << valSum << endl;

    cout << DEF_SEPARATOR << "\n" << endl;
}
