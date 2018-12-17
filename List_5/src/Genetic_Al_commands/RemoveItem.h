//
// Created by Jakub on 17.12.2018.
//

#ifndef LIST_3_REMOVEITEM_H
#define LIST_3_REMOVEITEM_H


#define GIVEN_NAME_TO_REMOVE "Provide a item name to remove: "
#define ITEM_NOT_FOUND "Item not found!"
#define EMPTY_ITEMS_VECTOR "Items vector is empty!"

#include <vector>
#include "../../lib/interface/CCommand.h"
#include "../Genetic_Al/KnapsackProblem/CItem.h"

class RemoveItem: public CCommand {
private:
    vector<CItem *> &itemVector;
public:
    explicit RemoveItem(vector<CItem *> &itemVector);
    void RunCommand() override;
};


#endif //LIST_3_REMOVEITEM_H
