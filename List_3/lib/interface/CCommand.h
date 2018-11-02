//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CCOMMAND_H
#define LIST_3_CCOMMAND_H

#define REMOVING_COMMAND_OBJECT "usuwam: "
#define COMMAND_OBJECT "CCommand"
#define DEFAULT_CCOMMAND "default CCommand "
using namespace std;

class CCommand {
public:
    virtual ~CCommand();
    virtual void RunCommand();
};


#endif //LIST_3_CCOMMAND_H
