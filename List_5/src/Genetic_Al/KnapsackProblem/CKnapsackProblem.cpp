//
// Created by jakub on 18.12.18.
//

#include "CKnapsackProblem.h"

template<>
CKnapsackProblem<bool>::CKnapsackProblem( vector<CItem *> &items, int maxCapacity) : items(items),
                                                                                     maxCapacity(maxCapacity),
                                                                                     bestIndividual(
                                                                                             nullptr) {
    if (this->maxCapacity <= 0) this->maxCapacity = 10;
    for (int i = 0; i < items.size(); ++i) {
        this->maxItems.push_back(1);
    };
}

template<>
vector<CItem *> CKnapsackProblem<bool>::getBestItem() const {
    vector<CItem *> solution;
    vector<bool> genotype = bestIndividual->getGenotype();
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype[i] == true) {
            solution.push_back(items[i]);
        }
    }
    return solution;
}

template<>
CIndividual<bool> *CKnapsackProblem<bool>::createIndividual(double &mutProb) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    vector<bool> genotype;
    for (int i = 0; i < items.size(); ++i) {
        genotype.push_back(dis(gen) == 1);
    }
    return new CIndividual<bool>(genotype, mutProb, maxItems);
}

template<>
double CKnapsackProblem<bool>::evaluateFitness(vector<bool> genotype) const {
    int currentValue = 0;
    int currentWeight = 0;
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype[i] == true) {
            currentValue += (*(items.at(i))).getValue();
            currentWeight += items[i]->getWeight();
            if (currentWeight > maxCapacity) {
                return 0;
            }
        }
    }
    return currentValue;
}