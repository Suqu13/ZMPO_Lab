//
// Created by Jakub on 02.11.2018.
//

#include <iostream>
#include <fstream>
#include "io_Txt_File.h"

bool io_Txt_File::writeToFile(string &Data_info, string &fileName) {
    ofstream fileStream(fileName);
    if (fileStream.is_open()) {
        fileStream << Data_info << endl;
        fileStream.close();
        return true;
    } else {
        fileStream.close();
        return false;
    }
}

string io_Txt_File::readFromFile(string &fileName) {
    ifstream fileStream(fileName);
    string menuTree;
    if (fileStream.is_open()) {
        getline(fileStream, menuTree);
    }
    fileStream.close();
    return menuTree;
}

