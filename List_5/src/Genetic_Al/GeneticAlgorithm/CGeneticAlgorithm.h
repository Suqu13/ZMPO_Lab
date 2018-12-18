//
// Created by jakub on 10.12.18.
//

#ifndef LIST_3_CGENETICALGORITHM_H
#define LIST_3_CGENETICALGORITHM_H
//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_5_CGENETICALGORITHM_H
#define LIST_5_CGENETICALGORITHM_H

#define DEF_GENALG_DELETED "GeneticAlgorithm object deleted"
#define DEF_TIME_MEASURE "Measured time: "

#include <random>
#include <iostream>
#include <climits>
#include <vector>
#include "../KnapsackProblem/CKnapsackProblem.h"
#include "../KnapsackProblem/CItem.h"


using namespace std;

template<class T>
class CGeneticAlgorithm {

private:
    int popSize;
    double mutProb;
    double crossProb;
    vector<CIndividual<T> *> population;
    CKnapsackProblem<T> *cKnapsackProblem;

    int getBetterFromTwo();
    void generatePopulation();
    void reproducePopulation(vector<CIndividual<T> *> &newPopulation);
    void rewritePopulation(vector<CIndividual<T> *> &newPopulation);

public:
    CGeneticAlgorithm(int popSize, double mutProb, double crossProb, CKnapsackProblem<T> *cKnapsackProblem);
    ~CGeneticAlgorithm();
    vector<CItem *> runGeneticAlgorithm(int &timeForIterations);
};

template<class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(const int popSize, const double mutProb, const double crossProb,
                                        CKnapsackProblem<T> *cKnapsackProblem)
        : popSize(popSize), mutProb(mutProb), crossProb(crossProb), cKnapsackProblem(cKnapsackProblem) {
    if (this->popSize <= 0) this->popSize = 5;
    if (this->mutProb <= 0 || this->mutProb >= 1) this->mutProb = 0.2;
    if (this->crossProb <= 0 || this->crossProb >= 1) this->crossProb = 0.6;
}

template<class T>
CGeneticAlgorithm<T>::~CGeneticAlgorithm() {
    for (auto &i : population) {
        delete i;
    }
    delete cKnapsackProblem;
    cout << DEF_GENALG_DELETED << endl;
}

template<class T>
void CGeneticAlgorithm<T>::generatePopulation() {
    while (population.size() < popSize) {
        population.push_back(cKnapsackProblem->createIndividual(mutProb));
    }
}

template<class T>
vector<CItem *> CGeneticAlgorithm<T>::runGeneticAlgorithm(int &timeForIterations) {
    if (timeForIterations <= 0)
        timeForIterations = 1;
    double start = time(nullptr);
    generatePopulation();
    double finish = 0;
    while (finish < timeForIterations) {
        vector<CIndividual<T> *> newPopulation;
        reproducePopulation(newPopulation);
        rewritePopulation(newPopulation);
        cKnapsackProblem->findBestCIndividual(population);
        finish = time(nullptr) - start;
    }
    cout << DEF_TIME_MEASURE << finish << "s" << endl;

    return cKnapsackProblem->getBestItem();
}

//TODO ZJEBANE
template<class T>
void CGeneticAlgorithm<T>::reproducePopulation(vector<CIndividual<T> *> &newPopulation) {
    while (newPopulation.size() < popSize) {

        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> real(0, 1);

        int firstIndividualIndex = getBetterFromTwo();
        int secondIndividualIndex = getBetterFromTwo();

        if (real(gen) < crossProb) {
            CIndividual<T> *firstChild = ((*population.at(firstIndividualIndex)) + (*population.at(secondIndividualIndex)));
            CIndividual<T> *secondChild = ((*population.at(secondIndividualIndex)) + (*population.at(firstIndividualIndex)));

            if (newPopulation.size() + 1 < popSize) {
                newPopulation.push_back(secondChild);
                newPopulation.push_back(firstChild);
            } else if (newPopulation.size() < popSize) {
                if (cKnapsackProblem->checkIfGreater(firstChild, secondChild)) {
                    newPopulation.push_back(firstChild);
                } else {
                    newPopulation.push_back(secondChild);
                }
            }
        } else {
            if (newPopulation.size() + 1 < popSize) {
                newPopulation.push_back(new CIndividual<T>(*population.at(firstIndividualIndex)));
                newPopulation.push_back(new CIndividual<T>(*population.at(secondIndividualIndex)));
            } else if (newPopulation.size() < popSize) {
                if (cKnapsackProblem->checkIfGreater(population.at(firstIndividualIndex),
                                                     population.at(secondIndividualIndex))) {
                    newPopulation.push_back(new CIndividual<T>(*population.at(firstIndividualIndex)));
                } else {
                    newPopulation.push_back(new CIndividual<T>(*population.at(secondIndividualIndex)));
                }
            }
        }
    }
}

template<class T>
void CGeneticAlgorithm<T>::rewritePopulation(vector<CIndividual<T> *> &newPopulation) {
    for (int k = 0; k < popSize; k++) {
        delete population.at(k);
    }
    population.clear();

    for (int j = 0; j < newPopulation.size(); ++j) {
        population.push_back(newPopulation.at(j));
    }
    newPopulation.clear();
}

template<class T>
int CGeneticAlgorithm<T>::getBetterFromTwo() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, popSize - 1);
    int first;
    int second;

    do {
        first = dis(gen);
        second = dis(gen);
    }while (first == second);

    if (cKnapsackProblem->checkIfGreater(population.at(first), population.at(second))) {
        return first;
    } else {
        return second;
    }
}

#endif //LIST_5_CGENETICALGORITHM_H
#endif //LIST_3_CGENETICALGORITHM_H
