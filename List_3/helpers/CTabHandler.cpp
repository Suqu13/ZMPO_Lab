//
// Created by Jakub on 21.10.2018.
//

#include "../src/CTab/CTable.h"
#include "CTabHandler.h"


CTabHandler::~CTabHandler() {
    for (int i = 0; i < vCTab.size(); ++i) {
        delete vCTab[i];
    }
    vCTab.clear();
}

vector<CTable *> &CTabHandler::getVector() {
    return vCTab;
}

