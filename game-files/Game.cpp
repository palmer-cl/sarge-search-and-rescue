#include "Game.hpp"
#include "InputVer.hpp"
#include<fstream>
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

//Constructor
Game::Game()
{
}

//Destructor
Game::~Game()
{
	//Delete the pointers
	delete Sarge;
	delete Zurg;

	delete SidsBackyard;
	delete SidsHouse;
	delete AndysHouse;
	delete AndysFrontYard;
	delete RoadToPizzaPort;
	delete PizzaPort;
}

/**************************************************************
This is a void function that is run at the start of the game. 
It sets up the pointers for all of the spaces on the map using
constructors. Each space has a north, south, east, and west set
up.
************************************************************/
void Game::setupMap()
{
	//Setup Directions for Sid's Backyard
	SidsBackyard->setAllDirections(nullptr, nullptr, SidsHouse, nullptr);

	//Setup Directions for Sid's House
	SidsHouse->setAllDirections(SidsBackyard, nullptr, AndysHouse, nullptr);

	//Setup Directions for Andy's House
	AndysHouse->setAllDirections(SidsHouse, AndysFrontYard, nullptr, nullptr);

	//Setup Directions for Andy's Front Yard
	AndysFrontYard->setAllDirections(nullptr, RoadToPizzaPort, nullptr, AndysHouse);

	//Setup Directions for Road to Pizza Port
	RoadToPizzaPort->setAllDirections(PizzaPort, nullptr, nullptr, AndysFrontYard);

	//Setup Directions for Pizza Port
	PizzaPort->setAllDirections(nullptr, nullptr, RoadToPizzaPort, nullptr);

}

/**************************************************************
This function is a utility function that sets up the actions for
the whole game. It uses an fstream to read the actions and store
in the proper variables. At the end of the function, the array
 index is incremented at the end and loops. 
************************************************************/
void Game::setupMasterActionList()
{
	std::ifstream fin;
	fin.open("actionlist.txt");
	
	if (fin.fail())
	{
		cout << "Error opening file." << endl;
		return;
	}

	string str;
	int num;
	bool tempBool;
	int arrayLocation = 0;

	while (!fin.eof())
	{
		//Room Name
		std::getline(fin, str);
		masterListofActions[arrayLocation].RoomName = str;
		
		//Menu Prompt
		std::getline(fin, str);
		masterListofActions[arrayLocation].menuDisplay = str;

		//Result Prompt
		std::getline(fin, str);
		masterListofActions[arrayLocation].result = str;

		//IS there an item required for this action
		std::getline(fin, str);
		masterListofActions[arrayLocation].requiresItem = str;

		//Does the user get an item bool.
		fin >> tempBool;
		masterListofActions[arrayLocation].getItem = tempBool;

		//Does the user get a Green Man at this location
		fin >> tempBool;
		masterListofActions[arrayLocation].getGreenMan = tempBool;

		//Does the user get a health bonus at this location
		fin >> num;
		masterListofActions[arrayLocation].HealthPoints = num;

		//Ignore for transition to new line character
		fin.ignore();

		//Item Name
		std::getline(fin, str);
		masterListofActions[arrayLocation].item.setName(str);

		//Item Health Points if applicable
		fin >> num;
		masterListofActions[arrayLocation].item.setHealthAdded(num);

		//Bool to check for the need to battle Zurg
		fin >> tempBool;
		masterListofActions[arrayLocation].battleZurg = tempBool;

		//Ignore for transition to new line character
		fin.ignore();

		arrayLocation++;
	}
	
	
}

