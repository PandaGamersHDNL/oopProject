#include "menu.h"
#include "employee.h"
#include "options.h"
#include "owner.h"
#include <iostream>

Menu::Menu()
{
}

std::string Menu::optionsToString(Options option)
{
    switch (option)
    {
    case Options::addArt:
        return "Add article";
        break;
    case Options::deleteArt:
        return "Delete article";
        break;
    case Options::changeArt:
        return "Change article";
        break;
    case Options::checkInvoice:
        return "Check invoices";
        break;
    case Options::placeOrder:
        return "Place order";
        break;
    case Options::deleteCust:
        return "Delete customer";
        break;
    case Options::changeCust:
        return "Change Customer";
        break;
    case Options::addCust:
        return "Add customer";
        break;
    case Options::updateStock:
        return "Update stock";
        break;
    case Options::searchArticles:
        return "Search articles";
    case Options::searchCustomers:
        return "Search customers";
    case Options::exit:
        return "Exit";
    default:
        return "not a valid option";
    }
}

Options Menu::showOptionMenu()
{
    int counter = 1;
    int choice;
    for (auto &option : options)
    {
        std::cout << counter++ << ". " << optionsToString(option) << std::endl;
    }
    std::cout << "pick your action. " << std::endl;
    std::cin >> choice;
    return this->options[--choice];
}

bool Menu::permissionMenu()
{
    int choice;
    std::cout << "Are you the owner or an employee?\n1. Owner\n2. Employee\n3. Exit";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        this->options = Owner::permissions();
        break;
    case 2:
        this->options = Employee::permissions();
        break;
    case 3:
        return false;
    default:
        std::cout << "Not a valid choice!\n\n\n";
        permissionMenu();
        break;
    }
    std::cout << "\n";
    return true;
}
