//
// Created by Jakub on 29.10.2018.
//

#include "InsertValueIntoCTable.h"
#include "../../../lib/utilities/Utilities.h"
#include <iostream>
#include <limits>

InsertValueIntoCTable::InsertValueIntoCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void InsertValueIntoCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << MESSAGE_IF_EMPTY << endl;
        return;
    }
    cout << "\n" << PROVIDE_TABLE_FOR_NEW_ELEMENT ;
    int iTableIndex = Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1;
    cout << PROVIDE_ELEMENT;
    int iNewElement = Utilities::iProvideInt();
    if (cTabHandler.getVector()[iTableIndex]->iGetLength() == 0) {
        (cTabHandler.getVector()[iTableIndex]->bInsertElement(1, iNewElement));
        return;
    }
    cout << PROVIDE_INDEX_FOR_NEW_ELEMENT ;
    cTabHandler.getVector()[iTableIndex]->bInsertElement(
            Utilities::iProvideIntBetween(0, cTabHandler.getVector()[iTableIndex]->iGetLength() - 1), iNewElement);
}