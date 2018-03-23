#ifndef Container_HPP
#define Container_HPP
#include <string>
#include "Menu.hpp"
#include "Item.hpp"
#include <vector>

/**************************************************************
The container class holds two variables, a vector full of items
and an inventory max value.
*************************************************************/
class Container
{
private:
	std::vector<Item> Inventory;
	const int InventoryMax = 2;

public:
	Container();
	~Container();
	std::vector<Item> getInventory();
	const int getMax();
	void printInventory();
	void addToInventory(Item i);
	Item removeFromInventory(int i);
	int searchInventory(string str);
};

#endif


