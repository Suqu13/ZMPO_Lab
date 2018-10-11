//
// Created by Jakub on 08.10.2018.
//

#include <iostream>
#include <sstream>
#include "Menu.h"
#include "Utilities.h"
#include <limits>


using namespace std;

Menu::Menu() {
}

Menu::~Menu() {
    int i = 0;
    while (!vCTables_Vec.empty()) {
        delete vCTables_Vec[i++];
    }
    vCTables_Vec.clear();
}


void Menu::vVec_CreateCTables() {
    cout << "Please provide a number of elements: ";
    int iNumber = Utilities::iProvideIntBetween(-1, numeric_limits<int>::max());
    for (int i = 0; i < iNumber; ++i) {
        vCTables_Vec.push_back(new CTable);
    }

}

void Menu::vVec_CreateSpecCTable() {
    string sName;
    int iLength;
    do {
        cout << "Please provide a name: ";
        sName = Utilities::sProvideString();

        cout << "Please provide a length: ";
        iLength = Utilities::iProvideIntBetween(0, numeric_limits<int>::max());

        vCTables_Vec.push_back(new CTable(sName, iLength));
        cout << "Do you want to create one more specified CTable? (Y/N):";

    } while (Utilities::bYOrNIntepreter());
}

void Menu::vVec_ToString() {
    if (vCTables_Vec.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    for (int i = 0; i < vCTables_Vec.size(); i++) {
        cout << (i + 1) << ". Name: " << vCTables_Vec[i]->sGetName() << "; Length: " << vCTables_Vec[i]->iGetLength()
             << "; Elements: "
             << vCTables_Vec[i]->sToString() << endl;
    }
}

void Menu::vVec_ToStringSingle() {
    if (vCTables_Vec.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please provide an index of the table to show: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, vCTables_Vec.size())) - 1;
    cout << (iTableIndex + 1) << ". Name: " << vCTables_Vec[iTableIndex]->sGetName() << "; Length: "
         << vCTables_Vec[iTableIndex]->iGetLength()
         << "; Elements: "
         << vCTables_Vec[iTableIndex]->sToString() << endl;
}


void Menu::vVec_DeleteCTable() {
    if (vCTables_Vec.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please provide an index of the table to delete: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, vCTables_Vec.size())) - 1;
    if (vCTables_Vec.size() > iTableIndex) {
        delete vCTables_Vec[iTableIndex];
        vCTables_Vec.erase(vCTables_Vec.begin() + iTableIndex);
    }
}

void Menu::vVec_DeleteAll() {
    for (int i = 0; i < vCTables_Vec.size(); i++) {
        delete vCTables_Vec[i];
    }
    vCTables_Vec.clear();
}

void Menu::vVec_Clone() {
    if (vCTables_Vec.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please provide an index of the table to clone: ";
    int iTableIndex = (Utilities::iProvideIntBetween(1, vCTables_Vec.size()) - 1);
    vCTables_Vec.push_back(new CTable(*vCTables_Vec[(iTableIndex)]));
}

void Menu::vVec_SetName() {
    if (vCTables_Vec.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please provide an index of the table to change name: ";
    int iTableIndex = Utilities::iProvideIntBetween(1, vCTables_Vec.size()) - 1;
    cout << "Please provide the name: ";
    string sNewName = Utilities::sProvideString();
    vCTables_Vec[iTableIndex]->vSetName(sNewName);
}

void Menu::vVec_Insert() {
    if (vCTables_Vec.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    vVec_ToString();
    cout << "\nPlease provide the table where you want to insert a new element: ";
    int iTableIndex = Utilities::iProvideIntBetween(1, vCTables_Vec.size()) - 1;
    cout << "Please provide the new element: ";
    int iNewElement = Utilities::iProvideInt();
    if (vCTables_Vec[iTableIndex]->iGetLength() == 0) {
        (vCTables_Vec[iTableIndex]->bInsertElement(1, iNewElement));
        return;
    }
    cout << "Please provide an index for the element: ";
    vCTables_Vec[iTableIndex]->bInsertElement(
            Utilities::iProvideIntBetween(0, vCTables_Vec[iTableIndex]->iGetLength() - 1), iNewElement);
}

void Menu::vVec_SetLength() {
    if (vCTables_Vec.empty()) {
        cout << "Firstly, you have to create a table!!" << endl;
        return;
    }
    cout << "Please enter the table whose length you want to change: ";
    int iTableIndex = Utilities::iProvideIntBetween(0, vCTables_Vec.size()) - 1;
    cout << "Please provide a new length: ";
    vCTables_Vec[iTableIndex]->bSetLength(Utilities::iProvideIntBetween(0, numeric_limits<int>::max()));

}

bool Menu::bVec_End() {
    vVec_DeleteAll();
    cout << "Ciao! :-D" << endl;
    return false;
}

void Menu::vVec_ShowMenu() {
    cout << "\n1.  Create a group of regular CTables." << endl << "2.  Create a specified CTable." << endl <<
         "3.  Clone a specified CTable and attach it to the list." << endl << "4.  Print the entire list." << endl
         << "5.  Print a single CTable." << endl
         << "6.  Change length of a specified CTable." << endl << "7.  Set name of a specified CTable."
         << endl << "8.  Insert a new element into a specified CTable." << endl << "9.  Delete a single CTable."
         << endl
         << "10. Delete all CTables." << endl << "11. Exit" << endl << "\nI'm ready! Provide an integer (1-11):";


}

void Menu::vRun() {
    bool bExit = true;
    int iChoose;
    while (bExit) {
        vVec_ShowMenu();
        iChoose = Utilities::iProvideIntBetween(1, 11);
        cout << endl;
        switch (iChoose) {
            default:
                cout << "Try again!" << endl;
                break;
            case 1:
                vVec_CreateCTables();
                break;
            case 2:
                vVec_CreateSpecCTable();
                break;
            case 3:
                vVec_Clone();
                break;
            case 4:
                vVec_ToString();
                break;
            case 5:
                vVec_ToStringSingle();
                break;
            case 6:
                vVec_SetLength();
                break;
            case 7:
                vVec_SetName();
                break;
            case 8:
                vVec_Insert();
                break;
            case 9:
                vVec_DeleteCTable();
                break;
            case 10:
                vVec_DeleteAll();
                break;
            case 11:
                bExit = bVec_End();
                break;


        }
    }

}

