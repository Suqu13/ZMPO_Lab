//
// Created by Jakub on 21.10.2018.
//

#include "ShowOne.h"
#include <iostream>
#include <limits>
#include "../utilities/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"
#include "RemoveAllCTable.h"

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



