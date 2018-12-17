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
#include "../../src/Genetic_Al_commands/GeneticAlgorithm_command.h"
#include "../../src/Genetic_Al_commands/AddItem.h"
#include "../../src/Genetic_Al_commands/RemoveItem.h"
#include "../../src/Genetic_Al_commands/RemoveItemVector.h"
#include "../../src/Genetic_Al_commands/ShowItems.h"


using namespace std;

void CInitializer::InitializeForCTable(CMenu &cMenu, CTabHandler &cTabHandler) {
    CMenu *menu_create;
    menu_create = new CMenu(CREATING_MENU, CREATING_COMMAND);

    menu_create->AddMenuItem(new CMenuCommand(CREATING_MULTIPLE, CREATING_MUTLIPLE_COMMAND, CREATING_MUTLIPLE_HELP,
                                              new CreateDefaultCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand(CREATING_ONE, CREATING_ONE_COMMAND, CREATING_ONE_HELP,
                                              new CreateSpecificCTables(cTabHandler)));
    menu_create->AddMenuItem(new CMenuCommand(DEFAULT, DEFAULT_COMMAND, DEFAULT_HELP, new CCommand));
    menu_create->AddMenuItem(new CMenuCommand(EMPTY, EMPTY_COMMAND, EMPTY_HELP, nullptr));
    cMenu.AddMenuItem(menu_create);

    CMenu *menu_change;
    menu_change = new CMenu(CHANGING_MENU, CHANGING_COMMAND);
    menu_change->AddMenuItem(new CMenuCommand(INSERTING_VAL, INSERTING_VAL_COMMAND, INSERTING_VAL_HELP,
                                              new InsertValueIntoCTable(cTabHandler)));
    menu_change->AddMenuItem(new CMenuCommand(SETTING_LENGTH, SETTING_LENGTH_COMMAND, SETTING_LENGTH_HELP,
                                              new SetLengthOfCTable(cTabHandler)));
    menu_change->AddMenuItem(
            new CMenuCommand(SETTING_NAME, SETTING_NAME_COMMAND, SETTING_NAME_HELP, new SetCTableName(cTabHandler)));

    cMenu.AddMenuItem(menu_change);

    CMenu *menu_remove;
    menu_remove = new CMenu(REMOVING_MENU, REMOVING_COMMAND);
    menu_remove->AddMenuItem(
            new CMenuCommand(REMOVING_ALL, REMOVING_ALL_COMMAND, REMOVING_ALL_HELP, new RemoveAllCTable(cTabHandler)));
    menu_remove->AddMenuItem(new CMenuCommand(REMOVING_ONE, REMOVING_ONE_COMMAND, REMOVING_ONE_HELP,
                                              new RemoveSingleCTable(cTabHandler)));

    cMenu.AddMenuItem(menu_remove);

    CMenu *menu_show;
    menu_show = new CMenu(SHOWING_MENU, SHOWING_COMMAND);
    menu_show->AddMenuItem(
            new CMenuCommand(SHOWING_ALL, SHOWING_ALL_COMMAND, SHOWING_ALL_HELP, new ShowAll(cTabHandler)));
    menu_show->AddMenuItem(
            new CMenuCommand(SHOWING_ONE, SHOWING_ONE_COMMAND, SHOWING_ONE_HELP, new ShowOne(cTabHandler)));

    cMenu.AddMenuItem(menu_show);

    cMenu.AddMenuItem(
            new CMenuCommand(CLONING_ONE, CLONING_ONE_COMMAND, CLONING_ONE_HELP, new CloneCTable(cTabHandler)));
}

void CInitializer::InitializeForGenetic(CMenu &cMenu, vector<CItem *> &itemVector) {

    CMenu *menu_solve;
    menu_solve = new CMenu("Solve Knapsack problem", "solve");

    menu_solve->AddMenuItem(new CMenuCommand("As int", "int", "It makes possible to run the algorithm as int example", new GeneticAlgorithm_command<int>(itemVector)));
    menu_solve->AddMenuItem(
            new CMenuCommand("As double", "double", "It makes possible to run the algorithm as double example", new GeneticAlgorithm_command<double>(itemVector)));
    menu_solve->AddMenuItem(
            new CMenuCommand("AS boolean", "boolean", "It makes possible to run the algorithm as boolean example", new GeneticAlgorithm_command<bool>(itemVector)));
    cMenu.AddMenuItem(menu_solve);

    CMenu *menu_menage;
    menu_menage = new CMenu("Items manage", "manage");

    menu_menage->AddMenuItem(new CMenuCommand("Add a new item", "add", "This command adds a completely new item to the vector", new AddItem(itemVector)));
    menu_menage->AddMenuItem(new CMenuCommand("Remove an item", "remove", "This command removes an item from the vector", new RemoveItem(itemVector)));
    menu_menage->AddMenuItem(new CMenuCommand("Clear vector", "clear", "This command erase the whole vector", new RemoveItemVector(itemVector)));
    cMenu.AddMenuItem(menu_menage);

    cMenu.AddMenuItem(new CMenuCommand("Show items", "show", "This command prints all items on the console", new ShowItems(itemVector)));

}

