#include "tireCenter.h"
#include "article.h"
#include "customer.h"
#include "invoice.h"

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
