#include "actions.h"
#include "menu.h"
#include "options.h"
#include "tireCenter.h"

#define DATAPATH "./../../data"

int main(void)
{
    auto center = TireCenter(DATAPATH);
    Menu menu;
    Options option;

    while (menu.permissionMenu())
    {
        do
        {
            option = menu.showOptionMenu();
            performAction(center, option);
        } while (option != Options::exit);
    }
    center.saveData();
    return 0;
}
