//
// Created by Jakub on 19.10.2018.
//

#include <iostream>
#include "CMenu.h"
#include "C:/Users/Jakub/Desktop/PWr/C++_SEM3/List_2/ctab/Utilities.h"

using namespace std;

CMenu::CMenu() {
    s_name = "def_name";
    s_command = "def_command";
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

void CMenu::Run() {
    Utilities utilities;
    cout << s_name << endl << s_command << endl;
    for (int i = 0; i < vMenuItems.size(); ++i) {
        cout << "Name: " + vMenuItems[i]->getS_command() + " Command" + vMenuItems[i]->getS_command() << endl;
    }
    string s_newCommand = utilities.sProvideString();
    if(s_newCommand == "back")
        return;
    for (int i = 0; i < vMenuItems.size(); ++i) {
        if (vMenuItems[i]->getS_command() == s_newCommand)
            vMenuItems[i]->Run();
    }

}