/**************************************************************
This function assigns each action to the proper space
based on the name and the space name. 
************************************************************/
void Game::assignMasterActionList()
{
	//Number of available actions is 17
	for (int i=0;i<17;i++)
	{
		Action TempAction = masterListofActions[i];

		if (TempAction.RoomName == "Sid's Backyard")
		{
			SidsBackyard->addToActions(TempAction);
		}
		else if (TempAction.RoomName == "Sid's House")
		{
			SidsHouse->addToActions(TempAction);
		}
		else if (TempAction.RoomName == "Andy's House")
		{
			AndysHouse->addToActions(TempAction);
		}
		else if (TempAction.RoomName == "Andy's Front Yard")
		{
			AndysFrontYard->addToActions(TempAction);
		}
		else if (TempAction.RoomName == "Road to Pizza Port")
		{
			RoadToPizzaPort->addToActions(TempAction);
		}
		else
		{
			PizzaPort->addToActions(TempAction);
		}
	}
}

/**************************************************************
This function is a void function that prints out the map. The map
is located in a text file and is read line by line with an fstream
and printed to the console window. 
************************************************************/
void Game::printMap()
{
	std::ifstream fin;
	string str;
	string filename = "map.txt";

	fin.open(filename.c_str());

	if (fin.fail())
	{
		cout << "Error.";
		return;
	}

	std::getline(fin, str);

	while(!fin.eof())
	{
		
		cout << str << std::endl;
		std::getline(fin, str);
	}

	fin.close();
}

Character* Game::getSarge()
{
	return Sarge;
}

Space* Game::getSidsBackyard()
{
	return SidsBackyard;
}

Space* Game::getSidsHouse()
{
	return SidsHouse;
}

Space* Game::getAndysHouse()
{
	return AndysHouse;
}

Space* Game::getAndysFrontYard()
{
	return AndysFrontYard;
}

Space* Game::getRoadtoPizzaPort()
{
	return RoadToPizzaPort;
}

Space* Game::getPizzaPort()
{
	return PizzaPort;
}

Space* Game::getSargeLocation()
{
	return SargeLocation;
}

