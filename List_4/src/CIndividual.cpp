//
// Created by Jakub on 28.11.2018.
//

#include "CIndividual.h"
#include <random>
#include <iostream>

using namespace std;

CIndividual::CIndividual(CKnapsackProblem *cKnapsackProblem) : cKnapsackProblem(cKnapsackProblem) {}

CIndividual::CIndividual(const vector<int> &genotype, CKnapsackProblem *cKnapsackProblem) : genotype(genotype),
                                                                                            cKnapsackProblem(
                                                                                                    cKnapsackProblem) {}

CIndividual::CIndividual(CIndividual &cIndividual): genotype(cIndividual.getGenotype()), cKnapsackProblem(cIndividual.cKnapsackProblem) {}

CIndividual::~CIndividual() {
    cout << "Individual deleted" << endl;
}

CKnapsackProblem *CIndividual::getCKnapsackProblem() const {
    return cKnapsackProblem;
}

const vector<int> &CIndividual::getGenotype() const {
    return genotype;
}

int CIndividual::evaluateFitness() {
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

void CIndividual::mutateIndividual(const int &mutProb) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);
    for (int i = 0; i < genotype.size(); ++i) {
        if (dis(gen) < mutProb) {
            if (genotype.at(i) == 0) {
                genotype.at(i) = 1;
            } else {
                genotype.at(i) = 0;
            }
        }
    }
}

//TODO finding better parent

void CIndividual::crossIndividuals(CIndividual *cIndividual, double &mutProb, vector<CIndividual *> &newPopulation) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, (int) cIndividual->genotype.size() - 1);
    int crossingPoint = dis(gen);

    CIndividual *firstChildren = new CIndividual(this->cKnapsackProblem);
    CIndividual *secondChildren = new CIndividual(this->cKnapsackProblem);

    CIndividual *betterParent;
    CIndividual *worstParent;

    if (this->evaluateFitness() > cIndividual->evaluateFitness()) {
        betterParent = this;
        worstParent = cIndividual;
    } else {
        betterParent = cIndividual;
        worstParent = this;
    }

    for (int i = 0; i < crossingPoint; ++i) {
            firstChildren->genotype.push_back(betterParent->genotype[i]);
            secondChildren->genotype.push_back(worstParent->genotype[i]);
    }

    for (int i = crossingPoint; i < genotype.size(); ++i) {
        firstChildren->genotype.push_back(worstParent->genotype[i]);
        secondChildren->genotype.push_back(betterParent->genotype[i]);
    }
    /*for (int i = 0; i < crossingPoint; ++i) {
        secondChildren->genotype.push_back(worstParent->genotype[i]);
    }*/

    firstChildren->mutateIndividual(mutProb);
    secondChildren->mutateIndividual(mutProb);

//    int counter = 0;

//    if (firstChildren->evaluateFitness() != 0) {
        newPopulation.push_back(firstChildren);
//    } else {
//        counter++;
//    }

//    if (secondChildren->evaluateFitness() != 0) {
        newPopulation.push_back(secondChildren);
//    } else {
//        counter++;
//    }

//    if (counter == 2) {
//        newPopulation.push_back(new CIndividual(*betterParent));
//        newPopulation.push_back(new CIndividual(*worstParent));
//    } else if (counter == 1) {
//        uniform_int_distribution<> rand(0, 1);
//        if (rand(gen) == 1) {
//            newPopulation.push_back(new CIndividual(*betterParent));
//        } else {
//            newPopulation.push_back(new CIndividual(*worstParent));
//        }
//    }
}













