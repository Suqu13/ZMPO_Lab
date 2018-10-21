//
// Created by Jakub on 21.10.2018.
//

#include "Comm_2.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void Comm_2::RunCommand() {
    if (CTabHandler::vCTab.empty()) {
        cout << "\nFirstly, you have to create a table!!" << endl;
        return;
    }
    cout << "\nPlease provide the table where you want to insert a new element: ";
    int iTableIndex = Utilities::iProvideIntBetween(1, CTabHandler::vCTab.size()) - 1;
    cout << "Please provide the new element: ";
    int iNewElement = Utilities::iProvideInt();
    if (CTabHandler::vCTab[iTableIndex]->iGetLength() == 0) {
        (CTabHandler::vCTab[iTableIndex]->bInsertElement(1, iNewElement));
        return;
    }
    cout << "Please provide an index for the element: ";
    CTabHandler::vCTab[iTableIndex]->bInsertElement(
            Utilities::iProvideIntBetween(0, CTabHandler::vCTab[iTableIndex]->iGetLength() - 1), iNewElement);
}