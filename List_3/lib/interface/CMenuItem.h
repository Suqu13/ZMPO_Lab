//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENUITEM_H
#define LIST_3_CMENUITEM_H

#include "string"

#define DEF_NAME "default_menu"
#define DEF_COMMAND "default_command"
using namespace std;

class CMenuItem {
public:
    CMenuItem();
    CMenuItem(const string &s_name,const string &s_command);
    virtual ~CMenuItem();
    virtual void Run() = 0;
    const string &getS_command() const;
    const string &getS_name() const;

protected:
    string s_command;
    string s_name;
};



#endif //LIST_3_CMENUITEM_H
