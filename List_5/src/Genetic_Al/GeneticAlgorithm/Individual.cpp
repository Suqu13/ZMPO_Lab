//
// Created by jakub on 18.12.18.
//
#include <random>
#include "CIndividual.h"

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
