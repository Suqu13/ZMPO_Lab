//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include "CMenuCommand.h"

CMenuCommand::CMenuCommand() {
    s_name = DEF_NAME;
    s_command = DEF_COMMAND;
}

CMenuCommand::CMenuCommand(string s_name, string s_command, CCommand *cCommand) {
    this->s_name = s_name;
    this->s_command = s_command;
    this->cCommand = cCommand;
}

CMenuCommand::~CMenuCommand() {
    cout << REMOVE << CMENU_COM << NAME << s_name << ", " << COMMAND << s_command << endl;
    delete cCommand;
}

//TODO
void CMenuCommand::Run() {
    if (cCommand)
        cCommand->RunCommand();
    else {
        cout << "\n" << empty_COMMAND;
        cout << endl;
    }
}


