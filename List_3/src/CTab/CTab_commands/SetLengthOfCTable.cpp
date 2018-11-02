//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include <limits>
#include "SetLengthOfCTable.h"
#include "../../../lib/utilities/Utilities.h"

SetLengthOfCTable::SetLengthOfCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void SetLengthOfCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << MESSAGE_IF_EMPTY << endl;
        return;
    }
    cout << "\n" << PROVIDE_INDEX_TABLE_TO_SET_LENGTH;
    int iTableIndex = Utilities::iProvideIntBetween(0, cTabHandler.getVector().size()) - 1;
    cout << PROVIDE_NEW_LENGTH;
    cTabHandler.getVector()[iTableIndex]->bSetLength(Utilities::iProvideIntBetween(0, numeric_limits<int>::max()));
}