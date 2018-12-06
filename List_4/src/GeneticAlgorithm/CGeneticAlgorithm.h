//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CGENETICALGORITHM_H
#define LIST_4_CGENETICALGORITHM_H

#define DEF_GENALG_DELETED "GeneticAlgorithm object dleted"

#include <vector>
#include "../KnapsackProblem/CKnapsackProblem.h"

using namespace std;

class CIndividual;

class CGeneticAlgorithm {

private:
    int popSize;
    double mutProb;
    double crossProb;
    vector<CIndividual *> population;
    CKnapsackProblem *cKnapsackProblem;

    int getRandomIndividualFromPopulation();
    void generatePopulation();
    void reproducePopulation(vector<CIndividual *> &newPopulation);
    void rewritePopulation(vector<CIndividual *> &newPopulation);
public:
    CGeneticAlgorithm(int popSize, double mutProb, double crossProb, CKnapsackProblem *cKnapsackProblem);
    ~CGeneticAlgorithm();
    vector<CItem *> runGeneticAlgorithm(int iterations);
};


#endif //LIST_4_CGENETICALGORITHM_H
