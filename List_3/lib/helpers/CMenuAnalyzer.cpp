//
// Created by Jakub on 29.10.2018.
//

#include <sstream>
#include <iostream>
#include "CMenuAnalyzer.h"
#include "../utilities/Utilities.h"

CMenu *CMenuAnalyzer::mainMenu;

void
CMenuAnalyzer::searchForCommand(CMenu *cMenu, const string &commandToFind, string &holder, string path, bool &exist) {
    if (!cMenu) {
        cMenu = mainMenu;
    }
    if (cMenu != mainMenu)
        path += SEARCH_DIRECTION;
    path += cMenu->getS_command();
    vector<CMenuItem *> menuItems = cMenu->getVMenuItems();
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getS_command() == commandToFind) {
            // cout << path << SEARCH_DIRECTION << menuItems[i]->getS_command() << endl;
            holder = path + SEARCH_DIRECTION + menuItems[i]->getS_command();
            exist = true;
        }
        if (CMenu *next = dynamic_cast<CMenu *>(menuItems[i])) {
            searchForCommand(next, commandToFind, holder, path, exist);
        }
    }
}

void CMenuAnalyzer::setStaticMember(CMenu *cMenu) {
    mainMenu = cMenu;
}

void CMenuAnalyzer::searchForRoute(CMenu *cMenu, const string &currentPlace, const string &commandToFind, bool &exist) {
    stringstream route;
    string fHolder;
    searchForCommand(cMenu, currentPlace, fHolder, EMPTY_STRING, exist);
    string sHolder;
    searchForCommand(cMenu, commandToFind, sHolder, EMPTY_STRING, exist);
    if (exist) {
        vector<string> first = Utilities::vSplitString(fHolder, SEARCH_DIRECTION);
        vector<string> second = Utilities::vSplitString(sHolder, SEARCH_DIRECTION);
        int sameLength = abs(int(first.size() - second.size()));
        if (sameLength == 0)
            sameLength = first.size();
        int lastSameString = 0;
        for (int i = 0; i < sameLength; ++i) {
            if (first[i] == second[i]) {
                lastSameString++;
            }
        }
        if (lastSameString != 0 && fHolder != sHolder) {
            for (int i = 0; i < first.size() - lastSameString; i++) {
                route << BACK_STRING << SEARCH_DIRECTION;
            }
            for (int i = lastSameString; i < second.size(); i++) {
                if (i != second.size() - 1)
                    route << second[i] << SEARCH_DIRECTION;
                else
                    route << second[i];
            }
            cout << route.str() << endl;
        } else {
            if (first[0] == EMPTY_STRING) {
                for (int i = 1; i < second.size(); i++) {
                    if (i != second.size() - 1)
                        route << second[i] << SEARCH_DIRECTION;
                    else
                        route << second[i];
                }
                cout << route.str() << endl;
            } else {
                cout << YOU_ARE_HERE << endl;
            }
        }
    }
}








