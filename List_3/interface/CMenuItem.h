//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENUITEM_H
#define LIST_3_CMENUITEM_H

#include "string"

#define DEF_NAME "DEFAULT_NAME"
#define DEF_COMMAND "DEFAULT_COMMAND"
#define DEF_HELP "DEFAULT_HELP"
using namespace std;

class CMenuItem {
public:
    CMenuItem();
    CMenuItem(string s_name, string s_command, string help);
    virtual ~CMenuItem();
    virtual void Run() = 0;
    virtual string getS_command() const;
    virtual string getS_name() const;
    virtual string getS_help() const;
protected:
    string s_command;
    string s_name;
    string s_help;
};



#endif //LIST_3_CMENUITEM_H
