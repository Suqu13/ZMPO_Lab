//
// Created by Jakub on 29.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "../helpers/CTabHandler.h"
#include "../utilities/Utilities.h"
#include "../helpers/CMenuAnalyzer.h"


using namespace std;

CMenu::CMenu() : CMenuItem() {
}

CMenu::CMenu(const string &s_name, const string &s_command) : CMenuItem(s_name, s_command) {
}

CMenu::~CMenu() {
    for (int i = 0; i < vMenuItems.size(); i++) {
        cout << REMOVING_CMENUITEM_OBJECT << vMenuItems[i]->getS_name() << endl;
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
    if (sCommandName == BACK_COMMAND) {
        return BACK_HELP;
    } else {
        for (int i = 0; i < vMenuItems.size(); ++i) {
            if (vMenuItems[i]->getS_command() == sCommandName) {
                if (CMenuCommand *com = dynamic_cast<CMenuCommand *> (vMenuItems[i]))
                    return com->getS_help();
            }
        }
        return NO_COMMAND;
    }
}

void CMenu::CMenuToString() {
    cout << "\n" << s_name << SPACE_AS_STRING << OPEN_BRACKET_AS_STRING << s_command << CLOSE_BRACKET_AS_STRING << "\n" << endl;
    for (int i = 0; i < vMenuItems.size(); ++i) {
        cout << vMenuItems[i]->getS_name() << SPACE_AS_STRING << OPEN_BRACKET_AS_STRING << vMenuItems[i]->getS_command() << CLOSE_BRACKET_AS_STRING
             << SPACE_AS_STRING << endl;
    }
    cout << BACK_COMMAND_SIGNATURE << "\n " << endl;
}

CMenuItem *CMenu::findMenuItem() {
    bool exist;
    string s_newCommand;
    while ((s_newCommand = Utilities::sProvideString()) != BACK_COMMAND) {
        vector<string> vString;
        if ((vString = Utilities::vSplitString(s_newCommand, ' ')).size() == 2) {
            if (vString.front() == HELP_COMMAND) {
                cout << findHelp(vString.back()) << endl;
            } else if (vString.front() == SEARCH_COMMAND) {
                string path;
                exist = false;
                CMenuAnalyzer::searchForCommand(NULL, vString.back(), path, exist);
                if (!exist) {
                    cout << NO_COMMAND << endl;
                }
            } else {
                cout << WRONG_COMMAND << endl;
            }
        } else {
            for (int i = 0; i < vMenuItems.size(); ++i) {
                if (vMenuItems[i]->getS_command() == s_newCommand) {
                    return vMenuItems[i];
                }
            }
            if (s_newCommand != "")
            cout << WRONG_COMMAND << endl;
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

vector<CMenuItem *> CMenu::getVMenuItems() const {
    return vMenuItems;
}

