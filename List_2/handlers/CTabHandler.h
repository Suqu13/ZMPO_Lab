//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_CTABHANDLER_H
#define LIST_2_CTABHANDLER_H


#include <vector>
#include "../ctab/CTable.h"

class CTabHandler {
public:
    ~CTabHandler();
    static vector<CTable*> vCTab;
};


#endif //LIST_2_CTABHANDLER_H
