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
    static void serialize(CMenuItem *cMenuItem, string fileName);
    static CMenuItem *deserialize(string fileName);
private:
    static int findClosingChar(char opening, string toAnalyze);
    static string serializeInterface(CMenuItem *cMenuItem);
    static CMenuItem *deserializeInterface(string Interface_info);
    static string serializeCMenuCommand(CMenuCommand *cMenuCommand);
    static string rightPlaceToDivide(int endPosition, const string &String_info);
    static CMenu *deserializeCMenu(string cMenu_info);
    static CMenuCommand *deserializeCMenuCommand(string cMenuCommand_info);
};


#endif //LIST_3_CMENUSERIALIZER_H
