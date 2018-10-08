//
// Created by Jakub on 08.10.2018.
//

#include <iostream>
#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface() {
    *bSucces = true;
}

UserInterface::~UserInterface() {
    int i = 0;
    while(!CTables_Vec.empty()) {
        delete CTables_Vec[i++];
    }
    CTables_Vec.clear();
    delete bSucces;
}

while (!(cin >> int_variable)) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void UserInterface::vCreateCTables() {
    int iAnswer;
    bool correctly = true;
    cout << "1. Create a group of default CTables. \n 2. Create a specific CTable. \n\n Choose (1/2): "
         << "Please provide an integer value: " << endl;
    do {
        correctly = true;
        cin >> iAnswer;
        switch (iAnswer) {
            default:
                cout << "Try again!" << endl;
                correctly = false;
                break;
            case 1:
                int iNumber;
                cout << "Give number of elements." << endl << "Please provide an integer value: " << endl;
                cin >> iNumber;
                for (int i = 0; i < iNumber; ++i) {
                    CTables_Vec.push_back(new CTable);
                }
                break;
            case 2:
                string sName;
                int iLength;
                bool bAgain;
                string sYesOrNo;
                do {

                    cout << "Give a name and a length." << endl << "Please provide a string: " << endl;
                    cin >> sName;

                    cout << "Please provide an integer value: " << endl;
                    cin >> iLength;
                    CTables_Vec.push_back(new CTable(sName, iLength));

                    cout << "Do you want to create one more CTable? (Y/N) " << endl << "Please provide a string: "
                         << endl;
                    cin >> sYesOrNo;

                    if (sYesOrNo.at(0) == 'Y') {
                        bAgain = true;
                    } else if (sYesOrNo.at(0) == 'N') {
                        bAgain = false;

                    }
                } while (bAgain);
                break;
        }
    } while (!correctly);
}

//TODO
void UserInterface::vAssignElementToTheTable() {
    int iLocation;
    int iElelemt;
    string sYesOrNo;
    bool bAgain;
    do {
        cout << "Provide a table location " << endl << "Please provide an integer value: " << endl;
        cin >> iLocation;
        cout << "Give a element." << endl << "Please provide an integer value: " << endl;
        cin >> iElelemt;
        cout << "Do you want to provide a location of the element in the CTable? (Y/N) " << endl
             << "Please provide a string: " << endl;
        cin >> sYesOrNo;
        if (sYesOrNo.at(0) == 'Y') {
            bAgain = true;
        } else if (sYesOrNo.at(0) == 'N') {
            bAgain = false;
        }


    } while (!bAgain);

}

void UserInterface::sTheTableToString() {
    for (int i = 0; i < CTables_Vec.size(); i++) {
        (*CTables_Vec[i]).sToString();
    }
}

void UserInterface::vRun() {
    sTheTableToString();
}

