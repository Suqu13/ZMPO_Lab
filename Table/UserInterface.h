//
// Created by Jakub on 08.10.2018.
//

#ifndef TABLE_USERINTERFACE_H
#define TABLE_USERINTERFACE_H

#include <string>
#include <vector>
#include "CTable.h"


using namespace std;


class UserInterface {


public:
    UserInterface();
    ~UserInterface();

    void vRun();

private:
    void vCreateCTables();
    void vAssignElementToTheTable();
    void vGetElementInTheTable();
    void vGetElementOfTheTable();
    void iGetLengthOfTheTable();
    void vSetNameOfTheTable();
    void vDeleteAll();
    void sGetNameOfTheTable();
    void sTheTableToString();


    bool *bSucces;
    vector<CTable *> CTables_Vec;
};


#endif //TABLE_USERINTERFACE_H
