//
// Created by Jakub on 21.10.2018.
//

#ifndef LIST_2_COMM_1_H
#define LIST_2_COMM_1_H


#define Provide_NAME "Please provide a name: "
#define Provide_LENGTH "Please provide a length: "
#define REPEAT "Do you want to create one more specified CTable? (Y/N): "

#include "../interface/CCommand.h"
#include "../interface/CCommandWithVector.h"

//creates a specific ctable
class CreateSpecificCTables: public CCommandWithVector {

public:
    explicit CreateSpecificCTables(CTabHandler &pHandler);
    void RunCommand() override;

};


#endif //LIST_2_COMM_1_H
