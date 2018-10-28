#include <iostream>
#include "src/interface/CMenu.h"
#include "src/helpers/CInitializer.h"
#include "src/calc/CCalculator.h"

int main() {
    CMenu cMenu;
    CTabHandler cTabHandler;
    CInitializer::Initialize(cMenu, cTabHandler);
//    CCalculator calculator;
//    CInitializer::InitializeCalulator(cMenu, calculator);
    cMenu.Run();
    return 0;
}