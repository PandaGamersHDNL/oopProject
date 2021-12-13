#include "actions.h"
#include "company.h"
#include "menu.h"
#include "options.h"
#include "rim.h"
#include "tire.h"
#include "tireCenter.h"

#define DATAPATH "C:/Users/panda/Documents/oopProject/data"

void updateStock(Article *art, int amount, bool absolute = false) {
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
  int count = 0, inputInt=0;

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
    std::cout << "Enter the name of article nr: " << i << " ";
    std::cin >> query;
    auto foundArticles = searchArticle(center, query);

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
    updateStock(selected, inputInt);
    article->setStock(inputInt);
    articles.push_back(article);
  }
  //TODO set price and discount
  //invoice->setPrice();
  //invoice->setDiscount();
}
void checkInvoices();

void performAction(TireCenter &center, Options option) {
    //TODO add lookup customer + lookup article(filters)
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
    break;
  case Options::placeOrder:
    break;
  case Options::deleteCust:
    break;
  case Options::changeCust:
    break;
  case Options::addCust:
    break;
  case Options::updateStock:
    break;
  default:
    break;
  }
}

int main(void) {
  auto center = TireCenter(DATAPATH);
  // auto art = center.getArticles();
  // auto beep = new Tire;
  // addCustomer(center);
  // addCustomer(center);
  // deleteCustomer(center);
  //  beep->setName("beep");
  //  beep->setType('T');
  //  art.push_back(beep);
  //  auto boop = new Rim;
  //  boop->setName("boop");
  //  boop->setType('R');
  //  art.push_back(boop);
  //  center.setArticles(art);
  //  std::cout << center.getAddress() << std::endl << center.getName() <<
  //  std::endl << "beep";
  //  Menu menu;
  //   test these:
  //  addArticle(center);
  //  addArticle(center);
  //  deleteArticle(center);
  changeCustomer(center);
  center.saveData();
  return 0;
}
