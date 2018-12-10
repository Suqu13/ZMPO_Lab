//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_3_H
#define LIST_2_COMM_3_H


#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please enter the table whose length you want to change: "
#define Provide_LENGTH "Please provide a new length: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//sets length of a ctable
class SetLengthOfCTable : public CCommandWithVector {
public:
    explicit SetLengthOfCTable(CTabHandler &pHandler);
    void RunCommand() override;
};



#endif //LIST_2_COMM_3_H
