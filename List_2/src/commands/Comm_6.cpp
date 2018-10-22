//
// Created by Jakub on 21.10.2018.
//

#include "Comm_6.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../helpers/CTabHandler.h"

Comm_6::Comm_6(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void Comm_6::RunCommand() {
    for (int i = 0; i < cTabHandler.getVector().size(); i++) {
        delete cTabHandler.getVector()[i];
    }
    cTabHandler.getVector().clear();
}

