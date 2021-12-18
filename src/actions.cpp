#include "actions.h"
#include "rim.h"
#include "tire.h"
#include "options.h"
#include "company.h"
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
      break;
  case 2:
    std::cout << "enter the diameter: ";
    std::cin >> inputInt;
    for (auto article : articles) {
      if (article->getDiameter() == inputInt) {
        found.push_back(article);
      }
    }
    break;
  case 3:
    do {
    std::cout << "enter the article type: T (Tire) or R (Rim) ";
    std::cin >> query;
    } while (query[0] != 'T' && query[0] != 'R');

    for (auto article : articles) {
      if (article->getType() == query[0])
        found.push_back(article);
    }
    break;
  default:
    found = articles;
  }
  return found;
}

Article *createArticle(TireCenter &center) {
  std::string strInput;
  int intInput;
  auto arts = searchArticle(center);
  if (arts.size() != 0) {
    do {
      for (auto art : arts) {
        std::cout << art->getName() << std::endl;
      }
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
  Article *art = nullptr;
  if (intInput == 1) {
    art = new Rim();
  } else if (intInput == 2) {
    art = new Tire();
  }
  if (art) {
    art->addData();
  }
  return art;
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

void updateStock(Article *art, int amount, bool absolute) {
  if (absolute) {
    art->setStock(amount);
  } else {
    art->setStock(art->getStock() + amount);
  }
}

void addCustomer(TireCenter &center) {
  std::string inputStr;
  int inputInt, counter;
  std::cout << "what's the name of the new customer? ";
  std::cin >> inputStr;
  std::cin.ignore();
  auto exist = searchCustomer(center, inputStr);
  if (exist.size() > 0) {
    do {
      counter = 1;
      std::cout << "i found these customers with the same name\n";
      for (auto e : exist) {
        std::cout << counter++ << ". " << e->getName() << std::endl;
      }
      std::cout << "Are you sure you wanna add: " << inputStr
                << " 1. yes 2. no ";
      std::cin >> inputInt;
    } while (inputInt < 1 || inputInt > 2);
    if (inputInt == 2)
      return;
  }

  do {
    // TODO use this to get rid of issues when entering a string (this would
    // create a shit storm cus endl isn't ignored
    std::cout << "is this customer a company? 1. yes 2. no ";
    inputInt = std::cin.get();
    std::cout << inputInt;
    // character value of 1 and 2
  } while (inputInt < 49 || inputInt > 50);
  Customer *cust;
  if (inputInt == 49) {
    cust = new Company();
  } else {
    cust = new Customer();
  }
  cust->setName(inputStr);
  cust->addData();
  auto customers = center.getCustomer();
  customers.push_back(cust);
  center.setCustomers(customers);
}

void deleteCustomer(TireCenter &center) {
  std::string query;

  std::cout << "what is the name of the customer you want to delete? ";
  std::cin >> query;
  std::cout << query;
  auto customers = searchCustomer(center, query);
  if (customers.size() == 0) {
    return;
  }
  int inputInt;
  int counter;
  do {
    counter = 1;
    for (auto cust : customers) {
      std::cout << counter++ << ". " << cust->getName() << std::endl;
    }
    std::cout << "enter a number to select an item to delete. ";
    std::cin >> inputInt;
  } while (inputInt >= counter || inputInt <= 0);
  auto del = customers[--inputInt];
  customers = center.getCustomer();
  counter = 0;
  for (auto art : customers) {
    if (art == del) {
      do {
        del->show();
        std::cout << "Are you sure you wanna delete this? 1. yes 2. no";
        std::cin >> inputInt;
      } while (inputInt != 1 && inputInt != 2);
      if (inputInt == 1) {
        delete art;
        customers.erase(customers.begin() + counter);
        center.setCustomers(customers);
        return;
      } else {
        return;
      }
    }
    counter++;
  }
}

void changeCustomer(TireCenter &center) {
  std::string inputStr;
  std::cout << "Which Customer are you looking to change? ";
  std::cin >> inputStr;

  auto customers = searchCustomer(center, inputStr);
  if (customers.size() == 0) {
    return;
  }
  int counter, inputInt;
  do {
    counter = 1;
    for (auto cust : customers) {
      std::cout << counter++ << ". " << cust->getName() << std::endl;
    }
    std::cout << "select an article to change. ";
    std::cin >> inputInt;
  } while (inputInt < 1 || inputInt >= counter);

  auto change = customers[--inputInt];
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

void placeOrder(TireCenter &center) {
  auto invoice = new Invoice();
  std::string query;
  int count = 0, inputInt = 0;

  std::cout << "Which customer has placed this order? ";
  std::cin >> query;
  auto foundCust = searchCustomer(center, query);
  do {
    count = 1;
    for (auto fc : foundCust) {
      std::cout << count++ << ". " << fc->getName() << std::endl;
    }
    std::cout << "Select the customer. ";
    std::cin >> inputInt;
  } while (inputInt < 1 || inputInt > count);
  invoice->setCustomer(foundCust[--inputInt]->clone());

  std::cout << "how many different articles did they order? ";
  std::cin >> inputInt;
  int length = inputInt;
  auto articles = invoice->getArticles();

  for (int i = 0; i < length; i++) {
    std::cout << "searching article nr: " << i << std::endl;
    auto foundArticles = searchArticle(center);

    do {
      count = 1;
      for (auto fa : foundArticles) {
        std::cout << count++ << ". " << fa->getName() << std::endl;
      }
      std::cout << "Select the article. ";
      std::cin >> inputInt;
    } while (inputInt < 1 || inputInt > count);
    auto selected = foundArticles[--inputInt];
    auto article = selected->clone();
    std::cout << "How many of these did they order? ";
    std::cin >> inputInt;
    updateStock(selected, -inputInt);
    article->setStock(inputInt);
    articles.push_back(article);
  }
  invoice->setArticles(articles);
  // TODO set price and discount
  invoice->setPrice();
  invoice->setDiscount();

  auto invoices = center.getInvoice();
  invoices.push_back(invoice);
  center.setInvoices(invoices);
}

void checkInvoices(TireCenter &center) {
  for (auto invoice : center.getInvoice()) {
    invoice->show();
  }
}

void performAction(TireCenter &center, Options option) {
  // TODO add lookup customer all
  switch (option) {
  case Options::addArt:
    addArticle(center);
    break;
  case Options::deleteArt:
    deleteArticle(center);
    break;
  case Options::changeArt:
    changeArticle(center);
    break;
  case Options::checkInvoice:
    checkInvoices(center);
    break;
  case Options::placeOrder:
    placeOrder(center);
    break;
  case Options::deleteCust:
    deleteCustomer(center);
    break;
  case Options::changeCust:
    changeCustomer(center);
    break;
  case Options::addCust:
    addCustomer(center);
    break;
  case Options::updateStock:
    // TODO
    // search article
    // select article
    // ask for change
    // updateStock();
    break;
  case Options::exit:
    return;
  default:
    break;
  }
}
