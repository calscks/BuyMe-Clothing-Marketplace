#pragma once
#ifndef ORDER_H
#define ORDER_H
#include "LinkedList.h"
#include "Clothes.h"

class Order
{
	int orderId;
	const LinkedList<Clothes>* items;
	double totalCost, amtReceived, balReturned;
public:
	class Delivery;
	class Delivery
	{
		friend class Order;
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

		void set_name(std::string& name)
		{
			this->name = name;
		}

		std::string get_addr() const
		{
			return addr;
		}

		void set_addr(std::string& addr)
		{
			this->addr = addr;
		}

		std::string get_contact() const
		{
			return contact;
		}

		void set_contact(std::string& contact)
		{
			this->contact = contact;
		}

	};
private:
	Delivery delivery;

public:
	Order(int order_id, const LinkedList<Clothes>* items, double total_cost, double amt_received, double bal_returned, Delivery delivery)
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

	void set_order_id(int order_id)
	{
		orderId = order_id;
	}

	const LinkedList<Clothes>* get_items() const
	{
		return items;
	}

	void set_items(const LinkedList<Clothes>* items)
	{
		this->items = items;
	}

	double total_cost() const
	{
		return totalCost;
	}

	void set_total_cost(double total_cost)
	{
		totalCost = total_cost;
	}

	double amt_received() const
	{
		return amtReceived;
	}

	void set_amt_received(double amt_received)
	{
		amtReceived = amt_received;
	}

	double bal_returned() const
	{
		return balReturned;
	}

	void set_bal_returned(double bal_returned)
	{
		balReturned = bal_returned;
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
	return stream << "Order ID: " << order.order_id() << std::setprecision(2) << std::fixed <<
		"\nTotal cost: " << order.total_cost() <<
		"\nAmount received: " << order.amt_received() <<
		"\nBalance returned: " << order.bal_returned() <<
		"\nDelivery name: " << order.get_delivery().get_name() <<
		"\nDelivery address: " << order.get_delivery().get_addr() <<
		"\nDelivery contact: " << order.get_delivery().get_contact() << std::endl;
}
#endif
