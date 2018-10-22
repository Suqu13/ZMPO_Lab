//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_7_H
#define LIST_2_COMM_7_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//removes a single ctable
class Comm_7 : public CCommandWithVector {
public:
    explicit Comm_7(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_7_H
