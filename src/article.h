#pragma once
#include <string>
#include <vector>

class Article
{
private:
    std::string name;
    std::string manufacturer;
    int stock;
    int diameter;
    float price;
    char type;
public:
    std::string getName();
    void setName(std::string name);

    std::string getManufacturer();
    void setManufacturer(std::string manufacturer);

    int getStock();
    void setStock(int stock);

    int getDiameter();
    void setDiameter(int diameter);
    
    float getPrice();
    void setPrice(float price);

    char getType();
    void setType(char type);

    void articleData();

    //TODO virtual destructors?
    virtual void show();

    virtual std::vector<std::string> getProperties();

    virtual void changeProperty(int propIndex);
};
