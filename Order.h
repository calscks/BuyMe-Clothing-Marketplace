#pragma once
#ifndef ORDER_H
#define ORDER_H
#include "LinkedList.h"
#include "Clothes.h"

class Order
{
	int orderId;
	LinkedList<Clothes>* items;
	double totalCost, amtReceived, balReturned;
public:
	class Delivery;
	class Delivery
	{
		std::string name, addr, contact;
	public:
		Delivery(const std::string& name, const std::string& addr, const std::string& contact)
			: name(name),
			  addr(addr),
			  contact(contact)
		{}

		std::string get_name() const
		{
			return name;
		}

		std::string get_addr() const
		{
			return addr;
		}

		std::string get_contact() const
		{
			return contact;
		}

	};
private:
	Delivery delivery;

public:
	Order(int order_id, LinkedList<Clothes>* items, double total_cost, double amt_received, double bal_returned, Delivery delivery)
		: orderId(order_id),
		  items(items),
		  totalCost(total_cost),
		  amtReceived(amt_received),
		  balReturned(bal_returned),
		  delivery(delivery)
	{}


	int order_id() const
	{
		return orderId;
	}

	LinkedList<Clothes>* get_items() const
	{
		return items;
	}

	double total_cost() const
	{
		return totalCost;
	}

	double amt_received() const
	{
		return amtReceived;
	}

	double bal_returned() const
	{
		return balReturned;
	}

	Delivery get_delivery() const
	{
		return delivery;
	}

	void set_delivery(Delivery delivery)
	{
		this->delivery = delivery;
	}
};

inline std::ostream& operator<<(std::ostream& stream, const Order& order){
	std::cout << "Order ID: " << order.order_id() << std::setprecision(2) << std::fixed <<
		"\nTotal cost: " << order.total_cost() <<
		"\nAmount received: " << order.amt_received() <<
		"\nBalance returned: " << order.bal_returned() <<
		"\nDelivery name: " << order.get_delivery().get_name() <<
		"\nDelivery address: " << order.get_delivery().get_addr() <<
		"\nDelivery contact: " << order.get_delivery().get_contact() << std::endl << std::endl;
	std::cout << "This order's item(s): " << std::endl;
	for (auto item = order.get_items()->getFirst(); item; item = item->next)
	{
		std::cout << item->data << std::endl;
	}
	return stream << std::endl;
}
#endif
