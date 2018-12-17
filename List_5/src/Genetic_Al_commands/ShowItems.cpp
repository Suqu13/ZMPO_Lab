//
// Created by Jakub on 17.12.2018.
//

#include <iostream>
#include <iomanip>
#include "ShowItems.h"

ShowItems::ShowItems(vector<CItem *> &itemVector) : itemVector(itemVector) {
}

void ShowItems::RunCommand() {
    if (itemVector.empty()) {
     cout << EMPTY_VECTOR << endl;
    } else {
        for (int i = 0; i < itemVector.size(); ++i) {
            cout << NAME_TO_SHOW << setw(8) << itemVector.at(i)->getName() << setw(10) << WEIGHT_TO_SHOW << setw(4)
                 << itemVector.at(i)->getWeight() << setw(10) << VALUE_TO_SHOW << setw(4) << itemVector.at(i)->getValue()
                 << endl;
        }
    }
}
