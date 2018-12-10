//
// Created by Jakub on 10.10.2018.
//

#ifndef LIST_1_UTILITIES_H
#define LIST_1_UTILITIES_H

#include <string>

using namespace std;


class Utilities {
public:
    static int iProvideInt();
    static int iProvideIntBetween(const int iStart, const int iEnd);
    static string sProvideString();
    static bool bYOrNIntepreter();
};


#endif //LIST_1_UTILITIES_H
