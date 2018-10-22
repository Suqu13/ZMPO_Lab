//
// Created by Jakub on 22.10.2018.
//

#include <iostream>
#include <sstream>
#include "CInitializer.h"
#include "../inter/CMenu.h"
#include "../inter/CMenuCommand.h"
#include "../commands/Comm_0.h"
#include "../commands/Comm_1.h"
#include "../commands/Comm_2.h"
#include "../commands/Comm_3.h"
#include "../commands/Comm_4.h"
#include "../commands/Comm_6.h"
#include "../commands/Comm_7.h"
#include "../commands/Comm_8.h"
#include "../commands/Comm_9.h"
#include "../commands/Comm_5.h"

using namespace std;

void CInitializer::Initialize(CMenu &cMenu, CTabHandler &cTabHandler) {
    CMenu *menu_create;
    menu_create = new CMenu("Create CTables", "create");
    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c1", new Comm_0(cTabHandler)));

    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c1", new Comm_0(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("Create default", "c1", new Comm_0(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c3", new Comm_0(cTabHandler)));

    menu_create->AddMenuItem(new CMenuCommand("Create a specific CTable", "c2", new Comm_1(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("default command", "c3", new CCommand));
    menu_create->AddMenuItem(new CMenuCommand("empty command", "c4", nullptr));
    cMenu.AddMenuItem(menu_create);

    CMenu *menu_change;
    menu_change = new CMenu("Change details", "change");
    menu_change->AddMenuItem(new CMenuCommand("Insert value into a specific CTable", "c1", new Comm_2(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand("Set a length of a specific CTable", "c2", new Comm_3(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand("Set a name of a specific CTable", "c3", new Comm_4(cTabHandler)));

    cMenu.AddMenuItem(menu_change);

    CMenu *menu_remove;
    menu_remove = new CMenu("Remove CTables", "remove");
    menu_remove->AddMenuItem(new CMenuCommand("Remove all CTables", "r1", new Comm_6(cTabHandler)));
    menu_remove->AddMenuItem(new CMenuCommand("Remove a specific CTable", "r2", new Comm_7(cTabHandler)));

    cMenu.AddMenuItem(menu_remove);

    CMenu *menu_show;
    menu_show = new CMenu("Show CTables", "show");
    menu_show->AddMenuItem(new CMenuCommand("Show all CTables", "s1", new Comm_8(cTabHandler)));
    menu_show->AddMenuItem(new CMenuCommand("Show a single CTable", "s2", new Comm_9(cTabHandler)));

    cMenu.AddMenuItem(menu_show);

    cMenu.AddMenuItem(new CMenuCommand("Clone a specific CTable", "clone", new Comm_5(cTabHandler)));

}