//
// Created by Jakub on 17.12.2018.
//

#ifndef LIST_3_REMOVEITEMVECTOR_H
#define LIST_3_REMOVEITEMVECTOR_H


#define CLEAR_VECTOR "Item vector is cleared now!"

#include <vector>
#include "../../lib/interface/CCommand.h"
#include "../Genetic_Al/KnapsackProblem/CItem.h"

class RemoveItemVector: public CCommand {
private:
    vector<CItem *> &itemVector;
public:
    explicit RemoveItemVector(vector<CItem *> &itemVector);
    void RunCommand() override;
};


#endif //LIST_3_REMOVEITEMVECTOR_H
