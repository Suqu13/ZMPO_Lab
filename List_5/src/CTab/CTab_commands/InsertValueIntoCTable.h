//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_INSERTVALUEINTOCTABLE_H
#define LIST_3_INSERTVALUEINTOCTABLE_H


#define MESSAGE_IF_EMPTY "Firstly, you have to create a table!!"
#define PROVIDE_TABLE_FOR_NEW_ELEMENT "Please provide the table where you want to insert a new element: "
#define PROVIDE_ELEMENT "Please provide the new element: "
#define PROVIDE_INDEX_FOR_NEW_ELEMENT "Please provide an index for the element: "


#include "../../../lib/interface/CCommandWithVector.h"

//inserts a value into a ctable
class InsertValueIntoCTable : public CCommandWithVector {
public:
    explicit InsertValueIntoCTable(CTabHandler &pHandler);

    void RunCommand() override;
};


#endif //LIST_3_INSERTVALUEINTOCTABLE_H
