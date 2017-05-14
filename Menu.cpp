#include "stdafx.h"
#include "Menu.h"

//i dunno what im doing but it works! oop ftw

MainMenu::MainMenu()
{
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
		system("cls");
		nextMenu = new OrderPlacementMenu();
		break;
	case 2:
		system("cls");
		nextMenu = new OrderModMenu();
		break;
	case 3:
		exit(0);
	default:
		std::cout << "Selection out of bound!" << std::endl;
		break;
	}
	return nextMenu;
}

OrderPlacementMenu::OrderPlacementMenu()
{
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
		system("cls");
		nextMenu = new ViewClothesMenu();
		break;
	case 2:
		system("cls");
		nextMenu = new SearchClothesMenu();
	case 6:
		system("cls");
		nextMenu = new MainMenu();
	default:
		OrderPlacementMenu::switches(choice);
	}
	return nextMenu;
}

void OrderPlacementMenu::switches(int& choice)
{
	
}



