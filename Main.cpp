#include "stdafx.h"
#define NOMINMAX
#include "Menu.h"
#include <Windows.h>
#include "LinkedList.h"
#include "Clothes.h"
#include "Order.h"

using MenuItem = Menu::Item;
using Delivery = Order::Delivery;
using namespace std;
using callback = function<void(Node<Order>*)>;

LinkedList<Clothes>* clothesList = new LinkedList<Clothes>();
LinkedList<Clothes>* cart = new LinkedList<Clothes>();
LinkedList<Order>* order = new LinkedList<Order>();

Menu mainMenu = Menu("Main Menu");
Menu orderMenu = Menu("Order Placement Menu");
Menu orderModMenu = Menu("Order Modification Menu");
Menu* viewClothes;

double total_cost = 0.0;

bool confirm();
void menu_setup();
void scene_mainMenu();
void scene_orderMenu();
void scene_orderModMenu();
void scene_viewClothes();
void scene_searchResult();
void scene_clothesMover();
void scene_orderMover();
void scene_cart();
void scene_checkout();
void scene_viewOrder();
void scene_modOrder();
void scene_delOrder();

template <class T> void mover(Node<T>* head_node);
template <>void mover(Node<Clothes>* head_node); //specialization for clothes
void searchClothes(Node<Clothes>* head_node, string searcher);
void modOrder(Node<Order>* head_node, int searcher);
void delOrder(Node<Order>* head_node, int searcher);

void validInt(int& in);
int noGenerator(Node<Order>* tail_node);

void(*scene)() = nullptr; //function pointer of scene,why? because this is so dynamic it always changes whenever i move back and forth

int main()
{
	SetConsoleTitle(_T("BuyMe Clothing Marketplace"));
	clothesList->append(Clothes(100, 5, "Shirt", "Round-necked, short-sleeved, blue", "M", 25.99));
	clothesList->append(Clothes(101, 5, "Jeans", "Skinny-fit", "32", 65.99));
	clothesList->append(Clothes(102, 5, "Skirt", "Short, pleated, pink", "28", 35.99));
	clothesList->append(Clothes(103, 5, "Skirt", "Short, denim, navy-blue", "30", 55.99));
	clothesList->append(Clothes(104, 5, "Slacks", "Slim-fit, navy-blue", "36", 85.99));
	menu_setup();
	scene = &scene_mainMenu;
	while (scene)
	{
		scene();
	}

	return 0;
}

void menu_setup()
{
	/*section: main menu*/
	mainMenu.addItem(MenuItem("Place orders", [](MenuItem const* menu_item)
	{
		scene = &scene_orderMenu;
	}));
	mainMenu.addItem(MenuItem("Modify orders", [](MenuItem const* menu_item)
	{
		scene = &scene_orderModMenu;
	}));

	/*section: order menu*/
	orderMenu.addItem(MenuItem("View clothes", [](MenuItem const* menu_item)
	{
		scene = &scene_viewClothes;
	}));
	orderMenu.addItem(MenuItem("Search for type", [](MenuItem const* menu_item)
	{
		scene = &scene_searchResult;
	}));
	orderMenu.addItem(MenuItem("Move back and forth", [](MenuItem const* menu_item)
	{
		scene = &scene_clothesMover;
	}));
	orderMenu.addItem(MenuItem("Order cart", [](MenuItem const* menu_item)
	{
		scene = &scene_cart;
	}));
	orderMenu.addItem(MenuItem("Checkout", [](MenuItem const* menu_item)
	{
		scene = &scene_checkout;
	}));
	orderMenu.addItem(MenuItem("Back", [](MenuItem const* menu_item)
	{
		scene = &scene_mainMenu;
	}));

	/*section: search clothes menu*/
	orderModMenu.addItem(MenuItem("View orders", [](MenuItem const* menu_item)
	{
		scene = &scene_viewOrder;
	}));
	orderModMenu.addItem(MenuItem("Move back and forth...", [](MenuItem const* menu_item)
	{
		scene = &scene_orderMover;
	}));
	orderModMenu.addItem(MenuItem("Modify orders", [](MenuItem const* menu_item)
	{
		scene = &scene_modOrder;
	}));
	orderModMenu.addItem(MenuItem("Delete orders", [](MenuItem const* menu_item)
	{
		scene = &scene_delOrder;
	}));
	orderModMenu.addItem(MenuItem("Back", [](MenuItem const* menu_item)
	{
		scene = &scene_mainMenu;
	}));
}

void scene_mainMenu()
{
	mainMenu.go();
}

