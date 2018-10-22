//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_4_H
#define LIST_2_COMM_4_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//sets name
class Comm_4 : public CCommandWithVector {
public:
    explicit Comm_4(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_4_H
