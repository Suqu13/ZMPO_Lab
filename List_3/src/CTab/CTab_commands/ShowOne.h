//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SHOWONE_H
#define LIST_3_SHOWONE_H


#include "../../../interface/CCommandWithVector.h"
#include "../../../helpers/CTabHandler.h"

#define Message_If_Empty "Firstly, you have to create a table!!"
#define Provide_INDEX "Please provide an index of the table to show: "
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
