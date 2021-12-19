#pragma once

#include "article.h"
#include "options.h"
#include <iostream>
#include <string>
#include <vector>

class Menu
{
  private:
    std::vector<Options> options;

  public:
    Menu();
    virtual ~Menu() = default;

    std::string optionsToString(Options option);
    Options showOptionMenu();
    // employee/customer Menu
    bool permissionMenu();
};
