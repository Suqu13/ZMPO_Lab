//
// Created by jakub on 10.12.18.
//

#define DEF_SEPARATOR "********************************************"
#define DEF_BACKPACK_CAPACITY "Provide a backpack capacity: "
#define DEF_POPULATION_SIZE "Provide a population size: "
#define DEF_MUTATION_PROBABILITY "Provide a mutation probability: "
#define DEF_CROSSING_PROBABILITY "Provide a crossing probability: "
#define DEF_TIME "Provide a time for algorithm in seconds: "
#define DEF_BEST_SOLUTION "The best solution!"
#define SUM_W "Weights sum: "
#define SUM_V "Values sum: "

#ifndef LIST_3_RUNFORINT_H
#define LIST_3_RUNFORINT_H


#define DEF_WORK_IN_PROGRESS "Work in progress..."

#include <vector>
#include "../../lib/interface/CCommand.h"
#include "../Genetic_Al/GeneticAlgorithm/CGeneticAlgorithm.h"
#include "../../lib/utilities/Utilities.h"

template<class T>
class GeneticAlgorithm_command : public CCommand {
private:
    vector<CItem *> itemVector;
public:
    explicit GeneticAlgorithm_command(const vector<CItem *> &itemVector);

    void RunCommand() override;

};

template<class T>
GeneticAlgorithm_command<T>::GeneticAlgorithm_command(const vector<CItem *> &itemVector) : itemVector(itemVector) {
};

template<class T>
void GeneticAlgorithm_command<T>::RunCommand() {

    cout << "\n" << DEF_SEPARATOR << endl;
    cout << DEF_BACKPACK_CAPACITY;
    int maxCapacity = Utilities::inputPositiveInt();
    cout << DEF_POPULATION_SIZE;
    int popSize = Utilities::inputPositiveInt();
    cout << DEF_MUTATION_PROBABILITY;
    double mutProb = Utilities::inputPositiveDoubleBet0_1();
    cout << DEF_CROSSING_PROBABILITY;
    double crossProb = Utilities::inputPositiveDoubleBet0_1();
    cout << DEF_TIME;
    int time = Utilities::inputPositiveInt();
    cout << "\n" <<  DEF_SEPARATOR << endl;

    cout << DEF_WORK_IN_PROGRESS << endl;

    CKnapsackProblem<T> *cKnapsackProblem;
    cKnapsackProblem = new CKnapsackProblem<T>(itemVector, maxCapacity);
    CGeneticAlgorithm<T> geneticAlgorithm(popSize, mutProb, crossProb, cKnapsackProblem);
    vector<CItem *> bestItems = geneticAlgorithm.runGeneticAlgorithm(time);

    cout << "\n" << DEF_SEPARATOR << endl;
    double weightSum = 0;
    double valSum = 0;

    cout << DEF_BEST_SOLUTION << endl;

    for (int i = 0; i < bestItems.size(); i++) {
        cout << *bestItems.at(i) << endl;
        weightSum += (bestItems.at(i)->getWeight()) * (bestItems.at(i)->getFactor());
        valSum += (bestItems.at(i)->getValue()) * (bestItems.at(i)->getFactor());
    }

    cout << SUM_W << weightSum << endl;
    cout << SUM_V << valSum << endl;

    cout << "\n" << DEF_SEPARATOR  << endl;

    for (int i = 0; i < itemVector.size(); i++) {
        itemVector.at(i)->setFactor(1);
    }
}


#endif //LIST_3_RUNFORINT_H

