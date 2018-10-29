//
// Created by Jakub on 22.10.2018.
//

#include <iostream>
#include <sstream>
#include "CTabHandler.h"
#include "CInitializer.h"
#include "../../src/CTab/CTab_commands/CreateDefaultCTables.h"
#include "../../src/CTab/CTab_commands/CreateSpecificCTables.h"
#include "../../src/CTab/CTab_commands/InsertValueIntoCTable.h"
#include "../../src/CTab/CTab_commands/SetLengthOfCTable.h"
#include "../../src/CTab/CTab_commands/SetCTableName.h"
#include "../../src/CTab/CTab_commands/ShowAll.h"
#include "../../src/CTab/CTab_commands/RemoveAllCTable.h"
#include "../../src/CTab/CTab_commands/RemoveSingleCTable.h"
#include "../../src/CTab/CTab_commands/ShowOne.h"
#include "../../src/CTab/CTab_commands/CloneCTable.h"
#include "../interface/CMenuCommand.h"


using namespace std;

void CInitializer::InitializeForCTable(CMenu &cMenu, CTabHandler &cTabHandler) {
    CMenu *menu_create;
    menu_create = new CMenu("Create CTables", "create", "This menu helps in creating new CTable objects");

    menu_create->AddMenuItem(new CMenuCommand("Create default CTables", "c1","Helps in creating a large amount of CTable objects",new CreateDefaultCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("Create a specific CTable", "c2", "Helps in creating a specific CTable, User can provide a length and name", new CreateSpecificCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand("default command", "c3", "Shows how default commands work", new CCommand));
    menu_create->AddMenuItem(new CMenuCommand("empty command", "c4","Shows how empty commands work", nullptr));
    cMenu.AddMenuItem(menu_create);

    CMenu *menu_change;
    menu_change = new CMenu("Change details", "change", "Makes changing details of a specific CTable possible");
    menu_change->AddMenuItem(new CMenuCommand("Insert value", "c1", "Makes inserting a value provided by User into a specific CTable possible", new InsertValueIntoCTable(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand("Set a length", "c2","Makes setting length of a CTable provided by User possible", new SetLengthOfCTable(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand("Set a name", "c3","Makes setting name of a CTable provided by User possible", new SetCTableName(cTabHandler)));

    cMenu.AddMenuItem(menu_change);

    CMenu *menu_remove;
    menu_remove = new CMenu("Remove CTables", "remove", "This menu makes removing possible");
    menu_remove->AddMenuItem(new CMenuCommand("Remove all CTables", "r1", "Removes all CTables, after that the handler for objects is empty", new RemoveAllCTable(cTabHandler)));
    menu_remove->AddMenuItem(new CMenuCommand("Remove a specific CTable", "r2","Help in removing a CTable from the index provided by User", new RemoveSingleCTable(cTabHandler)));

    cMenu.AddMenuItem(menu_remove);

    CMenu *menu_show;
    menu_show = new CMenu("Show CTables", "show", "Enable printing whole handler of objects");
    menu_show->AddMenuItem(new CMenuCommand("Show all CTables", "s1", "Shows all existing CTable objects", new ShowAll(cTabHandler)));
    menu_show->AddMenuItem(new CMenuCommand("Show a single CTable", "s2", "Shows a CTable from the index provided by User", new ShowOne(cTabHandler)));

    cMenu.AddMenuItem(menu_show);

    cMenu.AddMenuItem(new CMenuCommand("Clone a specific CTable", "clone", "Makes cloning possible. User have to give a index of the object to clone", new CloneCTable(cTabHandler)));

}

//void CInitializer::InitializeCalulator(CMenu &cMenu, CCalculator &calculator) {
//    cMenu.AddMenuItem(new CMenuCommand("Zmień liczbę A", "zma", new SetAValue(calculator)));
//    cMenu.AddMenuItem(new CMenuCommand("Zmień liczbę B", "zmb", new SetBValue(calculator)));
//
//    CMenu *operacje;
//    operacje = new CMenu("Operacje", "op");
//    operacje->AddMenuItem(new CMenuCommand("Dodaj", "dod", new AddValues(calculator)));
//    operacje->AddMenuItem(new CMenuCommand("Odejmij", "ode", new SubstractValues(calculator)));
//    operacje->AddMenuItem(new CMenuCommand("Resetuj", "res", new ResetValues(calculator)));
//    operacje->AddMenuItem(new CMenuCommand("Domyślna komenda", "dom", new CCommand));
//
//    cMenu.AddMenuItem(operacje);
//}

