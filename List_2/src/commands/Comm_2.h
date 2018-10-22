//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_2_H
#define LIST_2_COMM_2_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//inserts a value into a ctable
class Comm_2: public CCommandWithVector {
public:
    explicit Comm_2(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_2_H
