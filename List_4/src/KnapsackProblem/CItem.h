//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_4_CITEM_H
#define LIST_4_CITEM_H
#include <string>
#include <ostream>

using namespace std;

class CItem {
private:

    int weight;
    int value;
    string name;
public:

    CItem(string name, int weight, int value);
    ~CItem();
    friend ostream &operator<<(ostream &os, const CItem &item);
    int getWeight() const;
    int getValue() const;
};


#endif //LIST_4_CITEM_H
