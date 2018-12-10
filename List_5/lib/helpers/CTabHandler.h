//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_3_CTABHANDLER_H
#define LIST_3_CTABHANDLER_H


#include <vector>
#include "../../src/CTab/CTable.h"

class CTabHandler {
public:
~CTabHandler();
    vector<CTable*> &getVector();
private:
     vector<CTable*> vCTab;
};


#endif //LIST_3_CTABHANDLER_H
