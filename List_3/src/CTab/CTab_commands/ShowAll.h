//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SHOWALL_H
#define LIST_3_SHOWALL_H


#include "../../../lib/interface/CCommandWithVector.h"

#define Message_If_Empty "Firstly, you have to create a table!!"
#define NAME "Name: "
#define LENGTH "Length: "
#define ELEMENTS "Elements: "



//all ctables to string
class ShowAll : public CCommandWithVector {
public:
    explicit ShowAll(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_SHOWALL_H
