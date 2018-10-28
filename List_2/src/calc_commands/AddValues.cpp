//
// Created by Jakub on 25.10.2018.
//

#include <iostream>
#include "AddValues.h"

using namespace std;

void AddValues::RunCommand() {
    cout << RESULT << calulator->add() << endl;
}

AddValues::AddValues(CCalculator &calculator) : Def_Command_For_Calculator(calculator) {

}
