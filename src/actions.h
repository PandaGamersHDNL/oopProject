#pragma once
#include "article.h"
#include "tireCenter.h"
#include "options.h"
#include <string>
#include <vector>

std::vector<Article *> searchArticle(TireCenter &center);

Article *createArticle(TireCenter &center);

void addArticle(TireCenter &center);

void deleteArticle(TireCenter &center);

void changeArticle(TireCenter &center);

std::vector<Customer *> searchCustomer(TireCenter &center, std::string query);

void updateStock(Article *art, int amount, bool absolute = false);

void addCustomer(TireCenter &center);

void deleteCustomer(TireCenter &center);

void changeCustomer(TireCenter &center);

void placeOrder(TireCenter &center);

void checkInvoices(TireCenter &center);

void performAction(TireCenter &center, Options option);
