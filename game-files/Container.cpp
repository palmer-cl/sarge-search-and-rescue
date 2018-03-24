#include "Container.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Container::Container()
{
}

Container::~Container()
{
}

std::vector<Item> Container::getInventory()
{
	return Inventory;
}

const int Container::getMax()
{
	return InventoryMax;
}

/**************************************************************
This function checks if the vector is empty and if not, traverses
the vecotor and prints out the name value. Takes no parameters and 
returns void.
************************************************************/
void Container::printInventory()
{
	if (Inventory.empty())
	{
		cout << "Your inventory is empty." << endl;
		cout << endl;
	}
	else
	{
		cout << "Your inventory contains:" << std::endl;
		for (int v = 0; v < Inventory.size(); v++) {
			cout << v + 1 << ": ";
			cout << Inventory[v].getName() << std::endl;
		}
	}
}

/**************************************************************
This function takes an item argument and adds it to a container
object. Returns void. 
************************************************************/
void Container::addToInventory(Item i)
{
	Inventory.push_back(i);
}
/**************************************************************
This function takes an integer item and and makes a copy of the item
at that index value, then erases that value, but returns it
so it is used. Result: Out of the vector but still able to read
the item after returned. 
************************************************************/
Item Container::removeFromInventory(int i)
{
	Item TempItem = Inventory[i];

	Inventory.erase(Inventory.begin() + i);

	return TempItem;
}

/**************************************************************
This function takes a string and returns the index of the inventory
item with the same name. This is used as part of a search alogirthm
that looks at if what is returned is greater than -1, and if so,
tells us that we have a match.
************************************************************/
int Container::searchInventory(string str)
{
	int retInt = -1;

	for (int i = 0; i < Inventory.size(); i++)
	{
		if (str == Inventory[i].getName())
		{
			retInt = i;
		}


	}

	return retInt;

}
