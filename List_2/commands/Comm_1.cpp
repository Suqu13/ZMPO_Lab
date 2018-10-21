//
// Created by Jakub on 21.10.2018.
//

#include "Comm_1.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"


void Comm_1::RunCommand() {
    string sName;
    int iLength;
    do {
        cout << "Please provide a name: ";
        sName = Utilities::sProvideString();

        cout << "Please provide a length: ";
        iLength = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());

        CTabHandler::vCTab.push_back(new CTable(sName, iLength));
        cout << "Do you want to create one more specified CTable? (Y/N):";

    } while (Utilities::bYOrNIntepreter());
}

