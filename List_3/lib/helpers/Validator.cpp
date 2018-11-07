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
    char mistakeSymbol = DEFAULT_SYMBOL;
    validateMenu(Interface_info, mistakeSymbol, mistakeIndex, currentIndex, correct);
    if (!correct) {
        cout << "\n" <<FILE_WITH_MISTAKE << fileName << "\n" << SOURCE_OF_MISTAKE << mistakeIndex
             << "\n" << EXPECTED_CHARACTER << mistakeSymbol << endl;
    }
    return correct;
}

void Validator::validateMenu(string Interface_info, char &mistakeSymbol, int &mistakeIndex, int &currentIndex,
                             bool &correctness) {
    if (!checkSymbolCorrectness(Interface_info, 0, OPEN_BRACKET, mistakeSymbol, correctness) && mistakeIndex == -1)
        mistakeIndex = currentIndex;
    if (!checkSymbolCorrectness(Interface_info, Interface_info.length() - 1, CLOSE_BRACKET, mistakeSymbol, correctness) &&
        mistakeIndex == -1)
        mistakeIndex = currentIndex + Interface_info.length() - 1;
    if (Interface_info.length() > 2)
        Interface_info = Interface_info.substr(1, Interface_info.length() - 2);
    else {
        correctness = false;
        Interface_info = EMPTY_STRING;
    }
    currentIndex++;
    validateInsideItem(Interface_info, mistakeSymbol, mistakeIndex, currentIndex, correctness);

    if (!checkSymbolCorrectness(Interface_info, 0, SEMICOLON, mistakeSymbol, correctness) && mistakeIndex == -1)
        mistakeIndex = currentIndex;
    if (Interface_info.length() > 2)
        Interface_info = Interface_info.substr(1, Interface_info.length() - 1);
    else {
        Interface_info = EMPTY_STRING;
    }
    currentIndex++;

    while (!Interface_info.empty() && correctness) {
        if (Interface_info[0] != OPEN_BRACKET && Interface_info[0] != OPEN_SQUARE_BRACKET) {
            correctness = false;
            mistakeIndex = currentIndex;
            if (findClosingChar(Interface_info, OPEN_SQUARE_BRACKET) == -1)
                mistakeSymbol = OPEN_BRACKET;
            else
                mistakeSymbol = OPEN_SQUARE_BRACKET;
        }
        int innerMenuEnd = findClosingChar(Interface_info, Interface_info[0]);
        if (innerMenuEnd == -1 && correctness) {
            correctness = false;
            if (Interface_info[0] == OPEN_BRACKET)
                mistakeSymbol = CLOSE_BRACKET;
            else
                mistakeSymbol = CLOSE_SQUARE_BRACKET;

            mistakeIndex = currentIndex + Interface_info.length();
            int missingIndex = findIndexOfExpectedSymbol(Interface_info);
            if (missingIndex == -1)
                mistakeIndex = currentIndex + Interface_info.length();
            else
                mistakeIndex = currentIndex + missingIndex;
        } else {
            string innerMenu = Interface_info.substr(0, innerMenuEnd + 1);
            if (innerMenuEnd + 1 < Interface_info.length() - 1) {
                Interface_info = Interface_info.substr(innerMenuEnd + 1, Interface_info.length() - (innerMenuEnd + 1));
                currentIndex += 1;
                if (!checkSymbolCorrectness(Interface_info, 0, COMMA, mistakeSymbol, correctness) && mistakeIndex == -1)
                    mistakeIndex = currentIndex;
                if (Interface_info.length() > 1)
                    Interface_info = Interface_info.substr(1, Interface_info.length() - 1);
                else {
                    correctness = false;
                    Interface_info = EMPTY_STRING;
                }
                currentIndex++;
            } else {
                Interface_info = EMPTY_STRING;
            }
            if (correctness) {
                if (innerMenu[0] == OPEN_BRACKET) {
                    validateMenu(innerMenu, mistakeSymbol, mistakeIndex, currentIndex, correctness);
                } else {
                    validateMenuCommand(innerMenu, mistakeSymbol, mistakeIndex, currentIndex, correctness);
                }
            }
        }
    }
}

