//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CINDIVIDUAL_H
#define LIST_4_CINDIVIDUAL_H
#include <vector>
#include "KnapsackProblem/CKnapsackProblem.h"

using namespace std;

class CKnapsackProblem;

class CIndividual {
private:

    vector<int> genotype;
    CKnapsackProblem *cKnapsackProblem;

    void mutateIndividual(const int &mutProb);
public:

    CIndividual(CKnapsackProblem *cKnapsackProblem);
    CIndividual(const vector<int> &genotype, CKnapsackProblem *cKnapsackProblem);
    CIndividual(CIndividual &cIndividual);
    ~CIndividual();
    int evaluateFitness();
    void crossIndividuals(CIndividual *cIndividual, double &mutProb, vector<CIndividual *> &newPopulation);

    CKnapsackProblem *getCKnapsackProblem() const;

    const vector<int> &getGenotype() const;

};


#endif //LIST_4_CINDIVIDUAL_H
