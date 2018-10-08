//
// Created by Jakub on 07.10.2018.
//

#include "CTable.h"
#include <iostream>
#include <cstring>


using namespace std;

CTable::CTable() : iDEF_LENGTH(10), sDEF_NAME("Regular_CTable"), sName(sDEF_NAME), iLength(iDEF_LENGTH) {
    iArray = new int[iLength];
    cout << "bezp: '<" << sName << ">'" << endl;
}

CTable::CTable(string sName, int iLength) : sName(sName), iLength(iLength), iDEF_LENGTH(10),
                                            sDEF_NAME("Regular_CTable") {
    iArray = new int[iLength];
    cout << "parametr: '<" << sName << ">'" << endl;
}

CTable::CTable(const CTable &pcOther) : iDEF_LENGTH(10), sDEF_NAME("Regular_CTable") {
    sName = pcOther.sName + "_copy";
    iLength = pcOther.iLength;
    iArray = new int[iLength];
    //Working on pointers is faster
    int *w = iArray;
    int *w_ = pcOther.iArray;

    for (int i = 0; i < iLength; i++) {
        *w = *w_;
        //Changing addresses
        w++;
        w_++;
    }
    cout << "kopiuj: '<" << sName << ">'" << endl;
}

CTable::~CTable() {
    delete[] iArray;
    cout << "usuwam: '<" << sName << ">'" << endl;
}

CTable &CTable::operator=(const CTable &pcOther) {
    iLength = pcOther.iLength;
    int *iArray_ = new int[iLength];

    int *w = iArray_;
    int *w_ = pcOther.iArray;

    for (int i = 0; i < iLength; i++) {
        *w = *w_;
        //Changing addresses
        w++;
        w_++;
    }
    delete[] iArray;
    iArray = iArray_;
}

void CTable::vSetName(const string sName) {
    this->sName = sName;
}

string CTable::sGetName() {
    return sName;
}

int CTable::iGetLength() {
    return this->iLength;
}

int CTable::iGetElement(const int iElement_sPlace, int *iSuccess) {
    if (iElement_sPlace <= iLength - 1 && iElement_sPlace >= 0) {
        //If everything is right, it sets iSuccess on 1!
        *iSuccess = 1;
        return iArray[iElement_sPlace];
    } else {
        //If iElement_sPlace is out of the bounds, it sets iSuccess on -1!
        *iSuccess = -1;
        return -1;
    }
}

bool CTable::bAssignElement(const int iElement_sPlace, const int iElement) {
    if (iElement_sPlace <= iLength - 1 && iElement_sPlace >= 0) {
        iArray[iElement_sPlace];
        return true;
    } else {
        //If iElement_sPlace is out of the bounds, it returns false!
        return false;
    }
}

bool CTable::bSetLength(const int iNewLength) {
    if (0 <= iNewLength) {
        int *iArray_ = new int[iNewLength];
        int iElementsToCopy = (iLength < iNewLength) ? iLength : iNewLength;
        memcpy(iArray_, iArray, sizeof(int) * iElementsToCopy);

        delete[] iArray;

        iArray = iArray_;
        iLength = iNewLength;
        return true;
    }
    return false;
}

string CTable::sToString() {
    string sArrayAsAString = "[";
    int *w = iArray;
    for (int i = 0; i < iLength; i++) {
        sArrayAsAString += *w;
        if (i != iLength - 1) {
            sArrayAsAString += " , ";
        }
        w++;
    }
    sArrayAsAString = "]";
    return sArrayAsAString;
}

CTable *CTable::cClone() {
    return new CTable(*this);
}





