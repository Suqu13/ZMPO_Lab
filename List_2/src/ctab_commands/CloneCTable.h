//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_5_H
#define LIST_2_COMM_5_H

#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INT "Please provide an index of the table to clone: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//clones a table
class CloneCTable : public CCommandWithVector {
public:
    explicit CloneCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_5_H
