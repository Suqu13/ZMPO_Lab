//
// Created by Jakub on 22.11.2018.
//

#ifndef LIST_LIVE_CPROSTOKAT_H
#define LIST_LIVE_CPROSTOKAT_H


#include <ostream>
#include "CPunkt.h"

class CProstokat {
private:
    CPunkt wierzcholek_1;
    CPunkt wierzcholek_2;
    int znajdzMin(int v_1, int v_2);
    int znajdzMax(int v_1, int v_2);


public:
    friend ostream &operator<<(ostream &os, const CProstokat &prostokat);

public:
    CProstokat(int x_1, int y_1, int x_2, int y_2);
    CProstokat(CPunkt p_1, CPunkt p_2);
    CProstokat operator+(CProstokat &prostokat);

};


#endif //LIST_LIVE_CPROSTOKAT_H
