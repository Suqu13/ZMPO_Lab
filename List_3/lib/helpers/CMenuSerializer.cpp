//
// Created by Jakub on 31.10.2018.
//

#include <sstream>
#include <iostream>
#include "CMenuSerializer.h"
#include "../utilities/Utilities.h"

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
//    int start_point = toAnalyze.find(opening);
//    int end_point = -1;
//    int inside_point = start_point;
//    do {
//        inside_point = toAnalyze.find(opening, inside_point + 1);
//        end_point = toAnalyze.find(closing, end_point + 1);
//    } while (start_point < inside_point && inside_point < end_point);
//    return end_point;
}

string CMenuSerializer::rightPlaceToDivide(int endPosition, const string &String_info) {
    if (endPosition + 2 <= String_info.size()) {
        return String_info.substr(endPosition + 2);
    } else {
        return String_info.substr(endPosition + 1);
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

//TODO
bool CMenuSerializer::validateInterface_info(string Interface_info) {
    int currentIndex = 0;
    int mistakeIndex = -1;
    char mistakeChar;
    validateCMenu(Interface_info, currentIndex, mistakeIndex, mistakeChar);
    if (mistakeIndex != -1) {
        cout << "Error " << mistakeChar << "placed " << mistakeIndex << endl;
    }
}

void
CMenuSerializer::validateCMenu(const string &cMenu_info, int &currentIndex, int &mistakeIndex, char &mistakeSymbol) {
    if (cMenu_info.at(0) != '(') {
        mistakeIndex = currentIndex;
        mistakeSymbol = '(';
        return;
    }

    if (cMenu_info.at(cMenu_info.size() - 1) != ')') {
        mistakeIndex = currentIndex + cMenu_info.size() - 1;
        mistakeSymbol = ')';
        return;
    }
    currentIndex++;
    validateNameAndCommand(cMenu_info.substr(1, cMenu_info.size() - 2), currentIndex, mistakeIndex, mistakeSymbol);

}

void CMenuSerializer::validateNameAndCommand(const string &cMenu_info, int &currentIndex, int &mistakeIndex,
                                             char &mistakeSymbol) {
    if (cMenu_info.at(0) != '\'') {
        mistakeIndex = currentIndex;
        mistakeSymbol = '\'';
        return;
    }
    int nameEnding = 1 + findClosingChar('\'', cMenu_info.substr(1));
    if (nameEnding == -1) {
        mistakeIndex = currentIndex + nameEnding;
        mistakeSymbol = '\'';
        return;
    }
    if (cMenu_info.at(nameEnding + 1) != ',') {
        mistakeIndex = currentIndex + nameEnding + 1;
        mistakeSymbol = ',';
        return;
    }
    if (cMenu_info.at(nameEnding + 2) != '\'') {
        mistakeIndex = currentIndex + nameEnding + 2;
        mistakeSymbol = '\'';
        return;
    }
    int semicolon = 0;
    for (int i = nameEnding + 3; i < cMenu_info.size(); ++i) {
        if (cMenu_info.at(i) == '\'') {
            if (cMenu_info.at(i + 1) != ';' || i + 1 > cMenu_info.size()) {
                mistakeIndex = currentIndex + i;
                mistakeSymbol = ';';
                return;
            } else {
                semicolon = i + 1;
                break;
            }
        }
        if (cMenu_info.at(i) == ';' || cMenu_info.at(i) == '[' || cMenu_info.at(i) == ']' || cMenu_info.at(i) == '(' ||
            cMenu_info.at(i) == ')') {
            mistakeIndex = currentIndex + i;
            mistakeSymbol = '\'';
            return;
        }
    }
    currentIndex += currentIndex + semicolon + 1;
}

void
CMenuSerializer::validateCMenuCommand(const string &cMenu_info, int &currentIndex, int &mistakeIndex,
                                      char &mistakeSymbol) {
    if (cMenu_info.at(0) != '[') {
        mistakeIndex = currentIndex;
        mistakeSymbol = ']';
        return;
    }

    if (cMenu_info.at(cMenu_info.size() - 1) != '[') {
        mistakeIndex = currentIndex + cMenu_info.size() - 1;
        mistakeSymbol = ']';
        return;
    }
    currentIndex++;
    validateNameCommandAndHelp(cMenu_info.substr(1, cMenu_info.size() - 2), currentIndex, mistakeIndex, mistakeSymbol);

}

void CMenuSerializer::validateNameCommandAndHelp(const string &cMenu_info, int &currentIndex, int &mistakeIndex,
                                                 char &mistakeSymbol) {
    if (cMenu_info.at(0) != '\'') {
        mistakeIndex = currentIndex;
        mistakeSymbol = '\'';
        return;
    }
    int nameEnding = 1 + findClosingChar('\'', cMenu_info.substr(1));
    if (nameEnding == -1) {
        mistakeIndex = currentIndex + nameEnding;
        mistakeSymbol = '\'';
        return;
    }
    if (cMenu_info.at(nameEnding + 1) != ',') {
        mistakeIndex = currentIndex + nameEnding + 1;
        mistakeSymbol = ',';
        return;
    }
    if (cMenu_info.at(nameEnding + 2) != '\'') {
        mistakeIndex = currentIndex + nameEnding + 2;
        mistakeSymbol = '\'';
        return;
    }
    int semicolon = 0;
    for (int i = nameEnding + 3; i < cMenu_info.size(); ++i) {
        if (cMenu_info.at(i) == '\'') {
            if (cMenu_info.at(i + 1) != ';' || i + 1 > cMenu_info.size()) {
                mistakeIndex = currentIndex + i;
                mistakeSymbol = ';';
                return;
            } else {
                semicolon = i + 1;
                break;
            }
        }
        if (cMenu_info.at(i) == ';' || cMenu_info.at(i) == '[' || cMenu_info.at(i) == ']' || cMenu_info.at(i) == '(' ||
            cMenu_info.at(i) == ')') {
            mistakeIndex = currentIndex + i;
            mistakeSymbol = '\'';
            return;
        }
    }
    currentIndex += currentIndex + semicolon + 1;
}

