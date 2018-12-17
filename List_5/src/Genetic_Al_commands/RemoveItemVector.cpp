//
// Created by Jakub on 17.12.2018.
//

#include <iostream>
#include "RemoveItemVector.h"

RemoveItemVector::RemoveItemVector(vector<CItem *> &itemVector) : itemVector(itemVector) {
}

void RemoveItemVector::RunCommand() {
    for (int i = 0; i < itemVector.size(); ++i) {
        delete itemVector.at(i);
    }
    itemVector.clear();
    cout << "\n" << CLEAR_VECTOR << endl;
}


