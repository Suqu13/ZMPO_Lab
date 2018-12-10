//
// Created by Jakub on 29.10.2018.
//

#include <sstream>
#include <iostream>
#include "CMenuAnalyzer.h"
#include "../utilities/Utilities.h"

CMenu *CMenuAnalyzer::mainMenu;

void
CMenuAnalyzer::searchForCommand(CMenu *cMenu, const string &commandToFind, vector<string> &vecOfPath, string path,
                                bool &exist) {
    if (!cMenu)
        cMenu = mainMenu;
    if (cMenu != mainMenu)
        path += SEARCH_DIRECTION;
    path += cMenu->getS_command();
    vector<CMenuItem *> menuItems = cMenu->getVMenuItems();
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getS_command() == commandToFind) {
            string toAdd;
            toAdd = path + SEARCH_DIRECTION + menuItems[i]->getS_command();
            vecOfPath.push_back(toAdd);
            exist = true;
        }
        if (CMenu *next = dynamic_cast<CMenu *>(menuItems[i])) {
            searchForCommand(next, commandToFind, vecOfPath, path, exist);
        }
    }
}

void CMenuAnalyzer::setStaticMember(CMenu *cMenu) {
    mainMenu = cMenu;
}

void CMenuAnalyzer::searchForRoute(CMenu *cMenu, const string &currentPlace, const string &commandToFind, bool &exist) {
    int isHere = false;
    if (currentPlace == commandToFind) {
        cout << YOU_ARE_HERE << endl;
        isHere = true;
    }

    vector<string> routeToStart;
    searchForCommand(NULL, currentPlace, routeToStart, "", exist);
    vector<string> routeToFinish;
    searchForCommand(NULL, commandToFind, routeToFinish, "", exist);
    if (exist && !isHere) {
        if (routeToStart.empty()) {
            for (const auto &i : routeToFinish) {
                stringstream stream;
                stream << "Path: ";
                vector<string> first = Utilities::vSplitString(i, SEARCH_DIRECTION);
                for (int j = 1; j < first.size(); ++j) {
                    if (j != first.size() - 1)
                        stream << first[j] << SEARCH_DIRECTION;
                    else
                        stream << first[j];
                }
                cout << stream.str() << endl;
            }
        } else {
            for (const auto &i : routeToStart) {
                for (const auto &j : routeToFinish) {
                    vector<string> first = Utilities::vSplitString(i, SEARCH_DIRECTION);
                    vector<string> second = Utilities::vSplitString(j, SEARCH_DIRECTION);
                    int sameLength;
                    if (first.size() > second.size()) {
                        sameLength = int(second.size());
                    } else {
                        sameLength = int(first.size());
                    }
                    int lastSameElementIndex = 0;
                    for (int k = 0; k < sameLength; ++k) {
                        if (first[k] == second[k])
                            lastSameElementIndex++;
                    }
                    stringstream stream;
                    stream << "Path: ";
                    for (int n = lastSameElementIndex; n < first.size(); ++n) {
                        stream << BACK_STRING << SEARCH_DIRECTION;
                    }
                    for (int l = int(first.size() - 1); l > lastSameElementIndex; --l) {
                        stream << first[l] << SEARCH_DIRECTION;
                    }
                    for (int m = lastSameElementIndex; m < second.size(); ++m) {
                        if (m != second.size() - 1)
                            stream << second[m] << SEARCH_DIRECTION;
                        else
                            stream << second[m];
                    }
                    cout << stream.str() << endl;
                }
            }
        }
    }
}









