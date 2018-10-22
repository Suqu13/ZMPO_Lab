//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_5_H
#define LIST_2_COMM_5_H

#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//clones a table
class Comm_5 : public CCommandWithVector {
public:
    explicit Comm_5(CTabHandler &pHandler);
    void RunCommand() override;
};


#endif //LIST_2_COMM_5_H
