//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SETCTABLENAME_H
#define LIST_3_SETCTABLENAME_H


#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please provide an index of the table to change name: "
#define Provide_INT "Please provide the name: "



#include "../../../lib/interface/CCommandWithVector.h"

//sets name
class SetCTableName : public CCommandWithVector {
public:
    explicit SetCTableName(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_SETCTABLENAME_H
