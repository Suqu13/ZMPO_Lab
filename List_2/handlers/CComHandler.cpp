//
// Created by Jakub on 21.10.2018.
//

#include "../handlers/CComHandler.h"
#include "../inter/CCommand.h"
#include <vector>
#include <string>

CMenuItem* CComHandler::getCMenuCommand(string s_name, string s_command){
    for (int i = 0; i < vCom.size() ; ++i) {
        if (vCom[i]->getS_name() == s_name && vCom[i]->getS_command() == s_command)
            return vCom[i];
    }
    return nullptr;
}