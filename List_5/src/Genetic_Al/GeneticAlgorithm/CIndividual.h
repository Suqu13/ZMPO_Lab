//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_5_CINDIVIDUAL_H
#define LIST_5_CINDIVIDUAL_H

#include <vector>
#include <iostream>


using namespace std;

template<typename T>
class CIndividual {
private:

    vector<T> genotype;
    double mutProb;
    vector<double> maxItems;

    void mutate();

public:

    CIndividual();

    explicit CIndividual(double mutProb, vector<double> &maxItems);

    explicit CIndividual(const vector<T> &genotype, double mutProb, vector<double> &maxItems);

    CIndividual(CIndividual &cIndividual);

    ~CIndividual();

    void operator++(int);

    CIndividual operator+(CIndividual *secondParent);

    const vector<T> &getGenotype() const;
};

template<class T>
CIndividual<T>::CIndividual() = default;

template<class T>
CIndividual<T>::CIndividual(const double mutProb, vector<double> &maxItems) : mutProb(mutProb), maxItems(maxItems) {}


template<class T>
CIndividual<T>::CIndividual(const vector<T> &genotype, const double mutProb, vector<double> &maxItems) : genotype(
        genotype), mutProb(mutProb), maxItems(maxItems) {}

template<class T>
CIndividual<T>::CIndividual(CIndividual &cIndividual): genotype(cIndividual.genotype), mutProb(cIndividual.mutProb),
                                                       maxItems(cIndividual.maxItems) {

}

template<class T>
CIndividual<T>::~CIndividual() {
    maxItems.clear();
}

template<class T>
void CIndividual<T>::operator++(int) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> mut(0, 1);
    if (mut(gen) < mutProb) {
        mutate();
    }
}


template<class T>
void CIndividual<T>::mutate() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> mut(0, 1);
    for (int i = 0; i < genotype.size(); i++) {
        if (mut(gen) < mutProb) {
            uniform_real_distribution<> fold(-(maxItems.at(i)/2), maxItems.at(i));
            T newFactor = fold(gen);
            newFactor > 0 ? genotype.at(i) = newFactor : genotype.at(i) = 0;
        }
    }
}

template<>
void CIndividual<bool>::mutate() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> mut(0, 1);
    for (int i = 0; i < genotype.size(); i++) {
        if (mut(gen) < mutProb) {
            genotype.at(i) = !genotype.at(i);
        }
    }
}

template<class T>
CIndividual<T> CIndividual<T>::operator+(CIndividual *secondParent) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, int (this->genotype.size() - 1));
    int crossingPoint = dis(gen);

    CIndividual children(mutProb, this->maxItems);

    for (int i = 0; i < genotype.size(); ++i) {
        if (i < crossingPoint) {
            children.genotype.push_back(genotype.at(i));
        } else {
            children.genotype.push_back(secondParent->genotype.at(i));
        }
    }
    children++;
    return children;
}

template<class T>
const vector<T> &CIndividual<T>::getGenotype() const {
    return genotype;
}


#endif //LIST_5_CINDIVIDUAL_H
