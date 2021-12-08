#pragma once

#include "options.h"
#include "article.h"
#include <string>
#include <vector>
#include <iostream>

class Menu
{
private:
    std::vector<Options> options;
public:
    Menu();
    std::string optionsToString(Options option);
    Options showOptionMenu();
    //employee/customer Menu
    void permissionMenu(); //temp menu to pick if you're owner should be detected from who calls the menu


};

