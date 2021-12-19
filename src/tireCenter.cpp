#include "tireCenter.h"
#include "article.h"
#include "company.h"
#include "customer.h"
#include "invoice.h"
#include "rim.h"
#include "tire.h"
#include <fstream>
#include <iostream>

#define FILENAME "tirecenter.txt"

TireCenter::TireCenter()
{
}

TireCenter::TireCenter(std::string path)
{
    this->loadData(path);
}

void TireCenter::loadData(std::string path)
{
    std::fstream file(path + "/" + FILENAME);
    this->path = path;
    if (file.is_open())
    {
        std::cout << "load data" << std::endl;
        std::string text;
        std::getline(file, text);
        this->setName(text);
        std::getline(file, text);
        this->setAddress(text);
    }
    else
    {
      std::cout << "enter the name of the tire center. ";
        std::string str;
        std::getline(std::cin, str);
        this->setName(str);
        std::cout << "enter the address of the tire center. ";
        std::getline(std::cin, str);
        this->setAddress(str);
    }
    file.close();
    loadCusomers();
    loadInvoices();
    loadArticles();
}

void TireCenter::saveData()
{
    std::cout << this->path << std::endl;
    if (this->path.size() > 0)
    {
        std::ofstream file(this->path + "/" + FILENAME);
        file << this->getName() << std::endl;
        file << this->getAddress() << std::endl;
        file.close();
        saveCustomers();
        saveInvoices();
        saveArticles();
    }
}

void TireCenter::loadCusomers()
{
    std::cout << "loading customers" << std::endl;
    std::ifstream file(this->path + "/customers.txt");
    if (file.is_open())
    {
        std::string type;
        auto customers = this->getCustomer();

        while (std::getline(file, type))
        {
            Customer *cust = nullptr;
            if (type[0] == 'U')
            {
                cust = new Customer();
            }
            else if (type[0] == 'O')
            {
                cust = new Company();
            }
            if (cust)
            {
                cust->loadData(file);
                cust->setType();
                customers.push_back(cust);
                cust->show();
            }
        }
        this->setCustomers(customers);
    }
    file.close();
}

void TireCenter::saveCustomers()
{
    std::ofstream file(this->path + "/customers.txt");
    for (auto cust : this->getCustomer())
    {
        std::cout << cust->getName() << std::endl;
        cust->saveData(file);
    }
    file.close();
}

void TireCenter::loadInvoices()
{
    auto invoices = this->getInvoice();

    std::ifstream file(this->path + "/invoices.txt");
    std::string str;
    while (std::getline(file, str) && str != "")
    {
        auto invoice = new Invoice();
        invoice->loadData(file);
        invoice->show();
        invoices.push_back(invoice);
    }
    this->setInvoices(invoices);
    file.close();
}

void TireCenter::saveInvoices()
{
    std::ofstream file(this->path + "/invoices.txt");
    for (auto invoice : this->getInvoice())
    {
        file << "not end" << std::endl;
        invoice->saveData(file);
    }
    file.close();
}

void TireCenter::loadArticles()
{
    std::ifstream file(this->path + "/articles.txt");
    std::string type;
    auto artics = this->getArticles();
    Article *art = nullptr;
    while (std::getline(file, type))
    {
        if (type[0] == 'R')
        {
            art = new Rim();
        }
        else if (type[0] == 'T')
        {
            art = new Tire();
        }
        if (art)
        {
            art->loadData(file);
            art->setType();
            art->show();
            artics.push_back(art);
            art = nullptr;
        }
    }
    this->setArticles(artics);
    file.close();
}

void TireCenter::saveArticles()
{
    std::ofstream file(this->path + "/articles.txt");
    for (auto art : this->getArticles())
    {
        std::cout << art->getName() << std::endl;
        art->saveData(file);
        // delete art;
    }
    file.close();
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

std::vector<Article *> TireCenter::getArticles()
{
    return this->articles;
}

void TireCenter::setArticles(std::vector<Article *> articles)
{
    this->articles = articles;
}

std::vector<Customer *> TireCenter::getCustomer()
{
    return this->customers;
}

void TireCenter::setCustomers(std::vector<Customer *> customers)
{
    this->customers = customers;
}

std::vector<Invoice *> TireCenter::getInvoice()
{
    return this->invoices;
}

void TireCenter::setInvoices(std::vector<Invoice *> invoices)
{
    this->invoices = invoices;
}
