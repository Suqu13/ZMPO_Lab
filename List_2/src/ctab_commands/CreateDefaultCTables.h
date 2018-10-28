//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_0_H
#define LIST_2_COMM_0_H


#define Provide_INT "Please provide a number of CTables to create: "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

// creates default ctables, user gives a number of those
class CreateDefaultCTables : public CCommandWithVector {
public:
    explicit CreateDefaultCTables(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_0_H
