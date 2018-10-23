//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include "CCommand.h"

#define DEFAULT "default command";


CCommand::~CCommand() {
    cout << "usuwam: CCommand" << endl;
}

void CCommand::RunCommand() {
    cout << "\n" DEFAULT;
    cout << endl;
}
