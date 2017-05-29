#pragma once
#ifndef CLOTHES_H
#define CLOTHES_H
class Clothes
{
	int clothId = 0, quantity = 0;
	std::string clothType, desc, size;
	float price = 0.00f;

public:
	Clothes(int cloth_id, int quantity, const std::string& cloth_type, const std::string& desc, const std::string& size, float price)
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

	void set_clothId(int cloth_id)
	{
		clothId = cloth_id;
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

	void set_cloth_type(const std::string& cloth_type)
	{
		clothType = cloth_type;
	}

	std::string get_desc() const
	{
		return desc;
	}

	void set_desc(const std::string& desc)
	{
		this->desc = desc;
	}

	std::string get_size() const
	{
		return size;
	}

	void set_size(const std::string& size)
	{
		this->size = size;
	}

	float get_price() const
	{
		return price;
	}

	void set_price(float price)
	{
		this->price = price;
	}
};
#endif
