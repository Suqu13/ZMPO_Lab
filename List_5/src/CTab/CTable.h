//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CTABLE_H
#define LIST_3_CTABLE_H

#define PARAMETER "parametr: "
#define Copy_SUFFIX "_copy"
#define REMOVING_TABLE "delete CTable object: "
#define Def_NAME "Regular_CTable"
#define Def_CON "bezp: "
#define COPY "kopiuj: "

#include <string>

using namespace std;


class CTable {

public:

    CTable(); //Constructor
    CTable(string sName, int iLength);  //Parameterized Constructor
    CTable(const CTable &pcOther); //Copying Constructor

    ~CTable(); //Deconstuctor


    CTable &operator=(const CTable &pcOther); //Operator copies values from A to B

    //Functions
    void vSetName(const string sName);
    void vColapse();
    int iGetLength();
    int iGetElement(const int iIndex, bool *iSuccess);
    string sGetName();
    bool bInsertElement(const int iIndex, const int iElement);
    bool bSetLength(const int iNewLength);
    string sToString();
    CTable* cClone();


private:

    void vInitializeWithZeros(int *iTableToInitialize, const int iStartIndex, const int iEndIndex); //Initialization of all new CTables with zeroes

    //Default values
    const int iDEF_LENGTH;
    const string sDEF_NAME;

    //Variables
    int iLength;
    string sName;
    int *iArray;
};


#endif //LIST_3_CTABLE_H
