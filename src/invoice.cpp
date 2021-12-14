#include "invoice.h"
#include "article.h"
#include "customer.h"
#include <iostream>

Customer *Invoice::getCustomer() { return this->customer; }

void Invoice::setCustomer(Customer *customer) { this->customer = customer; }

std::vector<Article *> Invoice::getArticles() { return this->articles; }

void Invoice::setArticles(std::vector<Article *> articles) {
  this->articles = articles;
}

float Invoice::getPrice() { return this->price; }

void Invoice::setPrice() { this->price = calculatePrice(); }

int Invoice::getDiscount() { return this->discount; }

void Invoice::setDiscount() { this->discount = discount; }

void Invoice::show() {
  std::cout << "----------------------Invoice-------------------" << std::endl;
  std::cout << "customer: " << this->getCustomer()->getName();
  std::cout << "-------Articles------" << std::endl;
  for (auto art : this->getArticles()) {
    std::cout << art->getName() << std::endl;
  }
  std::cout << "Price: " << this->getPrice() << std::endl;
  std::cout << "discount: " << this->getDiscount() << std::endl;
  //TODO print payed price?
  std::cout << "---------------------End invoice----------------\n\n\n";
}

void Invoice::saveData() {}

void Invoice::loadData() {}

float Invoice::calculateDiscount() {
  // TODO
  float discount = 0;
  this->getArticles();
  return discount;
}

float Invoice::calculatePrice() {
  float sum = 0.0f;
  auto articles = this->getArticles();
  if (articles.size() > 0) {
    for (auto art : articles) {
      sum += (art->getPrice() * art->getStock());
    }
  }
  return sum;
}
