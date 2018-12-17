//
// Created by Jakub on 17.12.2018.
//

#ifndef LIST_3_SHOWITEMS_H
#define LIST_3_SHOWITEMS_H


#define EMPTY_VECTOR "Item vector is empty!"

#define NAME_TO_SHOW "Name: "

#define WEIGHT_TO_SHOW "Weight: "

#define VALUE_TO_SHOW "Value: "

#include <vector>
#include "../../lib/interface/CCommand.h"
#include "../Genetic_Al/KnapsackProblem/CItem.h"

class ShowItems: public CCommand {
private:
    vector<CItem *> &itemVector;
public:
    explicit ShowItems(vector<CItem *> &itemVector);
    void RunCommand() override;
};


#endif //LIST_3_SHOWITEMS_H
