#include "Diner.hpp"

//Constructor
Diner::Diner() : Space()
{
	name = "Diner";
}

Diner::Diner(string str) : Space()
{
	name = str;

}

Diner::~Diner()
{
}
/**************************************************************
This function takes in a char from the user and uses it to 
determine which space pointer to return. The function uses a 
switch statement. 
************************************************************/
Space* Diner::getDirection(char direction)
{
	switch (direction)
	{
	case 'N':
		return this->North;
		break;
	case 'E':
		return this->East;
		break;
	case 'S':
		return this->South;
		break;
	case 'W':
		return this->West;
		break;
	}
	}

string Diner::getName()
{
	return name;
}

/**************************************************************
This function returns the vector for actions at this location.
************************************************************/
std::vector<Action> Diner::getActions()
{
	return actions;
}

/**************************************************************
This funciton takes an integer argument and erases the vector
action at that designated index. 
************************************************************/
void Diner::removeFromActions(int i)
{
	actions.erase(actions.begin() + i);
}

/**************************************************************
This funciton takes an action argument and pushes it
to the vector. 
************************************************************/
void Diner::addToActions(Action a)
{
	actions.push_back(a);
}

