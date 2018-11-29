//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CKNAPSACKPROBLEM_H
#define LIST_4_CKNAPSACKPROBLEM_H

#include <vector>
#include "CItem.h"
#include "../CIndividual.h"

using namespace std;

class CIndividual;

class CKnapsackProblem {
private:
    int itemsNumber;
    vector<CItem*> items;
    int maxWeight;
public:
    //TODO gdzieś w wykładzie o I/O jest coś wspomnniane o komunikacji o błedach, np. maxWeight = -34
    CKnapsackProblem(int itemsNumber, const vector<CItem *> &items, int maxWeight);

    ~CKnapsackProblem();
    int getItemsNumber() const;
    vector<CItem *> getItems() const;
    int getMaxWeight() const;
    CIndividual *getBest(vector<CIndividual*> population);
    vector<CItem *> getSolution(CIndividual *cIndividual) const;
};


#endif //LIST_4_CKNAPSACKPROBLEM_H
