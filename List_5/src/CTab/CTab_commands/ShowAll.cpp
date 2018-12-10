//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "ShowAll.h"

ShowAll::ShowAll(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void ShowAll::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n"<<MESSAGE_IF_EMPTY << endl;
        return;
    }
    for (int i = 0; i < cTabHandler.getVector().size(); i++) {
        cout << (i + 1) << ". "<< CURRENT_NAME << cTabHandler.getVector()[i]->sGetName() << "; "<< CURRENT_LENGTH << cTabHandler.getVector()[i]->iGetLength()
             << ";" << CURRENT_ELEMENTS
             << cTabHandler.getVector()[i]->sToString() << endl;
    }
}