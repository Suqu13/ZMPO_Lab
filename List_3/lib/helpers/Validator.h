//
// Created by Jakub on 05.11.2018.
//

#ifndef LIST_3_VALIDATOR_H
#define LIST_3_VALIDATOR_H

#define FILE_WITH_MISTAKE "Program mistake error in file: "
#define SOURCE_OF_MISTAKE "Index of mistake: "
#define EXPECTED_CHARACTER "Expected char symbol at this index is: "
#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'
#define SEMICOLON ';'
#define OPEN_SQUARE_BRACKET '['
#define COMMA ','
#define CLOSE_SQUARE_BRACKET ']'
#define APOSTROPHE '\''
#define EMPTY_STRING ""
#define DEFAULT_SYMBOL '~'

#include <string>

using namespace std;


class Validator {
public:
    static bool validate(string Interface_info, string fileName);
private:
    static void validateMenu(string Interface_info, char &mistakeSymbol, int &mistakeIndex, int &currentIndex, bool &correctness);
    static int findClosingChar(string &Interface_info, char opening);
    static int findIndexOfExpectedSymbol(string &menuSave);
    static void validateMenuCommand(string cMenuCommand_info, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);
    static void validateInsideItem(string &cMenu_info, char &errorCode, int &errorIndex, int &currentIndex,
                                   bool &correctness);
    static bool checkSymbolCorrectness(string &Interface_info, int index, char compareWith, char &errorCode,
                                       bool &correctness);

};


#endif //LIST_3_VALIDATOR_H
