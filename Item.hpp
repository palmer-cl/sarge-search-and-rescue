#ifndef Item_HPP
#define Item_HPP
#include <string>
#include "Menu.hpp"

/**************************************************************
The item class stores all of the infomration regarding items in the game.
Items have a name and contain an integer if item adds or subtracts
health.
************************************************************/

class Item
{
private:
	string name;
	int healthAdded;

public:
	Item();
	Item(string , int);
	~Item();
	void setName(string);
	void setHealthAdded(int);
	string getName();
	int getHealthAdded();

};

#endif


