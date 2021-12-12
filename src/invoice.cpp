#include "invoice.h"
#include "article.h"
#include "customer.h"

Customer Invoice::getCustomer() { return this->customer; }

void Invoice::setCustomer(Customer customer) { this->customer = customer; }

std::vector<Article*> Invoice::getArticles() { return this->articles; }

void Invoice::setArticles(std::vector<Article*> articles) {
  this->articles = articles;
}

float Invoice::getPrice() { return this->price; }

void Invoice::setPrice(float price) { this->price = price; }

int Invoice::getDiscount() { return this->discount; }

void Invoice::setDiscount(int discount) { this->discount = discount; }

float Invoice::calculateDiscount() {
  // TODO
  float discount = 0;
  return discount;
}

float Invoice::calculatePrice() {
  // TODO
  return this->price;
}
