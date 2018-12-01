//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CKNAPSACKPROBLEM_H
#define LIST_4_CKNAPSACKPROBLEM_H

#include <vector>
#include "CItem.h"
#include "../GeneticAlgorithm/CIndividual.h"

using namespace std;

class CIndividual;

class CKnapsackProblem {
private:
    vector<CItem*> items;
    int maxWeight;
    CIndividual *bestIndividual;
public:
    //TODO gdzieś w wykładzie o I/O jest coś wspomnniane o komunikacji o błedach, np. maxWeight = -34
    CKnapsackProblem(const vector<CItem *> &items, int maxWeight);
    ~CKnapsackProblem();
    vector<CItem *> getItems() const;
    int getMaxWeight() const;
    void findBestCIndividual(vector<CIndividual*> population);
    vector<CItem *> getSolution(CIndividual *cIndividual) const;
    CIndividual *getCIndividual() const;
};


#endif //LIST_4_CKNAPSACKPROBLEM_H
