//
// Created by Jakub on 28.11.2018.
//

#include <random>
#include <iostream>
#include <climits>
#include "CGeneticAlgorithm.h"

using namespace std;

CGeneticAlgorithm::CGeneticAlgorithm(const int popSize, const double mutProb, const double crossProb,
                                     CKnapsackProblem *cKnapsackProblem)
        : popSize(popSize), mutProb(mutProb), crossProb(crossProb), cKnapsackProblem(cKnapsackProblem), bestSolution(
        nullptr) {
    if (this->popSize <= 0) this->popSize = 5;
    if (this->mutProb <= 0 || this->mutProb >= 1) this->mutProb = 0.2;
    if (this->crossProb <= 0 || this->crossProb >= 1) this->crossProb = 0.6;
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    for (int i = 0; i < population.size(); ++i) {
        delete population[i];
    }
    delete cKnapsackProblem;
    cout << DEF_GENALG_DELETED << endl;
}

void CGeneticAlgorithm::generatePopulation(const int &genotypeSize) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    while (population.size() < popSize) {
        vector<int> genotype;
        for (int i = 0; i < genotypeSize; ++i) {
            genotype.push_back(dis(gen));
        }
        CIndividual *cIndividual = new CIndividual(genotype);
        population.push_back(cIndividual);
    }
}

CIndividual *CGeneticAlgorithm::runGeneticAlgorithm(int iterations) {

    if (iterations <= 0) iterations = 10;

    generatePopulation(cKnapsackProblem->getItems().size());

    for (int i = 0; i < iterations; i++) {
        vector<CIndividual *> newPopulation;
        crossingProcess(newPopulation);
        rewritingPopulation(newPopulation);
        findBestSolution();
    }
    return bestSolution;
}

void CGeneticAlgorithm::crossingProcess(vector<CIndividual *> &newPopulation) {
    while (newPopulation.size() != popSize) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, popSize - 1);
        uniform_real_distribution<> real(0, 1);
        int firstIndividualIndex = dis(gen);
        const int secondIndividualIndex = dis(gen);
        double currentCrossProb = real(gen);

        if (currentCrossProb < crossProb) {
            population.at(firstIndividualIndex)->crossIndividuals(population.at(secondIndividualIndex), mutProb,
                                                                  newPopulation, cKnapsackProblem);
        } else {
            newPopulation.push_back(new CIndividual(*population.at(firstIndividualIndex)));
            newPopulation.push_back(new CIndividual(*population.at(secondIndividualIndex)));
        }
    }
}

void CGeneticAlgorithm::rewritingPopulation(vector<CIndividual *> &newPopulation) {
    for (int k = 0; k < popSize; k++) {
        delete population.at(k);
    }
    population.clear();

    for (int j = 0; j < newPopulation.size(); ++j) {
        population.push_back(newPopulation.at(j));
    }
    newPopulation.clear();
}

void CGeneticAlgorithm::findBestSolution() {
    cKnapsackProblem->findBestCIndividual(population);
    CIndividual *candidate = new CIndividual(*cKnapsackProblem->getCIndividual());
    if (bestSolution == nullptr ||
        bestSolution->evaluateFitness(cKnapsackProblem) < candidate->evaluateFitness(cKnapsackProblem)) {
        delete bestSolution;
        bestSolution = new CIndividual(*candidate);
    }
    delete candidate;
}


