#include "company.h"
#include <fstream>
#include <iostream>
#include <vector>

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
  this->setType('O');
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

std::vector<std::string> Company::getProperties() {
  std::vector<std::string> properties = Customer::getProperties();
  properties.push_back("VAT");
  properties.push_back("VolumeDiscount");
  return properties;
}

void Company::changeProperty(int propertyIndex) {
  const int customerProp = 2;
  std::string inputStr;
  Customer::changeProperty(propertyIndex);
  // std::cin >> std::ws; // shouldn't have to be cleared gets cleared in
  // customer
  switch (propertyIndex) {
  case customerProp:
    std::cout << "enter the new VAT: ";
    std::cin >> std::ws;
    std::cin >> inputStr;
    this->setVAT(inputStr);
    break;
  case customerProp + 1:
    int inputInt;
    std::cout << "what is the new volume discount? ";
    std::cin >> std::ws;
    std::cin >> inputInt;
    this->setVolumeDiscount(inputInt);
    break;
  }
}

void Company::loadData(std::ifstream &file) {
  Customer::loadData(file);
  std::string inputStr;
  int inputInt;

  std::getline(file, inputStr);
  this->setVAT(inputStr);
  file >> inputInt;
  this->setVolumeDiscount(inputInt);
}

void Company::saveData(std::ofstream &file) {
  Customer::saveData(file);
  file << this->getVAT() << std::endl;
  file << this->getVolumeDiscount() << std::endl;
}

Customer *Company::clone() { return new Customer(*this); }
