//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_1_H
#define LIST_2_COMM_1_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//creates a specific ctable
class Comm_1: public CCommandWithVector {

public:
    explicit Comm_1(CTabHandler &pHandler);
    void RunCommand() override;

};


#endif //LIST_2_COMM_1_H
