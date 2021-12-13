#pragma once
#include "article.h"
#include <string>

class Rim : public Article {
private:
  std::string color;
  bool aluminium;
  int width;

public:
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

  virtual Article *clone() override;

  void rimData();
};
