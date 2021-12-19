#pragma once
#include "article.h"
#include <string>

class Rim : public Article {
private:
  std::string color = "not set";
  bool aluminium = false;
  int width = 0;

public:
  Rim() { this->setType(); }
  virtual ~Rim() = default;

  int getWidth();
  void setWidth(int w);

  bool getAluminium();
  void setAluminium(bool a);

  std::string getColor();
  void setColor(std::string c);

  virtual void show() override;

  virtual std::vector<std::string> getProperties() override;

  virtual void changeProperty(int propIndex) override;

  virtual void setType() override;

  virtual void loadData(std::ifstream &file);
  virtual void saveData(std::ofstream &file);

  virtual Article *clone() override;

  virtual void addData() override;
};
