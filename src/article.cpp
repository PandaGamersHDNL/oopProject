#include "article.h"
#include <fstream>
#include <iostream>

std::string Article::getName() { return this->name; }

void Article::setName(std::string name) { this->name = name; }

std::string Article::getManufacturer() { return this->manufacturer; }

void Article::setManufacturer(std::string manufacturer) {
  this->manufacturer = manufacturer;
}

int Article::getStock() { return this->stock; }

void Article::setStock(int stock) { this->stock = stock; }

int Article::getDiameter() { return this->diameter; }

void Article::setDiameter(int diameter) { this->diameter = diameter; }

float Article::getPrice() { return this->price; }

void Article::setPrice(float price) { this->price = price; }

char Article::getType() { return this->type; }

void Article::show() {
  std::cout << "Diameter: " << this->getDiameter() << std::endl;
  std::cout << "Manufacturer: " << this->getManufacturer() << std::endl;
  std::cout << "Price: " << this->getPrice() << std::endl;
  std::cout << "Stock: " << this->getStock() << std::endl;
  std::cout << "Type: " << this->getType() << std::endl;
  std::cout << "========================================================\n\n";
}

std::vector<std::string> Article::getProperties() {
  return {"Name", "Manufacturer", "Stock", "Diameter", "Price"};
}

void Article::changeProperty(int propIndex) {
  std::string inputStr;
  int inputInt;
  float inputFloat;

  switch (propIndex) {
  case 0:
    std::cout << "enter the new name value. ";
    std::cin >> inputStr;
    this->setName(inputStr);
    break;
  case 1:
    std::cout << "enter the new manufacturer value. ";
    std::cin >> inputStr;
    this->setManufacturer(inputStr);
    break;
  case 2:
    std::cout << "enter the new stock value. ";
    std::cin >> inputInt;
    this->setStock(inputInt);
    break;
  case 3:
    std::cout << "enter the new diameter value. ";
    std::cin >> inputInt;
    this->setDiameter(inputInt);
    break;
  case 4:
    std::cout << "enter the new price value. ";
    std::cin >> inputFloat;
    this->setPrice(inputFloat);
    break;
  }
}

void Article::loadData(std::ifstream &file) {
  std::string output;
  int outputInt;
  float outputFloat;
  std::getline(file, output);
  this->setName(output);
  std::getline(file, output);
  this->setManufacturer(output);
  file >> outputInt;
  this->setDiameter(outputInt);
  file >> outputFloat;
  this->setPrice(outputFloat);
  file >> outputInt;
  this->setStock(outputInt);
}

void Article::saveData(std::ofstream &file) {
  file << this->getType() << std::endl;
  file << this->getName() << std::endl;
  file << this->getManufacturer() << std::endl;
  file << this->getDiameter() << std::endl;
  file << this->getPrice() << std::endl;
  file << this->getStock() << std::endl;
}

void Article::addData() {
  int inputInt;
  std::string inputStr;
  float inputFloat;

  std::cout << "please enter the name. ";
  std::cin >> inputStr;
  this->setName(inputStr);

  std::cout << "please enter the diameter. ";
  std::cin >> inputInt;
  this->setDiameter(inputInt);

  std::cout << "enter the manufacturer. ";
  std::cin >> inputStr;
  this->setManufacturer(inputStr);

  std::cout << "enter the price. ";
  std::cin >> inputFloat;
  this->setPrice(inputFloat);

  std::cout << "enter the stock. ";
  std::cin >> inputInt;
  this->setStock(inputInt);
}
