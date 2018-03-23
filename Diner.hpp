#ifndef DINER_HPP
#define DINER_HPP
#include <string>
#include "Menu.hpp"
#include "Space.hpp"
#include "Container.hpp"
#include "Actions.hpp"

/**************************************************************
This class is a derived class of the space class, and has two
vectors, items and actions. 
************************************************************/
class Diner : public Space
{
private:
	string name;
	std::vector<Item> floor;
	std::vector<Action> actions;


public:
	Diner();
	Diner(string str);
	~Diner();
	Space* getDirection(char);
	string getName();
	std::vector<Action> getActions();
	void addToActions(Action a);
	void removeFromActions(int i);



};

#endif


#pragma once
