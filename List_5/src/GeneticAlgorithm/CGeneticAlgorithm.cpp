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
        : popSize(popSize), mutProb(mutProb), crossProb(crossProb), cKnapsackProblem(cKnapsackProblem) {
    if (this->popSize <= 0) this->popSize = 5;
    if (this->mutProb <= 0 || this->mutProb >= 1) this->mutProb = 0.2;
    if (this->crossProb <= 0 || this->crossProb >= 1) this->crossProb = 0.6;
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    for (auto &i : population) {
        delete i;
    }
    delete cKnapsackProblem;
    cout << DEF_GENALG_DELETED << endl;
}

void CGeneticAlgorithm::generatePopulation() {
    while (population.size() < popSize) {
        population.push_back(cKnapsackProblem->createIndividual(mutProb));
    }
}

vector<CItem *> CGeneticAlgorithm::runGeneticAlgorithm(double &timeForIterations) {

    if (timeForIterations <= 0)
        timeForIterations = 1.0;
    double start = time(nullptr);
    generatePopulation();
    double finish = 0;
    while (finish < timeForIterations) {
        vector<CIndividual *> newPopulation;
        reproducePopulation(newPopulation);
        rewritePopulation(newPopulation);
        cKnapsackProblem->findBestCIndividual(population);
        finish = time(nullptr) - start;
    }

    return cKnapsackProblem->getBestItem();
}

void CGeneticAlgorithm::reproducePopulation(vector<CIndividual *> &newPopulation) {
    while (newPopulation.size() < popSize) {

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, popSize - 1);
        uniform_real_distribution<> real(0, 1);
        int firstIndividualIndex = getRandomIndividualFromPopulation();
        int secondIndividualIndex = getRandomIndividualFromPopulation();

        double currentCrossProb = real(gen);

        if (currentCrossProb < crossProb) {
            population.at(firstIndividualIndex)->crossIndividuals(population.at(secondIndividualIndex), popSize,
                                                                  newPopulation);
        } else {
            newPopulation.push_back(new CIndividual(*population.at(firstIndividualIndex)));
            if (newPopulation.size() < popSize)
                newPopulation.push_back(new CIndividual(*population.at(secondIndividualIndex)));
        }
    }
}

void CGeneticAlgorithm::rewritePopulation(vector<CIndividual *> &newPopulation) {
    for (int k = 0; k < popSize; k++) {
        delete population.at(k);
    }
    population.clear();

    for (int j = 0; j < newPopulation.size(); ++j) {
        population.push_back(newPopulation.at(j));
    }
    newPopulation.clear();
}

int CGeneticAlgorithm::getRandomIndividualFromPopulation() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, popSize - 1);
    int first = dis(gen);
    int second = dis(gen);

    if (cKnapsackProblem->checkIfGreater(population.at(first), population.at(second))) {
        return first;
    } else {
        return second;
    }
}



