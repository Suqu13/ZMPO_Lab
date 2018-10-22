//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_6_H
#define LIST_2_COMM_6_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//removes all ctables
class Comm_6 : public CCommandWithVector {
public:
    explicit Comm_6(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_6_H
