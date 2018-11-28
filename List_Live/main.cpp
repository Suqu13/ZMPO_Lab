#include <iostream>
#include "CPunkt.h"
#include "CProstokat.h"

using namespace std;


int main() {
    CPunkt a(1,1), b(2,2);
    CPunkt c(3,3), d(a);
    cout << a << b << c << d << endl;
    c=b;
    c.setX(10); c.setY(10);
    a.setX(20); a.setY(20);
    cout << a << b << c << d << endl;

    CProstokat p1 (0,0,4,5);
    CProstokat p2 (1,2,8,3);
    cout << p1 + p2 << endl;

    CProstokat p3(a, b);
    CProstokat p4(c,d);
    cout << p3 + p4 << endl;
}