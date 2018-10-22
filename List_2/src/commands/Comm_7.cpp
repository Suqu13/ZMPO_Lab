//
// Created by Jakub on 21.10.2018.
//

#include "Comm_7.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

Comm_7::Comm_7(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_7::RunCommand() {
        if (cTabHandler.getVector().empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    cout << "\nPlease provide an index of the table to delete: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size())) - 1;
    if (cTabHandler.getVector().size() > iTableIndex) {
        delete cTabHandler.getVector()[iTableIndex];
        cTabHandler.getVector().erase(cTabHandler.getVector().begin() + iTableIndex);
    }
}
