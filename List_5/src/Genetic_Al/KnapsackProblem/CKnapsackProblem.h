//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_5_CKNAPSACKPROBLEM_H
#define LIST_5_CKNAPSACKPROBLEM_H

#define DEF_KNAPSACKPROBLEM_DELETED "KnapsackProblem object deleted"

#include <climits>
#include <iostream>
#include <random>
#include <vector>
#include "CItem.h"
#include "../GeneticAlgorithm/CIndividual.h"


using namespace std;


template<class T>
class CKnapsackProblem {
private:
    vector<CItem *> &items;
    int maxCapacity;
    CIndividual<T> *bestIndividual;
    vector<double> maxItems;

    double evaluateFitness(vector<T> genotype) const;

public:
    CKnapsackProblem(vector<CItem *> &items, int maxCapacity);
    ~CKnapsackProblem();
    CIndividual<T> *createIndividual(double &mutProb);
    void findBestCIndividual(vector<CIndividual<T> *> population);
    vector<CItem *> getBestItem() const;
    bool checkIfGreater(CIndividual<T> *first, CIndividual<T> *second);

};


template<class T>
CKnapsackProblem<T>::CKnapsackProblem(vector<CItem *> &items, int maxCapacity) : items(items),
                                                                                       maxCapacity(maxCapacity),
                                                                                       bestIndividual(
                                                                                               nullptr) {
    if (this->maxCapacity <= 0) this->maxCapacity = 10;

    for (int i = 0; i < items.size(); ++i) {
        int weight = items.at(i)->getWeight();
        double toInsert = ((double) maxCapacity / weight);
        this->maxItems.push_back(toInsert);
    };
}


template<class T>
CKnapsackProblem<T>::~CKnapsackProblem() {
    delete bestIndividual;
    maxItems.clear();
    cout << DEF_KNAPSACKPROBLEM_DELETED << endl;
}

template<class T>
vector<CItem *> CKnapsackProblem<T>::getBestItem() const {
    vector<CItem *> solution;
    vector<T> genotype = bestIndividual->getGenotype();
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype[i] != 0) {
            items.at(i)->setFactor(genotype[i]);
            solution.push_back(items[i]);
        }
    }
    return solution;
}

template<class T>
void CKnapsackProblem<T>::findBestCIndividual(vector<CIndividual<T> *> population) {
    double bestValue = 0;
    if (bestIndividual != nullptr) {
        bestValue = this->evaluateFitness(bestIndividual->getGenotype());
    }
    for (CIndividual<T> *candidate: population) {
        if (this->evaluateFitness(candidate->getGenotype()) > bestValue) {
            delete bestIndividual;
            bestIndividual = new CIndividual<T>(*candidate);
            bestValue = this->evaluateFitness(bestIndividual->getGenotype());
        }
    }
}

template<class T>
double CKnapsackProblem<T>::evaluateFitness(vector<T> genotype) const {
    double currentValue = 0;
    double currentWeight = 0;
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype.at(i) != 0) {
            currentValue += (*(items.at(i))).getValue() * genotype.at(i);
            currentWeight += items[i]->getWeight() * genotype.at(i);
            if (currentWeight > maxCapacity) {
                return 0;
            }
        }
    }
    return currentValue;
}

template<class T>
bool CKnapsackProblem<T>::checkIfGreater(CIndividual<T> *first, CIndividual<T> *second) {
    return evaluateFitness(first->getGenotype()) >
           evaluateFitness(second->getGenotype());
}

template<class T>
CIndividual<T> *CKnapsackProblem<T>::createIndividual(double &mutProb) {
    random_device rd;
    mt19937 gen(rd());
    vector<T> genotype;
    for (int i = 0; i < items.size(); ++i) {
        uniform_int_distribution<> dis(-(maxItems.at(i) / 2), maxItems.at(i));
        T newFold = dis(gen);
        newFold < 0 ? genotype.push_back(0) : genotype.push_back(newFold);
    }
    return new CIndividual<T>(genotype, mutProb, maxItems);
}



#endif //LIST_5_CKNAPSACKPROBLEM_H
