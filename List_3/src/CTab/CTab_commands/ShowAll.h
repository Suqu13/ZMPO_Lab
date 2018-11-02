//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_SHOWALL_H
#define LIST_3_SHOWALL_H


#include "../../../lib/interface/CCommandWithVector.h"

#define MESSAGE_IF_EMPTY "Firstly, you have to create a table!!"
#define CURRENT_NAME "Name: "
#define CURRENT_LENGTH "Length: "
#define CURRENT_ELEMENTS "Elements: "



//all ctables to string
class ShowAll : public CCommandWithVector {
public:
    explicit ShowAll(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_SHOWALL_H
