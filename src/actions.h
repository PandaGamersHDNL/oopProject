#pragma once
#include "article.h"
#include "tireCenter.h"
#include <string>
#include <vector>

std::vector<Article *> searchArticle(TireCenter &center, std::string query);

Article *createArticle(TireCenter &center);

void addArticle(TireCenter &center);

void deleteArticle(TireCenter &center);

void changeArticle(TireCenter &center);

std::vector<Customer *> searchCustomer(TireCenter &center, std::string query);
