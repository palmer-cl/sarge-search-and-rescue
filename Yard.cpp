#include "Yard.hpp"

Yard::Yard() : Space()
{
	name = "Yard";
}

Yard::Yard(string str) : Space()
{
	name = str;

}

Yard::~Yard()
{
}

/**************************************************************
This function takes in a char from the user and uses it to
determine which space pointer to return. The function uses a
switch statement.
************************************************************/
Space* Yard::getDirection(char direction)
{
	switch (direction)
	{
	case 'N':
		return this->North;
	case 'E':
		return this->East;
	case 'S':
		return this->South;
	case 'W':
		return this->West;
	}
}


string Yard::getName()
{
	return name;
}

/**************************************************************
This function returns the vector for actions at this location.
************************************************************/
std::vector<Action> Yard::getActions()
{
	return actions;
}

/**************************************************************
This funciton takes an action argument and pushes it
to the vector.
************************************************************/
void Yard::addToActions(Action a)
{
	actions.push_back(a);
}

/**************************************************************
This funciton takes an integer argument and erases the vector
action at that designated index.
************************************************************/
void Yard::removeFromActions(int i)
{
	actions.erase(actions.begin() + i);
}

