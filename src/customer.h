#pragma once
#include <string>
#include <vector>

class Customer {
private:
  std::string name;
  std::string address;

protected:
  char type;

public:
  virtual ~Customer() = default;

  std::string getName();
  void setName(std::string name);

  std::string getAddress();
  void setAddress(std::string address);

  char getType();
  virtual void setType();

  virtual void addData();

  virtual void show();

  virtual std::vector<std::string> getProperties();
  virtual void changeProperty(int propertyIndex);

  virtual void loadData(std::ifstream &file);
  virtual void saveData(std::ofstream &file);

  virtual Customer *clone();
};
