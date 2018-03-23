#include "House.hpp"

House::House() : Space()
{
	name = "House";
}

House::House(string str) : Space()
{
	name = str;

}

House::~House()
{
}

/**************************************************************
This function takes in a char from the user and uses it to
determine which space pointer to return. The function uses a
switch statement.
************************************************************/
Space* House::getDirection(char direction)
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

string House::getName()
{
	return name;
}

/**************************************************************
This function returns the vector for actions at this location.
************************************************************/
std::vector<Action> House::getActions()
{
	return actions;
}

/**************************************************************
This funciton takes an integer argument and erases the vector
action at that designated index.
************************************************************/
void House::removeFromActions(int i)
{
	actions.erase(actions.begin() + i);
}

/**************************************************************
This funciton takes an action argument and pushes it
to the vector.
************************************************************/
void House::addToActions(Action a)
{
	actions.push_back(a);
}
