#include "company.h"


std::string Company::getVAT() 
{
    return this->VAT;
}

void Company::setVAT(std::string VAT) 
{
    this->VAT = VAT;
}

int Company::getVolumeDiscount() 
{
    return this->volumeDiscount;
}

void Company::setVolumeDiscount(int newDiscount) 
{
    this->volumeDiscount = newDiscount;
}
