#pragma once
#include "article.h"
#include <string>

class Tire : public Article
{
  private:
    int width = 0;
    int height = 0;
    std::string speedIndex = "not set";
    char season = 'N';

  public:
    Tire()
    {
        this->setType();
    }
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

    virtual void changeProperty(int propIndex) override;

    virtual void setType() override;

    virtual void loadData(std::ifstream &file);
    virtual void saveData(std::ofstream &file);

    virtual Article *clone() override;

    virtual void addData() override;
};
