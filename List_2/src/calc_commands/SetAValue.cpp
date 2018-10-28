//
// Created by Jakub on 25.10.2018.
//

#include <iostream>
#include "SetAValue.h"
#include "../utilities/Utilities.h"

using namespace std;



void SetAValue::RunCommand() {
    cout << Provide_A;
    calulator->setAValue(Utilities::iProvideInt());
}

SetAValue::SetAValue(CCalculator &calculator) : Def_Command_For_Calculator(calculator) {

}
