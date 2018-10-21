//
// Created by Jakub on 10.10.2018.
//
#include "Utilities.h"
#include <limits>
#include <iostream>
#include <sstream>


using namespace std;

int Utilities::iProvideInt() {
    int iInput;
    bool bValid;
    do {
        std::string string;
        std::stringstream stream;
        std::getline(std::cin, string);
        stream << string;
        bValid = (bool) (stream >> iInput);
    } while (!bValid);
    return iInput;
}

int Utilities::iProvideIntBetween(int iStart, int iEnd) {
    int iInput;
    bool bValid;
    do {
        string sString_;
        stringstream sStream;
        getline(cin, sString_);
        sStream << sString_;
        bValid = (bool) (sStream >> iInput);
    } while (!bValid || iInput < iStart || iEnd < iInput);
    return iInput;
}

string Utilities::sProvideString() {
    string sInput;
    cin >> sInput;
    return sInput;
}

bool Utilities::bYOrNIntepreter() {
    string sInput;
    while (true) {
        cin >> sInput;
        if (sInput.at(0) == 'Y' || sInput.at(0) == 'y')
            return true;
        if (sInput.at(0) == 'N' || sInput.at(0) == 'n')
            return false;
    }
}