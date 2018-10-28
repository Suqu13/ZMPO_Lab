//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_8_H
#define LIST_2_COMM_8_H


#define Message_If_Empty "Firstly, you have to create a table!!"

#define NAME "Name: "
#define LENGTH "Length: "
#define ELEMENTS "Elements: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//all ctables to string
class ShowAll : public CCommandWithVector {
public:
    explicit ShowAll(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_8_H
