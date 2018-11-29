//
// Created by Jakub on 28.11.2018.
//

#include <random>
#include <iostream>
#include <climits>
#include "CGeneticAlgorithm.h"

using namespace std;

CGeneticAlgorithm::CGeneticAlgorithm(const int popSize, const double mutProb, const double crossProb, CKnapsackProblem *cKnapsackProblem)
        : popSize(popSize), mutProb(mutProb), crossProb(crossProb), cKnapsackProblem(cKnapsackProblem), bestSolution(
        nullptr) {}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    for (int i = 0; i < population.size(); ++i) {
        delete population[i];
    }
    delete cKnapsackProblem;
    cout << "Genetic Algorithm object dleted" << endl;
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

    generatePopulation(cKnapsackProblem->getItemsNumber());

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, popSize - 1);
    uniform_real_distribution<> real(0, 1);

    for (int i = 0; i < iterations; i++) {
        vector<CIndividual *> newPopulation;
        crossingProcess(newPopulation, dis(gen), dis(gen), real(gen));
        rewritingPopulation(newPopulation);
        findBestSolution();
    }
    return bestSolution;
}

//void CGeneticAlgorithm::showPopulation() const {
//    for (int i = 0; i < population.size(); ++i) {
//        cout <<"Fitness: " << population[i]->evaluateFitness(cKnapsackProblem) << endl;
//        for (int j = 0; j < population[i]->getGenotype().size(); j++ ) {
//            cout << (population[i]->getGenotype())[j] << " ";
//        }
//        cout << endl;
//    }
//}

void CGeneticAlgorithm::crossingProcess(vector<CIndividual *> &newPopulation, const int firstIndividualIndex, const int secondIndividualIndex, const double currentCrossProb) {
    while (newPopulation.size() != popSize) {
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
    CIndividual* pretendent = new CIndividual(*cKnapsackProblem->getCIndividual());
    if (bestSolution == nullptr || bestSolution->evaluateFitness(cKnapsackProblem) < pretendent->evaluateFitness(cKnapsackProblem)){
        bestSolution = pretendent;
    }
}



