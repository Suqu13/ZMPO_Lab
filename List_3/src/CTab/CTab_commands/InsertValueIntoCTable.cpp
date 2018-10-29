//
// Created by Jakub on 29.10.2018.
//

#include "InsertValueIntoCTable.h"
#include <iostream>
#include <limits>
#include "../../../utilities/Utilities.h"

InsertValueIntoCTable::InsertValueIntoCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void InsertValueIntoCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << Message_If_Empty << endl;
        return;
    }
    cout << "\n" << Provide_INDEX;
    int iTableIndex = Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1;
    cout << Provide_VALUE;
    int iNewElement = Utilities::iProvideInt();
    if (cTabHandler.getVector()[iTableIndex]->iGetLength() == 0) {
        (cTabHandler.getVector()[iTableIndex]->bInsertElement(1, iNewElement));
        return;
    }
    cout << Provide_VALUE_INDEX;
    cTabHandler.getVector()[iTableIndex]->bInsertElement(
            Utilities::iProvideIntBetween(0, cTabHandler.getVector()[iTableIndex]->iGetLength() - 1), iNewElement);
}