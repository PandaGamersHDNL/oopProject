#pragma once
#include <string>
#include <vector>
#include "article.h"
#include "customer.h"
#include "invoice.h"

class TireCenter
{
private:
    std::string path;
    std::string name;
    std::string address;
    std::vector<Article*> articles;
    std::vector<Customer> customers;
    std::vector<Invoice> invoices;
public:
    TireCenter(std::string path);
    TireCenter();
    ~TireCenter();

    void loadData(std::string path);
    void saveData();

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
