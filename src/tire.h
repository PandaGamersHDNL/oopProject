#pragma once
#include "article.h"
#include <string>

class Tire : public Article {
private:
  int width;
  int height;
  std::string speedIndex;
  char season;

public:
  virtual ~Tire() = default;

  int getWidth();
  void setWidth(int width);

  int getHeight();
  void setHeight(int height);

  std::string getSpeedIndex();
  void setSpeedIndex(std::string speedIndex);

  char getSeason();
  void setSeason(char season);

  virtual void show() override;

  virtual std::vector<std::string> getProperties() override;

  virtual void changeProperty(int propIndex);

  void tireData();
};
