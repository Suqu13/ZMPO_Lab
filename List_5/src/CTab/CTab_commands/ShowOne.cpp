//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "ShowOne.h"
#include "../../../lib/utilities/Utilities.h"

ShowOne::ShowOne(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void ShowOne::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << MESSAGE_IF_EMPTY << endl;
        return;
    }
    cout << "\n " << PROVIDE_INDEX_TABLE_TO_SHOW;
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size())) - 1;
    cout << (iTableIndex + 1) << ". " << DEF_NAME_SHOW << cTabHandler.getVector()[iTableIndex]->sGetName() << "; " << LENGTH
         << cTabHandler.getVector()[iTableIndex]->iGetLength()
         << ";" << ELEMENTS
         << cTabHandler.getVector()[iTableIndex]->sToString() << endl;
}