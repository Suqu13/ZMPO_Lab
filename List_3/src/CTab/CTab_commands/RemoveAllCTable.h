//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_REMOVEALLCTABLE_H
#define LIST_3_REMOVEALLCTABLE_H


#include "../../../helpers/CTabHandler.h"
#include "../../../interface/CCommandWithVector.h"

//removes all ctables
class RemoveAllCTable : public CCommandWithVector {
public:
    explicit RemoveAllCTable(CTabHandler &pHandler);
    void RunCommand() override;
};



#endif //LIST_3_REMOVEALLCTABLE_H
