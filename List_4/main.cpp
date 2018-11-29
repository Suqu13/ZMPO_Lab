#include <iostream>
#include <random>
#include "src/GeneticAlgorithm/CGeneticAlgorithm.h"

using namespace std;

int main() {
    vector<CItem *> items = {new CItem("item 1", 2, 4),
                             new CItem("item 2", 9, 1),
                             new CItem("item 3", 1, 10),
                             new CItem("item 4", 8, 12),
                             new CItem("item 5", 4, 13),
                             new CItem("item 6", 20, 100),
                             new CItem("item 7", 4, 19),
                             new CItem("item 8", 32, 13),
                             new CItem("item 9", 6, 22),
                             new CItem("item 10", 3, 8)

    };
    CKnapsackProblem *cKnapsackProblem;
    cKnapsackProblem = cKnapsackProblem = new CKnapsackProblem(10, items, 34);
    CGeneticAlgorithm geneticAlgorithm(4, 0.25, 0.75, cKnapsackProblem);
    CIndividual* bestSolution = geneticAlgorithm.runGeneticAlgorithm(100);
    vector<CItem*> bestItems = cKnapsackProblem->getSolution(bestSolution);
    for (int i = 0; i < bestItems.size(); ++i) {
        cout << *bestItems.at(i) << endl;
    }
    items.clear();

    delete bestSolution;
}