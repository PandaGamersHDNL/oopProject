#include "tire.h"
#include <fstream>
#include <iostream>

int Tire::getWidth()
{
    return this->width;
}

void Tire::setWidth(int width)
{
    this->width = width;
}

int Tire::getHeight()
{
    return this->height;
}

void Tire::setHeight(int height)
{
    this->height = height;
}

std::string Tire::getSpeedIndex()
{
    return this->speedIndex;
}

void Tire::setSpeedIndex(std::string speedIndex)
{
    this->speedIndex = speedIndex;
}

char Tire::getSeason()
{
    return this->season;
}

void Tire::setSeason(char season)
{
    this->season = season;
}

void Tire::show()
{
    std::cout << "=========================Tire============================\n";
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Season: " << this->getSeason() << std::endl;
    std::cout << "Speed index: " << this->getSpeedIndex() << std::endl;
    std::cout << "Height: " << this->getHeight() << std::endl;
    std::cout << "width: " << this->getWidth() << std::endl;
    Article::show();
}

std::vector<std::string> Tire::getProperties()
{
    auto prop = Article::getProperties();
    prop.push_back("Width");
    prop.push_back("Height");
    prop.push_back("SpeedIndex");
    prop.push_back("Season");
    return prop;
}

void Tire::changeProperty(int propIndex)
{
    Article::changeProperty(propIndex);
    // property size of articles
    const int sizeArt = 5;
    int inputInt;
    std::string inputStr;
    char inputChar;
    switch (propIndex)
    {
    case sizeArt + 0:
        std::cout << "enter the new width value. ";
        std::cin >> inputInt;
        this->setWidth(inputInt);
        break;
    case sizeArt + 1:
        std::cout << "enter the new height value. ";
        std::cin >> inputInt;
        this->setHeight(inputInt);
        break;
    case sizeArt + 2:
        std::cout << "enter the new speed index value. ";
        std::cin >> inputStr;
        this->setSpeedIndex(inputStr);
        break;
    case sizeArt + 3:
        std::cout << "enter the new season value. ";
        std::cin >> inputChar;
        this->setSeason(inputChar);
        break;
    }
}

void Tire::setType()
{
    this->type = 'T';
}

void Tire::loadData(std::ifstream &file)
{
    Article::loadData(file);
    std::string inputStr;
    int inputInt;
    file >> inputInt;
    this->setWidth(inputInt);
    file >> inputInt;
    this->setHeight(inputInt);
    file >> std::ws;
    std::getline(file, inputStr);
    this->setSpeedIndex(inputStr);
    std::getline(file, inputStr);
    this->setSeason(inputStr[0]);
}

void Tire::saveData(std::ofstream &file)
{
    Article::saveData(file);
    file << this->getWidth() << std::endl;
    file << this->getHeight() << std::endl;
    file << this->getSpeedIndex() << std::endl;
    file << this->getSeason() << std::endl;
}

Article *Tire::clone()
{
    return new Tire(*this);
}

void Tire::addData()
{
    Article::addData();
    int inputInt;
    char inputChar;
    std::string inputStr;

    std::cout << "enter the width. ";
    std::cin >> inputInt;
    this->setWidth(inputInt);

    std::cout << "enter the height. ";
    std::cin >> inputInt;
    this->setHeight(inputInt);

    std::cout << "enter the speed index. ";
    std::cin >> inputStr;
    this->setSpeedIndex(inputStr);

    std::cout << "enter the tires' season. ";
    std::cin >> inputChar;
    this->setSeason(inputChar);
}