/**************************************************************
This function asks for an integer from the user. After it gets the integer,
it stores the action in a temporary action variable, and pops the action
off the stack. The action can still be used because we return it 
from the function. Later in the program, we may have to push it back
onto the stack if prerequistes for an action are not met. 
************************************************************/
Action Game::getAction()
{
	int userchoice;
	Action TempAction;

	//Iterate over the vector and print the options
	for (int v=0;v<getSargeLocation()->getActions().size();v++)
	{
		
		cout << v+1 << ": ";
		cout << SargeLocation->getActions()[v].menuDisplay << endl;

	}

	//Get a seclection from the user, match to the proper action, complete the actions
	//Pop from the available actions.
	cout << endl;
	cout << "Please enter an action you wish to take. " << endl;

	userchoice = gameVerifier.verifyBetweenInc(1, SargeLocation->getActions().size());

	//Store the action to be taken before popping the action off of available actions
	TempAction = SargeLocation->getActions().at(userchoice - 1);

	//Pop off vector
	//Psuedocode is Actions at location -> Erase -> Actions at locations beginning added with user choice

	SargeLocation->removeFromActions(userchoice - 1);

	return TempAction;

}
/**************************************************************
* General overview of Execture Round Function:

*Checks and actions needed in Execute Round Function:
*1. Check if the action requires an item or not
*	- If it does and user has no item, place action back in location and return
*	- If user has item, continue
*2. If a battle is required, execute the battle. 
*3. Display the result of the action
*4. If you get an item:
*	- Check whether bag is full or empty
*	- Take appropriate swap action
*5. If the action warrants a green man, call the green man function.
************************************************************/
void Game::executeAction(Action a)
{
	int actionChoice = 0;
	Character * BattleWinner = 0;

	//Pre Step, Make sure that the action does not require an item
	if (a.requiresItem != "0")
	{
		if (!a.checkIfHaveReqItem(Sarge))
		{
			cout << endl;
			cout << "You do not have the required item for this action." << endl;
			cout << endl;

			//If the action was unable to be executed, place the action back in
			//the list of possible actions
			SargeLocation->addToActions(a);

			return;

		}
	}

	if (a.battleZurg)
	{
		cout << endl;
		cout << "You grab your coin and go towards the crane to use it, but ZURG blocks you in your tracks!" << endl;
		cout << endl;
		cout << "Prepare to battle Zurg!" << endl;
		cout << endl;

		BattleWinner = a.fightZurg(Sarge, Zurg);

		if (BattleWinner->getName() == "Sergeant")
		{
			cout << endl;
			cout<< "You defeated Zurg. You operate the crane machine and rescue 2 ARMY MEN!" << endl;
			cout << endl;
			//Get 2 green man if battle Zurg is successful. 
			a.recGreenMan(Sarge);
			a.recGreenMan(Sarge);
		}

		return;
	}

	//Step 1: Display the result of the action
	cout << endl;
	cout << "Result of your action: ";
	cout << a.result;
	cout << endl;
	
	//Step 2: Move any health or items
	Sarge->editStrengthPoints(a.HealthPoints);

	//Step 3: Update any inventory
	//Step 3.1 - Check if there is an item available
	if (a.getItem)
	{
		//Step 3.2 - Check if the user's backpack is full
		if(Sarge->getBackpack()->getInventory().size() == Sarge->getBackpack()->getMax())
		{
			//Ask if the user wants to swap a backpack item with new item
			cout << "Your backpack is full. Select from the options below:" << endl;
			cout << "1. Leave the item on the floor." << endl;
			cout << "2. Swap item with an item in your inventory. " << endl;
			cout << "Inventory item will be left on the floor." << endl;
			cout << endl;

			actionChoice = gameVerifier.verifyBetweenInc(1, 2);

			switch (actionChoice)
			{
			case 1:
				//If user selects the floor, place the item in the floor container
				SargeLocation->addToFloor(a.item);
				cout << "Item has been left on the floor." << endl;
				cout << endl;

				break;
			case 2:
				//Call the swap function
				SargeLocation->swapInventoryforFloor(Sarge, a.item);
				cout << "Inventory item swapped." << endl;
				cout << endl;

				break;
			}

		}
		else
		{
			//Ask the user if they want to add item or leave item on the floor
			cout << endl;
			cout << "Your backpack has free space. Select from the options below:" << endl;
			cout << "1. Leave the item on the floor." << endl;
			cout << "2. Place item in your inventory. " << endl;
			cout << endl;

			actionChoice = gameVerifier.verifyBetweenInc(1, 2);

			switch (actionChoice)
			{
			case 1:
				//If user selects the floor, place the item in the floor container
				SargeLocation->addToFloor(a.item);
				cout << "Item has been left on the floor." << endl;
				cout << endl;

				break;
			case 2:
				Sarge->getBackpack()->addToInventory(a.item);
				cout << "Item has been placed in your inventory." << endl;
				cout << endl;

				break;
			}

		}
	}

	//If you get a green man, put it in your 'Green Man Pouch'
	if (a.getGreenMan)
	{
		a.recGreenMan(Sarge);
	}
	
	

}

/**************************************************************
This function is a void function that asks the user for a direction and shows
them a map. This function controls all movement within the map.
After getting the char from the user, the function calls moveSarge, which
takes the direction and changes the 'Current Location' pointer. The moveSarge
function will validate that the location chosen is a valid location. 
************************************************************/
void Game::promptAndMoveSarge()
{
	char userDirection;

	cout << endl;
	printMap();
	cout << endl;
	cout << "You are currently at " << getSargeLocation()->getName();
	cout << endl;

	cout << "Please enter a direction for Sarge to move in. Valid direction ";
	cout << "choices are N, S, E, W: ";
	cin >> userDirection;

	userDirection = toupper(userDirection);
	moveSarge(userDirection);

}

//See definition above
void Game::moveSarge(char direction)
{
	while (!(direction == 'N' || direction == 'E' || direction == 'S' || direction == 'W'))
	{
		cout << "Invalid Direction." << endl;
		cout << "Enter N, S, E, or W for a new direction: " << endl;
		cin >> direction;
	}

	while (SargeLocation->getDirection(direction) == nullptr)
	{
		
		
		cout << "No path in that direction, there is now way through." << endl;
		cout << "Enter N, S, E, or W for a new direction." << endl;
		gameVerifier.clearBuffer();
		cin >> direction;
		direction = toupper(direction);
		
	}
			
		SargeLocation = SargeLocation->getDirection(direction);
	
}

