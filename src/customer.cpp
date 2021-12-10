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
  //TODO address is a line not a single string
  std::getline(std::cin, inputStr); //empty buffer
  std::getline(std::cin, inputStr);
  this->setAddress(inputStr);
  this->setType('U');
}

void Customer::show() {
  std::cout << "===============Customer=====================\n";
  std::cout << "Type: " << this->getType() << std::endl;
  std::cout << "Name: " << this->getName() << std::endl;
  std::cout << "address: " << this->getAddress() << std::endl;
}
