//
// Created by Jakub on 25.10.2018.
//

#ifndef LIST_2_CAL_COMM_0_H
#define LIST_2_CAL_COMM_0_H


#define Provide_A "Podaj wartość A: "

#include "../calc/CCalculator.h"
#include "Def_Command_For_Calculator.h"

using namespace std;


class SetAValue: public Def_Command_For_Calculator {

public:
    explicit SetAValue(CCalculator &calculator);
    void RunCommand();
};


#endif //LIST_2_CAL_COMM_0_H
