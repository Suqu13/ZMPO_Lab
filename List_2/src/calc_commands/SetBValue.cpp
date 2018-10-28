//
// Created by Jakub on 25.10.2018.
//

#include <iostream>
#include "SetBValue.h"
#include "../utilities/Utilities.h"

using namespace std;

void SetBValue::RunCommand() {
    cout << Provide_B;
    calulator->setBValue(Utilities::iProvideInt());
}

SetBValue::SetBValue(CCalculator &calculator) : Def_Command_For_Calculator(calculator) {

}
