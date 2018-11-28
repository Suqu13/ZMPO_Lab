//
// Created by Jakub on 22.11.2018.
//

#include "CProstokat.h"


CProstokat::CProstokat(int x_1, int y_1, int x_2, int y_2) : wierzcholek_1(x_1, y_1), wierzcholek_2(x_2, y_2) {
}

CProstokat::CProstokat(CPunkt p_1, CPunkt p_2) : wierzcholek_1(p_1), wierzcholek_2(p_2) {
}

CProstokat CProstokat::operator+(CProstokat &prostokat) {
    int left = znajdzMin(znajdzMin(this->wierzcholek_1.getX(), this->wierzcholek_2.getX()),
                         znajdzMin(prostokat.wierzcholek_1.getX(), prostokat.wierzcholek_2.getX()));
    int right = znajdzMax(znajdzMax(this->wierzcholek_2.getX(), this->wierzcholek_1.getX()),
                          znajdzMax(prostokat.wierzcholek_2.getX(), prostokat.wierzcholek_1.getX()));
    int bottom = znajdzMin(znajdzMin(this->wierzcholek_1.getY(), this->wierzcholek_2.getY()),
                           znajdzMin(prostokat.wierzcholek_1.getY(), prostokat.wierzcholek_2.getY()));
    int top = znajdzMax(znajdzMax(this->wierzcholek_2.getY(), this->wierzcholek_1.getY()),
                        znajdzMax(prostokat.wierzcholek_2.getY(), prostokat.wierzcholek_1.getY()));

    CProstokat cProstokat(left, bottom, right, top);

    return cProstokat;
}

int CProstokat::znajdzMin(int v_1, int v_2) {
    if (v_1 <= v_2) {
        return v_1;
    } else {
        return v_2;
    }
}

int CProstokat::znajdzMax(int v_1, int v_2) {
    if (v_1 <= v_2) {
        return v_2;
    } else {
        return v_1;
    }
}

ostream &operator<<(ostream &os, const CProstokat &prostokat) {
    os << "wierzcholek_1: " << prostokat.wierzcholek_1 << " wierzcholek_2: " << prostokat.wierzcholek_2;
    return os;
}



