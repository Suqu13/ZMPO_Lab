#include <iostream>
#include "lib/interface/CMenu.h"
#include "lib/helpers/CTabHandler.h"
#include "lib/helpers/CInitializer.h"
#include "lib/helpers/CMenuAnalyzer.h"
#include "lib/helpers/CMenuSerializer.h"
#include "lib/utilities/Utilities.h"
#include "lib/helpers/Validator.h"
#define DEF_SEPARATOR_MAIN "********************************************"


int main() {

    vector<CItem *> itemVector = {
            new CItem("item_1", 2, 4),
            new CItem("item_2", 9, 1),
            new CItem("item_3", 1, 10),
            new CItem("item_4", 8, 12),
            new CItem("item_5", 4, 13),
            new CItem("item_6", 20, 100),
            new CItem("item_7", 4, 19),
            new CItem("item_8", 32, 13),
            new CItem("item_9", 6, 22),
            new CItem("item_10", 3, 8)
//            new CItem("item_0", 10, 7),
//            new CItem("item_1", 7, 5),
//            new CItem("item_2", 5, 4),
//            new CItem("item_3", 3, 3),
//            new CItem("item_4", 6, 6),
//            new CItem("item_5", 8, 7),
//            new CItem("item_6", 3, 2),
//            new CItem("item_7", 2, 1)
    };

    CMenu *cMenu = new CMenu("Knapsack Problem", "SPECIAL INTERFACE");
    CInitializer::InitializeForGenetic(*cMenu,itemVector);
    bool again = true;

    cout << "\n" << DEF_SEPARATOR_MAIN << endl;

    while (again) {
        CMenuAnalyzer::setStaticMember(cMenu);

        cout << "Do you want to run: " << cMenu->getS_name() << " (" << cMenu->getS_command() << ")?(y/n): ";
        if (Utilities::bYOrNIntepreter()) {
            cMenu->Run();
        }

        cout << "\n" << DEF_SEPARATOR_MAIN << endl;

        cout << "Do you want to serialize this object?(y/n): ";
        if (Utilities::bYOrNIntepreter()) {
            cout << "Provide source name: ";
            string fileName;
            cin >> fileName;
            CMenuSerializer::serialize(cMenu, fileName);
        }

        cout << "\n" << DEF_SEPARATOR_MAIN << endl;

        cout << "Do you want to deserialize some file?(y/n): ";
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
            cout << "\n" << DEF_SEPARATOR_MAIN << endl;
            delete cMenu;
        }
    }

    cout << "\n" << DEF_SEPARATOR_MAIN << endl;

    return 0;
}