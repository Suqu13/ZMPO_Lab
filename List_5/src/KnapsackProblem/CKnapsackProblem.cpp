//
// Created by Jakub on 28.11.2018.
//

#include <climits>
#include <iostream>
#include <random>
#include "CKnapsackProblem.h"


CKnapsackProblem::CKnapsackProblem(const vector<CItem *> &items, int maxCapacity) : items(items),
                                                                                    maxCapacity(maxCapacity),
                                                                                    bestIndividual(
                                                                                            nullptr) {
    if (this->maxCapacity <= 0) this->maxCapacity = 10;
}

CKnapsackProblem::~CKnapsackProblem() {
    for (int i = 0; i < items.size(); ++i) {
        delete items[i];
    }
    delete bestIndividual;
    cout << DEF_KNAPSACKPROBLEM_DELETED << endl;
}

vector<CItem *> CKnapsackProblem::getBestItem() const {
    vector<CItem *> solution;
    vector<int> genotype = bestIndividual->getGenotype();
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype[i] == 1) {
            solution.push_back(items[i]);
        }
    }
    return solution;
}

void CKnapsackProblem::findBestCIndividual(vector<CIndividual *> population) {
    int bestValue = 0;
    if (bestIndividual != nullptr) {
        bestValue = this->evaluateFitness(bestIndividual->getGenotype());
    }
    for (CIndividual *candidate: population) {
        if (this->evaluateFitness(candidate->getGenotype()) > bestValue) {
            delete bestIndividual;
            bestIndividual = new CIndividual(*candidate);
            bestValue = this->evaluateFitness(bestIndividual->getGenotype());
        }
    }
}

int CKnapsackProblem::evaluateFitness(vector<int> genotype) const {
    int currentValue = 0;
    int currentWeight = 0;
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype[i] == 1) {
            currentValue += (*(items.at(i))).getValue();
            currentWeight += items[i]->getWeight();
            if (currentWeight > maxCapacity) {
                return 0;
            }
        }
    }
    return currentValue;
}

bool CKnapsackProblem::checkIfGreater(CIndividual *first, CIndividual *second) const {
    return this->evaluateFitness(first->getGenotype()) >
           this->evaluateFitness(second->getGenotype());
}

CIndividual *CKnapsackProblem::createIndividual(double &mutProb) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    vector<int> genotype;
    for (int i = 0; i < items.size(); ++i) {
        genotype.push_back(dis(gen));
    }
    return new CIndividual(genotype, mutProb);
}









