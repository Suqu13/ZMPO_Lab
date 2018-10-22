//
// Created by Jakub on 21.10.2018.
//

#include "Comm_9.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"
#include "Comm_6.h"

Comm_9::Comm_9(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_9::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    cout << "\nPlease provide an index of the table to show: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size())) - 1;
    cout << (iTableIndex + 1) << ". Name: " << cTabHandler.getVector()[iTableIndex]->sGetName() << "; Length: "
         << cTabHandler.getVector()[iTableIndex]->iGetLength()
         << "; Elements: "
         << cTabHandler.getVector()[iTableIndex]->sToString() << endl;
}



