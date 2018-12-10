//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_4_H
#define LIST_2_COMM_4_H


#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please provide an index of the table to change name: "
#define Provide_INT "Please provide the name: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//sets name
class SetCTableName : public CCommandWithVector {
public:
    explicit SetCTableName(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_4_H
