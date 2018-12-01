#include <iostream>
#include <random>
#include "src/GeneticAlgorithm/CGeneticAlgorithm.h"
#include "tools/IO_module.h"

using namespace std;

int main() {

    vector<CItem *> items = {
//                             new CItem("item_1", 4, 5),
//                             new CItem("item_2", 1, 1),
//                             new CItem("item_3", 3, 4),
//                             new CItem("item_4", 2, 3),
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

    };
    cout << "\n********************************************" << endl;
    cout << "Provide a backpack capacity: ";
    int maxCapacity = IO_module::inputPositiveInt();
    cout << "Provide a population size: ";
    int popSize = IO_module::inputPositiveInt();
    cout << "Provide a mutation probability: ";
    double mutProb = IO_module::inputPositiveDouble();
    cout << "Provide a crossing probability: ";
    double crossProb = IO_module::inputPositiveDouble();
    cout << "Provide a iterations number: ";
    int iterations = IO_module::inputPositiveInt();
    cout << "********************************************\n" << endl;

    CKnapsackProblem *cKnapsackProblem;
    cKnapsackProblem = cKnapsackProblem = new CKnapsackProblem(items, maxCapacity);
    CGeneticAlgorithm geneticAlgorithm(popSize, mutProb, crossProb, cKnapsackProblem);
    CIndividual *bestSolution = geneticAlgorithm.runGeneticAlgorithm(iterations);

    cout << "\n********************************************" << endl;
    if (bestSolution->evaluateFitness(cKnapsackProblem) != 0) {
        cout << "The best solution!" << endl;
        vector<CItem *> bestItems = cKnapsackProblem->getSolution(bestSolution);
        for (int i = 0; i < bestItems.size(); ++i) {
            cout << *bestItems.at(i) << endl;
        }
    } else {
        cout << "The solution has been not found, try again with a bigger population!" << endl;
    }
    cout << "********************************************\n" << endl;

    items.clear();
    delete bestSolution;
}