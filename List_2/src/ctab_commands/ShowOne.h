//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_9_H
#define LIST_2_COMM_9_H


#define Message_If_Empty "Firstly, you have to create a table!!"

#define Provide_INDEX "Please provide an index of the table to show: "

#define NAME "Name: "
#define LENGTH "Length: "
#define ELEMENTS "Elements: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//a single ctable to string
class ShowOne : public CCommandWithVector {
public:
    explicit ShowOne(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_9_H
