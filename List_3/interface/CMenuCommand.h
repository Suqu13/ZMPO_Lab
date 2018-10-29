//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENUCOMMAND_H
#define LIST_3_CMENUCOMMAND_H


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
    CMenuCommand(string s_name, string s_command, string s_help, CCommand* cCommand);
    ~CMenuCommand() override;
    void Run() override;

private:
    CCommand* cCommand;
};


#endif //LIST_3_CMENUCOMMAND_H
