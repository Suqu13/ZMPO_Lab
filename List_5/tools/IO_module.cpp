//
// Created by Jakub on 01.12.2018.
//

#include "IO_module.h"
#include <iostream>
#include <climits>
#include <regex>

using namespace std;

int IO_module::inputPositiveInt() {
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

double IO_module::inputPositiveDoubleBet0_1() {
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

double IO_module::inputPositiveDouble() {
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
