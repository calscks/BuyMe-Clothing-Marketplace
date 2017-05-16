#pragma once
#ifndef MENU_H
#define MENU_H
class Menu
{
public:
	Menu(){};
	virtual ~Menu(){};
	virtual Menu *getNextMenu(int& choice){return nullptr;};
	virtual void printSelectionText()
	{
		std::cout << selectionText.str();
	};
	virtual void switches(int& choice){};
protected:
	std::stringstream selectionText;
};

class MainMenu : public Menu
{
public:
	MainMenu();
	Menu *getNextMenu(int& choice) override;
};

class OrderPlacementMenu : public Menu
{
public:
	OrderPlacementMenu();
	void switches(int& choice) override;
	Menu *getNextMenu(int& choice) override;
};

class OrderModMenu : public Menu
{
public:
	OrderModMenu();
	Menu *getNextMenu(int& choice) override;
	void switches(int& choice) override;
};

class ViewClothesMenu : public Menu
{
public:
	ViewClothesMenu();
	Menu *getNextMenu(int& choice) override;
	void switches(int& choice) override;

};

class SearchClothesMenu : public Menu
{
public:
	SearchClothesMenu();
	Menu *getNextMenu(int& choice) override;
	void switches(int& choice) override;
};

class ViewOrderMenu : public Menu
{
public:
	ViewOrderMenu();
	Menu *getNextMenu(int& choice) override;
	void switches(int& choice) override;
};
#endif