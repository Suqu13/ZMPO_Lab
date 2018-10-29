//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "../utilities/Utilities.h"
#include "../helpers/CTabHandler.h"

using namespace std;

CMenu::CMenu() : CMenuItem() {
}

CMenu::CMenu(string s_name, string s_command, string s_help) : CMenuItem(s_name, s_command, s_help) {
}

CMenu::~CMenu() {
    for (int i = 0; i < vMenuItems.size(); i++) {
        cout << REMOVE << CMENU + vMenuItems[i]->getS_name() << endl;
        delete vMenuItems[i];
    }
    vMenuItems.clear();
}

bool CMenu::AddMenuItem(CMenuItem *vMenuItem) {
    if (ifExist(vMenuItem)) {
        vMenuItems.push_back(vMenuItem);
        return true;
    }
    return false;
}

bool CMenu::DeleteMenuItem(string s_command) {
    for (int i = 0; i < vMenuItems.size(); ++i) {
        if (vMenuItems[i]->getS_command() == s_command) {
            delete vMenuItems.at(i);
            vMenuItems.erase(vMenuItems.begin() + i);
            return true;
        }
    }
    return false;
}

void CMenu::Run() {
    CMenuToString();
    CMenuItem *item;
    while ((item = this->findMenuItem()) != nullptr) {
        item->Run();
        CMenuToString();
    }
}

string CMenu::findHelp(string sCommandName) {
    if (sCommandName == "back") {
        return "This command makes moving back and exiting whole program possible";
    } else {
        for (int i = 0; i < vMenuItems.size(); ++i) {
            if (vMenuItems[i]->getS_command() == sCommandName) {
                return vMenuItems[i]->getS_help();
            }
        }
        return "command does not exist";
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
        vector<string> vString;
        if ((vString= Utilities::vSplitString(s_newCommand, ' ')).size() == 2 && vString.front() == "help") {
            cout << findHelp(vString.back()) << endl;
        } else {
            for (int i = 0; i < vMenuItems.size(); ++i) {
                if (vMenuItems[i]->getS_command() == s_newCommand) {
                    return vMenuItems[i];
                }
            }
            cout << Wrong_Command << endl;
        }
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

vector<CMenuItem *> CMenu::getVector() {
    return vMenuItems;
}
