//
// Created by Jakub on 28.11.2018.
//

#include <climits>
#include <iostream>
#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem(const vector<CItem *> &items, int maxWeight) : items(items), maxCapacity(maxWeight), bestIndividual(
        nullptr){
    if(this->maxCapacity <= 0) this->maxCapacity = 10;
}

CKnapsackProblem::~CKnapsackProblem() {
    for (int i = 0; i < items.size() ; ++i) {
        delete items[i];
    }
        delete bestIndividual;
    cout << DEF_KNAPSACKPROBLEM_DELETED << endl;
}

int CKnapsackProblem::getMaxWeight() const {
    return maxCapacity;
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

void CKnapsackProblem::findBestCIndividual(vector<CIndividual *> population) {
    int bestValue;
    if(bestIndividual != nullptr) {
        bestValue = bestIndividual->evaluateFitness(this);
    } else {
        bestValue = INT_MIN;
    }
    for(CIndividual* candidate: population) {
        if (candidate->evaluateFitness(this) > bestValue) {
            delete bestIndividual;
            bestIndividual = new CIndividual(*candidate);
            bestValue = bestIndividual->evaluateFitness(this);
        }
    }
}

CIndividual *CKnapsackProblem::getCIndividual() const {
    return bestIndividual;
}







