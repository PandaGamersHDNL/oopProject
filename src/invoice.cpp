#include "invoice.h"
#include "article.h"
#include "company.h"
#include "customer.h"
#include "rim.h"
#include "tire.h"
#include <fstream>
#include <iostream>

Customer *Invoice::getCustomer()
{
    return this->customer;
}

void Invoice::setCustomer(Customer *customer)
{
    this->customer = customer;
}

std::vector<Article *> Invoice::getArticles()
{
    return this->articles;
}

void Invoice::setArticles(std::vector<Article *> articles)
{
    this->articles = articles;
}

float Invoice::realPrice()
{
    auto cust = this->getCustomer();
    auto comp = dynamic_cast<Company *>(cust);
    auto disc = this->getDiscount();
    if (comp)
    {
        disc += comp->getVolumeDiscount();
    }
    return (this->getPrice() * (((float)(disc / 100))) * 1.21f);
}

float Invoice::getPrice()
{
    return this->price;
}

void Invoice::setPrice()
{
    this->price = calculatePrice();
}

int Invoice::getDiscount()
{
    return this->discount;
}

void Invoice::setDiscount()
{
    this->discount = calculateDiscount();
}

void Invoice::show()
{
    std::cout << "----------------------Invoice-------------------" << std::endl;
    auto cust = this->getCustomer();
    if (cust)
        std::cout << "customer: " << cust->getName() << std::endl;
    auto comp = dynamic_cast<Company *>(cust);
    int volDisc = 0;
    if (comp)
    {
        volDisc = comp->getVolumeDiscount();
        std::cout << "volume discount: " << volDisc << std::endl;
    }
    std::cout << "-------Articles------" << std::endl;
    for (auto art : this->getArticles())
    {
        std::cout << art->getName() << std::endl;
    }
    std::cout << "-------end Articles------" << std::endl;
    std::cout << "Price: " << this->getPrice() << std::endl;
    std::cout << "discount: " << this->getDiscount() << std::endl;
    std::cout << "payed price: " << this->realPrice() << std::endl;
    auto disc = this->getDiscount() + volDisc;
    float totalPrice = (this->getPrice() - (this->getPrice() * ((float)(this->getDiscount() + volDisc) / 100))) * 1.21f;
    std::cout << this->getPrice() << "  " << ((float)(this->getDiscount() + volDisc) / 100) << std::endl;
    std::cout << "total price: " << totalPrice << std::endl;
    std::cout << "total = (price - (price * (vol disc + discount)/100)) * 1.21" << std::endl;
    std::cout << "---------------------End invoice----------------\n\n\n";
}

#define ARTICLESEND "-----------Articles-end----------"
void Invoice::saveData(std::ofstream &file)
{
    this->getCustomer()->saveData(file);
    for (auto art : this->getArticles())
    {
        art->saveData(file);
    }
    file << ARTICLESEND << std::endl;
    file << this->getDiscount() << std::endl;
    file << this->getPrice() << std::endl;
}

void Invoice::loadData(std::ifstream &file)
{
    std::string inputStr;
    Customer *cust = nullptr;
    std::getline(file, inputStr);

    if (inputStr[0] == 'O')
    {
        cust = new Company();
    }
    else
    {
        cust = new Customer();
    }
    cust->loadData(file);
    this->setCustomer(cust);
    auto list = this->getArticles();
    do
    {
        Article *art = nullptr;
        std::getline(file, inputStr);
        if (inputStr == ARTICLESEND)
            break;
        if (inputStr[0] == 'T')
        {
            art = new Tire();
        }
        else if (inputStr[0] == 'R')
        {
            art = new Rim();
        }
        if (art)
        {
            art->setType();
            art->loadData(file);
            list.push_back(art);
        }
    } while (inputStr != ARTICLESEND);
    this->setArticles(list);
    int inputInt;
    file >> inputInt;
    this->setDiscount();
    float inputFloat;
    file >> inputFloat;
    this->setPrice();
}

int Invoice::calculateDiscount()
{
    int disc = 0;
    for (auto art : this->getArticles())
    {
        if (art->getStock() > 4)
        {
            disc = 20;
            for (auto art2 : this->getArticles())
            {
                if (art->getDiameter() == art2->getDiameter())
                {
                    return 30;
                }
            }
        }
    }
    return disc;
}

float Invoice::calculatePrice()
{
    float sum = 0.0f;
    auto articles = this->getArticles();
    if (articles.size() > 0)
    {
        for (auto art : articles)
        {
            sum += (art->getPrice() * art->getStock());
        }
    }
    return sum;
}
