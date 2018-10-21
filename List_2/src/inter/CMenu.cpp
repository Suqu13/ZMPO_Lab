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
#include "../../src/handlers/CTabHandler.h"

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
        cout << "usuwam CMenu: " + vMenuItems[i]->getS_name() << endl;
        delete vMenuItems[i];
    }
    vMenuItems.clear();
}

void CMenu::AddMenuItem(CMenuItem *vMenuItem) {
    vMenuItems.push_back(vMenuItem);
}

void CMenu::InitializeMenu() {
    CMenu *menu_create;
    menu_create = new CMenu("Create CTables", "create");
    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c1", new Comm_0));
    menu_create->AddMenuItem(new CMenuCommand("Create a specific CTable", "c2", new Comm_1));
    menu_create->AddMenuItem(new CMenuCommand("default command", "c3", new CCommand));
    menu_create->AddMenuItem(new CMenuCommand("empty command", "c4", nullptr));
    this->AddMenuItem(menu_create);

    CMenu *menu_change;
    menu_change = new CMenu("Change details", "change");
    menu_change->AddMenuItem(new CMenuCommand("Insert value into a specific CTable", "c1", new Comm_2));
    menu_change->AddMenuItem(new CMenuCommand("Set a length of a specific CTable", "c2", new Comm_3));
    menu_change->AddMenuItem(new CMenuCommand("Set a name of a specific CTable", "c3", new Comm_4));

    this->AddMenuItem(menu_change);

    CMenu *menu_remove;
    menu_remove = new CMenu("Remove CTables", "remove");
    menu_remove->AddMenuItem(new CMenuCommand("Remove all CTables", "r1", new Comm_6));
    menu_remove->AddMenuItem(new CMenuCommand("Remove a specific CTable", "r2", new Comm_7));

    this->AddMenuItem(menu_remove);

    CMenu *menu_show;
    menu_show = new CMenu("Show CTables", "show");
    menu_show->AddMenuItem(new CMenuCommand("Show all CTables", "s1", new Comm_8));
    menu_show->AddMenuItem(new CMenuCommand("Show a single CTable", "s2", new Comm_9));

    this->AddMenuItem(menu_show);

    AddMenuItem(new CMenuCommand("Clone a specific CTable", "clone", new Comm_5));

}

void CMenu::Run() {
    CMenuToString();
    CMenuItem *item;
    while ((item = this->findMenuItem()) != nullptr) {
        item->Run();
        CMenuToString();
    }
    if (s_name == "Main MENU") {
        cout << "Ciao!\n";
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
