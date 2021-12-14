#include "actions.h"
#include "rim.h"
#include "tire.h"
#include <iostream>

std::vector<Article *> searchArticle(TireCenter &center) {
  int inputInt;
  do {
    std::cout << "select a filter. 1. by name 2. by diameter 3. by article type 4. all";
    std::cin >> inputInt;
  } while (inputInt < 1 || inputInt > 4);

  std::vector<Article *> found;
  auto articles = center.getArticles();
  std::string query;
  switch (inputInt) {
  case 1:
    std::cout << "enter the name: ";
    std::cin >> query;
      for (auto article : articles) {
        if (std::string::npos != article->getName().find(query)) {
          found.push_back(article);
         
        }
      }
    
  case 2:
    std::cout << "enter the diameter: ";
    std::cin >> inputInt;
    for (auto article : articles) {
      if (article->getDiameter() == inputInt) {
        found.push_back(article);
      }
    }
  case 3:
    do {
    std::cout << "enter the article type: T (Tire) or R (Rim) ";
    std::cin >> query;
    } while (query[0] != 'T' && query[0] != 'R');

    for (auto article : articles) {
      if (article->getType() == query[0])
        found.push_back(article);
    }
  default:
    found = articles;
  }
  return found;
}

Article *createArticle(TireCenter &center) {
  std::string strInput;
  int intInput;
  if (searchArticle(center).size() != 0) {
    do {
      std::cout << "Are you sure you want to add " << strInput
                << "?\n 1. yes\n 2. no\n";
      std::cin >> intInput;
    } while (intInput > 2 || intInput < 1);
    if (intInput == 2) {
      return nullptr;
    }
  }

  do {
    std::cout << "What type 1. rim or 2. tire?";
    std::cin >> intInput;
  } while (intInput > 2 || intInput < 1);
  if (intInput == 1) {
    auto rim = new Rim();
    rim->setType();
    rim->setName(strInput);
    rim->articleData();
    rim->rimData();
    return rim;
  } else if (intInput == 2) {
    auto tire = new Tire();
    tire->setType();
    tire->setName(strInput);
    tire->articleData();
    tire->tireData();
    return tire;
  }
  return nullptr;
}

void addArticle(TireCenter &center) {
  auto art = createArticle(center);
  if (art) {
    // TODO summary + confirmation
    art->show();
    auto articles = center.getArticles();
    articles.push_back(art);
    center.setArticles(articles);
  }
}

void deleteArticle(TireCenter &center) {
  std::string query;
  auto articles = searchArticle(center);
  if (articles.size() == 0) {
    return;
  }
  int inputInt;
  int counter;
  do {
    counter = 1;
    for (auto art : articles) {
      std::cout << counter++ << ". " << art->getName() << std::endl;
    }
    std::cout << "enter a number to select an item to delete. ";
    std::cin >> inputInt;
  } while (inputInt >= counter || inputInt <= 0);
  auto del = articles[--inputInt];
  articles = center.getArticles();
  counter = 0;
  for (auto art : articles) {
    if (art == del) {
      do {
        del->show();
        std::cout << "Are you sure you wanna delete this? 1. yes 2. no";
        std::cin >> inputInt;
      } while (inputInt != 1 && inputInt != 2);
      if (inputInt == 1) {
        delete art;
        articles.erase(articles.begin() + counter);
        center.setArticles(articles);
        return;
      } else {
        return;
      }
    }
    counter++;
  }
}

void changeArticle(TireCenter &center) {
  std::string inputStr;
  std::cout << "What article are you looking to change? ";
  std::cin >> inputStr;

  auto articles = searchArticle(center);
  if (articles.size() == 0) {
    return;
  }
  int counter, inputInt;
  do {
    counter = 1;
    for (auto art : articles) {
      std::cout << counter++ << ". " << art->getName() << std::endl;
    }
    std::cout << "select an article to change. ";
    std::cin >> inputInt;
  } while (inputInt < 1 || inputInt >= counter);

  auto change = articles[--inputInt];
  change->show();
  counter = 1;
  for (auto &prop : change->getProperties()) {
    std::cout << counter++ << ". " << prop << std::endl;
  }

  std::cout << "Enter the number of the property you want to change. ";
  std::cin >> inputInt;
  change->changeProperty(--inputInt);
  change->show();
}

std::vector<Customer *> searchCustomer(TireCenter &center, std::string query) {
  auto customers = center.getCustomer();
  std::vector<Customer *> found;

    for (auto customer : customers) {
      if (std::string::npos != customer->getName().find(query)) {
        found.push_back(customer);
      }
    }
    return found;
}
