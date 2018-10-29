//
// Created by Jakub on 29.10.2018.
//

#include "CloneCTable.h"
#include "CloneCTable.h"
#include <iostream>
#include <limits>
#include "../CTable.h"
#include "../../../utilities/Utilities.h"
#include "../../../helpers/CTabHandler.h"

CloneCTable::CloneCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void CloneCTable::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n" << Message_If_Empty << endl;
        return;
    }
    cout << "\n" << Provide_INT;
    int iTableIndex = (Utilities::iProvideIntBetween(1, cTabHandler.getVector().size()) - 1);
    cTabHandler.getVector().push_back(new CTable(*cTabHandler.getVector()[(iTableIndex)]));
}