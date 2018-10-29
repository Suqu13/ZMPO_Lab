//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CREATEDEFAULTCTABLES_H
#define LIST_3_CREATEDEFAULTCTABLES_H


#define Provide_INT "Please provide a number of CTables to create: "


#include "../../../lib/interface/CCommandWithVector.h"

// creates default ctables, user gives a number of those
class CreateDefaultCTables : public CCommandWithVector {
public:
    explicit CreateDefaultCTables(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_3_CREATEDEFAULTCTABLES_H
