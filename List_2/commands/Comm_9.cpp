//
// Created by Jakub on 21.10.2018.
//

#include "Comm_9.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void Comm_9::RunCommand() {
    if (CTabHandler::vCTab.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please provide an index of the table to show: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, CTabHandler::vCTab.size())) - 1;
    cout << (iTableIndex + 1) << ". Name: " << CTabHandler::vCTab[iTableIndex]->sGetName() << "; Length: "
         << CTabHandler::vCTab[iTableIndex]->iGetLength()
         << "; Elements: "
         << CTabHandler::vCTab[iTableIndex]->sToString() << endl;
}

