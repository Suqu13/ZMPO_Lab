//
// Created by Jakub on 28.11.2018.
//

#include "CIndividual.h"
#include <random>
#include <iostream>

using namespace std;

CIndividual::CIndividual() = default;

CIndividual::CIndividual(const double mutProb) : mutProb(mutProb) {}

CIndividual::CIndividual(const vector<int> &genotype, const double mutProb) : genotype(genotype), mutProb(mutProb) {}

CIndividual::CIndividual(CIndividual &cIndividual): genotype(cIndividual.genotype), mutProb(cIndividual.mutProb) {

}

CIndividual::~CIndividual() = default;

const vector<int> &CIndividual::getGenotype() const {
    return genotype;
}

void CIndividual::mutateIndividual() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> mut(0, 1);
    if (mut(gen) < mutProb) {
        for (int &i : genotype) {
            if (mut(gen) < mutProb) {
                if (i == 0) {
                    i = 1;
                } else {
                    i = 0;
                }
            }
        }
    }
}

void CIndividual::crossIndividuals(CIndividual *cIndividual, int &popSize,
                                   vector<CIndividual *> &newPopulation) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, (int) cIndividual->genotype.size() - 1);
    int crossingPoint = dis(gen);

    CIndividual *firstChildren = new CIndividual(mutProb);
    CIndividual *secondChildren = new CIndividual(mutProb);

    CIndividual *firstParent = this;
    CIndividual *secondParent = cIndividual;

    for (int i = 0; i < firstParent->genotype.size(); ++i) {
        if (i < crossingPoint) {
            firstChildren->genotype.push_back(firstParent->genotype.at(i));
            secondChildren->genotype.push_back(secondParent->genotype.at(i));
        } else {
            firstChildren->genotype.push_back(secondParent->genotype.at(i));
            secondChildren->genotype.push_back(firstParent->genotype.at(i));
        }
    }

    (*firstChildren)++;
    newPopulation.push_back(firstChildren);

    if (newPopulation.size() < popSize) {
        (*secondChildren)++;
        newPopulation.push_back(secondChildren);
    }
}

void CIndividual::operator++(int) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> mut(0, 1);
    if (mut(gen) < mutProb) {
        for (int &i : genotype) {
            if (mut(gen) < mutProb) {
                if (i == 0) {
                    i = 1;
                } else {
                    i = 0;
                }
            }
        }
    }
}



















