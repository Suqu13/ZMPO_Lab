//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenuItem.h"

CMenuItem::CMenuItem() {
    s_name = DEF_NAME;
    s_command = DEF_COMMAND;
    s_help = DEF_HELP;
}

CMenuItem::CMenuItem(string s_name, string s_command, string help) {
    this->s_name = s_name;
    this->s_command = s_command;
    this->s_help = help;
}

CMenuItem::~CMenuItem() {
}

string CMenuItem::getS_name() const {
    return s_name;
}

string CMenuItem::getS_command() const {
    return s_command;
}

string CMenuItem::getS_help() const {
    return s_help;
}