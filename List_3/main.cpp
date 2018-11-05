#include <iostream>
#include "lib/interface/CMenu.h"
#include "lib/helpers/CTabHandler.h"
#include "lib/helpers/CInitializer.h"
#include "lib/helpers/CMenuAnalyzer.h"
#include "lib/helpers/CMenuSerializer.h"
#include "lib/utilities/Utilities.h"

int main() {
//    CMenu cMenu("Main menu", "main menu command");
//    CTabHandler cTabHandler;
//    CInitializer::InitializeForCTable(cMenu, cTabHandler);
//
//
    string example = "('menu','gowne';('sub','Sun';['com','com1','com2']),('sub1','subcom';))";
//    string info_1_source = CMenuSerializer::serializeInterface(&cMenu);
//
//
//    CMenu *cMenu_1 = dynamic_cast<CMenu *>(CMenuSerializer::deserializeInterface(info_1_source));
//    string info_1 = CMenuSerializer::serializeInterface(cMenu_1);
//    CMenu *cMenu_2 = dynamic_cast<CMenu *>(CMenuSerializer::deserializeInterface(example));
//    string info_2 = CMenuSerializer::serializeInterface(cMenu_2);
//    CMenuAnalyzer::setStaticMember(cMenu_2);
//
//
//    cout << info_1_source << endl;
//    cout << info_1 << "\n" << endl;
//    cout << info_2 << "\n" << endl;
//
//    cMenu_1->Run();
//    delete cMenu_1;
//
//    cMenu_2->Run();
//    delete cMenu_2;
//
////    cMenu.Run();
//

    CMenuSerializer::validateInterface_info(example);
    return 0;
}