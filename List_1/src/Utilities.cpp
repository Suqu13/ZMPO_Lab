//
// Created by Jakub on 10.10.2018.
//

#include <iostream>
#include <limits>
#include "Utilities.h"

using namespace std;

int Utilities::iProvideInt() {
    int iInput;
    while (!(cin >> iInput)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again, you provided wrong data." << endl;
    }
    return iInput;
}

//TODO
int Utilities::iProvideIntBetween(const int iStart, const int iEnd) {
    int iInput;
    while (!(cin >> iInput) && iInput >= iStart && iInput <= iEnd) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again, you provided wrong data." << endl;
    }
    return iInput;
}

string Utilities::sProvideString() {
    string sInput;
    cin >> sInput;

    return sInput;
}