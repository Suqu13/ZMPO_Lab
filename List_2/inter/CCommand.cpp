//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include "CCommand.h"


void CCommand::RunCommand() {
    if(this == nullptr) {
        cout << "Komenda domyśłna!!" << endl;
        return;
    }
}