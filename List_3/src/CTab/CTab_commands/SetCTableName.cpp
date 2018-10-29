//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "SetCTableName.h"
#include "../../../lib/utilities/Utilities.h"

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