//
// Created by Jakub on 29.10.2018.
//

#include <sstream>
#include <iostream>
#include "CMenuAnalyzer.h"
#include "../utilities/Utilities.h"

CMenu* CMenuAnalyzer::mainMenu;

void CMenuAnalyzer::searchForCommand(CMenu *menu, const string &commandToFind, string path, bool &exist) {
    if (!menu) {
        menu = mainMenu;
    }
    if (menu != mainMenu)
        path += "->";
    path += menu->getS_command();
    vector<CMenuItem *> menuItems = menu->getVMenuItems();
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getS_command() == commandToFind) {
            cout << path << "->" << menuItems[i]->getS_command() << endl;
            exist = true;
        }
        if (CMenu *next = dynamic_cast<CMenu *>(menuItems[i])) {
            searchForCommand(next, commandToFind, path, exist);
        }
    }
}

void CMenuAnalyzer::setStaticMember(CMenu *cMenu) {
    mainMenu = cMenu;
}








