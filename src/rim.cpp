#include "rim.h"
#include <iostream>

int Rim::getWidth() 
{
    return width;
}

void Rim::setWidth(int w) 
{
    width = w;
}

bool Rim::getAluminium() 
{
    return aluminium;
}

void Rim::setAluminium(bool a) 
{
    aluminium = a;
}

std::string Rim::getColor() 
{
    return color;
}

void Rim::setColor(std::string c) 
{
    color = c;
}

void Rim::show()
{
    std::cout << "=========================Rim=============================\n";
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Aluminium: " << (this->getAluminium() ? "yes." : "no") << std::endl;
    std::cout << "Color: " << this->getColor() << std::endl;
    std::cout << "Width: " << this->getWidth() << std::endl;
    Article::show();
}

std::vector<std::string> Rim::getProperties()
{
    auto prop = Article::getProperties();
    prop.push_back("Aluminum");
    prop.push_back("Color");
    prop.push_back("Width");
    return prop;
}

void Rim::changeProperty(int propIndex)
{
    Article::changeProperty(propIndex);
    //property size of articles
    const int sizeArt = 5;
    int inputInt; std::string inputStr; char inputChar;
    switch (propIndex)
    {
    case sizeArt + 0:
        do
        {
            std::cout << "enter the new aluminium value. 1. yes 2. no";
            std::cin >> inputInt;
        } while (inputInt > 2 || inputInt < 1);
        this->setAluminium(inputInt == 1 ? true : false);
        break;
    case sizeArt + 1:
        std::cout << "enter the new color value. ";
        std::cin >> inputStr;
        this->setColor(inputStr);
        break;
    case sizeArt + 2:
        std::cout << "enter the new width value. ";
        std::cin >> inputInt;
        this->setWidth(inputInt);
        break;
    }
}



