//
// Created by Jakub on 21.10.2018.
//

#include "RemoveSingleCTable.h"
#include <iostream>
#include <limits>
#include "../utilities/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

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
