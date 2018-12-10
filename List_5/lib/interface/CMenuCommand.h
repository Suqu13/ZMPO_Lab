//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENUCOMMAND_H
#define LIST_3_CMENUCOMMAND_H


#define EMPTY_COMMAND_BY_DEFAULT "empty command"

#include <string>
#include "CCommand.h"
#include "CMenuItem.h"


class CMenuCommand: public CMenuItem {
public:
    CMenuCommand();
    CMenuCommand(const string &s_name, const string &s_command, const string &s_help, CCommand* cCommand);
    ~CMenuCommand() override;
    void Run() override;

    const string &getS_help() const;

private:
    CCommand* cCommand;
    string s_help;
};


#endif //LIST_3_CMENUCOMMAND_H
