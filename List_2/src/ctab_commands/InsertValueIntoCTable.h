//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_2_H
#define LIST_2_COMM_2_H


#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please provide the table where you want to insert a new element: "
#define Provide_VALUE "Please provide the new element: "
#define Provide_VALUE_INDEX "Please provide an index for the element: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//inserts a value into a ctable
class InsertValueIntoCTable: public CCommandWithVector {
public:
    explicit InsertValueIntoCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_2_H
