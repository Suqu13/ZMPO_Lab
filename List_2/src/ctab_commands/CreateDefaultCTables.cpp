//
// Created by Jakub on 21.10.2018.
//

#include <iostream>
#include <limits>
#include "CreateDefaultCTables.h"
#include "../utilities/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

CreateDefaultCTables::CreateDefaultCTables(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void CreateDefaultCTables::RunCommand() {
    cout << "\n" << Provide_INT;
    int iNumber = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());
    for (int i = 0; i < iNumber; ++i) {
        cTabHandler.getVector().push_back(new CTable);
    }
}


