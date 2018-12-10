//
// Created by Jakub on 29.10.2018.
//

#include "CreateSpecificCTables.h"
#include <iostream>
#include <limits>
#include "../CTable.h"
#include "../../../lib/utilities/Utilities.h"

CreateSpecificCTables::CreateSpecificCTables(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void CreateSpecificCTables::RunCommand() {
    string sName;
    int iLength;
    do {
        cout << "\n" << PROVIDE_NAME;
        sName = Utilities::sProvideString();

        cout << PROVIDE_LENGTH;
        iLength = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());

        cTabHandler.getVector().push_back(new CTable(sName, iLength));
        cout << REPEATING_OPERATION;

    } while (Utilities::bYOrNIntepreter());
}