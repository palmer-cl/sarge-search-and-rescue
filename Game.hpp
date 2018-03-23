#ifndef GAME_HPP
#define  GAME_HPP
#include "character.hpp"
#include "Sergeant.hpp"
#include "Yard.hpp"
#include "House.hpp"
#include "Zurg.hpp"
#include "Diner.hpp"
#include "Actions.hpp"

/**************************************************************
Game class controls the operation of the game. All key variables such
as the Main characters, rooms, locations, and actions.
*************************************************************/
class Game
{
private:
	//Utility
	InVer gameVerifier;
	Menu locationMenu;

	//Main Characters
	Character* Sarge = new Sergeant;
	Character* Zurg = new ::Zurg;

	//Available Rooms
	Space* SidsBackyard = new Yard("Sid's Backyard");
	Space* SidsHouse = new House("Sid's House");
	Space* AndysHouse = new House("Andy's House");
	Space* AndysFrontYard = new Yard("Andy's Front Yard");
	Space* RoadToPizzaPort = new Yard("Road to Pizza Port");
	Space* PizzaPort = new Diner("Pizza Port");

	//Locations + set default location
	Space* SargeLocation = AndysFrontYard;

	//Actions
	Action masterListofActions[17];
	

protected:
public:
	Game();
	~Game();
	Character* getSarge();
	Space* getSidsBackyard();
	Space* getSidsHouse();
	Space* getAndysHouse();
	Space* getAndysFrontYard();
	Space* getRoadtoPizzaPort();
	Space* getPizzaPort();
	Space* getSargeLocation();
	Action getAction();
	void setupMap();
	void setupMasterActionList();
	void assignMasterActionList();
	void printMap();
	void executeAction(Action a);
	void promptAndMoveSarge();
	void moveSarge(char direction);
	void displayLocation();
	void startRound(int &);
	void printGreenMenAccum(Character* c);
	void printHealthPoints(Character* c);
	void healSarge(Character* c);

	


};


#endif
