//
// Created by Jakub on 21.10.2018.
//

#include "Comm_1.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

Comm_1::Comm_1(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_1::RunCommand() {
    string sName;
    int iLength;
    do {
        cout << "\nPlease provide a name: ";
        sName = Utilities::sProvideString();

        cout << "Please provide a length: ";
        iLength = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());

        cTabHandler.getVector().push_back(new CTable(sName, iLength));
        cout << "Do you want to create one more specified CTable? (Y/N):";

    } while (Utilities::bYOrNIntepreter());
}

