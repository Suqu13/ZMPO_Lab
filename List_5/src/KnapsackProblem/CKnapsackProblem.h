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
struct CIndividual;

template<class T>
struct CKnapsackProblem {
private:
    vector<CItem *> items;
    int maxCapacity;
    CIndividual<T> *bestIndividual;
    vector<double> maxItems;

    double evaluateFitness(vector<T> genotype) const;

public:
    CKnapsackProblem(const vector<CItem *> &items, int maxWeight);

    ~CKnapsackProblem();

    CIndividual<T> *createIndividual(double &mutProb);

    void findBestCIndividual(vector<CIndividual<T> *> population);

    vector<CItem *> getBestItem() const;

    bool checkIfGreater(CIndividual<T> *first, CIndividual<T> *second) const;

};


template<class T>
CKnapsackProblem<T>::CKnapsackProblem(const vector<CItem *> &items, int maxCapacity) : items(items),
                                                                                       maxCapacity(maxCapacity),
                                                                                       bestIndividual(
                                                                                               nullptr) {
    if (this->maxCapacity <= 0) this->maxCapacity = 10;

    for (int i = 0; i < items.size() ; ++i) {
        int weight = items.at(i)->getWeight();
        double toInsert = ((double)maxCapacity/weight);
        this->maxItems.push_back(toInsert);
    };
}

template<class T>
CKnapsackProblem<T>::~CKnapsackProblem() {
    for (int i = 0; i < items.size(); ++i) {
        delete items[i];
    }
    delete bestIndividual;
    cout << DEF_KNAPSACKPROBLEM_DELETED << endl;
}

template<class T>
vector<CItem *> CKnapsackProblem<T>::getBestItem() const {
    vector<CItem *> solution;
    vector<T> genotype = bestIndividual->getGenotype();
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype[i] != 0) {
            items.at(i)->setFold(genotype[i]);
            solution.push_back(items[i]);
        }
    }
    return solution;
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
        if (genotype[i] != 0) {
            currentValue += (*(items.at(i))).getValue() * genotype.at(i);
            currentWeight += items[i]->getWeight() * genotype.at(i);
            if (currentWeight > maxCapacity) {
                return 0;
            }
        }
    }
    return currentValue;
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

template<class T>
bool CKnapsackProblem<T>::checkIfGreater(CIndividual<T> *first, CIndividual<T> *second) const {
    return this->evaluateFitness(first->getGenotype()) >
           this->evaluateFitness(second->getGenotype());
}

template<class T>
CIndividual<T > *CKnapsackProblem<T >::createIndividual(double &mutProb) {
    random_device rd;
    mt19937 gen(rd());
    vector<T> genotype;
    for (int i = 0; i < items.size(); ++i) {
        uniform_int_distribution<> dis(-(maxItems.at(i)/2), maxItems.at(i));
        T newFold = dis(gen);
        newFold < 0 ? genotype.push_back(0) : genotype.push_back(newFold);
    }
    return new CIndividual<T>(genotype, mutProb, maxItems);
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

#endif //LIST_5_CKNAPSACKPROBLEM_H
