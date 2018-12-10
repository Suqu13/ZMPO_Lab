//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CCOMMANDWITHVECTOR_H
#define LIST_3_CCOMMANDWITHVECTOR_H


#include "CCommand.h"
#include "../helpers/CTabHandler.h"

class CCommandWithVector : public CCommand {
public:
    explicit CCommandWithVector(CTabHandler &cTabHandler);
    ~CCommandWithVector() override;
protected:
    CTabHandler &cTabHandler;
};


#endif //LIST_3_CCOMMANDWITHVECTOR_H
