//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CKNAPSACKPROBLEM_H
#define LIST_4_CKNAPSACKPROBLEM_H

#define DEF_KNAPSACKPROBLEM_DELETED "KnapsackProblem object deleted"

#include <vector>
#include "CItem.h"
#include "../GeneticAlgorithm/CIndividual.h"

using namespace std;

class CIndividual;

class CKnapsackProblem {
private:
    vector<CItem*> items;
    int maxCapacity;
    CIndividual *bestIndividual;
    int evaluateFitness(vector<int> genotype) const;
public:
    CKnapsackProblem(const vector<CItem *> &items, int maxWeight);
    ~CKnapsackProblem();
    CIndividual *createIndividual();
    void findBestCIndividual(vector<CIndividual*> population);
    vector<CItem *> getBestItem() const;
    bool checkIfGreater(CIndividual *first, CIndividual *second) const;
};


#endif //LIST_4_CKNAPSACKPROBLEM_H
