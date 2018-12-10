//
// Created by Jakub on 28.11.2018.
//

#ifndef LIST_5_CITEM_H
#define LIST_5_CITEM_H
#define DEF_ITEM_DELETED "Item object deleted"
#define DEF_NAME " Name: "
#define DEF_WEIGHT "Weight: "
#define DEF_VALUE " Value: "
#define DEF_FACTOR " Factor: "

#include <string>
#include <ostream>

using namespace std;

class CItem {
private:

    int weight;
    int value;
    double factor;
    string name;
public:

    CItem(string name, int weight, int value);
    ~CItem();
    int getWeight() const;
    int getValue() const;

    void setFactor(double fold);

    double getFactor() const;

    friend ostream &operator<<(ostream &os, const CItem &item);
};


#endif //LIST_5_CITEM_H
