//
// Created by Jakub on 17.12.2018.
//

#include <iostream>
#include "AddItem.h"

AddItem::AddItem(vector<CItem *> &itemVector): itemVector(itemVector){
}

void AddItem::RunCommand() {
    string itemName;
    int itemWeight;
    int itemValue;

    cout << GIVEN_NAME;
    itemName = Utilities::sProvideString();

    cout << GIVEN_WEIGHT;
    itemWeight = Utilities::inputPositiveInt();

    cout << GIVEN_VALUE;
    itemValue = Utilities::inputPositiveInt();

    itemVector.push_back(new CItem(itemName, itemWeight, itemValue));
}