void scene_orderMenu()
{
	orderMenu.go();
}

void scene_orderModMenu()
{
	orderModMenu.go();
}

void scene_viewClothes()
{
	system("cls");

	clothesList->traversePrint([](LinkedList<Clothes>* list)
	{
		list->sort([](double x, double y)
		{
			return y - x; //y - x -> cheapest first, x - y -> expensive first
		});
	});
	system("pause");
	scene = &scene_orderMenu;
}

void scene_searchResult()
{
	system("cls");
	string searcher;
	cout << "Enter search string for the type of clothing: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, searcher);
	searchClothes(clothesList->getFirst(), searcher);
	system("pause");
	scene = &scene_orderMenu;
}

void searchClothes(Node<Clothes>* head_node, string searcher) //ugh. case sensitive.
{
	if (head_node == nullptr)
		cout << "Nothing here" << endl;
	else
	{
		for (; head_node; head_node = head_node->next)
		{
			if (head_node->data.get_clothType().find(searcher) != string::npos) //string::npos means not found
				cout << head_node->data << endl;
		}
	}
}

void scene_clothesMover()
{
	system("cls");
	mover(clothesList->getFirst());
}

void scene_cart()
{
	system("cls");
	for (Node<Clothes>* node = cart->getFirst(); node; node = node->next)
		cout << node->data << endl;
	system("pause");
	scene = &scene_orderMenu;
}

void scene_checkout()
{
	system("cls");
	string name = "", addr = "", cont = "";
	double amt = 0;
	if (cart->getFirst() == nullptr) 
	{
		cout << "Nothing here" << endl;
		system("pause");
		scene = &scene_orderMenu;
		return;
	}

	cout << "Total cost: " << total_cost << endl;
	cout << "Need delivery? Total cost would be " << total_cost + 50.00 << " ";

	if (confirm())
	{
		cout << "Total cost now: " << total_cost + 50.00 << endl;
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter address: ";
		getline(cin, addr);
		cout << "Enter contact: ";
		getline(cin, cont);
		total_cost = total_cost + 50; //now this time is real
	}
	while (true)
	{
		cout << "Please enter the total received: ";
		cin >> amt;
		amt = floor(amt * 100.0) / 100.0; //2 decimal places, round down
		if (amt - total_cost < 0)
		{
			cout << "Too low!" << endl;
		} else
			break;
	}
	double bal = amt - total_cost;
	cout << endl << "Amount received: " << amt << endl;
	cout << "Balance return: " << bal << endl;
	auto delivery = Delivery(name, addr, cont);
	order->append(Order(noGenerator(order->getLast()), new const LinkedList<Clothes>(*cart), total_cost, amt, bal, delivery));
	delete cart; //woohoo
	cart = new LinkedList<Clothes>();

	cout << "Order successful!" << endl;
	system("pause");
	total_cost = 0.00;
	scene = &scene_orderMenu;
}

template <class T>
void mover(Node<T>* head_node)
{
	int choice;
	if (head_node == nullptr)
	{
		cout << "Nothing here" << endl;
		return;
	}
	while (true)
	{
		system("cls");
		cout << head_node->data << endl;
		if (head_node->prev != nullptr)
			cout << "1. Previous\t";
		if (head_node->next != nullptr)
			cout << "2. Next  \t";
		cout << "3. Back" << endl;
		validInt(choice);

		if (choice == 1)
		{
			if (head_node->prev != nullptr)
				head_node = head_node->prev;
		} else if (choice == 2)
		{
			if (head_node->next != nullptr)
				head_node = head_node->next;
		} else if (choice == 3)
		{
			scene = &scene_orderMenu;
			break;
		} else
			cout << "Invalid choice" << endl;
	}
}

template <>
void mover (Node<Clothes>* head_node)
{
	int choice;
	if (head_node == nullptr)
	{
		cout << "Nothing here" << endl;
		return;
	}
	while (true)
	{
		system("cls");
		cout << head_node->data << endl;
		if (head_node->prev != nullptr)
			cout << "1. Previous\t";
		if (head_node->next != nullptr)
			cout << "2. Next  \t";
		cout << "3. Add this to cart  \t" << "4. Back" << endl;
		validInt(choice);

		if (choice == 1)
		{
			if (head_node->prev != nullptr)
				head_node = head_node->prev;
		}
		else if (choice == 2)
		{
			if (head_node->next != nullptr)
				head_node = head_node->next;
		}
		else if (choice == 3)
		{
			int quantity;
			while (true)
			{
				cout << "Enter quantity: ";
				validInt(quantity);
				if (quantity > head_node->data.get_quantity())
					cout << "Not enough stock! Please re-enter quantity: " << endl;
				else if (quantity == 0)
					cout << "What are you doing! Please re-enter quantity: " << endl;
				else
					break;
			}

			auto temp = Clothes(head_node->data); //essentially copying
			temp.set_quantity(quantity);
			temp.set_price(head_node->data.get_price() * quantity);
			total_cost = total_cost + head_node->data.get_price() * quantity;
			cart->append(temp);
			head_node->data.set_quantity(head_node->data.get_quantity() - quantity);
		}
		else if (choice == 4)
		{
			scene = &scene_orderMenu;
			break;
		}
		else
			cout << "Invalid choice" << endl;
	}
}

