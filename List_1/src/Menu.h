//
// Created by Jakub on 08.10.2018.
//

#ifndef LIST_1_MENU_H
#define LIST_1_MENU_H

#include "CTable.h"
#include <string>
#include <vector>


using namespace std;


class Menu {


public:
    Menu();

    ~Menu();

    void vRun();

private:
    void vVec_ShowMenu();
    void vVec_CreateCTables();
    void vVec_CreateSpecCTable();
    void vVec_Insert();
    void vVec_SetLength();
    void vVec_SetName();
    void vVec_Clone();
    void vVec_DeleteAll();
    void vVec_DeleteCTable();
    void vVec_ToString();
    bool bVec_End();

    vector<CTable *> vCTables_Vec;
};


#endif //TABLE_USERINTERFACE_H

