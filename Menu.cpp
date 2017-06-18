#include "stdafx.h"
#include "menu.h"

#define string std::string
#define vector std::vector

Menu::Item::Item(string title, callback callback)
{
	this->title = title;
	this->item_callback = callback;
}

Menu::Menu(string title)
{
	this->title = title;
	this->items = vector<Item>();
}

void Menu::addItem(Item item)
{
	this->items.push_back(item);
}

//go!
void Menu::go() const
{
	int choice;
	while (true) {
		system("cls");
		std::cout << this->title << std::endl << std::endl;
		for (auto i = 0; i < this->items.size(); i++)
		{
			std::cout << "\t" << i + 1 << ".\t";
			std::cout << this->items.at(i).title << std::endl; //print all "vectored" items added
		}
		std::cout << std::endl;
		std::cout << "Your choice: ";
		std::cin >> choice;
		if (choice > 0 && choice <= this->items.size())
			break;
		std::cout << "Invalid choice." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
	}
	items.at(choice - 1).item_callback(&items.at(choice - 1)); //perform that particular "callback", or in this case activity
}

#undef string
#undef vector