void Validator::validateMenuCommand(string cMenuCommand_info, char &errorCode, int &errorIndex, int &currentIndex,
                                    bool &correctness) {
    if (!checkSymbolCorrectness(cMenuCommand_info, 0, OPEN_SQUARE_BRACKET, errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }

    if (!checkSymbolCorrectness(cMenuCommand_info, cMenuCommand_info.length() - 1, CLOSE_SQUARE_BRACKET, errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex + cMenuCommand_info.length();
    }
    cMenuCommand_info = cMenuCommand_info.substr(1, cMenuCommand_info.length() - 2);
    currentIndex++;
    validateInsideItem(cMenuCommand_info, errorCode, errorIndex, currentIndex, correctness);
    if (!checkSymbolCorrectness(cMenuCommand_info, 0, COMMA, errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }
    cMenuCommand_info = cMenuCommand_info.substr(1, cMenuCommand_info.length() - 1);
    currentIndex++;

    if (!checkSymbolCorrectness(cMenuCommand_info, 0, APOSTROPHE, errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }

    if (findClosingChar(cMenuCommand_info, APOSTROPHE) != cMenuCommand_info.length() - 1 && correctness) {
        correctness = false;
        if (errorIndex == -1) {
            errorIndex = currentIndex + cMenuCommand_info.length() - 1;
            errorCode = APOSTROPHE;
        }
    }
}

void Validator::validateInsideItem(string &cMenu_info, char &errorCode, int &errorIndex, int &currentIndex,
                                   bool &correctness) {
    if (!checkSymbolCorrectness(cMenu_info, 0, APOSTROPHE, errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }
    int nameEnd = findClosingChar(cMenu_info, APOSTROPHE);
    if (nameEnd == -1 && errorIndex == -1) {
        correctness = false;
        errorIndex = currentIndex + nameEnd;
    }
    if (cMenu_info[nameEnd - 1] == COMMA) {
        correctness = false;
        errorIndex = currentIndex + nameEnd - 1;
        errorCode = APOSTROPHE;
    }

    if (!checkSymbolCorrectness(cMenu_info, nameEnd + 1, COMMA, errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex + nameEnd + 1;
    }
    cMenu_info = cMenu_info.substr(nameEnd + 2, cMenu_info.length() - (nameEnd + 2));
    currentIndex += nameEnd + 2;
    if (!checkSymbolCorrectness(cMenu_info, 0, APOSTROPHE, errorCode, correctness) && errorIndex == -1) {
        errorIndex = currentIndex;
    }
    int commandEnd = findClosingChar(cMenu_info, APOSTROPHE);
    if (commandEnd == -1 && errorIndex == -1) {
        errorIndex = currentIndex;
        correctness = false;
    }
    if (cMenu_info[commandEnd - 1] == COMMA) {
        correctness = false;
        errorCode = APOSTROPHE;
        errorIndex = currentIndex - 1;
    }
    cMenu_info = cMenu_info.substr(commandEnd + 1, cMenu_info.length() - (commandEnd + 1));
    currentIndex += commandEnd + 1;
}

bool Validator::checkSymbolCorrectness(string &Interface_info, int index, char compareWith, char &errorCode,
                                       bool &correctness) {
    if (0 <= index && index < Interface_info.length() && correctness) {
        if (Interface_info[index] != compareWith) {
            correctness = false;
            if (errorCode == DEFAULT_SYMBOL)
                errorCode = compareWith;
            return false;
        }
        return true;
    }
    return false;
}

int Validator::findIndexOfExpectedSymbol(string &menuSave) {
    int index = -1;
    int openingOccurrences = 1;
    for (int i = 1; i < menuSave.size(); ++i) {
        if (menuSave[i] == OPEN_BRACKET || menuSave[i] == OPEN_SQUARE_BRACKET) {
            if (menuSave[i - 1] == COMMA && openingOccurrences == 1) {
                return i - 2;
            } else {
                openingOccurrences++;
            }
        }
    }
    return index;
}

int Validator::findClosingChar(string &Interface_info, char opening) {
    char closing;
    switch (opening) {
        case APOSTROPHE:
            for (int i = 1; i < Interface_info.length(); ++i) {
                if (Interface_info[i] == opening)
                    return i;
            }
            return -1;
        case OPEN_BRACKET:
            closing = CLOSE_BRACKET;
            break;
        case OPEN_SQUARE_BRACKET:
            closing = CLOSE_SQUARE_BRACKET;
            break;
        default:
            return -1;
    }
    int occurrencesBeforeClosing = 1;
    for (int j = 1; j < Interface_info.length(); ++j) {
        if (Interface_info[j] == opening) {
            occurrencesBeforeClosing++;
        } else if (Interface_info[j] == closing) {
            occurrencesBeforeClosing--;
            if (occurrencesBeforeClosing == 0)
                return j;
        }
    }
    return -1;
}