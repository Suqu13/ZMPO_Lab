//
// Created by Jakub on 25.10.2018.
//

#ifndef LIST_2_CAL_COMM_3_H
#define LIST_2_CAL_COMM_3_H


#define RESULT "Wynik: "

#include "Def_Command_For_Calculator.h"

using namespace std;

class SubstractValues: public Def_Command_For_Calculator {
public:
    explicit SubstractValues(CCalculator &calculator);
    void RunCommand();
};


#endif //LIST_2_CAL_COMM_3_H
