//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_8_H
#define LIST_2_COMM_8_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//all ctables to string
class Comm_8 : public CCommandWithVector {
public:
    explicit Comm_8(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_8_H
