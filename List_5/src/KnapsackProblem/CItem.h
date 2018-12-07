//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_5_CITEM_H
#define LIST_5_CITEM_H
#define DEF_ITEM_DELETED "Item object deleted"
#define DEF_NAME "Name: "
#define DEF_WEIGHT " Weight: "
#define DEF_VALUE " Value: "

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


#endif //LIST_5_CITEM_H
