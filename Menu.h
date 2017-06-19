#pragma once

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <functional>

#define string std::string
#define vector std::vector //using vector in the menu to push added items to back in the main

//all main menus shall use this
class Menu
{
public:
	class Item;
	typedef std::function<void(Item const*)> callback; //callback again :)
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