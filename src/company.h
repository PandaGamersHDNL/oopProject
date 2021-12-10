#pragma once
#include <string>
#include "customer.h"

class Company : public Customer
{
private:
    std::string VAT;
    int volumeDiscount;
public:
    std::string getVAT();
    void setVAT(std::string VAT);

    int getVolumeDiscount();
    void setVolumeDiscount(int newDiscount);

    virtual void addData() override;
};