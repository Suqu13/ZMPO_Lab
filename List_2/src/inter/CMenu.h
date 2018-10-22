//
// Created by Jakub on 19.10.2018.
//

#ifndef LIST_2_CMENU_H
#define LIST_2_CMENU_H


#include <vector>
#include "CMenuItem.h"
using namespace std;

class CMenu: public CMenuItem {
public:
    CMenu();
    CMenu(string s_name, string s_command);
    ~CMenu() override;
    void Run() override;
    void CMenuToString();
    void AddMenuItem(CMenuItem* vMenuItem);

private:
    bool ifExist(CMenuItem *vMenuItem);
    CMenuItem* findMenuItem();
    vector<CMenuItem*> vMenuItems;

};


#endif //LIST_2_CMENU_H
