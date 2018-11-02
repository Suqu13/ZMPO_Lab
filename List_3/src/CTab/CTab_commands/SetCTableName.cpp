//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "SetCTableName.h"
#include "../../../lib/utilities/Utilities.h"

SetCTableName::SetCTableName(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void SetCTableName::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << MESSAGE_IF_EMPTY << endl;
        return;
    }
    cout << "\n" << PROVIDE_INDEX_TABLE_TO_SET_NAME;
    int iTableIndex = Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1;
    cout << PROVIDE_NEW_NAME;
    string sNewName = Utilities::sProvideString();
    cTabHandler.getVector()[iTableIndex]->vSetName(sNewName);
}