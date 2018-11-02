//
// Created by Jakub on 29.10.2018.
//

#include "CloneCTable.h"
#include "CloneCTable.h"
#include <iostream>
#include <limits>
#include "../CTable.h"
#include "../../../lib/utilities/Utilities.h"

CloneCTable::CloneCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void CloneCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << MESSAGE_IF_EMPTY << endl;
        return;
    }
    cout << "\n" << PROVIDE_INDEX_TO_CLONE;
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1);
    cTabHandler.getVector().push_back(new CTable(*cTabHandler.getVector()[(iTableIndex)]));
}