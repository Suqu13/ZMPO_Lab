//
// Created by Jakub on 22.10.2018.
//

#ifndef LIST_3_CINITIALIZER_H
#define LIST_3_CINITIALIZER_H


#define CREATING_MENU "Create CTables"
#define CREATING_COMMAND "create"
#define CREATING_MULTIPLE "Create default CTables"
#define CREATING_MUTLIPLE_COMMAND "c1"
#define CREATING_MUTLIPLE_HELP "Helps in creating a large amount of CTable objects"
#define CREATING_ONE "Create a specific CTable"
#define CREATING_ONE_COMMAND "c2"
#define CREATING_ONE_HELP "Helps in creating a specific CTable, User can provide a length and name"
#define DEFAULT "default command"
#define DEFAULT_COMMAND "c3"
#define DEFAULT_HELP "Shows how default commands work"
#define EMPTY "empty command"
#define EMPTY_COMMAND "c4"
#define EMPTY_HELP "Shows how empty commands work"
#define CHANGING_MENU "Change details"
#define CHANGING_COMMAND "change"
#define INSERTING_VAL "Insert value"
#define INSERTING_VAL_COMMAND "c1"
#define INSERTING_VAL_HELP "Makes inserting a value provided by User into a specific CTable possible"
#define SETTING_LENGTH "Set a length"
#define SETTING_LENGTH_COMMAND "c2"
#define SETTING_LENGTH_HELP "Makes setting length of a CTable provided by User possible"
#define SETTING_NAME "Set a name"
#define SETTING_NAME_COMMAND "c3"
#define SETTING_NAME_HELP "Makes setting name of a CTable provided by User possible"
#define REMOVING_MENU "Remove CTables"
#define REMOVING_COMMAND "remove"
#define REMOVING_ALL "Remove all CTables"
#define REMOVING_ALL_COMMAND "r1"
#define REMOVING_ALL_HELP "Removes all CTables, after that the handler for objects is empty"
#define REMOVING_ONE "Remove a specific CTable"
#define REMOVING_ONE_COMMAND "r2"
#define REMOVING_ONE_HELP "Help in removing a CTable from the index provided by User"
#define SHOWING_MENU "Show CTables"
#define SHOWING_COMMAND "show"
#define SHOWING_ALL "Show all CTables"
#define SHOWING_ALL_COMMAND "s1"
#define SHOWING_ALL_HELP "Shows all existing CTable objects"
#define SHOWING_ONE "Show a single CTable"
#define SHOWING_ONE_COMMAND "s2"
#define SHOWING_ONE_HELP "Shows a CTable from the index provided by User"
#define CLONING_ONE "Clone a specific CTable"
#define CLONING_ONE_COMMAND "clone"
#define CLONING_ONE_HELP "Makes cloning possible. User have to give a index of the object to clone"

#include "CTabHandler.h"
#include "../interface/CMenu.h"

class CInitializer {
public:
    static void InitializeForCTable(CMenu &cMenu, CTabHandler &cTabHandler);
    // static void InitializeCalulator(CMenu &cMenu, CCalculator &calculator);
};


#endif //LIST_3_CINITIALIZER_H
