//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENUANALYZER_H
#define LIST_3_CMENUANALYZER_H

#include "string"
#include "vector"
#include "../interface/CMenu.h"

using namespace std;

class CMenuAnalyzer {
    class Node {
    public:
        Node();
        ~Node();
        Node* makeMap(CMenuItem *cMenu);
        string writeMap();
        void findPath(string path,  const string &commandToFind);

    private:
        string s_name;
        string s_command;
        string s_help;
        vector<Node*> childrens;
    };

public:
    CMenuAnalyzer();
    ~CMenuAnalyzer();
    string searchPath(string s_name);
    void InitializeMap(CMenuItem &cMenu);
    string sevaMap();


private:
    Node *mainNode;
    vector<string> path;
};


#endif //LIST_3_CMENUANALYZER_H
