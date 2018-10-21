//
// Created by Jakub on 21.10.2018.
//

#include "Comm_3.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void Comm_3::RunCommand() {
    if (CTabHandler::vCTab.empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    cout << "\nPlease enter the table whose length you want to change: ";
    int iTableIndex = Utilities::iProvideIntBetween(0, CTabHandler::vCTab.size()) - 1;
    cout << "Please provide a new length: ";
    CTabHandler::vCTab[iTableIndex]->bSetLength(Utilities::iProvideIntBetween(0, numeric_limits<int>::max()));
}
