#include "company.h"
#include <iostream>
#include <fstream>

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
