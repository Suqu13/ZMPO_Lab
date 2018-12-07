//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CINDIVIDUAL_H
#define LIST_4_CINDIVIDUAL_H
#include <vector>
#include "../KnapsackProblem/CKnapsackProblem.h"

using namespace std;

class CKnapsackProblem;

class CIndividual {
private:

    vector<int> genotype;

    void mutateIndividual(const double &mutProb);
public:

    CIndividual();
    explicit CIndividual(const vector<int> &genotype);
    CIndividual(CIndividual &cIndividual);
    ~CIndividual();
    const vector<int> &getGenotype() const;
    void crossIndividuals(CIndividual *cIndividual,int &popSize, double &mutProb, vector<CIndividual *> &newPopulation);

};


#endif //LIST_4_CINDIVIDUAL_H
