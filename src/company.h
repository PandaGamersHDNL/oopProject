#pragma once
#include "customer.h"
#include <string>

class Company : public Customer
{
  private:
    std::string VAT = "VAT not set";
    int volumeDiscount = 0;

  public:
    std::string getVAT();
    void setVAT(std::string VAT);

    int getVolumeDiscount();
    void setVolumeDiscount(int newDiscount);

    virtual void addData() override;

    virtual void show() override;

    virtual std::vector<std::string> getProperties() override;

    virtual void changeProperty(int propertyIndex) override;
    virtual void setType() override;

    virtual void loadData(std::ifstream &file) override;
    virtual void saveData(std::ofstream &file) override;

    virtual Customer *clone() override;
};
