#include "customer.h"
#include <iostream>

std::string Customer::getName() { return this->name; }

void Customer::setName(std::string name) { this->name = name; }

std::string Customer::getAddress() { return this->address; }

void Customer::setAddress(std::string address) { this->address = address; }

char Customer::getType() { return this->type; }

void Customer::setType(char type) { this->type = type; }

void Customer::addData() {
  std::string inputStr;
  std::cout << "What's the address. ";
  std::getline(std::cin, inputStr);
  this->setAddress(inputStr);
  this->setType('U');
}
