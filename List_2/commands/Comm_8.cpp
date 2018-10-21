//
// Created by Jakub on 21.10.2018.
//

#include "Comm_8.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void Comm_8::RunCommand() {
    if (CTabHandler::vCTab.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    for (int i = 0; i < CTabHandler::vCTab.size(); i++) {
        cout << (i + 1) << ". Name: " << CTabHandler::vCTab[i]->sGetName() << "; Length: " << CTabHandler::vCTab[i]->iGetLength()
             << "; Elements: "
             << CTabHandler::vCTab[i]->sToString() << endl;
    }
}


