//
// Created by Jakub on 28.11.2018.
//

#include "CIndividual.h"
#include <random>
#include <iostream>

using namespace std;

CIndividual::CIndividual() {}

CIndividual::CIndividual(const vector<int> &genotype) : genotype(genotype) {}

CIndividual::CIndividual(CIndividual &cIndividual) : genotype(cIndividual.getGenotype()) {}

CIndividual::~CIndividual() {
//    cout << "Individual object deleted" << endl;
}

const vector<int> &CIndividual::getGenotype() const {
    return genotype;
}

int CIndividual::evaluateFitness(const CKnapsackProblem *cKnapsackProblem) {
    vector<CItem *> items = cKnapsackProblem->getItems();
    int maxWeight = cKnapsackProblem->getMaxWeight();
    int currentValue = 0;
    int currentWeight = 0;
    for (int i = 0; i < genotype.size(); ++i) {
        if (genotype[i] == 1) {
            currentValue += (*(items.at(i))).getValue();
            currentWeight += items[i]->getWeight();
            if (currentWeight > maxWeight) {
                return 0;
            }
        }
    }
    return currentValue;
}

void CIndividual::mutateIndividual(const double &mutProb) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> mut(0, 1);
    //TODO added
    if (mut(gen) < mutProb) {
        for (int i = 0; i < genotype.size(); ++i) {
            if (mut(gen) < mutProb) {
                if (genotype.at(i) == 0) {
                    genotype.at(i) = 1;
                } else {
                    genotype.at(i) = 0;
                }
            }
        }
    }
}

void CIndividual::crossIndividuals(CIndividual *cIndividual, double &mutProb, vector<CIndividual *> &newPopulation,
                                   const CKnapsackProblem *cKnapsackProblem) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, (int) cIndividual->genotype.size() - 1);
    int crossingPoint = dis(gen);

    CIndividual *firstChildren = new CIndividual();
    CIndividual *secondChildren = new CIndividual();

    CIndividual *betterParent;
    CIndividual *worstParent;

    if (this->evaluateFitness(cKnapsackProblem) > cIndividual->evaluateFitness(cKnapsackProblem)) {
        betterParent = this;
        worstParent = cIndividual;
    } else {
        betterParent = cIndividual;
        worstParent = this;
    }

//    //TODO check if crossing procedure is correct
//    for (int i = 0; i < crossingPoint; ++i) {
//        firstChildren->genotype.push_back(betterParent->genotype.at(i));
//        secondChildren->genotype.push_back(worstParent->genotype.at(i));
//    }
//
//    for (int i = crossingPoint; i < genotype.size(); ++i) {
//        firstChildren->genotype.push_back(worstParent->genotype.at(i));
//        secondChildren->genotype.push_back(betterParent->genotype.at(i));
//    }

    for (int i = 0; i < betterParent->genotype.size(); ++i) {
        if (i < crossingPoint)
            firstChildren->genotype.push_back(betterParent->genotype.at(i));
        else
            firstChildren->genotype.push_back(worstParent->genotype.at(i));
    }

    for (int i = crossingPoint; i < betterParent->genotype.size(); ++i) {
        secondChildren->genotype.push_back(betterParent->genotype.at(i));
    }
    for (int i = 0; i < crossingPoint; ++i) {
        secondChildren->genotype.push_back(worstParent->genotype.at(i));
    }


    firstChildren->mutateIndividual(mutProb);
    secondChildren->mutateIndividual(mutProb);

    newPopulation.push_back(firstChildren);
    newPopulation.push_back(secondChildren);
}













