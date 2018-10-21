//
// Created by Jakub on 21.10.2018.
//

#include "Comm_7.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void Comm_7::RunCommand() {
    if (CTabHandler::vCTab.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please provide an index of the table to delete: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, CTabHandler::vCTab.size())) - 1;
    if (CTabHandler::vCTab.size() > iTableIndex) {
        delete CTabHandler::vCTab[iTableIndex];
        CTabHandler::vCTab.erase(CTabHandler::vCTab.begin() + iTableIndex);
    }
}
