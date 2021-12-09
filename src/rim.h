#pragma once
#include <string>
#include "article.h"

class Rim : public Article
{
private:
    std::string color;
    bool aluminium;
    int width;

public:
    int getWidth();
    void setWidth(int w);

    bool getAluminium();
    void setAluminium(bool a);

    std::string getColor();
    void setColor(std::string c);

    virtual void show() override;

    virtual std::vector<std::string> getProperties() override;

    virtual void changeProperty(int propIndex);

    void rimData();
};