//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENUANALYZER_H
#define LIST_3_CMENUANALYZER_H

#define SEARCH_DIRECTION "->"

#include "string"
#include "vector"
#include "../interface/CMenuItem.h"
#include "../interface/CMenu.h"

using namespace std;

class CMenuAnalyzer {
public:
    static void searchForCommand(CMenu *menu, const string &commandToFind, string path, bool &exist);
    static void setStaticMember(CMenu* cMenu);
private:
    static CMenu *mainMenu;
};


#endif //LIST_3_CMENUANALYZER_H
