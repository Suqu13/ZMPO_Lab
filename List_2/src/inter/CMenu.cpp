//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "../../src/ctab/Utilities.h"
#include "../../src/commands/Comm_0.h"
#include "../../src/commands/Comm_1.h"
#include "../../src/commands/Comm_2.h"
#include "../../src/commands/Comm_3.h"
#include "../../src/commands/Comm_4.h"
#include "../../src/commands/Comm_5.h"
#include "../../src/commands/Comm_6.h"
#include "../../src/commands/Comm_7.h"
#include "../../src/commands/Comm_8.h"
#include "../../src/commands/Comm_9.h"
#include "../../src/helpers/CTabHandler.h"

#define DEFAULT_NAME "Main MENU";
#define DEFAULT_COMMAND "Empty command";

using namespace std;

CMenu::CMenu() {
    s_name = DEFAULT_NAME;
    s_command = DEFAULT_COMMAND;
};

CMenu::CMenu(string s_name, string s_command) {
    this->s_name = s_name;
    this->s_command = s_command;
}

CMenu::~CMenu() {
    for (int i = 0; i < vMenuItems.size(); i++) {
        cout << "usuwam: CMenu > " + vMenuItems[i]->getS_name() << endl;
        delete vMenuItems[i];
    }
    vMenuItems.clear();
}

void CMenu::AddMenuItem(CMenuItem *vMenuItem) {
    if (ifExist(vMenuItem)) {
        vMenuItems.push_back(vMenuItem);
    }
}

void CMenu::Run() {
    CMenuToString();
    CMenuItem *item;
    while ((item = this->findMenuItem()) != nullptr) {
        item->Run();
        CMenuToString();
    }
}


void CMenu::CMenuToString() {
    cout << "\nCMenu name: " << s_name << endl << "CMenu command: " << s_command << endl << endl;
    for (int i = 0; i < vMenuItems.size(); ++i) {
        stringstream sstream;
        sstream << (i + 1);
        sstream << ". Name: ";
        sstream << vMenuItems[i]->getS_name();
        sstream << "\n   Command: ";
        sstream << vMenuItems[i]->getS_command();
        string str = sstream.str();
        cout << str << endl;
    }
}

CMenuItem *CMenu::findMenuItem() {
    string s_newCommand;
    while ((s_newCommand = Utilities::sProvideString()) != "back") {
        for (int i = 0; i < vMenuItems.size(); ++i) {
            if (vMenuItems[i]->getS_command() == s_newCommand) {
                return vMenuItems[i];
            }
        }
        cout << "Wrong command, try again!" << endl;
    }
    return nullptr;
}

bool CMenu::ifExist(CMenuItem *vMenuItem) {
    for (int i = 0; i < vMenuItems.size(); ++i) {
        if (vMenuItems[i]->getS_name() == vMenuItem->getS_name() ||
            vMenuItems[i]->getS_command() == vMenuItem->getS_command())
            return false;
    }
    return true;
}
