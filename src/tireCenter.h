#pragma once
#include <string>
#include <vector>
#include "article.h"
#include "customer.h"
#include "invoice.h"

class TireCenter
{
private:
    std::string name;
    std::string address;
    std::vector<Article*> articles;
    std::vector<Customer> customers;
    std::vector<Invoice> invoices;
public:

    std::string getName();
    void setName(std::string name);

    std::string getAddress();
    void setAddress(std::string address);

    std::vector<Article*> getArticles();
    void setArticles(std::vector<Article*> articles);

    std::vector<Customer> getCustomer();
    void setCustomers(std::vector<Customer> customers);

    std::vector<Invoice> getInvoice();
    void setInvoices(std::vector<Invoice> invoices);
};
