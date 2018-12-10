//
// Created by Jakub on 21.10.2018.
//

#include "SetLengthOfCTable.h"
#include <iostream>
#include <limits>
#include "../utilities/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

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

