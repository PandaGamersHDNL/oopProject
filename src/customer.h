#pragma once
#include <string>
#include <vector>

class Customer {
private:
  std::string name;
  std::string address;
  char type;

public:
  virtual ~Customer() = default;

  std::string getName();
  void setName(std::string name);

  std::string getAddress();
  void setAddress(std::string address);

  char getType();
  void setType(char type);

  virtual void addData();

  virtual void show();

  virtual std::vector<std::string> getProperties();
  virtual void changeProperty(int propertyIndex);

  virtual void loadData(std::ifstream &file);
  virtual void saveData(std::ofstream &file);
};
