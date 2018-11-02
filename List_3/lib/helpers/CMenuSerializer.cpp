//
// Created by Jakub on 31.10.2018.
//

#include <sstream>
#include <iostream>
#include "CMenuSerializer.h"
#include "../utilities/Utilities.h"

CMenu *CMenuSerializer::mainMenu;

void CMenuSerializer::setMainMenu(CMenu *mainMenu) {
    CMenuSerializer::mainMenu = mainMenu;
}

string CMenuSerializer::serializeInterface(CMenuItem *cMenuItem) {
    stringstream stream;
    if (CMenu *cMenu = dynamic_cast<CMenu *> (cMenuItem)) {
        stream << "('" << cMenu->getS_name() << "','" << cMenu->getS_command() << "';";
        for (int i = 0; i < cMenu->getVMenuItems().size(); i++) {
            if (i > 0) {
                stream << ",";
            }
            stream << serializeInterface(cMenu->getVMenuItems()[i]);
        }
        stream << ")";
    } else if (CMenuCommand *cMenuCommand = dynamic_cast<CMenuCommand *>(cMenuItem)) {
        stream << serializeCMenuCommand(cMenuCommand);
    }
    return stream.str();
}


string CMenuSerializer::serializeCMenuCommand(CMenuCommand *cMenuCommand) {
    string cMenuCommand_info;
    cMenuCommand_info = "['" + cMenuCommand->getS_name() + "','" + cMenuCommand->getS_command() + "','" +
                        cMenuCommand->getS_help() + "']";
    return cMenuCommand_info;
}

CMenuCommand *CMenuSerializer::deserializeCMenuCommand(string cMenuCommand_info) {
    vector<string> vec = Utilities::vSplitString(cMenuCommand_info.substr(2, cMenuCommand_info.size() - 3), "','");
    return (new CMenuCommand(vec[0], vec[1], vec[2], nullptr));
}

CMenu *CMenuSerializer::deserializeCMenu(string cMenu_info) {
    vector<string> newCMenu = Utilities::vSplitString(cMenu_info.substr(2, cMenu_info.size() - 3), "','");
    return new CMenu(newCMenu[0], newCMenu[1]);
}

int CMenuSerializer::findClosingChar(char opening, string toAnalyze) {
    char closing;
    switch (opening) {
        case '(':
            closing = ')';
            break;
        case '[':
            closing = ']';
            break;
        default:
            return -1;
    }
    int start_point = toAnalyze.find(opening);
    int end_point = -1;
    int inside_point = start_point;
    do {
        inside_point = toAnalyze.find(opening, inside_point + 1);
        end_point = toAnalyze.find(closing, end_point + 1);
    } while (start_point < inside_point && inside_point < end_point);
    return end_point;
}

CMenuItem *CMenuSerializer::deserializeInterface(string Interface_info) {
    if (Interface_info.at(0) == '(') {
        int endPosition;
        int findSemicolon = Interface_info.find(';');
        CMenu *cMenu = deserializeCMenu(Interface_info.substr(0, findSemicolon));
        string actualString = Interface_info.substr(findSemicolon + 1, Interface_info.size() - findSemicolon - 1);
        //dzieli string dwojako, po commandach zostaje pusty "", natomiast po menu mamy jakiś pojedynczy znak konczący
        while ((actualString.size() != 0) && (endPosition = findClosingChar(actualString.at(0), actualString)) != -1) {
            CMenuItem *cMenuItem = deserializeInterface(actualString.substr(0, endPosition + 1));
            if (cMenuItem) {
                cMenu->AddMenuItem(cMenuItem);
            }
            actualString = actualString.substr(endPosition + 2);
        }
        return cMenu;
    } else if (Interface_info.at(0) == '[') {
        int closingCMenuCommand = findClosingChar('[', Interface_info);
        CMenuCommand *cMenuCommand = deserializeCMenuCommand(Interface_info.substr(0, closingCMenuCommand));
        return cMenuCommand;
    } else {
        return nullptr;
    }
}



