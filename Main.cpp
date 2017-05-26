#include "stdafx.h"
#include "Menu.h"
#include <Windows.h>

void main()
{
	SetConsoleTitle(_T("BuyMe Clothing Marketplace"));
	Menu* currentMenu = new MainMenu();
	while (true)
	{
		currentMenu->printSelectionText();
		auto choice = 0;
		//system("pause >nul");
		std::cin >> choice;
		Menu* p_menu = currentMenu->getNextMenu(choice);
		if (p_menu != nullptr)
		{
			delete currentMenu;
			currentMenu = p_menu;
		}
	}
}
