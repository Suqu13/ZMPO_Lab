//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "CMenuCommand.h"

CMenuCommand::CMenuCommand() : CMenuItem() {
}

CMenuCommand::CMenuCommand(string s_name, string s_command, string s_help, CCommand *cCommand) : CMenuItem(s_name, s_command, s_help) {
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