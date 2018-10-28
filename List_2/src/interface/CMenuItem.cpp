//
// Created by Jakub on 21.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenuItem.h"

CMenuItem::~CMenuItem() {
}

string CMenuItem::getS_name() const {
    return s_name;
}

string CMenuItem::getS_command() const {
    return s_command;
}
