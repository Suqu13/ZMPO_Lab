//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SETLENGTHOFCTABLE_H
#define LIST_3_SETLENGTHOFCTABLE_H



#include "../../../lib/interface/CCommandWithVector.h"

#define MESSAGE_IF_EMPTY "Firstly, you have to create a table!!"
#define PROVIDE_INDEX_TABLE_TO_SET_LENGTH "Please enter the table whose length you want to change: "
#define PROVIDE_NEW_LENGTH "Please provide a new length: "



//sets length of a ctable
class SetLengthOfCTable : public CCommandWithVector {
public:
    explicit SetLengthOfCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_SETLENGTHOFCTABLE_H
