#pragma once
#include <string>

class Customer {
private:
  std::string name;
  std::string address;
  char type;

public:
  std::string getName();
  void setName(std::string name);

  std::string getAddress();
  void setAddress(std::string address);

  char getType();
  void setType(char type);

  virtual void addData();
};
