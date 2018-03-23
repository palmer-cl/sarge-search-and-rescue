#include "Item.hpp"

//Constructor
Item::Item()
{
}

//Constructor
Item::Item(string n, int HP)
{
	name = n;
	healthAdded = HP;
}

//Destructor
Item::~Item()
{
}

//Set and get functions
void Item::setName(string str)
{
	name = str;
}

//Set and get functions
void Item::setHealthAdded(int hp)
{
	healthAdded = hp;
}

//Set and get functions
string Item::getName()
{
	return name;
}

//Set and get functions
int Item::getHealthAdded()
{
	return healthAdded;
}
