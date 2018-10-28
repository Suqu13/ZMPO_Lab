//
// Created by Jakub on 25.10.2018.
//

#include <iostream>
#include "SubstractValues.h"

using namespace std;

void SubstractValues::RunCommand() {
    cout << RESULT << calulator->substract() << endl;
}

SubstractValues::SubstractValues(CCalculator &calculator) : Def_Command_For_Calculator(calculator) {
}
