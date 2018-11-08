//
// Created by Jakub on 29.10.2018.
//

#ifndef LIST_3_CMENU_H
#define LIST_3_CMENU_H


#define WRONG_COMMAND "Wrong command, try again!"
#define REMOVING_CMENUITEM_OBJECT "usuwam CMenuItem: "
#define NAME "name: "
#define BACK_COMMAND "back"
#define BACK_HELP "This command makes moving back and exiting whole program possible"
#define NO_COMMAND "CMenu doesn't support help!"
#define BACK_COMMAND_SIGNATURE "Back (back)"
#define HELP_COMMAND "help"
#define SEARCH_COMMAND "search"

#define SPACE_AS_STRING " "

#define OPEN_BRACKET_AS_STRING "("

#define CLOSE_BRACKET_AS_STRING ")"

#define STARS "**********************************"

#include <vector>
#include "CMenuItem.h"


using namespace std;
class CMenuAnalyzer;
class CMenu: public CMenuItem {
public:
    CMenu();
    CMenu(const string &s_name, const string &s_command);
    ~CMenu() override;
    void Run() override;
    void CMenuToString();
    bool AddMenuItem(CMenuItem* vMenuItem);
    bool DeleteMenuItem(string s_command);
    vector<CMenuItem *> getVMenuItems() const;

private:
    string findHelp(string sCommandName);
    bool ifExist(CMenuItem *vMenuItem);
    CMenuItem* findAction();
    vector<CMenuItem*> vMenuItems;
};


#endif //LIST_3_CMENU_H
