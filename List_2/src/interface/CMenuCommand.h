//
// Created by Jakub on 19.10.2018.
//

#ifndef LIST_2_CMENUCOMAND_H
#define LIST_2_CMENUCOMAND_H

#define DEF_NAME "def_name"
#define DEF_COMMAND "def_command"
#define REMOVE "usuwam: "
#define CMENU_COM "CMenuCommand "
#define NAME "name: "
#define COMMAND "command: "
#define empty_COMMAND "empty command"

#include <string>
#include "CCommand.h"
#include "CMenuItem.h"


class CMenuCommand: public CMenuItem {
public:
    CMenuCommand();
    CMenuCommand(string s_name, string s_command, CCommand* cCommand);
    ~CMenuCommand() override;
    void Run() override;

private:
    CCommand* cCommand;
};


#endif //LIST_2_CMENUCOMAND_H
