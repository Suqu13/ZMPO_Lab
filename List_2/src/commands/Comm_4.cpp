//
// Created by Jakub on 21.10.2018.
//

#include "Comm_4.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

Comm_4::Comm_4(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_4::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    cout << "\nPlease provide an index of the table to change name: ";
    int iTableIndex = Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1;
    cout << "Please provide the name: ";
    string sNewName = Utilities::sProvideString();
    cTabHandler.getVector()[iTableIndex]->vSetName(sNewName);
}
