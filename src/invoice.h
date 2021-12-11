#pragma once
#include "article.h"
#include "customer.h"
#include <vector>

class Invoice {
private:
  Customer customer;
  std::vector<Article> articles;
  float price;
  int discount;

public:
  virtual ~Invoice() = default;

  Customer getCustomer();
  void setCustomer(Customer customer);

  std::vector<Article> getArticles();
  void setArticles(std::vector<Article>);

  float getPrice();
  void setPrice(float price);

  int getDiscount();
  void setDiscount(int discount);

  float calculateDiscount();
  float calculatePrice();
};
