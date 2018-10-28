//
// Created by Jakub on 22.10.2018.
//

#ifndef LIST_2_CINITIALIZER_H
#define LIST_2_CINITIALIZER_H


#include "../interface/CMenu.h"
#include "CTabHandler.h"
#include "../calc/CCalculator.h"

class CInitializer {
public:
    static void Initialize(CMenu &cMenu, CTabHandler &cTabHandler);
    static void InitializeCalulator(CMenu &cMenu, CCalculator &calculator);
};


#endif //LIST_2_CINITIALIZER_H
