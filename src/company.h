#pragma once
#include "customer.h"
#include <string>

class Company : public Customer {
private:
  std::string VAT;
  int volumeDiscount;

public:
  std::string getVAT();
  void setVAT(std::string VAT);

  int getVolumeDiscount();
  void setVolumeDiscount(int newDiscount);

  virtual void addData() override;

  virtual void show() override;

  virtual std::vector<std::string> getProperties();

   virtual void changeProperty(int propertyIndex);

  virtual void loadData(std::ifstream &file);
  virtual void saveData(std::ofstream &file);
};
