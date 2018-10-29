//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "RemoveSingleCTable.h"
#include "../../../lib/utilities/Utilities.h"


RemoveSingleCTable::RemoveSingleCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void RemoveSingleCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << Message_If_Empty << endl;
        return;
    }
    cout << "\n" << Provide_INDEX;
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size())) - 1;
    if (cTabHandler.getVector().size() > iTableIndex) {
        delete cTabHandler.getVector()[iTableIndex];
        cTabHandler.getVector().erase(cTabHandler.getVector().begin() + iTableIndex);
    }
}