//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "ShowAll.h"

ShowAll::ShowAll(CTabHandler &pHandler) : CCommandWithVector(pHandler) {}

void ShowAll::RunCommand() {
    if (cTabHandler.getVector().empty()) {
        cout << "\n"<<Message_If_Empty << endl;
        return;
    }
    for (int i = 0; i < cTabHandler.getVector().size(); i++) {
        cout << (i + 1) << ". "<< NAME << cTabHandler.getVector()[i]->sGetName() << "; "<< LENGTH << cTabHandler.getVector()[i]->iGetLength()
             << ";" << ELEMENTS
             << cTabHandler.getVector()[i]->sToString() << endl;
    }
}