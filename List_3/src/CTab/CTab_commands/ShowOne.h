//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SHOWONE_H
#define LIST_3_SHOWONE_H

#include "../../../lib/interface/CCommandWithVector.h"

#define MESSAGE_IF_EMPTY "Firstly, you have to create a table!!"
#define PROVIDE_INDEX_TABLE_TO_SHOW "Please provide an index of the table to show: "
#define NAME "Name: "
#define LENGTH "Length: "
#define ELEMENTS "Elements: "



//a single ctable to string
class ShowOne : public CCommandWithVector {
public:
    explicit ShowOne(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_SHOWONE_H
