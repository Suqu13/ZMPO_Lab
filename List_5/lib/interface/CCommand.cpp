//
// Created by Jakub on 29.10.2018.
//

#include "CCommand.h"
#include <iostream>
#include "CCommand.h"


CCommand::~CCommand() {
    cout << REMOVING_COMMAND_OBJECT << COMMAND_OBJECT << endl;
}

void CCommand::RunCommand() {
    cout << "\n" << DEFAULT_CCOMMAND;
    cout << endl;
}