void scene_viewOrder() //not efficient, but does the job.
{
	system("cls");
	order->traversePrint([](LinkedList<Order>* list)
	{
		for (Node<Order>* i = list->getFirst(); i; i = i->next)
		{
			for (Node<Order>* j = i->next; j; j = j->next)
			{
				if (i->data.get_delivery().get_name() == "" && j->data.get_delivery().get_name() != "")
				{
					auto temp1 = i->data;
					i->data = j->data;
					j->data = temp1;
				}
			}
		}

		for (Node<Order>* i = list->getFirst(); i; i = i->next)
		{
			for (Node<Order>* j = i->next; j; j = j->next)
			{
				if (i->data.get_delivery().get_name() != "" && j->data.get_delivery().get_name() != "")
				{
					if (i->data.total_cost() - j->data.total_cost() > 0)
					{
						auto temp1 = i->data;
						i->data = j->data;
						j->data = temp1;
					}
				}
			}
		}

		for (Node<Order>* i = list->getFirst(); i; i = i->next)
		{
			for (Node<Order>* j = i->next; j; j = j->next)
			{
				if (i->data.get_delivery().get_name() == "" && j->data.get_delivery().get_name() == "")
				{
					if (i->data.total_cost() - j->data.total_cost() > 0)
					{
						auto temp1 = i->data;
						i->data = j->data;
						j->data = temp1;
					}
				}
			}
		}
	});
	system("pause");
	scene = &scene_orderModMenu;
}

void scene_orderMover()
{
	system("cls");
	mover(order->getFirst());
	system("pause");
	scene = &scene_orderModMenu;
}

void scene_modOrder()
{
	int id;
	system("cls");
	cout << "Enter order ID: ";
	validInt(id);
	modOrder(order->getFirst(), id);
	system("pause");
	scene = &scene_orderModMenu;
}

void modOrder(Node<Order>* head_node, int searcher)
{
	if (head_node == nullptr)
		cout << "Nothing here" << endl;
	else
	{
		for (; head_node; head_node = head_node->next)
		{
			if (head_node->data.order_id() == searcher)
			{
				cout << head_node->data << endl;
				break;
			}
		}
		cout << "Edit? ";
		if (confirm())
		{
			if (head_node->data.get_delivery().get_name() == "")
			{
				cout << "Not allowed to edit this one. " << endl;
				return;
			}
			string name, addr, cont;
			cout << "Enter new name." << endl;
			getline(cin, name);
			cout << "Enter new address." << endl;
			getline(cin, addr);
			cout << "Enter new contact." << endl;
			getline(cin, cont);
			head_node->data.set_delivery(Delivery(name, addr, cont));
			cout << "Edit successful!" << endl;
		}
	}
}

void scene_delOrder()
{
	int id;
	system("cls");
	cout << "Enter order ID: ";
	validInt(id);
	delOrder(order->getFirst(), id);
	scene = &scene_orderModMenu;
}

void delOrder(Node<Order>* head_node, int searcher)
{
	if (head_node == nullptr)
		cout << "Nothing here" << endl;
	else
	{
		auto count = 1;
		for (; head_node; head_node = head_node->next)
		{
			if (head_node->data.order_id() == searcher)
			{
				cout << head_node->data << endl;
				cout << "Delete? ";
				if (confirm())
				{
					order->destroy(count);
					cout << "Deleted successful!" << endl;
				}
			}
			count++;
		}
	}
}

void validInt(int& in)
{
	while (true)
	{
		if (cin >> in)
		{
			break;
		}
		cout << "Eh, number please." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer completely
	}
}

bool confirm()
{
	string input;
	cout << "(Y/N)";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input == "Y" || input == "y";
}

int noGenerator(Node<Order>* tail_node)
{
	if (tail_node == nullptr)
		return 100000;
	return tail_node->data.order_id() + 1;
}