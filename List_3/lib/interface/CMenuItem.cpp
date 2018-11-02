//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenuItem.h"

CMenuItem::CMenuItem() {
    s_name = DEF_NAME;
    s_command = DEF_COMMAND;
}

CMenuItem::CMenuItem(const string &s_name,const string &s_command) {
    this->s_name = s_name;
    this->s_command = s_command;
}

CMenuItem::~CMenuItem() = default;

const string &CMenuItem::getS_command() const {
    return s_command;
}

const string &CMenuItem::getS_name() const {
    return s_name;
}




