//
// Created by Jakub on 25.10.2018.
//

#ifndef LIST_2_CAL_COMM_1_H
#define LIST_2_CAL_COMM_1_H


#define Provide_B "Podaj wartość B: "

#include "Def_Command_For_Calculator.h"

using namespace std;

class SetBValue: public Def_Command_For_Calculator {
public:
    explicit SetBValue(CCalculator &calculator);
    void RunCommand();
};


#endif //LIST_2_CAL_COMM_1_H
