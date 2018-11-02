//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "RemoveSingleCTable.h"
#include "../../../lib/utilities/Utilities.h"


RemoveSingleCTable::RemoveSingleCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void RemoveSingleCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << MESSAGE_IF_EMPTY << endl;
        return;
    }
    cout << "\n" << PROVIDE_INDEX_TABLE_TO_DELETE;
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size())) - 1;
    if (cTabHandler.getVector().size() > iTableIndex) {
        delete cTabHandler.getVector()[iTableIndex];
        cTabHandler.getVector().erase(cTabHandler.getVector().begin() + iTableIndex);
    }
}