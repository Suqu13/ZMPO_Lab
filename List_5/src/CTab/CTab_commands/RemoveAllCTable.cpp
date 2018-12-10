//
// Created by Jakub on 29.10.2018.
//

#include "RemoveAllCTable.h"
#include <iostream>
#include <limits>

RemoveAllCTable::RemoveAllCTable(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void RemoveAllCTable::RunCommand() {
    for (int i = 0; i < cTabHandler.getVector().size(); i++) {
        delete cTabHandler.getVector()[i];
    }
    cTabHandler.getVector().clear();
}
