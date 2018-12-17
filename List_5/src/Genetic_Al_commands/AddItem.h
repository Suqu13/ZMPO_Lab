//
// Created by Jakub on 17.12.2018.
//

#ifndef LIST_3_ADDITEM_H
#define LIST_3_ADDITEM_H


#define GIVEN_NAME "Provide a new item name: "
#define GIVEN_WEIGHT "Provide a new item weight: "
#define GIVEN_VALUE "Provide a new item value: "

#include <vector>
#include <string>
#include "../../lib/interface/CCommand.h"
#include "../Genetic_Al/KnapsackProblem/CItem.h"
#include "../../lib/utilities/Utilities.h"

using namespace std;

class AddItem : public CCommand {
private:
    vector<CItem *> &itemVector;
public:
    explicit AddItem(vector<CItem *> &itemVector);
    void RunCommand() override;
};


#endif //LIST_3_ADDITEM_H
