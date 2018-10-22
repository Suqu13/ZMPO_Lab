#include <iostream>
#include "src/inter/CMenu.h"
#include "src/helpers/CInitializer.h"

int main() {
    CMenu cMenu;
    CTabHandler cTabHandler;
    CInitializer::Initialize(cMenu, cTabHandler);
    cMenu.Run();
}