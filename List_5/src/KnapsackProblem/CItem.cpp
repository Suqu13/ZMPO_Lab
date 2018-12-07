//
// Created by Jakub on 28.11.2018.
//

#include <iostream>
#include "CItem.h"

using namespace std;

CItem::CItem(string name, int weight, int value) : name(name), weight(weight), value(value) {
    if (this->weight <= 0) this->weight = 1;
    if (this->value <= 0) this->value = 1;
}

CItem::~CItem() {
    cout << DEF_ITEM_DELETED << endl;
}

int CItem::getWeight() const {
    return weight;
}

ostream &operator<<(ostream &os, const CItem &item) {
    os << DEF_NAME << item.name << DEF_WEIGHT << item.weight << DEF_VALUE << item.value;
    return os;
}

int CItem::getValue() const {
    return value;
}

