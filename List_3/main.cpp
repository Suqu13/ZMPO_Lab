#include <iostream>
#include "lib/interface/CMenu.h"
#include "lib/helpers/CTabHandler.h"
#include "lib/helpers/CInitializer.h"
#include "lib/helpers/CMenuAnalyzer.h"
#include "lib/helpers/CMenuSerializer.h"
#include "lib/utilities/Utilities.h"
#include "lib/helpers/Validator.h"


int main() {

    CMenu *cMenu = new CMenu("Main menu", "main menu command");
    CTabHandler cTabHandler;
    CInitializer::InitializeForCTable(*cMenu, cTabHandler);
    bool again = true;

    while (again) {
        CMenuAnalyzer::setStaticMember(cMenu);

        cout << "\nDo you want to run: " << cMenu->getS_name() << " (" << cMenu->getS_command() << ")?(y/n): ";
        if (Utilities::bYOrNIntepreter()) {
            cMenu->Run();
        }

        cout << "\nDo you want to serialize this object?(y/n): ";
        if (Utilities::bYOrNIntepreter()) {
            cout << "Provide source name: ";
            string fileName;
            cin >> fileName;
            CMenuSerializer::serialize(cMenu, fileName);
        }

        cout << "\nDo you want to deserialize some file?(y/n): ";
        again = Utilities::bYOrNIntepreter();
        if (again) {
            delete cMenu;
            cout << "\nProvide source name: ";
            string fileName;
            while (fileName.empty() || cMenu == nullptr) {
                cin >> fileName;
                cMenu = dynamic_cast<CMenu *> (CMenuSerializer::deserialize(fileName));
                if (cMenu == nullptr) {
                    cout << "\nSomething went wrong. Do you want to exit?(y/n): ";
                    if (Utilities::bYOrNIntepreter()) {
                        return 0;
                    }
                }
            }
        } else {
            delete cMenu;
        }
    }
    return 0;
}