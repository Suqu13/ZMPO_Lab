//
// Created by Jakub on 28.11.2018.
//

#include <climits>
#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem(int itemsNumber, const vector<CItem *> &items, int maxWeight) : itemsNumber(
        itemsNumber), items(items), maxWeight(maxWeight) {}

CKnapsackProblem::~CKnapsackProblem() {
    for (int i = 0; i < items.size() ; ++i) {
        delete items[i];
    }
}

int CKnapsackProblem::getItemsNumber() const {
    return itemsNumber;
}

int CKnapsackProblem::getMaxWeight() const {
    return maxWeight;
}

vector<CItem *> CKnapsackProblem::getItems() const {
    return items;
}

vector<CItem *> CKnapsackProblem::getSolution(CIndividual *cIndividual) const {
    vector<CItem*> solution;
    vector<int> genotype = cIndividual->getGenotype();
    for (int i = 0; i < genotype.size() ; ++i) {
        if(genotype[i] == 1) {
            solution.push_back(items[i]);
        }
    }
    return solution;
}

CIndividual *CKnapsackProblem::getBest(vector<CIndividual *> population) {
    CIndividual *cIndividual;
    int bestValue = INT_MIN	;
    for(CIndividual* pretendent: population) {
        if (pretendent->evaluateFitness() > bestValue) {
            cIndividual = pretendent;
            bestValue = pretendent->evaluateFitness();
        }
    }
    return new CIndividual(*cIndividual);
}







