//
// Created by Jakub on 05.11.2018.
//

#include <iostream>
#include "Validator.h"

bool Validator::validate(string Interface_info, string fileName) {
    if (Interface_info.empty())
        return false;

    bool correct = true;
    int mistakeIndex = -1;
    int currentIndex = 0;
    char mistakeSymbol = '~';
    validateMenu(Interface_info, mistakeSymbol, mistakeIndex, currentIndex, correct);
    if (!correct) {
        cout << FILE_WITH_MISTAKE << fileName << "\n" << SOURCE_OF_MISTAKE << mistakeIndex
             << ". \n" << EXPECTED_CHARACTER << mistakeSymbol << endl;
    }
    return correct;
}

void Validator::validateMenu(string Interface_info, char &mistakeSymbol, int &mistakeIndex, int &currentIndex,
                             bool &correctness) {
    if (!checkSymbolInString(Interface_info, 0, '(', mistakeSymbol, correctness) && mistakeIndex == -1)
        mistakeIndex = currentIndex;
    if (!checkSymbolInString(Interface_info, Interface_info.length() - 1, ')', mistakeSymbol, correctness) &&
        mistakeIndex == -1)
        mistakeIndex = currentIndex + Interface_info.length() - 1;
    if (Interface_info.length() > 2)
        Interface_info = Interface_info.substr(1, Interface_info.length() - 2);
    else {
        correctness = false;
        Interface_info = "";
    }
    currentIndex++;
    validateNameAndCommand(Interface_info, mistakeSymbol, mistakeIndex, currentIndex, correctness);

    if (!checkSymbolInString(Interface_info, 0, ';', mistakeSymbol, correctness) && mistakeIndex == -1)
        mistakeIndex = currentIndex;
    if (Interface_info.length() > 2)
        Interface_info = Interface_info.substr(1, Interface_info.length() - 1);
    else {
        Interface_info = "";
    }
    currentIndex++;

    while (!Interface_info.empty() && correctness) {
        if (Interface_info[0] != '(' && Interface_info[0] != '[') {
            correctness = false;
            mistakeIndex = currentIndex;
            if (findClosingChar(Interface_info, '[') == -1)
                mistakeSymbol = '(';
            else
                mistakeSymbol = '[';
        }

        int innerMenuEnd = findClosingChar(Interface_info, Interface_info[0]);
        if (innerMenuEnd == -1 && correctness) {
            correctness = false;
            if (Interface_info[0] == '(')
                mistakeSymbol = ')';
            else
                mistakeSymbol = ']';

            mistakeIndex = currentIndex + Interface_info.length();
            int missingIndex = findIndexOfMissingChar(Interface_info);
            if (missingIndex == -1)
                mistakeIndex = currentIndex + Interface_info.length();
            else
                mistakeIndex = currentIndex + missingIndex;
        } else {
            string innerMenu = Interface_info.substr(0, innerMenuEnd + 1);
            if (innerMenuEnd + 1 < Interface_info.length() - 1) {
                Interface_info = Interface_info.substr(innerMenuEnd + 1, Interface_info.length() - (innerMenuEnd + 1));
                currentIndex += 1;
                if (!checkSymbolInString(Interface_info, 0, ',', mistakeSymbol, correctness) && mistakeIndex == -1)
                    mistakeIndex = currentIndex;
                if (Interface_info.length() > 1)
                    Interface_info = Interface_info.substr(1, Interface_info.length() - 1);
                else {
                    correctness = false;
                    Interface_info = "";
                }
                currentIndex++;
            } else {
                Interface_info = "";
            }
            if (correctness) {
                if (innerMenu[0] == '(') {
                    validateMenu(innerMenu, mistakeSymbol, mistakeIndex, currentIndex, correctness);
                } else {
                    validateMenuCommand(innerMenu, mistakeSymbol, mistakeIndex, currentIndex, correctness);
                }
            }
        }
    }
}

void Validator::validateMenuCommand(string toValidate, char &errorCode, int &errorIndex, int &currentIndex,
                                    bool &correctness) {
    if (!checkSymbolInString(toValidate, 0, '[', errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }

    if (!checkSymbolInString(toValidate, toValidate.length() - 1, ']', errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex + toValidate.length();
    }
    toValidate = toValidate.substr(1, toValidate.length() - 2);
    currentIndex++;
    validateNameAndCommand(toValidate, errorCode, errorIndex, currentIndex, correctness);
    if (!checkSymbolInString(toValidate, 0, ',', errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }
    toValidate = toValidate.substr(1, toValidate.length() - 1);
    currentIndex++;

    if (!checkSymbolInString(toValidate, 0, '\'', errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }

    if (findClosingChar(toValidate, '\'') != toValidate.length() - 1 && correctness) {
        correctness = false;
        if (errorIndex == -1) {
            errorIndex = currentIndex + toValidate.length() - 1;
            errorCode = '\'';
        }
    }
}

void Validator::validateNameAndCommand(string &toValidate, char &errorCode, int &errorIndex, int &currentIndex,
                                       bool &correctness) {
    if (!checkSymbolInString(toValidate, 0, '\'', errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }
    int nameEnd = findClosingChar(toValidate, '\'');
    if (nameEnd == -1 && errorIndex == -1) {
        correctness = false;
        errorIndex = currentIndex + nameEnd;
    }
    if (!checkSymbolInString(toValidate, nameEnd + 1, ',', errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex + nameEnd + 1;
    }
    toValidate = toValidate.substr(nameEnd + 2, toValidate.length() - (nameEnd + 2));
    currentIndex += nameEnd + 2;
    if (!checkSymbolInString(toValidate, 0, '\'', errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }
    int commandEnd = findClosingChar(toValidate, '\'');
    if (commandEnd == -1 && errorIndex == -1) {
        correctness = false;
        errorIndex = currentIndex;
    }
    toValidate = toValidate.substr(commandEnd + 1, toValidate.length() - (commandEnd + 1));
    currentIndex += commandEnd + 1;
}

bool Validator::checkSymbolInString(string &toValidate, int index, char compareWith, char &errorCode,
                                    bool &correctness) {
    if (0 <= index && index < toValidate.length() && correctness) {
        if (toValidate[index] != compareWith) {
            correctness = false;
            if (errorCode == '~')
                errorCode = compareWith;
            return false;
        }
        return true;
    }
    return false;
}

int Validator::findIndexOfMissingChar(string &menuSave) {
    int index = -1;
    int openingOccurrences = 1;
    for (int i = 1; i < menuSave.size(); ++i) {
        if (menuSave[i] == '(' || menuSave[i] == '[') {
            if (menuSave[i - 1] == ',' && openingOccurrences == 1) {
                return i - 2;
            } else {
                openingOccurrences++;
            }
        }
    }
    return index;
}

int Validator::findClosingChar(string &menuTree, char opening) {
    char closing;
    switch (opening) {
        case '\'':
            for (int i = 1; i < menuTree.length(); ++i) {
                if (menuTree[i] == opening)
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
    int occurrencesBeforeClosing = 0;
    for (int j = 0; j < menuTree.length(); ++j) {
        if (menuTree[j] == opening) {
            occurrencesBeforeClosing++;
        } else if (menuTree[j] == closing) {
            occurrencesBeforeClosing--;
            if (occurrencesBeforeClosing == 0)
                return j;
        }
    }
    return -1;
}