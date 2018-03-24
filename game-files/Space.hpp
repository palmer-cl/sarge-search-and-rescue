#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "Menu.hpp"
#include "Actions.hpp"
#include <vector>
#include "Sergeant.hpp"

/**************************************************************
 The space class is the base class for all of the areas in the project.
 It has space class pointers to each direction one would be able to move
and all of the member functions having to do with the space itself, as well
as items that are left on the floor.
*************************************************************/
class Space
{
protected:
	InVer SpaceVerifier;
	Space* North;
	Space* South;
	Space* East;
	Space* West;
	std::vector<Item> floor;

public:
	Space();
	virtual ~Space() = 0;
	virtual Space* getDirection(char) = 0;
	virtual string getName() = 0;
	virtual std::vector<Action> getActions() = 0;
	virtual void addToActions(Action a) = 0;
	virtual void removeFromActions(int i) = 0;
	virtual void swapInventoryforFloor(Character*, Item i);
	virtual void setAllDirections(Space* N, Space* E, Space* S, Space* W);
	virtual void addToFloor(Item i);
	virtual Item removeFromFloor(int i);
	virtual void printFloor();
	virtual void floorOptions(Character *);


};

#endif


