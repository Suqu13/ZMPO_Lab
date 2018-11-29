//
// Created by Jakub on 28.11.2018.
//

#include <iostream>
#include "CItem.h"

using namespace std;

CItem::CItem(string name, int weight, int value) : weight(weight), value(value) {}

CItem::~CItem() {
cout << "Item object deleted" << endl;
}

int CItem::getWeight() const {
    return weight;
}

int CItem::getValue() const {
    return value;
}

const string &CItem::getName() const {
    return name;
}

ostream &operator<<(ostream &os, const CItem &item) {
    os << "weight: " << item.weight << " value: " << item.value << " name: " << item.name;
    return os;
}
