//
// Created by Jakub on 19.10.2018.
//

#ifndef LIST_2_CCOMMAND_H
#define LIST_2_CCOMMAND_H
#define REMOVE "usuwam: "
#define CCOM "CCommand"
#define DEF "default "
using namespace std;


class CCommand {
public:
    virtual ~CCommand();
    virtual void RunCommand();
};


#endif //LIST_2_CCOMMAND_H
