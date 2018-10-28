//
// Created by Jakub on 25.10.2018.
//

#include "CCalculator.h"

int CCalculator::add() {
    return AValue + BValue;
}

int CCalculator::substract() {
    return  AValue - BValue;
}

void CCalculator::setAValue(int value) {
    AValue = value;
}

void CCalculator::setBValue(int value) {
    BValue = value;
}

//int CCalculator::getFirstValue() {
//    return AValue;
//}
//
//int CCalculator::getSecondValue() {
//    return AValue;
//}

CCalculator::CCalculator(): AValue(0), BValue(0) {
}
