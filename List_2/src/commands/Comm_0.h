//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_0_H
#define LIST_2_COMM_0_H


#include "../inter/CCommand.h"

// creates default ctables, user gives a number of those
class Comm_0 : public CCommand {
public:
    void RunCommand() override;
};


#endif //LIST_2_COMM_0_H