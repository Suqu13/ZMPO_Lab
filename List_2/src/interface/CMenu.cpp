//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "../utilities/Utilities.h"
#include "../ctab_commands/CreateDefaultCTables.h"
#include "../ctab_commands/CreateSpecificCTables.h"
#include "../ctab_commands/InsertValueIntoCTable.h"
#include "../ctab_commands/SetLengthOfCTable.h"
#include "../ctab_commands/SetCTableName.h"
#include "../ctab_commands/CloneCTable.h"
#include "../ctab_commands/RemoveAllCTable.h"
#include "../ctab_commands/RemoveSingleCTable.h"
#include "../ctab_commands/ShowAll.h"
#include "../ctab_commands/ShowOne.h"
#include "../../src/helpers/CTabHandler.h"

using namespace std;

CMenu::CMenu() {
    s_name = DEF_NAME;
    s_command = DEF_COMMAND;
};

CMenu::CMenu(string s_name, string s_command) {
    this->s_name = s_name;
    this->s_command = s_command;
}

CMenu::~CMenu() {
    for (int i = 0; i < vMenuItems.size(); i++) {
        cout << REMOVE << CMENU + vMenuItems[i]->getS_name() << endl;
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
    cout << "\n" << CMENU << NAME << s_name << endl << CMENU << COMMAND << s_command << endl << endl;
    for (int i = 0; i < vMenuItems.size(); ++i) {
        cout << vMenuItems[i]->getS_name() << " (" << vMenuItems[i]->getS_command() << ") " << endl;
    }
    cout << "Back " << "(back)\n " << endl;
}

CMenuItem *CMenu::findMenuItem() {
    string s_newCommand;
    while ((s_newCommand = Utilities::sProvideString()) != "back") {
        for (int i = 0; i < vMenuItems.size(); ++i) {
            if (vMenuItems[i]->getS_command() == s_newCommand) {
                return vMenuItems[i];
            }
        }
        cout << Wrong_Command << endl;
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
