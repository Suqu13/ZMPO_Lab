//
// Created by Jakub on 28.10.2018.
//

#include "ResetValues.h"

ResetValues::ResetValues(CCalculator &calculator) : Def_Command_For_Calculator(calculator) {

}

void ResetValues::RunCommand() {
    calulator->setAValue(0);
    calulator->setBValue(0);
}
