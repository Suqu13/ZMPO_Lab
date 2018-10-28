//
// Created by Jakub on 21.10.2018.
//

#include "RemoveAllCTable.h"
#include <iostream>
#include <limits>
#include "../utilities/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"
#include "../interface/CCommandWithVector.h"

RemoveAllCTable::RemoveAllCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void RemoveAllCTable::RunCommand() {
    for (int i = 0; i < cTabHandler.getVector().size(); i++) {
        delete cTabHandler.getVector()[i];
    }
    cTabHandler.getVector().clear();
}

