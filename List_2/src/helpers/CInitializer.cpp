//
// Created by Jakub on 22.10.2018.
//

#include <iostream>
#include <sstream>
#include "CInitializer.h"
#include "../interface/CMenu.h"
#include "../interface/CMenuCommand.h"
#include "../ctab_commands/CreateDefaultCTables.h"
#include "../ctab_commands/CreateSpecificCTables.h"
#include "../ctab_commands/InsertValueIntoCTable.h"
#include "../ctab_commands/SetLengthOfCTable.h"
#include "../ctab_commands/SetCTableName.h"
#include "../ctab_commands/RemoveAllCTable.h"
#include "../ctab_commands/RemoveSingleCTable.h"
#include "../ctab_commands/ShowAll.h"
#include "../ctab_commands/ShowOne.h"
#include "../ctab_commands/CloneCTable.h"


using namespace std;

void CInitializer::Initialize(CMenu &cMenu, CTabHandler &cTabHandler) {
    CMenu *menu_create;
    menu_create = new CMenu("Create CTables", "create");
    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c1", new CreateDefaultCTables(cTabHandler)));

    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c1", new CreateDefaultCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("Create default", "c1", new CreateDefaultCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c3", new CreateDefaultCTables(cTabHandler)));

    menu_create->AddMenuItem(new CMenuCommand("Create a specific CTable", "c2", new CreateSpecificCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("default command", "c3", new CCommand));
    menu_create->AddMenuItem(new CMenuCommand("empty command", "c4", nullptr));
    cMenu.AddMenuItem(menu_create);

    CMenu *menu_change;
    menu_change = new CMenu("Change details", "change");
    menu_change->AddMenuItem(new CMenuCommand("Insert value into a specific CTable", "c1", new InsertValueIntoCTable(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand("Set a length of a specific CTable", "c2", new SetLengthOfCTable(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand("Set a name of a specific CTable", "c3", new SetCTableName(cTabHandler)));

    cMenu.AddMenuItem(menu_change);

    CMenu *menu_remove;
    menu_remove = new CMenu("Remove CTables", "remove");
    menu_remove->AddMenuItem(new CMenuCommand("Remove all CTables", "r1", new RemoveAllCTable(cTabHandler)));
    menu_remove->AddMenuItem(new CMenuCommand("Remove a specific CTable", "r2", new RemoveSingleCTable(cTabHandler)));

    cMenu.AddMenuItem(menu_remove);

    CMenu *menu_show;
    menu_show = new CMenu("Show CTables", "show");
    menu_show->AddMenuItem(new CMenuCommand("Show all CTables", "s1", new ShowAll(cTabHandler)));
    menu_show->AddMenuItem(new CMenuCommand("Show a single CTable", "s2", new ShowOne(cTabHandler)));

    cMenu.AddMenuItem(menu_show);

    cMenu.AddMenuItem(new CMenuCommand("Clone a specific CTable", "clone", new CloneCTable(cTabHandler)));

}


