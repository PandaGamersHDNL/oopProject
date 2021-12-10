#include "company.h"
#include <iostream>

std::string Company::getVAT() { return this->VAT; }

void Company::setVAT(std::string VAT) { this->VAT = VAT; }

int Company::getVolumeDiscount() { return this->volumeDiscount; }

void Company::setVolumeDiscount(int newDiscount) {
  this->volumeDiscount = newDiscount;
}

void Company::addData() {
  std::string inputStr;
  int inputInt;
  Customer::addData();
  this->setType('U');
  std::cout << "Enter the VAT. ";
  std::cin >> inputStr;
  this->setVAT(inputStr);

  std::cout << "Enter the volume discount. ";
  std::cin >> inputInt;
  this->setVolumeDiscount(inputInt);
}

void Company::show() {
  Customer::show();
  std::cout << "VAT: " << this->getVAT() << std::endl;
  std::cout << "Volume discount: " << this->getVolumeDiscount() << std::endl;
}
