//
// Created by Jakub on 31.10.2018.
//

#include <sstream>
#include <iostream>
#include "CMenuSerializer.h"
#include "../utilities/Utilities.h"
#include "Validator.h"
#include "../utilities/io_Txt_File.h"
#include <stack>

void CMenuSerializer::serialize(CMenuItem *cMenuItem, string fileName) {
    string data = serializeInterface(cMenuItem);
    io_Txt_File::writeToFile(data, fileName);
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
    return stream.str();;
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
        case '\'':
            for (int i = 0; i < toAnalyze.length(); ++i) {
                if (toAnalyze[i] == opening)
                    return i;
            }
            return -1;
        case '(':
            closing = ')';
            break;
        case '[':
            closing = ']';
            break;
        default:
            return -1;
    }

    int balanceIndex = 0;
    for (int i = 0; i < toAnalyze.size(); ++i) {
        if (toAnalyze[i] == opening) {
            balanceIndex++;
        } else if (toAnalyze[i] == closing) {
            balanceIndex--;
            if (balanceIndex == 0)
                return i;
        }
    }
    return -1;
}

string CMenuSerializer::rightPlaceToDivide(int endPosition, const string &String_info) {
    if (endPosition + 2 <= String_info.size()) {
        return String_info.substr(endPosition + 2);
    } else {
        return String_info.substr(endPosition + 1);
    }
}

CMenuItem *CMenuSerializer::deserialize(string fileName) {
    string Interface_info = io_Txt_File::readFromFile(fileName);
    if (Validator::validate(Interface_info, fileName)) {
        return deserializeInterface(Interface_info);
    } else {
        return nullptr;
    }
}

CMenuItem *CMenuSerializer::deserializeInterface(string Interface_info) {
    if (Interface_info.at(0) == '(') {
        int findSemicolon = Interface_info.find(';');
        CMenu *cMenu = deserializeCMenu(Interface_info.substr(0, findSemicolon));
        string actualString = Interface_info.substr(findSemicolon + 1, Interface_info.size() - findSemicolon - 2);
        while (!actualString.empty()) {
            int endPosition = findClosingChar(actualString.at(0), actualString);
            CMenuItem *cMenuItem = deserializeInterface(actualString.substr(0, endPosition + 1));
            if (cMenuItem) {
                cMenu->AddMenuItem(cMenuItem);
            }
            actualString = rightPlaceToDivide(endPosition, actualString);
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





