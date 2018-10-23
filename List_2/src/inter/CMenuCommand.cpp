//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include "CMenuCommand.h"

#define DEFAULT_COMMAND "empty command";

CMenuCommand::CMenuCommand() {
    s_name = "def_name";
    s_command = "def_command";
}

CMenuCommand::CMenuCommand(string s_name, string s_command, CCommand *cCommand) {
    this->s_name = s_name;
    this->s_command = s_command;
    this->cCommand = cCommand;
}

CMenuCommand::~CMenuCommand() {
    cout << "usuwam: CMenuCommand > name: " + s_name + ", command: " + s_command << endl;
    delete cCommand;
}

//TODO
void CMenuCommand::Run() {
    if (cCommand)
        cCommand->RunCommand();
    else {
        cout << "\n" DEFAULT_COMMAND;
        cout << endl;
    }
}


