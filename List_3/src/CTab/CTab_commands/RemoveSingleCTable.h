//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_REMOVESINGLECTABLE_H
#define LIST_3_REMOVESINGLECTABLE_H


#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please provide an index of the table to delete: "

#include "../../../helpers/CTabHandler.h"
#include "../../../interface/CCommandWithVector.h"

//removes a single ctable
class RemoveSingleCTable : public CCommandWithVector {
public:
    explicit RemoveSingleCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_REMOVESINGLECTABLE_H
