#include <iostream>
#include "interface/CMenu.h"
#include "helpers/CTabHandler.h"
#include "helpers/CInitializer.h"

int main() {
    CMenu cMenu;
    CTabHandler cTabHandler;
    CInitializer::Initialize(cMenu, cTabHandler);
    cMenu.Run();
    return 0;
}