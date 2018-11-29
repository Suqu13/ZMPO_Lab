//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CGENETICALGORITHM_H
#define LIST_4_CGENETICALGORITHM_H



#include <vector>
#include "../KnapsackProblem/CKnapsackProblem.h"

using namespace std;

class CIndividual;

class CGeneticAlgorithm {

private:
    int popSize;
    double mutProb;
    double crossProb;
    CIndividual* bestSolution;
    vector<CIndividual *> population;
    CKnapsackProblem *cKnapsackProblem;

    void generatePopulation(const int &genotypeSize);
    void showPopulation() const;

public:
    CGeneticAlgorithm(int popSize, double mutProb, double crossProb, CKnapsackProblem *cKnapsackProblem);
    ~CGeneticAlgorithm();

    CIndividual *runGeneticAlgorithm(int iterations);
};


#endif //LIST_4_CGENETICALGORITHM_H
