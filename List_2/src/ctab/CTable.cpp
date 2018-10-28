//
// Created by Jakub on 07.10.2018.
//

#include "CTable.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <tgmath.h>


using namespace std;

//Constructor
CTable::CTable() : iDEF_LENGTH(10), sDEF_NAME(Def_NAME),
                   sName(sDEF_NAME), iLength(iDEF_LENGTH) {
    iArray = new int[iLength];
    vInitializeWithZeros(iArray, 0, iLength);
    cout << Def_CON << sName << endl;
}

//Parameterized Constructor
CTable::CTable(string sName, int iLength) : sDEF_NAME(Def_NAME), iDEF_LENGTH(10), sName(sName),
                                            iLength(iLength) {
    iArray = new int[iLength];
    vInitializeWithZeros(iArray, 0, iLength);
    cout << PARAMETER << sName << endl;
}

//Copying Constructor
CTable::CTable(const CTable &pcOther) : iDEF_LENGTH(10), sDEF_NAME(Def_NAME) {
    sName = pcOther.sName + Copy_SUFFIX;
    iLength = pcOther.iLength;
    iArray = new int[iLength];
    int *w = iArray;
    int *w_ = pcOther.iArray;

    for (int i = 0; i < iLength; i++) {
        *w = *w_;
        w++;
        w_++;
    }
    cout << COPY << sName << endl;
}

//Deconstuctor
CTable::~CTable() {
    delete[] iArray;
    cout << REMOVE << sName << endl;
}

//Operator copies values from A to B
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

//Initialization of all new CTables with zeroes
void CTable::vInitializeWithZeros(int *iTableToInitialize, const int iStartIndex, const int iEndIndex) {
    if (iEndIndex - iStartIndex > 0) {
        int *w = iTableToInitialize;
        for (int i = iStartIndex; i < iEndIndex; i++) {
            *(w + i) = 0;
        }
    } else {
        return;
    }
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

int CTable::iGetElement(const int iIndex, bool *iSuccess) {
    if (iIndex < iLength && iIndex >= 0) {
        //If everything is right, it sets iSuccess on 1!
        *iSuccess = true;
        return iArray[iIndex];
    } else {
        //If iIndex is out of the bounds, it sets iSuccess on -1!
        *iSuccess = false;
        return -1;
    }
}

bool CTable::bInsertElement(const int iIndex, const int iElement) {
    if (iIndex <= iLength - 1 && iIndex >= 0) {
        iArray[iIndex] = iElement;
        return true;
    } else {
        //If iIndex is out of the bounds, it returns false!
        return false;
    }
}

bool CTable::bSetLength(const int iNewLength) {
    if (0 <= iNewLength) {
        int *iArray_ = new int[iNewLength];
        int iElementsToCopy = (iNewLength < iLength) ? iNewLength : iLength;
        memcpy(iArray_, iArray, sizeof(int) * iElementsToCopy);

        delete[] iArray;

        iArray = iArray_;
        vInitializeWithZeros(iArray_, iLength, iNewLength);
        iLength = iNewLength;

        return true;
    }
    return false;
}

string CTable::sToString() {
    stringstream sArrayAsAString;
    sArrayAsAString << "[";
    int *w = iArray;
    for (int i = 0; i < iLength; i++) {
        sArrayAsAString << *w;
        if (i != iLength - 1) {
            sArrayAsAString << ", ";
        }
        w++;
    }
    sArrayAsAString << "]";
    return sArrayAsAString.str();
}


CTable *CTable::cClone() {
    return new CTable(*this);
}

void CTable::vColapse() {
    int newLength;
    if (iLength % 2 != 0) {
        newLength = (iLength / 2) + 1;
    } else {
        newLength = iLength / 2;
    }
    int *newTable = new int[newLength];
    for (int i = 0; i != newLength; ++i) {
        if (newLength + i < iLength) {
            *(newTable + i) = *(iArray + (newLength + i)) + *(iArray + i);
        } else {
            *(newTable + i) = *(iArray + i);
        }
    }
    delete[] iArray;
    iArray = newTable;
    iLength = newLength;
}




