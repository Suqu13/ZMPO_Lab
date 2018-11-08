//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENUANALYZER_H
#define LIST_3_CMENUANALYZER_H

#define SEARCH_DIRECTION "->"

#define BACK_STRING "back"

#define YOU_ARE_HERE "You are here!"

#define EMPTY_STRING ""

#include "string"
#include "vector"
#include "../interface/CMenuItem.h"
#include "../interface/CMenu.h"

using namespace std;

class CMenuAnalyzer {
public:
    static void searchForCommand(CMenu *cMenu, const string &commandToFind,string &holder, string path, bool &exist);
    static void searchForRoute(CMenu *cMenu, const string &currentPlace, const string &commandToFind, bool &exist);
    static void setStaticMember(CMenu* cMenu);
private:
    static CMenu *mainMenu;
};


#endif //LIST_3_CMENUANALYZER_H
