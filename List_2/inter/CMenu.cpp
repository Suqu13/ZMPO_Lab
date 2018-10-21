//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include <sstream>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "../ctab/Utilities.h"
#include "../commands/Comm_0.h"
#include "../commands/Comm_1.h"
#include "../commands/Comm_2.h"
#include "../commands/Comm_3.h"
#include "../commands/Comm_4.h"
#include "../commands/Comm_5.h"
#include "../commands/Comm_6.h"
#include "../commands/Comm_7.h"
#include "../commands/Comm_8.h"
#include "../commands/Comm_9.h"
#include "../handlers/CTabHandler.h"

using namespace std;

CMenu::CMenu() {
    s_name = "Main MENU";
    s_command = "without command";
};

CMenu::CMenu(string s_name, string s_command) {
    this->s_name = s_name;
    this->s_command = s_command;
}

CMenu::~CMenu() {
    for (int i = 0; i < vMenuItems.size(); i++) {
        delete vMenuItems[i];
    }
    vMenuItems.clear();
}

string CMenu::getS_command() const {
}

string CMenu::getS_name() const {
}

void CMenu::AddMenuItem(CMenuItem *vMenuItem) {
    vMenuItems.push_back(vMenuItem);
}

void CMenu::InitializeMenu() {

    AddMenuItem(new CMenuCommand("create default CTables", "comm_1", new Comm_0));
    AddMenuItem(new CMenuCommand("create a specific CTable", "comm_2", new Comm_1));
    AddMenuItem(new CMenuCommand("insert value into a specific CTable", "comm_3", new Comm_2));
    AddMenuItem(new CMenuCommand("set a length of a specific CTable", "comm_4", new Comm_3));
    AddMenuItem(new CMenuCommand("set a name of a specific CTable", "comm_5", new Comm_4));
    AddMenuItem(new CMenuCommand("clone a specific CTable", "comm_6", new Comm_5));
    AddMenuItem(new CMenuCommand("remove all CTables", "comm_7", new Comm_6));
    AddMenuItem(new CMenuCommand("remove a specific CTable", "comm_8", new Comm_7));
    AddMenuItem(new CMenuCommand("show all CTables", "comm_9", new Comm_8));
    AddMenuItem(new CMenuCommand("show a single CTable", "comm_10", new Comm_9));
}

void CMenu::Run() {
    CMenuToString();
    CMenuItem *item;
    while ((item = findMenuItem()) != nullptr) {
        item->Run();
        CMenuToString();
    }
    if (s_name == "Main MENU") {
        cout << "Ciao!";
        CTabHandler::cleanIt();
    }
    return;
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