/**************************************************************
This function prints the current location of the Seargent. 
************************************************************/
void Game::displayLocation()
{
	cout << endl;
	cout << std::left << std::setw(74) << std::setfill('-') << '-' << endl;
	cout << std::setfill(' ') << std::setw(25) << " " << "Sarge's Current Location:" << std::setw(31) << ' ' << endl;
	cout << std::setfill(' ') << std::setw(30) << " " << SargeLocation->getName() << endl;
	cout << std::left << std::setw(74) << std::setfill('-') << '-' << endl;
	cout << endl;
}

/**************************************************************
This function displays infomration at the start of a round, and asks the user
what they would like to do, the otions include:

1. Action
2. Check the floor for objects.
3. Move to an adjacent location
4. Display current Inventory.
5. Display map.
6. Display current Green Men found.
7. Display your current health points.
8. Exit Game
************************************************************/
void Game::startRound(int &control)
{
	int userChoice = 0;
//	int actionChoice = 0;
	Action chosenAction;

	displayLocation();

	userChoice = locationMenu.getUserIntChoice();
	cout << endl;

	switch (userChoice)
	{

	case 1:
		//Get action execute action
		if (getSargeLocation()->getActions().empty())
		{
			cout << "No more actions available at this location." << endl;
			break;
		}
		
		chosenAction = getAction();
		executeAction(chosenAction);
		cout << endl;
		break;
	case 2:
		SargeLocation->floorOptions(Sarge);
		break;
	case 3:
		promptAndMoveSarge();
		break; 
	case 4:
		Sarge->getBackpack()->printInventory();
		cout << endl;
		break;
	case 5:
		printMap();
		cout << endl;
		break;
	case 6:
		printGreenMenAccum(Sarge);
		break;
	case 7:
		printHealthPoints(Sarge);
		break;
	case 8:
		healSarge(Sarge);
		break;
	case 9:
		control = -1;
		return;
	}

	cout << endl;
	cout << "PRESS ANY KEY TO CONTINUE..." << endl;
	gameVerifier.clearBuffer();
	cin.get();
	return;
	
}

/**************************************************************
This function prints the current amount of green men found.
************************************************************/
void Game::printGreenMenAccum(Character* c)
{
	Sergeant* sPtr = 0;
	sPtr = dynamic_cast<Sergeant*>(c);

	cout << endl;
	cout << "You have accumulated a total of " << sPtr->getNumArmyFound() << " out of 4 green men total!" << endl;
	cout << "Keep looking!" << endl;
	cout << endl;
}

/**************************************************************
This function prints the current health points of the Seargent.
************************************************************/
void Game::printHealthPoints(Character* c)
{
	Sergeant* sPtr = 0;
	sPtr = dynamic_cast<Sergeant*>(c);

	cout << endl;
	cout << "You currently have " << sPtr->getStrengthPts() << " strength points!" << endl;
	cout << endl;

}
/**************************************************************
This function allows the use of healing items for Sarge.
************************************************************/
void Game::healSarge(Character* c)
{
	Sergeant* sPtr = 0;
	sPtr = dynamic_cast<Sergeant*>(c);
	
	//Need to check if the medpack exists in the itempack
	std::vector<Item> inventory = sPtr->getBackpack()->getInventory();

	for (int a = 0; a < inventory.size(); a++)
	{
		if(inventory[a].getName() == "Med Pack")
		{
			//5 Points for now, only healing item is MedPack with 5 points,
			//but can change later.
			sPtr->editStrengthPoints(5);

			//Display action result
			cout << "You have used a Med Pack and gained 5 strength points." << endl;
			return;
		}
	}

	cout << "No useable items." << endl;

	

}

