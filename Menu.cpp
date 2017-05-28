#include "stdafx.h"
#include "Menu.h"
#include "LinkedList.h"
#include "Clothes.h"
#include "Order.h"

//i dunno what im doing but it works! oop ftw
std::string outOfBounds = "Selection out of bounds!";

MainMenu::MainMenu()
{
	system("cls");
	selectionText << "Welcome to BuyMe Clothing Marketplace! Please select your choices below.\n\n" <<
		"1. Order Placement\n" <<
		"2. Order Modification and Viewing\n" <<
		"3. Exit\n";
}

Menu* MainMenu::getNextMenu(int& choice)
{
	Menu *nextMenu = nullptr;
	switch (choice)
	{
	case 1:
		nextMenu = new OrderPlacementMenu();
		break;
	case 2:
		nextMenu = new OrderModMenu();
		break;
	case 3:
		exit(0);
	default:
		std::cout << outOfBounds << std::endl;
		break;
	}
	return nextMenu;
}

OrderPlacementMenu::OrderPlacementMenu()
{
	system("cls");
	selectionText << "Order Placement Menu\n\n" <<
		"1. View Clothes\n" <<
		"2. Search Clothes\n" <<
		"3. Select Clothes to Order\n" <<
		"4. Order Cart\n" <<
		"5. Checkout\n" <<
		"6. Back\n";
}


Menu* OrderPlacementMenu::getNextMenu(int& choice)
{
	Menu *nextMenu = nullptr;
	switch (choice)
	{
	case 1:
		nextMenu = new ViewClothesMenu();
		break;
	case 2:
		nextMenu = new SearchClothesMenu();
		break;
	case 6:
		nextMenu = new MainMenu();
		break;
	default:
		switches(choice);
		break;
	}
	return nextMenu;
}

void OrderPlacementMenu::switches(int& choice)
{
	switch (choice)
	{
	case 3:
		//TODO: select clothes and add to cart
	case 4:
		//TODO: cart linkedlist
	case 5:
		//TODO: checkout
	default:
		std::cout << outOfBounds << std::endl;
	}
}

OrderModMenu::OrderModMenu()
{
	system("cls");
	selectionText << "Order Modification Menu\n\n" <<
		"1. View Orders\n" <<
		"2. Modify Orders\n" <<
		"3. Delete Orders\n" <<
		"4. Back\n";
}

Menu* OrderModMenu::getNextMenu(int& choice)
{
	Menu *nextMenu = nullptr;
	switch (choice)
	{
	case 1:
		nextMenu = new ViewOrderMenu();
		break;
	case 4:
		nextMenu = new MainMenu();
		break;
	default:
		switches(choice);
		break;
	}
	return nextMenu;
}

void OrderModMenu::switches(int& choice)
{
	switch (choice)
	{
	case 2:
		//TODO: Select and modify orders
	case 3:
		//TODO: Select and delete orders
	default:
		std::cout << outOfBounds << std::endl;
		break;
	}
}

ViewClothesMenu::ViewClothesMenu()
{
	system("cls");
	selectionText << "View Clothes Menu\n\n" <<
		"1. View all clothes" <<
		"2. View all jeans" <<
		"3. View all shirt" <<
		"4. View all shorts" <<
		"5. View all skirt" <<
		"6. View all slacks" <<
		"7. Move forward and backwards from position..." <<
		"8. Back";
}

Menu* ViewClothesMenu::getNextMenu(int& choice)
{
	Menu *nextMenu = nullptr;
	switch (choice)
	{
	case 8:
		nextMenu = new OrderPlacementMenu();
		break;
	default:
		switches(choice);
		break;
	}
	return nextMenu;
}

void ViewClothesMenu::switches(int& choice)
{
	switch (choice)
	{
	case 1:
		//
	case 2:
		//
	case 3:
		//
	case 4:
		//
	case 5:
		//
	case 6:
		//
	case 7:
		//
	default:
		std::cout << outOfBounds << std::endl;
		break;
	}
}

SearchClothesMenu::SearchClothesMenu()
{
	system("cls");
	selectionText << "Search Clothes Menu\n\n" <<
		"1. Search for clothes ID\n" <<
		"2. Search for type\n" <<
		"3. Search for description\n" <<
		"4. Search for quantity\n" <<
		"5. Search for price\n" <<
		"6. Back\n";
}

Menu* SearchClothesMenu::getNextMenu(int& choice)
{
	Menu* nextMenu = nullptr;
	switch (choice)
	{
	case 6:
		nextMenu = new OrderPlacementMenu();
		break;
	default:
		switches(choice);
		break;
	}

	return nextMenu;
}

void SearchClothesMenu::switches(int& choice)
{
	switch (choice)
	{
	case 1:
		//
	case 2:
		//
	case 3:
		//
	case 4:
		//
	case 5:
		//
	default:
		std::cout << outOfBounds << std::endl;
		break;
	}
}

ViewOrderMenu::ViewOrderMenu()
{
	system("cls");
	selectionText << "View Order Menu\n\n" <<
		"1. View all orders\n" <<
		"2. Select order from ID\n" <<
		"3. Select order from position\n and move forward/backward\n" <<
		"4. Back\n";
}

Menu* ViewOrderMenu::getNextMenu(int& choice)
{
	Menu *nextMenu = nullptr;
	switch (choice)
	{
	case 4:
		nextMenu = new OrderModMenu();
		break;
	default:
		switches(choice);
		break;
	}
	return nextMenu;
}

void ViewOrderMenu::switches(int& choice)
{
	switch (choice)
	{
	case 1:
		//
	case 2:
		//
	case 3:
		//
	default:
		std::cout << outOfBounds << std::endl;
		break;
	}
}
