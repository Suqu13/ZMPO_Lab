//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SETLENGTHOFCTABLE_H
#define LIST_3_SETLENGTHOFCTABLE_H


#include "../../../interface/CCommandWithVector.h"
#include "../../../helpers/CTabHandler.h"

#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please enter the table whose length you want to change: "
#define Provide_LENGTH "Please provide a new length: "



//sets length of a ctable
class SetLengthOfCTable : public CCommandWithVector {
public:
    explicit SetLengthOfCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_SETLENGTHOFCTABLE_H
