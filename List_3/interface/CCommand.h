//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CCOMMAND_H
#define LIST_3_CCOMMAND_H

#define REMOVE "usuwam: "
#define CCOM "CCommand"
#define DEF "default "
using namespace std;


class CCommand {
public:
    virtual ~CCommand();

    virtual void RunCommand();
};


#endif //LIST_3_CCOMMAND_H
