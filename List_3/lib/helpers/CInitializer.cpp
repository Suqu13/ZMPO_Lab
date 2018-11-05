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
#include "CMenuAnalyzer.h"


using namespace std;

void CInitializer::InitializeForCTable(CMenu &cMenu, CTabHandler &cTabHandler) {
    CMenu *menu_create;
    menu_create = new CMenu(CREATING_MENU, CREATING_COMMAND);

    menu_create->AddMenuItem(new CMenuCommand(CREATING_MULTIPLE, CREATING_MUTLIPLE_COMMAND,CREATING_MUTLIPLE_HELP,new CreateDefaultCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand(CREATING_ONE, CREATING_ONE_COMMAND, CREATING_ONE_HELP, new CreateSpecificCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand(DEFAULT, DEFAULT_COMMAND, DEFAULT_HELP, new CCommand));
    menu_create->AddMenuItem(new CMenuCommand(EMPTY, EMPTY_COMMAND,EMPTY_HELP, nullptr));
    cMenu.AddMenuItem(menu_create);

    CMenu *menu_change;
    menu_change = new CMenu(CHANGING_MENU, CHANGING_COMMAND);
    menu_change->AddMenuItem(new CMenuCommand(INSERTING_VAL, INSERTING_VAL_COMMAND, INSERTING_VAL_HELP, new InsertValueIntoCTable(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand(SETTING_LENGTH, SETTING_LENGTH_COMMAND,SETTING_LENGTH_HELP, new SetLengthOfCTable(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand(SETTING_NAME, SETTING_NAME_COMMAND,SETTING_NAME_HELP, new SetCTableName(cTabHandler)));

    cMenu.AddMenuItem(menu_change);

    CMenu *menu_remove;
    menu_remove = new CMenu(REMOVING_MENU, REMOVING_COMMAND);
    menu_remove->AddMenuItem(new CMenuCommand(REMOVING_ALL, REMOVING_ALL_COMMAND, REMOVING_ALL_HELP, new RemoveAllCTable(cTabHandler)));
    menu_remove->AddMenuItem(new CMenuCommand(REMOVING_ONE, REMOVING_ONE_COMMAND,REMOVING_ONE_HELP, new RemoveSingleCTable(cTabHandler)));

    cMenu.AddMenuItem(menu_remove);

    CMenu *menu_show;
    menu_show = new CMenu(SHOWING_MENU, SHOWING_COMMAND);
    menu_show->AddMenuItem(new CMenuCommand(SHOWING_ALL, SHOWING_ALL_COMMAND, SHOWING_ALL_HELP, new ShowAll(cTabHandler)));
    menu_show->AddMenuItem(new CMenuCommand(SHOWING_ONE, SHOWING_ONE_COMMAND, SHOWING_ONE_HELP, new ShowOne(cTabHandler)));

    cMenu.AddMenuItem(menu_show);

    cMenu.AddMenuItem(new CMenuCommand(CLONING_ONE, CLONING_ONE_COMMAND, CLONING_ONE_HELP, new CloneCTable(cTabHandler)));
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

