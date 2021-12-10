#include "article.h"
#include "rim.h"
#include "tire.h"
#include "customer.h"
#include "invoice.h"
#include <fstream>
#include <iostream>
#include "tireCenter.h"



#define FILENAME "tirecenter.txt"

TireCenter::TireCenter()
{
}
TireCenter::~TireCenter()
{
    //TODO save before delete
}
TireCenter::TireCenter(std::string path)
{
    this->loadData(path);
    //load data from file
}

void TireCenter::loadData(std::string path)
{
    std::fstream file(path + "/" + FILENAME);
    if (file.is_open())
    {
    std::cout << "load data";
        this->path = path;
        std::string text;
        std::getline(file, text);
        this->setName(text);
        std::getline(file, text);
        this->setAddress(text);
        //load customers
        //load invoices
        loadArticles();
    }
    else
    {
        //TODO create tirecenter
    }
}

void TireCenter::saveData()
{
    std::cout << this->path << std::endl;
    if (this->path.size() > 0)
    {
        std::ofstream file(this->path + "/" + FILENAME);
        file << this->getName() << std::endl;
        file << this->getAddress() << std::endl;
        //save customers
        //save invoices
        saveArticles();
        std::cout << "saved data";
        file.close();
    }
}

void TireCenter::loadArticles()
{
    std::ifstream file(this->path + "/articles.txt");
    std::string type;
    auto artics = this->getArticles();
    
    while (std::getline(file, type))
    {
        if (type[0] == 'R')
        {
            auto tire = new Tire();
            tire->loadData(file);
            tire->setType('R');
            artics.push_back(tire);
            tire->show();
        }
        else if (type[0] == 'T')
        {
            auto rim = new Rim();
            rim->loadData(file);
            rim->setType('T');
            artics.push_back(rim);
            rim->show();
        }
    }
    this->setArticles(artics);
    std::cout << artics.size() << std::endl;
}

void TireCenter::saveArticles()
{
    std::ofstream file(this->path + "/articles.txt");
    for (auto art : this->getArticles())
    {
        std::cout << art->getName() << std::endl;
        art->saveData(file);
        delete art;
    }
}

std::string TireCenter::getName()
{
    return this->name;
}

void TireCenter::setName(std::string name) 
{
    this->name = name;
}

std::string TireCenter::getAddress() 
{
    return this->address;
}

void TireCenter::setAddress(std::string address) 
{
    this->address = address;
}

std::vector<Article*> TireCenter::getArticles() 
{
    return this->articles;
}

void TireCenter::setArticles(std::vector<Article*> articles) 
{
    this->articles = articles;
}

std::vector<Customer*> TireCenter::getCustomer() 
{
    return this->customers;
}

void TireCenter::setCustomers(std::vector<Customer*> customers) 
{
    this->customers = customers;
}

std::vector<Invoice*> TireCenter::getInvoice() 
{
    return this->invoices;
}

void TireCenter::setInvoices(std::vector<Invoice*> invoices) 
{
    this->invoices = invoices;
}
