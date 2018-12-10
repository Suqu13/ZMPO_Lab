//
// Created by Jakub on 21.10.2018.
//

#include "CreateSpecificCTables.h"
#include <iostream>
#include <limits>
#include "../utilities/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

CreateSpecificCTables::CreateSpecificCTables(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void CreateSpecificCTables::RunCommand() {
    string sName;
    int iLength;
    do {
        cout << "\n" << Provide_NAME;
        sName = Utilities::sProvideString();

        cout << Provide_LENGTH;
        iLength = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());

        cTabHandler.getVector().push_back(new CTable(sName, iLength));
        cout << REPEAT;

    } while (Utilities::bYOrNIntepreter());
}

