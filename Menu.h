#pragma once

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <functional>

#define string std::string
#define vector std::vector

//Using vector to store all the Menus
class Menu
{
public:
	class Item;
	typedef std::function<void(Item const*)> callback; //using lambda expression to perform callback mechanism
	class Item
	{
		friend class Menu;
	public:
		Item(string title, callback callback);
	private:
		string title;
		callback item_callback;
	};
	Menu(string title);
	void addItem(Item item);
	void go() const;
private:
	vector<Item> items;
	string title;
};

#undef string
#undef vector

#endif