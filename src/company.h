#pragma once
#include <string>
#include "customer.h"

class Company : Customer
{
private:
    std::string VAT;
    int volumeDiscount;
public:
    std::string getVAT();
    void setVAT(std::string VAT);

    int getVolumeDiscount();
    void setVolumeDiscount(int newDiscount);
};