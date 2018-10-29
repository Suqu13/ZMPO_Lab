//
// Created by Jakub on 29.10.2018.
//

#include "CCommand.h"
#include <iostream>
#include "CCommand.h"


CCommand::~CCommand() {
    cout << REMOVE << CCOM << endl;
}

void CCommand::RunCommand() {
    cout << "\n" << DEF << CCOM;
    cout << endl;
}
