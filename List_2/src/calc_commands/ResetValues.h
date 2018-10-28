//
// Created by Jakub on 28.10.2018.
//

#ifndef LIST_2_RESTARTVALUES_H
#define LIST_2_RESTARTVALUES_H


#include "Def_Command_For_Calculator.h"

class ResetValues: public Def_Command_For_Calculator{
public:
    explicit ResetValues(CCalculator &calculator);
    void RunCommand();
};


#endif //LIST_2_RESTARTVALUES_H
