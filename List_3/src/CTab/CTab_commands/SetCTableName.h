//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SETCTABLENAME_H
#define LIST_3_SETCTABLENAME_H


#define MESSAGE_IF_EMPTY "Firstly, you have to create a table!!"
#define PROVIDE_INDEX_TABLE_TO_SET_NAME "Please provide an index of the table to change name: "
#define PROVIDE_NEW_NAME "Please provide the name: "



#include "../../../lib/interface/CCommandWithVector.h"

//sets name
class SetCTableName : public CCommandWithVector {
public:
    explicit SetCTableName(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_SETCTABLENAME_H
