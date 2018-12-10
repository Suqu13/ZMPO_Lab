//
// Created by Jakub on 01.12.2018.
//

#include <regex>
#include "Utilities.h"
#include <limits>
#include <climits>
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
    getline(cin, sInput);
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

vector<string> Utilities::vSplitString(string sString, char cDelimiter) {
    vector<string> str;
    string token;
    istringstream stringstream(sString);
    while (getline(stringstream, token, cDelimiter)) {
        str.push_back(token);
    }
    return str;
}

vector<string> Utilities::vSplitString(string sString, string sDelimiter) {
    vector<string> vec;
    int startPoint = 0;
    int endPoint = 0;
    while(endPoint != -1){
        endPoint = sString.find(sDelimiter, startPoint);
        string newStr = sString.substr(startPoint,endPoint - startPoint);
        vec.push_back(newStr);
        startPoint = endPoint + sDelimiter.size();
    }
    return vec;
}

int Utilities::inputPositiveInt() {
    string str;
    bool correctness;
    regex regex_pattern(R"(^[0-9]\d*?$)");
    do {
        cin >> str;
        correctness = !regex_match(str, regex_pattern);
        if (correctness) {
            cout << "Wrong data!\nTry again!" << endl;
        }
    } while (correctness);

    return stod(str);
}

double Utilities::inputPositiveDoubleBet0_1() {
    string str;
    bool correctness;
    regex regex_pattern(R"(^[0]\d*(\.\d+)?$)");
    do {
        cin >> str;
        correctness = !regex_match(str, regex_pattern);
        if (correctness) {
            cout << "Wrong data!\nTry again!" << endl;
        }
    } while (correctness);

    return stod(str);
}

double Utilities::inputPositiveDouble() {
    string str;
    bool correctness;
    regex regex_pattern(R"(^[0-9]\d*(\.\d+)?$)");
    do {
        cin >> str;
        correctness = !regex_match(str, regex_pattern);
        if (correctness) {
            cout << "Wrong data!\nTry again!" << endl;
        }
    } while (correctness);

    return stod(str);
}

