//
// Created by Jakub on 28.11.2018.
//

#include <iostream>
#include <iomanip>
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

void CItem::setFactor(double fold) {
    CItem::factor = fold;
}

ostream &operator<<(ostream &os, const CItem &item) {
    os << DEF_NAME << setw(8) << item.name << setw(10) << DEF_WEIGHT << setw(4) << item.weight << setw(10) << DEF_VALUE << setw(4) << item.value << setw(10) << DEF_FACTOR << setw(4) << item.factor  << endl;
    return os;
}

double CItem::getFactor() const {
    return factor;
}

string CItem::getName() const {
    return name;
}

