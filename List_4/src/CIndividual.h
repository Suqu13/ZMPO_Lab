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

    void mutateIndividual(const double &mutProb);
public:

    CIndividual();
    CIndividual(const vector<int> &genotype);
    CIndividual(CIndividual &cIndividual);
    ~CIndividual();
    const vector<int> &getGenotype() const;
    int evaluateFitness(const CKnapsackProblem *cKnapsackProblem);
    void crossIndividuals(CIndividual *cIndividual, double &mutProb, vector<CIndividual *> &newPopulation, const CKnapsackProblem *cKnapsackProblem);

};


#endif //LIST_4_CINDIVIDUAL_H
