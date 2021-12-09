#include "tireCenter.h"
#include "article.h"
#include "customer.h"
#include "invoice.h"
#include <fstream>
#include <iostream>

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
        this->path = path;
        std::string text;
        std::getline(file, text);
        this->setName(text);
        std::getline(file, text);
        this->setAddress(text);
        //load customers
        //load invoices
        //load articles
    }
    else
    {
        //TODO create tirecenter
    }
}

void TireCenter::saveData()
{
    std::cout << this->path;
    if (this->path.size() > 0)
    {
        std::ofstream file(this->path + "/" + FILENAME);
        file << this->getName() << std::endl;
        file << this->getAddress() << std::endl;
        file.close();
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

std::vector<Customer> TireCenter::getCustomer() 
{
    return this->customers;
}

void TireCenter::setCustomers(std::vector<Customer> customers) 
{
    this->customers = customers;
}

std::vector<Invoice> TireCenter::getInvoice() 
{
    return this->invoices;
}

void TireCenter::setInvoices(std::vector<Invoice> invoices) 
{
    this->invoices = invoices;
}
