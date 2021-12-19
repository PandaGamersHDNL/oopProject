#include "customer.h"
#include <fstream>
#include <iostream>
#include <vector>

std::string Customer::getName() { return this->name; }

void Customer::setName(std::string name) { this->name = name; }

std::string Customer::getAddress() { return this->address; }

void Customer::setAddress(std::string address) { this->address = address; }

char Customer::getType() { return this->type; }

void Customer::setType() { this->type = 'U'; }

void Customer::addData() {
  std::string inputStr;
  std::cout << "What's the name. ";
  std::cin >> std::ws; // empty buffer
  std::getline(std::cin, inputStr);
  std::cout << "What's the address. ";
  std::getline(std::cin, inputStr);
  this->setAddress(inputStr);
  this->setType();
}

void Customer::show() {
  std::cout << "===============Customer=====================\n";
  std::cout << "Type: " << this->getType() << std::endl;
  std::cout << "Name: " << this->getName() << std::endl;
  std::cout << "address: " << this->getAddress() << std::endl;
}

std::vector<std::string> Customer::getProperties() {
  std::vector<std::string> properties;
  properties.push_back("Name");
  properties.push_back("address");
  return properties;
}

void Customer::changeProperty(int propertyIndex) {
  
  std::string inputStr;
  switch (propertyIndex) {
  case 0:
    std::cout << "what is the new name? ";
    std::cin >> std::ws; // clear buffer
    std::cin >> inputStr;
    this->setName(inputStr);
    break;
  case 1:
    std::cout << "what is the new address";
    std::cin >> std::ws;
    std::getline(std::cin, inputStr);
    this->setAddress(inputStr);
  }
}

void Customer::loadData(std::ifstream &file) {
  this->setType();
  std::string input;
  std::getline(file, input);
  this->setName(input);
  std::getline(file, input);
  this->setAddress(input);
}

void Customer::saveData(std::ofstream &file) {
  file << this->getType() << " " << std::endl;
  file << this->getName() << std::endl;
  file << this->getAddress() << std::endl;
}

Customer *Customer::clone() { return new Customer(*this); }
