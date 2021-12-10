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
};
