//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "ShowOne.h"
#include "../../../lib/utilities/Utilities.h"

ShowOne::ShowOne(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void ShowOne::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << Message_If_Empty << endl;
        return;
    }
    cout << "\n " << Provide_INDEX;
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size())) - 1;
    cout << (iTableIndex + 1) << ". " << NAME << cTabHandler.getVector()[iTableIndex]->sGetName() << "; " << LENGTH
         << cTabHandler.getVector()[iTableIndex]->iGetLength()
         << ";" << ELEMENTS
         << cTabHandler.getVector()[iTableIndex]->sToString() << endl;
}