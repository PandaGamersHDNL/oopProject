#include "tireCenter.h"
#include "menu.h"
#include "options.h"
#include "rim.h"
#include "tire.h"

#define DATAPATH "C:/Users/panda/Desktop/Classes/oop/project/data"

std::vector<Article*> searchArticle(TireCenter& center, std::string query)
{
	std::vector<Article*> found;
	auto articles = center.getArticles();
	for (auto article : articles)
	{
		if (std::string::npos != article->getName().find(query))
		{
			found.push_back(article);
		}
	}
	/*std::cout << "i found these items:\n";
	for (auto item : found)
	{
		std::cout << item->getName() << std::endl;
	}*/
	return found;
}

Article* createArticle(TireCenter& center)
{
	std::string strInput;
	int intInput;
	std::cout << "What is the name of the new article?";
	std::cin >> strInput;
	if (searchArticle(center, strInput).size() != 0)
	{ 	
		do {
			std::cout << "Are you sure you want to add " << strInput << "?\n 1. yes\n 2. no\n";
			std::cin >> intInput;
		} while (intInput > 2 || intInput < 1);
		if (intInput == 2)
		{
			return nullptr;
		}
	}
	
	do {
		std::cout << "What type 1. rim or 2. tire?";
		std::cin >> intInput;
	} while (intInput > 2 || intInput < 1);
	Article* art = nullptr;
	if (intInput == 1)
	{
		auto rim = new Rim();
		rim->setType('R');
		rim->setName(strInput);
		rim->articleData();
		rim->rimData();
		return rim;
	}
	else if(intInput == 2)
	{
		auto tire = new Tire();
		tire->setType('T');
		tire->setName(strInput);
		tire->articleData();
		tire->tireData();
		return tire;
	}
	return nullptr;
}

void addArticle(TireCenter& center)
{
	auto art = createArticle(center);
	if (art)
	{
		//TODO summary + confirmation
		art->show(); 
		auto articles = center.getArticles();
		articles.push_back(art);
		center.setArticles(articles);
	}
}

void deleteArticle(TireCenter& center)
{
	std::string query;

	std::cout << "what is the name of the article you want to delete? \nenter nothing to get a full list. ";
	std::cin >> query;
	auto articles = searchArticle(center, query);
	if (articles.size() == 0)
	{
		return;
	}
	int inputInt;
	int counter;
	do
	{
		counter = 1;
		for (auto art : articles)
		{
			std::cout << counter++ << ". " << art->getName() << std::endl;
		}
		std::cout << "enter a number to select an item to delete. ";
		std::cin >> inputInt;
	} while (inputInt >= counter || inputInt <= 0);
	auto del = articles[--inputInt];
	articles = center.getArticles();
	counter = 0;
	for (auto art : articles)
	{
		if (art == del)
		{
			do
			{
				del->show();
				std::cout << "Are you sure you wanna delete this? 1. yes 2. no";
				std::cin >> inputInt;
			} while (inputInt != 1 && inputInt != 2);
			if (inputInt == 1)
			{
				delete art;
				articles.erase(articles.begin() + counter);
				center.setArticles(articles);
				return;
			}
			else
			{
				return;
			}
		}
		counter++;
	}
}

void changeArticle(TireCenter& center) {
	std::string inputStr;
	std::cout << "What article are you looking to change? ";
	std::cin >> inputStr;

	auto articles = searchArticle(center, inputStr);
	if (articles.size() == 0)
	{
		return;
	}
	int counter, inputInt;
	do
	{
		counter = 1;
		for (auto art : articles)
		{
			std::cout << counter++  <<". " << art->getName() << std::endl;
		}
		std::cout << "select an article to change. ";
		std::cin >> inputInt;
	} while (inputInt < 1 || inputInt >= counter);

	auto change = articles[--inputInt];
	change->show();
	counter = 1;
	for (auto prop : change->getProperties())
	{
		std::cout << counter++ << ". " << prop << std::endl;
	}
	
	std::cout << "Enter the number of the property you want to change. ";
	std::cin >> inputInt;
	change->changeProperty(--inputInt);
	change->show();
}
void placeOrder();
void checkInvoices();
void updateStock();
void addCustomer();
void deleteCustomer();
void changeCustomer();


void performAction(TireCenter& center,Options option)
{
	switch (option)
	{
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

int main(void)
{
    auto center = TireCenter(DATAPATH);
	auto art = center.getArticles();
	auto beep = new Tire;
	beep->setName("beep");
	art.push_back(beep);
	auto boop = new Rim;
	boop->setName("boop");
	art.push_back(boop);
	center.setArticles(art);
	center.setName("tirecenter");
	center.setAddress("beep street 2");
    //Menu menu;
	// test these: 
	//addArticle(center);
	//deleteArticle(center);
	changeArticle(center);
	center.saveData();
    return 0;
}
