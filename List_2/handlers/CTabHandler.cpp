//
// Created by Jakub on 21.10.2018.
//

#include "CTabHandler.h"


vector<CTable*> CTabHandler:: vCTab;

void CTabHandler::cleanIt() {
    for (int i = 0; i < vCTab.size() ; ++i) {
        delete vCTab[i];
    }
    vCTab.clear();
}
