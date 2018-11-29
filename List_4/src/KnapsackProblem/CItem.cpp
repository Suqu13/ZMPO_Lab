//
// Created by Jakub on 28.11.2018.
//

#include <iostream>
#include "CItem.h"

using namespace std;

CItem::CItem(string name, int weight, int value) : name(name), weight(weight), value(value) {}

CItem::~CItem() {
cout << "Item object deleted" << endl;
}

int CItem::getWeight() const {
    return weight;
}

ostream &operator<<(ostream &os, const CItem &item) {
    os << "Name: " << item.name << " Weight: " << item.weight << " Value: " << item.value;
    return os;
}

int CItem::getValue() const {
    return value;
}

