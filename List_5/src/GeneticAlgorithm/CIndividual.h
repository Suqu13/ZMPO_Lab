//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_5_CINDIVIDUAL_H
#define LIST_5_CINDIVIDUAL_H
#include <vector>
#include "../KnapsackProblem/CKnapsackProblem.h"

using namespace std;

class CIndividual {
private:

    vector<int> genotype;
    double mutProb;


    void mutateIndividual();
public:

    CIndividual();
    explicit CIndividual(double mutProb);
    explicit CIndividual(const vector<int> &genotype, double mutProb);
    CIndividual(CIndividual &cIndividual);
    ~CIndividual();
    void operator++(int);
    CIndividual *operator+(CIndividual *secondParent);
    const vector<int> &getGenotype() const;
    void crossIndividuals(CIndividual *cIndividual,int &popSize, vector<CIndividual *> &newPopulation);

};


#endif //LIST_5_CINDIVIDUAL_H
