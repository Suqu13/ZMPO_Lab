//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_REMOVESINGLECTABLE_H
#define LIST_3_REMOVESINGLECTABLE_H


#define MESSAGE_IF_EMPTY "Firstly, you have to create a table!!"
#define PROVIDE_INDEX_TABLE_TO_DELETE "Please provide an index of the table to delete: "

#include "../../../lib/interface/CCommandWithVector.h"

//removes a single ctable
class RemoveSingleCTable : public CCommandWithVector {
public:
    explicit RemoveSingleCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_REMOVESINGLECTABLE_H
