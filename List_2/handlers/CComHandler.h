//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_CCOMHANDLER_H
#define LIST_2_CCOMHANDLER_H

#include "../inter/CMenuCommand.h"
#include <vector>
#include <string>


static class CComHandler {
public:
    static CMenuItem* getCMenuCommand(string s_name, string s_command);
    static vector<CMenuItem*> vCom;
};

#endif //LIST_2_CCOMHANDLER_H
