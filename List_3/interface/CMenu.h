//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENU_H
#define LIST_3_CMENU_H


#define Wrong_Command "Wrong command, try again!"
#define REMOVE "usuwam: "
#define CMENU "CMenu "
#define NAME "name: "
#define COMMAND "command: "

#include <vector>
#include "CMenuItem.h"
using namespace std;

class CMenu: public CMenuItem {
public:
    CMenu();
    CMenu(string s_name, string s_command, string s_help);
    ~CMenu() override;
    vector<CMenuItem*> getVector();
    void Run() override;
    void CMenuToString();
    bool AddMenuItem(CMenuItem* vMenuItem);
    bool DeleteMenuItem(string s_command);

private:
    string findHelp(string sCommandName);
    bool ifExist(CMenuItem *vMenuItem);
    CMenuItem* findMenuItem();
    vector<CMenuItem*> vMenuItems;
};


#endif //LIST_3_CMENU_H
