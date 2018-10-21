//
// Created by Jakub on 21.10.2018.
//

#include <iostream>
#include <limits>
#include "Comm_0.h"
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void CCommand::RunCommand() {
    cout << "Please provide a number of CTables to create: ";
    int iNumber = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());
    for (int i = 0; i < iNumber; ++i) {
        CTabHandler::vCTab.push_back(new CTable);
    }
}
