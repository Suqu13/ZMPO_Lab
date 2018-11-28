//
// Created by Jakub on 22.11.2018.
//

#include <sstream>
#include "CPunkt.h"

CPunkt::CPunkt(int x, int y) {
    this->x = new int(x);
    this->y = new int(y);
}

CPunkt::CPunkt(CPunkt &pcOther) {
    x = new int();
    y = new int();
    *x = *(pcOther.x);
    *y = *(pcOther.y);
}

CPunkt::~CPunkt() {
    delete x;
    delete y;
}

int CPunkt::getX() const {
    return *x;
}

void CPunkt::setX(int x_) {
    *x = x_;
}

int CPunkt::getY() const {
    return *y;
}

void CPunkt::setY(int y_) {
    *y = y_;
}

void CPunkt::operator=(CPunkt &punkt) {
    *x = *(punkt.x);
    *y = *(punkt.y);
}

ostream &operator<<(ostream &os, const CPunkt &punkt) {
    os << "x: " << *punkt.x << " y: " << *punkt.y;
    return os;
}

