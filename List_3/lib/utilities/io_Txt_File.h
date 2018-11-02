//
// Created by Jakub on 02.11.2018.
//

#ifndef LIST_3_IO_TXT_FILE_H
#define LIST_3_IO_TXT_FILE_H

#include "string"

using namespace std;

class io_Txt_File {
public:
    static bool writeToFile(string Data_info, string &fileName);
    static string readFromFile(string &fileName);
};


#endif //LIST_3_IO_TXT_FILE_H
