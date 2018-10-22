//
// Created by Jakub on 21.10.2018.
//

#include "Comm_8.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

Comm_8::Comm_8(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_8::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    for (int i = 0; i < cTabHandler.getVector().size(); i++) {
        cout << (i + 1) << ". Name: " << cTabHandler.getVector()[i]->sGetName() << "; Length: " << cTabHandler.getVector()[i]->iGetLength()
             << "; Elements: "
             << cTabHandler.getVector()[i]->sToString() << endl;
    }
}



