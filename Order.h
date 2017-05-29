#pragma once
#ifndef ORDER_H
#define ORDER_H
#include "LinkedList.h"
#include "Clothes.h"

class Order
{
	int orderId;
	LinkedList<Clothes> items;
	float totalCost, amtReceived, balReturned;

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

	Delivery* delivery = nullptr;

public:

	Order(int order_id, const LinkedList<Clothes>& items, float total_cost, float amt_received, float bal_returned)
		: orderId(order_id),
		  items(items),
		  totalCost(total_cost),
		  amtReceived(amt_received),
		  balReturned(bal_returned)
	{}


	Order(int order_id, const LinkedList<Clothes>& items, float total_cost, float amt_received, float bal_returned, Delivery* delivery)
		: orderId(order_id),
		  items(items),
		  totalCost(total_cost),
		  amtReceived(amt_received),
		  balReturned(bal_returned),
		  delivery(delivery)
	{}
};
#endif
