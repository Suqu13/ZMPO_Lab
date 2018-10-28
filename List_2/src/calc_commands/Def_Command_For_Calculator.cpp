//
// Created by Jakub on 25.10.2018.
//

#include "Def_Command_For_Calculator.h"
#include "../calc/CCalculator.h"

using namespace std;


Def_Command_For_Calculator::Def_Command_For_Calculator(CCalculator &calculator) {
    this->calulator = &calculator;
}


