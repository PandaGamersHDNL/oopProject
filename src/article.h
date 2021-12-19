#pragma once
#include <string>
#include <vector>

class Article
{
  private:
    std::string name = "not set";
    std::string manufacturer = "not set";
    int stock = 0;
    int diameter = 0;
    float price = 0.0f;

  protected:
    char type = 'A';

  public:
    virtual ~Article() = default;

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
    virtual void setType() = 0;

    virtual Article *clone() = 0;

    virtual void addData();

    virtual void show();

    virtual std::vector<std::string> getProperties();

    virtual void changeProperty(int propIndex);

    virtual void loadData(std::ifstream &file);
    virtual void saveData(std::ofstream &file);
};
