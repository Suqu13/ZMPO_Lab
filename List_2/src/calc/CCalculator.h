//
// Created by Jakub on 25.10.2018.
//

#ifndef LIST_2_CCALCULATOR_H
#define LIST_2_CCALCULATOR_H


class CCalculator {
public:
    CCalculator();
    void setAValue(int value);
    void setBValue(int value);
//    int getFirstValue();
//    int getSecondValue();
    int add();
    int substract();
private:
    int AValue;
    int BValue;
};


#endif //LIST_2_CCALCULATOR_H
