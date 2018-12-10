//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_7_H
#define LIST_2_COMM_7_H


#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please provide an index of the table to delete: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//removes a single ctable
class RemoveSingleCTable : public CCommandWithVector {
public:
    explicit RemoveSingleCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_7_H
