//
// Created by Jakub on 29.10.2018.
//

#include <sstream>
#include <iostream>
#include "CMenuAnalyzer.h"


CMenuAnalyzer::CMenuAnalyzer() {
    mainNode = new Node();
}

CMenuAnalyzer::~CMenuAnalyzer() {
    delete mainNode;
}

void CMenuAnalyzer::InitializeMap(CMenuItem &cMenu) {
    mainNode->makeMap(&cMenu);
}

string CMenuAnalyzer::sevaMap() {
    string s = mainNode->writeMap();
    cout << s << endl;
    return s;
}

//TODO
string CMenuAnalyzer::searchPath(string s_name) {
    string path;
    mainNode->findPath(path, s_name);
    cout << path;
}

//Node Part *************************************************


CMenuAnalyzer::Node::Node() {
    s_name = "def_name";
    s_command = "def_command";
    s_help = "def_help";
}

CMenuAnalyzer::Node::~Node() {
    for (int i = 0; i < childrens.size(); ++i) {
        delete childrens[i];
    }
    childrens.clear();
}

CMenuAnalyzer::Node *CMenuAnalyzer::Node::makeMap(CMenuItem *cMenuItem) {
    s_name = cMenuItem->getS_name();
    s_command = cMenuItem->getS_command();
    s_help = cMenuItem->getS_help();
    if (CMenu *item = dynamic_cast<CMenu *>(cMenuItem)) {
        vector<CMenuItem *> vec = item->getVMenuItems();
        for (int i = 0; i < vec.size(); i++) {
            this->childrens.push_back((new Node)->makeMap(vec[i]));
        }
    }
    return this;
}

string CMenuAnalyzer::Node::writeMap() {
    stringstream stream;
    if (!this->childrens.empty()) {
        stream << "(" << this->s_name << "," << this->s_command << ";";
        for (int i = 0; i < childrens.size(); i++) {
            if (i > 0) {
                stream << ",";
            }
            stream << childrens[i]->writeMap();
        }
        stream << ")";
    } else {

        stream << "[" << this->s_name << "," << this->s_command << "," << this->s_help << "]";
    }
    return stream.str();
}

//TODO
void CMenuAnalyzer::Node::findPath(string path, const string &commandToFind) {
    path += s_command;
    vector<Node *> menuItems = childrens;
    for (int i = 0; i < childrens.size(); ++i) {
        if (childrens[i]->s_command == commandToFind) {
            cout << path << " -> " << childrens[i]->s_command << endl;
        }
        childrens[i]->findPath(path, commandToFind);
    }

}




