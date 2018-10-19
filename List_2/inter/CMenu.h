//
// Created by Jakub on 19.10.2018.
//

#ifndef LIST_2_CMENU_H
#define LIST_2_CMENU_H


#include <vector>
#include "CMenuItem.h"
using namespace std;

class CMenu: protected CMenuItem {
protected:
    void Run();
private:
    vector<CMenuItem*> vMenuItems;
};


#endif //LIST_2_CMENU_H