//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_6_H
#define LIST_2_COMM_6_H


#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//removes all ctables
class RemoveAllCTable : public CCommandWithVector {
public:
    explicit RemoveAllCTable(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_6_H
