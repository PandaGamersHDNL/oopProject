#include "customer.h"

std::string Customer::getName() 
{
    return this->name;
}

void Customer::setName(std::string name) 
{
    this->name = name;
}

std::string Customer::getAddress() 
{
    return this->address;
}

void Customer::setAddress(std::string address) 
{
    this->address = address;
}

char Customer::getType() 
{
    return this->type;
}

void Customer::setType(char type) 
{
    this->type = type;
}
