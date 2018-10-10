//
// Created by Jakub on 08.10.2018.
//

#include <iostream>
#include <sstream>
#include "Menu.h"

using namespace std;

Menu::Menu() {
    //*bSucces = true;
}

Menu::~Menu() {
    int i = 0;
    while (!vCTables_Vec.empty()) {
        delete vCTables_Vec[i++];
    }
    vCTables_Vec.clear();
}


void Menu::vVec_CreateCTables() {

    cout << "Create a group of default CTables." << endl;
    int iNumber;
    cout << "Provide the number of elements: ";
    cin >> iNumber;
    for (int i = 0; i < iNumber; ++i) {
        vCTables_Vec.push_back(new CTable);
    }

}

void Menu::vVec_CreateSpecCTable() {
    string sName;
    int iLength;

    cout << "Please provide a name: ";
    cin >> sName;

    cout << "\nPlease provide a length: ";
    cin >> iLength;

    vCTables_Vec.push_back(new CTable(sName, iLength));
}

void Menu::vVec_ToString() {
    for (int i = 0; i < vCTables_Vec.size(); i++) {
        cout << (i + 1) << ". Name: " << vCTables_Vec[i]->sGetName() << "; Length: " << vCTables_Vec[i]->iGetLength()
             << "; Elements: "
             << vCTables_Vec[i]->sToString() << endl;
    }

}

void Menu::vVec_DeleteCTable() {
    int iTableIndex;
    cout << "Please provide an index of the table to delete: ";
    cin >> iTableIndex;
    iTableIndex--;
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
    int iTableIndex;
    cout << "Please provide an index of the table to clone: ";
    cin >> iTableIndex;
    vCTables_Vec.push_back(new CTable(*vCTables_Vec[(iTableIndex - 1)]));
}

void Menu::vVec_SetName() {
    int iTableIndex;
    string sNewName;
    cout << "Please provide an index of the table to change name: ";
    cin >> iTableIndex;
    while (!(iTableIndex > 0 && iTableIndex <= vCTables_Vec.size())) {
        cout << "Try again!" << endl;
        cin >> iTableIndex;
    }
    cout << "Please provide a new name: ";
    cin >> sNewName;
    vCTables_Vec[iTableIndex - 1]->vSetName(sNewName);
}

void Menu::vVec_Insert() {
    int iTableIndex;
    int iIndexOfElement;
    int iNewElement;
    cout << "Please provide a new element: ";
    cin >> iNewElement;
    cout << "Please provide a table where you want to insert element: ";
    cin >> iTableIndex;
    while (!(iTableIndex > 0 && iTableIndex <= vCTables_Vec.size())) {
        cout << "Try again!" << endl;
        cin >> iTableIndex;
    }

    vCTables_Vec[iTableIndex - 1]->sToString();
    cout << "Please provide an index of a new element: ";
    cin >> iIndexOfElement;
    while (!vCTables_Vec[iTableIndex - 1]->bInsertElement(iIndexOfElement, iNewElement)) {
        cout << "Try again!" << endl;
        cin >> iIndexOfElement;
    }
}

void Menu::vVec_SetLength() {
    int iNewLength;
    int iTableIndex;
    cout << "Please provide a table to change a length: ";
    cin >> iTableIndex;
    while (!(iTableIndex > 0 && iTableIndex <= vCTables_Vec.size())) {
        cout << "Try again!" << endl;
        cin >> iTableIndex;
    }
    cout << "Please provide a new length: ";
    cin >> iNewLength;
    while (!vCTables_Vec[iTableIndex - 1]->bSetLength(iNewLength)) {
        cout << "Try again!" << endl;
        cin >> iNewLength;
    }
}

bool Menu::bVec_End() {
    vVec_DeleteAll();
    return false;
}

void Menu::vVec_ShowMenu() {
    cout << "\n1.  Create a group of regular CTables." << endl << "2.  Create a specified CTable." << endl <<
         "3.  Clone a specified CTable and attach it to the vector." << endl << "4.  Print the entire list." << endl
         << "5.  Change length of a specified CTable." << endl << "6.  Set name of a specified CTable."
         << endl << "7.  Insert a new element into a specified CTable." << endl << "8.  Delete a specified CTable."
         << endl
         << "9.  Delete all CTables." << endl << "10. Exit" << endl << endl;


}

void Menu::vRun() {
    vVec_ShowMenu();
    bool bExit = true;
    int iChoose;
    while (bExit) {
        cin >> iChoose;
        switch (iChoose) {
            default:
                cout << "Try again!" << endl;
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
                vVec_SetLength();
                break;
            case 6:
                vVec_SetName();
                break;
            case 7:
                vVec_Insert();
                break;
            case 8:
                vVec_DeleteCTable();
                break;
            case 9:
                vVec_DeleteAll();
                break;
            case 10:
                bExit = bVec_End();
                break;


        }
    }

}

