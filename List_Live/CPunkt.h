//
// Created by Jakub on 22.11.2018.
//

#ifndef LIST_LIVE_CPUNKT_H
#define LIST_LIVE_CPUNKT_H
#include <string>
#include <ostream>

using namespace std;

class CPunkt {
private:
    int *x;
    int *y;
public:
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void operator=(CPunkt &punkt);
    friend ostream &operator<<(ostream &os, const CPunkt &punkt);

public:
    CPunkt(int x, int y);
    CPunkt(CPunkt &pcOther);
    ~CPunkt();


};


#endif //LIST_LIVE_CPUNKT_H
