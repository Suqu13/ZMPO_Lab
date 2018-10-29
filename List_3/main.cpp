#include <iostream>
#include "lib/interface/CMenu.h"
#include "lib/helpers/CTabHandler.h"
#include "lib/helpers/CInitializer.h"
#include "lib/helpers/CMenuAnalyzer.h"

int main() {
    CMenu cMenu;
    CTabHandler cTabHandler;
    CInitializer::InitializeForCTable(cMenu, cTabHandler);
    CMenuAnalyzer analyzer;
    analyzer.InitializeMap(cMenu);
    analyzer.sevaMap();
    cout<<" \n";
    cMenu.Run();
    analyzer.searchPath("c1");
    return 0;
}