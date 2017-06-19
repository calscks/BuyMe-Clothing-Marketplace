#pragma once
#ifndef CLOTHES_H
#define CLOTHES_H
#include <iomanip>

class Clothes
{
	int clothId = 0, quantity = 0;
	std::string clothType, desc, size;
	double price = 0.00;

public:
	Clothes(int cloth_id, int quantity, const std::string& cloth_type, const std::string& desc, const std::string& size, double price)
		: clothId(cloth_id),
		  quantity(quantity),
		  clothType(cloth_type),
		  desc(desc),
		  size(size),
		  price(price)
	{}

	int get_clothId() const
	{
		return clothId;
	}

	int get_quantity() const
	{
		return quantity;
	}

	void set_quantity(int quantity)
	{
		this->quantity = quantity;
	}

	std::string get_clothType() const
	{
		return clothType;
	}

	std::string get_desc() const
	{
		return desc;
	}

	std::string get_size() const
	{
		return size;
	}

	double get_price() const
	{
		return price;
	}

	void set_price(double price)
	{
		this->price = price;
	}
};

inline std::ostream& operator<<(std::ostream& stream, const Clothes& clothes) {
	return stream << "Clothes ID: " << clothes.get_clothId() <<
		"\nClothes Type: " << clothes.get_clothType() <<
		"\nQuantity: " << clothes.get_quantity() <<
		"\nSize: " << clothes.get_size() <<
		"\nDescription: " << clothes.get_desc() <<
		"\nPrice: " << std::setprecision(2) << std::fixed << clothes.get_price() << std::endl;
}
#endif
