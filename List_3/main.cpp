#include <iostream>
#include "lib/interface/CMenu.h"
#include "lib/helpers/CTabHandler.h"
#include "lib/helpers/CInitializer.h"
#include "lib/helpers/CMenuAnalyzer.h"
#include "lib/helpers/CMenuSerializer.h"
#include "lib/utilities/Utilities.h"

int main() {
    //CMenu cMenu("Main menu", "main menu command");
    //CTabHandler cTabHandler;
    //CInitializer::InitializeForCTable(cMenu, cTabHandler);
    string kq = "('menu','gowne';('sub','Sun';['com','com1','com2']),('sub1','subcom';))";
    // string ser = CMenuSerializer::serializeInterface(&cMenu);
    // cMenu.Run();
    CMenu *cMenu1 = dynamic_cast<CMenu*>(CMenuSerializer::deserializeInterface(kq));
    string ser = CMenuSerializer::serializeInterface(cMenu1);
    cout << ser << endl;
    return 0;
}