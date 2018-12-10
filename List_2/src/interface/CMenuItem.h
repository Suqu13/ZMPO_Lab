//
// Created by Jakub on 19.10.2018.
//

#include <string>

#ifndef LIST_2_CMENUITEM_H
#define LIST_2_CMENUITEM_H
using namespace std;

class CMenuItem {
public:
    virtual ~CMenuItem();
    virtual void Run() = 0;
    virtual string getS_command() const;
    virtual string getS_name() const;

protected:
    string s_command;
    string s_name;
};



#endif //LIST_2_CMENUITEM_H
