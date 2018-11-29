//
// Created by Jakub on 28.11.2018.
//

#include <random>
#include <iostream>
#include <climits>
#include "CGeneticAlgorithm.h"

using namespace std;

CGeneticAlgorithm::CGeneticAlgorithm(const int popSize, const double mutProb, const double crossProb, CKnapsackProblem *cKnapsackProblem)
        : popSize(popSize), mutProb(mutProb), crossProb(crossProb), cKnapsackProblem(cKnapsackProblem) {}

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
        CIndividual *cIndividual;
        if ((cIndividual = new CIndividual(genotype, cKnapsackProblem))->evaluateFitness() != 0)
            population.push_back(cIndividual);
    }
    showPopulation();
}

CIndividual *CGeneticAlgorithm::runGeneticAlgorithm(int iterations) {
    generatePopulation(cKnapsackProblem->getItemsNumber());

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, popSize - 1);
    uniform_real_distribution<> real(0, 1);


    for (int i = 0; i < iterations; i++) {
        vector<CIndividual *> newPopulation;
        while (newPopulation.size() != popSize) {
            int firstIndividualIndex = dis(gen);
            int secondIndividualIndex = dis(gen);
            if (real(gen) < crossProb) {
                population.at(firstIndividualIndex)->crossIndividuals(population.at(secondIndividualIndex), mutProb,
                                                                   newPopulation);
            } else {
                newPopulation.push_back(new CIndividual(*population.at(firstIndividualIndex)));
                newPopulation.push_back(new CIndividual(*population.at(secondIndividualIndex)));
            }
        }

        for (int k = 0; k < popSize; k++) {
            delete population.at(k);
        }
        population.clear();

        for (int j = 0; j < newPopulation.size(); ++j) {
            population.push_back(newPopulation.at(j));
        }
        newPopulation.clear();
        showPopulation();
        CIndividual* pretendent;
        if (bestSolution == nullptr || bestSolution < (pretendent = cKnapsackProblem->getBest(population))) {
            bestSolution = pretendent;
        }
    }
    return bestSolution;
}

void CGeneticAlgorithm::showPopulation() const {
    for (int i = 0; i < population.size(); ++i) {
        cout <<"Fitness: " << population[i]->evaluateFitness() << endl;
        for (int j = 0; j < population[i]->getGenotype().size(); j++ ) {
            cout << (population[i]->getGenotype())[j] << " ";
        }
        cout << endl;
    }
}



