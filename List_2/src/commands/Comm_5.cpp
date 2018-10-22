//
// Created by Jakub on 21.10.2018.
//

#include "Comm_5.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

Comm_5::Comm_5(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_5::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    cout << "\nPlease provide an index of the table to clone: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1);
    cTabHandler.getVector().push_back(new CTable(*cTabHandler.getVector()[(iTableIndex)]));
}
