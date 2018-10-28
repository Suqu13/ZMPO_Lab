//
// Created by Jakub on 25.10.2018.
//

#ifndef LIST_2_CAL_COMM_H
#define LIST_2_CAL_COMM_H


#include "../interface/CCommand.h"
#include "../calc/CCalculator.h"

using namespace std;


class Def_Command_For_Calculator : public CCommand {
public:
    explicit Def_Command_For_Calculator(CCalculator &calculator);

protected:
    CCalculator *calulator;
};


#endif //LIST_2_CAL_COMM_H
