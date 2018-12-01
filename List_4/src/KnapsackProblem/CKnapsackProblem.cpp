//
// Created by Jakub on 28.11.2018.
//

#include <climits>
#include <iostream>
#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem(const vector<CItem *> &items, int maxWeight) : items(items), maxWeight(maxWeight), bestIndividual(
        nullptr){}

CKnapsackProblem::~CKnapsackProblem() {
    for (int i = 0; i < items.size() ; ++i) {
        delete items[i];
    }
        delete bestIndividual;
    cout << "KnapsackProblem object deleted" << endl;
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

void CKnapsackProblem::findBestCIndividual(vector<CIndividual *> population) {
    int bestValue;
    if(bestIndividual != nullptr) {
        bestValue = bestIndividual->evaluateFitness(this);
    } else {
        bestValue = INT_MIN;
    }
    for(CIndividual* candidate: population) {
        if (candidate->evaluateFitness(this) > bestValue) {
            bestIndividual = new CIndividual(*candidate);
            bestValue = bestIndividual->evaluateFitness(this);
        }
    }
}

CIndividual *CKnapsackProblem::getCIndividual() const {
    return bestIndividual;
}







