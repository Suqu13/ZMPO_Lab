//
// Created by Jakub on 21.10.2018.
//

#include "Comm_6.h"
#include <iostream>
#include <limits>
#include "../ctab/Utilities.h"
#include "../ctab/CTable.h"
#include "../handlers/CTabHandler.h"

void Comm_6::RunCommand() {
    for (int i = 0; i < CTabHandler::vCTab.size(); i++) {
        delete CTabHandler::vCTab[i];
    }
    CTabHandler::vCTab.clear();
}
