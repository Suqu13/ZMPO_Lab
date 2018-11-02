//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_UTILITIES_H
#define LIST_3_UTILITIES_H

#include <string>
#include <vector>

using namespace std;


class Utilities {
public:
    static int iProvideInt();
    static int iProvideIntBetween(const int iStart, const int iEnd);
    static string sProvideString();
    static bool bYOrNIntepreter();
    static vector<string> vSplitString(string sString, char cDelimiter);
    static vector<string> vSplitString(string sString, string sDelimiter);

};


#endif //LIST_3_UTILITIES_H
