//
// Created by Jakub on 21.10.2018.
//

#include "SetCTableName.h"
#include <iostream>
#include <limits>
#include "../utilities/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

SetCTableName::SetCTableName(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void SetCTableName::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << Message_If_Empty << endl;
        return;
    }
    cout << "\n" << Provide_INDEX;
    int iTableIndex = Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1;
    cout << Provide_INT;
    string sNewName = Utilities::sProvideString();
    cTabHandler.getVector()[iTableIndex]->vSetName(sNewName);
}
