#pragma once
#include "article.h"
#include "customer.h"
#include <vector>

class Invoice {
private:
  Customer *customer =nullptr;
  std::vector<Article *> articles;
  float price = 0.0f;
  int discount = 0;

  float calculateDiscount();
  float calculatePrice();

public:
  virtual ~Invoice() = default;

  Customer *getCustomer();
  void setCustomer(Customer *customer);

  std::vector<Article *> getArticles();
  void setArticles(std::vector<Article *>);

  float getPrice();
  void setPrice();

  int getDiscount();
  void setDiscount();

  void show();

  void saveData();
  void loadData();
};
