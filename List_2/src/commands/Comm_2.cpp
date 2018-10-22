//
// Created by Jakub on 21.10.2018.
//

#include "Comm_2.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

Comm_2::Comm_2(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_2::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    cout << "\nPlease provide the table where you want to insert a new element: ";
    int iTableIndex = Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1;
    cout << "Please provide the new element: ";
    int iNewElement = Utilities::iProvideInt();
    if (cTabHandler.getVector()[iTableIndex]->iGetLength() == 0) {
        (cTabHandler.getVector()[iTableIndex]->bInsertElement(1, iNewElement));
        return;
    }
    cout << "Please provide an index for the element: ";
    cTabHandler.getVector()[iTableIndex]->bInsertElement(
            Utilities::iProvideIntBetween(0, cTabHandler.getVector()[iTableIndex]->iGetLength() - 1), iNewElement);
}

