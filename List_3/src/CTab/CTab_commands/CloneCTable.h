//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CLONECTABLE_H
#define LIST_3_CLONECTABLE_H

#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INT "Please provide an index of the table to clone: "


#include "../../../lib/interface/CCommandWithVector.h"
#include "../../../lib/helpers/CTabHandler.h"

//clones a table
class CloneCTable : public CCommandWithVector {
public:
    explicit CloneCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_CLONECTABLE_H
