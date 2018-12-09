//
// Created by Jakub on 28.11.2018.
//

#include <iostream>
#include "CItem.h"

using namespace std;

CItem::CItem(string name, int weight, int value) : name(name), weight(weight), value(value), factor(1) {
    if (this->weight <= 0) this->weight = 1;
    if (this->value <= 0) this->value = 1;
}

CItem::~CItem() {
    cout << DEF_ITEM_DELETED << endl;
}

int CItem::getWeight() const {
    return weight;
}

int CItem::getValue() const {
    return value;
}

void CItem::setFold(double fold) {
    CItem::factor = fold;
}

ostream &operator<<(ostream &os, const CItem &item) {
    os << DEF_WEIGHT << item.weight << DEF_VALUE << item.value << DEF_FACTOR << item.factor << DEF_NAME << item.name;
    return os;
}

double CItem::getFactor() const {
    return factor;
}

