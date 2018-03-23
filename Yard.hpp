#ifndef YARD_HPP
#define YARD_HPP
#include <string>
#include "Space.hpp"
#include "Item.hpp"
#include <vector>
#include "Actions.hpp"

/**************************************************************
Yard is a derived class of the Space class. The yard class contains
a string name, and 2 vectors for holding the items on the floor,
and actions that are available on the 
************************************************************/

class Yard : public Space
{
private:
	string name;
	std::vector<Item> floor;
	std::vector<Action> actions;

public:
	Yard();
	Yard(string str);
	~Yard();
	Space* getDirection(char);
	string getName();
	std::vector<Action> getActions();
	void addToActions(Action a);
	void removeFromActions(int i);

};

#endif


