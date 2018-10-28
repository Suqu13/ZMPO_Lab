//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include "CCommand.h"


CCommand::~CCommand() {
    cout << REMOVE << CCOM << endl;
}

void CCommand::RunCommand() {
    cout << "\n" << DEF << CCOM;
    cout << endl;
}
