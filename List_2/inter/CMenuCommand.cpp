//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include "CMenuCommand.h"

CMenuCommand::CMenuCommand() {
    s_name = "def_name";
    s_command = "def_command" ;
}

CMenuCommand::CMenuCommand(string s_name, string s_command, CCommand* cCommand) {
    this->s_name = s_name;
    this->s_command = s_command;
    this->cCommand = cCommand;
}

CMenuCommand::~CMenuCommand() {
    delete cCommand;
}

//TODO
void CMenuCommand::Run() {
    if (cCommand == nullptr) {
        cout << "pusta komenda" << endl;
    }
    cCommand->RunCommand();
}

string CMenuCommand::getS_command() const {
    return s_command;
}

string CMenuCommand::getS_name() const {
    return s_name;
}

