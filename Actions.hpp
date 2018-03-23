#ifndef ACTIONS_HPP
#define  ACTIONS_HPP
#include "Item.hpp"
#include "character.hpp"

/**************************************************************
Actions is a struct that contains all the necessary information 
for actions in the game. Actions are initialized via an included
file. 
*************************************************************/
struct Action
{
	string RoomName;
	string menuDisplay;
	string result;
	string requiresItem;
	bool getItem;
	bool getGreenMan;
	int HealthPoints;
	Item item;
	bool battleZurg;

	bool checkIfHaveReqItem(Character*);
	void recGreenMan(Character*);
	Character * fightZurg(Character* S, Character* Z);
	
	
};

#endif
