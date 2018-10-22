//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_9_H
#define LIST_2_COMM_9_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//a single ctable to string
class Comm_9 : public CCommandWithVector {
public:
    explicit Comm_9(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_9_H
