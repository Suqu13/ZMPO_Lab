#include <iostream>
#include "lib/interface/CMenu.h"
#include "lib/helpers/CTabHandler.h"
#include "lib/helpers/CInitializer.h"
#include "lib/helpers/CMenuAnalyzer.h"
#include "lib/helpers/CMenuSerializer.h"
#include "lib/utilities/Utilities.h"
#include "lib/helpers/Validator.h"


int main() {
    CMenu cMenu("Main menu", "main menu command");
    CTabHandler cTabHandler;
    CInitializer::InitializeForCTable(cMenu, cTabHandler);
    CMenuAnalyzer::setStaticMember(&cMenu);
//    cMenu.Run();
    CMenuSerializer::serialize(&cMenu, "newOne.txt");
    CMenu *test = dynamic_cast<CMenu *> (CMenuSerializer::deserialize("newOne.txt"));
    CMenuAnalyzer::setStaticMember(test);
    test->Run();

    return 0;
}