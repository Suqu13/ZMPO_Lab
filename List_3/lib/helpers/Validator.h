//
// Created by Jakub on 05.11.2018.
//

#ifndef LIST_3_VALIDATOR_H
#define LIST_3_VALIDATOR_H

#define FILE_WITH_MISTAKE "Program mistake error in file: "

#define SOURCE_OF_MISTAKE "Index of mistake:"

#define EXPECTED_CHARACTER "Expected char symbol at this index is: "

#include <string>

using namespace std;


class Validator {
public:
    static bool validate(string Interface_info, string fileName);
private:
    static void validateMenu(string Interface_info, char &mistakeSymbol, int &mistakeIndex, int &currentIndex, bool &correctness);
    static int findClosingChar(string &menuTree, char opening);
    static int findIndexOfMissingChar(string &menuSave);
    static void validateMenuCommand(string toValidate, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);
    static void validateNameAndCommand(string &toValidate, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);
    static bool checkSymbolInString(string &toValidate, int index, char compareWith, char &errorCode, bool &correctness);

};


#endif //LIST_3_VALIDATOR_H
