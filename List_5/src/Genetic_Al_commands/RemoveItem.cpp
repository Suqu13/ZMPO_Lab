//
// Created by Jakub on 17.12.2018.
//

#include <iostream>
#include "RemoveItem.h"
#include "../../lib/utilities/Utilities.h"

RemoveItem::RemoveItem(vector<CItem *> &itemVector) : itemVector(itemVector) {

}

void RemoveItem::RunCommand() {
    if (itemVector.empty()) {
        cout << EMPTY_ITEMS_VECTOR << endl;
        return;
    }
    string itemName;
    bool removed = false;

    cout << GIVEN_NAME_TO_REMOVE;
    itemName = Utilities::sProvideString();

    for (int i = 0; i < itemVector.size(); ++i) {
        if (!removed && itemVector.at(i)->getName() == itemName) {
            delete itemVector.at(i);
            itemVector.erase(itemVector.begin() + i);
            removed = true;
        }
    }

    if (!removed)
        cout << ITEM_NOT_FOUND << endl;
}