#pragma once
#ifndef CONTROLS_H
#define CONTROLS_H
#include "LinkedList.h"
#include "Clothes.h"

LinkedList<Clothes>* clothes = new LinkedList<Clothes>;
LinkedList<Clothes>* cart;

inline void validInt(int& in)
{
	while (true)
	{
		if (std::cin >> in)
			break;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

inline void validString(std::string& in)
{
	
}

void selectClothesFromId(const int& id)
{
	
}

#endif
