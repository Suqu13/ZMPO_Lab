//
// Created by Jakub on 07.10.2018.
//

#ifndef TABLE_CTABLE_H
#define TABLE_CTABLE_H

#include <string>

using namespace std;


class CTable {

public:

    CTable(); //Constructor
    CTable(string sName, int iLength);  //Parameterized Constructor
    CTable(const CTable &pcOther); //Copying Constructor

    ~CTable(); //Deconstuctor

    CTable& operator=(const CTable &pcOther); //Operator

    //Functions
    void vSetName(const string sName);
    int iGetLength();
    int iGetElement(const int iElement_sPlace, bool *iSuccess);
    string sGetName();
    bool bAssignElement(const int iElement_sPlace, const int iElement);
    bool bSetLength(const int iNewLength);
    string sToString();
    CTable *cClone();

private:

    //Variables
    int iLength;
    string sName;
    int *iArray;

    //Default values
    const int iDEF_LENGTH;
    const string sDEF_NAME;
};


#endif //TABLE_CTABLE_H
