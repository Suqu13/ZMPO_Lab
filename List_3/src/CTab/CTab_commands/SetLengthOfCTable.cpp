//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include <limits>
#include "SetLengthOfCTable.h"
#include "../../../utilities/Utilities.h"

SetLengthOfCTable::SetLengthOfCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void SetLengthOfCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << Message_If_Empty << endl;
        return;
    }
    cout << "\n" << Provide_INDEX;
    int iTableIndex = Utilities::iProvideIntBetween(0, cTabHandler.getVector().size()) - 1;
    cout << Provide_LENGTH;
    cTabHandler.getVector()[iTableIndex]->bSetLength(Utilities::iProvideIntBetween(0, numeric_limits<int>::max()));
}