//
// Created by Jakub on 21.10.2018.
//

#include "Comm_5.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void Comm_5::RunCommand() {
    if (CTabHandler::vCTab.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please provide an index of the table to clone: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, CTabHandler::vCTab.size()) - 1);
    CTabHandler::vCTab.push_back(new CTable(*CTabHandler::vCTab[(iTableIndex)]));
}
