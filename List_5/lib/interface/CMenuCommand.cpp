//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include "CMenuCommand.h"

CMenuCommand::CMenuCommand() : CMenuItem() {
}

CMenuCommand::CMenuCommand(const string &s_name, const string &s_command, const string &s_help, CCommand *cCommand) : CMenuItem(s_name, s_command) {
    this->cCommand = cCommand;
    this->s_help = s_help;
}

CMenuCommand::~CMenuCommand() {
    cout << REMOVING_COMMAND_OBJECT<< s_name << ", "<< s_command << endl;
    delete cCommand;
}

//TODO
void CMenuCommand::Run() {
    if (cCommand)
        cCommand->RunCommand();
    else {
        cout << "\n" << EMPTY_COMMAND_BY_DEFAULT;
        cout << endl;
    }
}

const string &CMenuCommand::getS_help() const {
    return s_help;
}
