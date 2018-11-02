//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include <limits>
#include "CreateDefaultCTables.h"
#include "../../../lib/utilities/Utilities.h"

CreateDefaultCTables::CreateDefaultCTables(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void CreateDefaultCTables::RunCommand() {
    cout << "\n" << PROVIDE_AMOUNT;
    int iNumber = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());
    for (int i = 0; i < iNumber; ++i) {
        cTabHandler.getVector().push_back(new CTable);
    }
}