//
// Created by Jakub on 22.10.2018.
//

#ifndef LIST_2_CCOMMANDWITHVECTOR_H
#define LIST_2_CCOMMANDWITHVECTOR_H


#include "CCommand.h"
#include "../helpers/CTabHandler.h"

class CCommandWithVector : public CCommand {
public:
    explicit CCommandWithVector(CTabHandler &cTabHandler);
    virtual ~CCommandWithVector();

protected:
    CTabHandler &cTabHandler;
};


#endif //LIST_2_CCOMMANDWITHVECTOR_H
