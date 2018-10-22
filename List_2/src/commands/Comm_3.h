//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_3_H
#define LIST_2_COMM_3_H


#include "../inter/CCommand.h"
#include "../inter/CCommandWithVector.h"

//sets length of a ctable
class Comm_3 : public CCommandWithVector {
public:
    explicit Comm_3(CTabHandler &pHandler);
    void RunCommand() override;
};



#endif //LIST_2_COMM_3_H
