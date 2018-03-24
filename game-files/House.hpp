#ifndef HOUSE_HPP
#define HOUSE_HPP
#include <string>
#include "Menu.hpp"
#include "Space.hpp"
#include "Item.hpp"
#include <vector>
#include "Actions.hpp"

/**************************************************************
This class is a derived class of the space class, and has two
vectors, Items and actions. 
************************************************************/
class House : public Space
{
private:
	string name;
	std::vector<Item> floor;
	std::vector<Action> actions;

	
public:
	House();
	House(string str);
	~House();
	Space* getDirection(char);
	string getName();
	std::vector<Action> getActions();
	void addToActions(Action a);
	void removeFromActions(int i);



};

#endif


