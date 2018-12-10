//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CREATESPECIFICCTABLES_H
#define LIST_3_CREATESPECIFICCTABLES_H


#define PROVIDE_NAME "Please provide a name: "
#define PROVIDE_LENGTH "Please provide a length: "
#define REPEATING_OPERATION "Do you want to create one more specified CTable? (Y/N): "


#include "../../../lib/interface/CCommandWithVector.h"

//creates a specific ctable
class CreateSpecificCTables: public CCommandWithVector {

public:
    explicit CreateSpecificCTables(CTabHandler &pHandler);
    void RunCommand() override;

};


#endif //LIST_3_CREATESPECIFICCTABLES_H
