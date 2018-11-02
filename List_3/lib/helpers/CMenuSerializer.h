//
// Created by Jakub on 31.10.2018.
//

#ifndef LIST_3_CMENUSERIALIZER_H
#define LIST_3_CMENUSERIALIZER_H


#include "../interface/CMenu.h"
#include "../interface/CMenuItem.h"
#include "../interface/CMenuCommand.h"


class CMenuSerializer {
public:
    static void setMainMenu(CMenu *mainMenu);
    static string serializeInterface(CMenuItem *cMenuItem);
    static int findClosingChar(char opening, string toAnalyze);
    static CMenuItem* deserializeInterface(string Interface_info);


private:
    static string serializeCMenuCommand(CMenuCommand *cMenuCommand);
    static CMenu* deserializeCMenu(string cMenu_info);
    static CMenuCommand* deserializeCMenuCommand(string cMenuCommand_info);
    static CMenu *mainMenu;
};


#endif //LIST_3_CMENUSERIALIZER_H
