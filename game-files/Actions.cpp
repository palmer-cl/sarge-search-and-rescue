#include "Actions.hpp"
#include "Sergeant.hpp"
#include <iostream>

/**************************************************************
This function checks to see if the character inventory has the located
item. The funciton is passed a string to search for in a list of items.
If there is a match, true is returned. 
************************************************************/
bool Action::checkIfHaveReqItem(Character* c)
{

	if (c->getBackpack()->searchInventory(requiresItem) >= 0)
	{
		return true;
	}

	return false;
}

/**************************************************************
This function adds a Green Man to the Character. It takes a character
pointer and casts it to a Sergeant. Then, it calls the Sergeant
member function to increment the local Green Man Number. 
************************************************************/
void Action::recGreenMan(Character* c)
{
	Sergeant* sPtr = 0;
	sPtr = dynamic_cast<Sergeant*>(c);

	sPtr->incNumArmy();
}
/**************************************************************
This function takes two character pointers and creates a
battle between the two characters. There is a while loop that checks
if either character has less than 0 points, and stops the 
battle. 

Function also prints the winner after the battle is complete. The 
funciton then returns a pointer to whoever won.
************************************************************/
Character* Action::fightZurg(Character* S, Character* Z)
{
	Character * P1Ptr = S;
	Character * P2Ptr = Z;
	int roundCounter = 1;
	int P1Attack;
	int P2Attack;



	while (P1Ptr->getStrengthPts() > 0 && P2Ptr->getStrengthPts() > 0)
	{
		std::cout << "*** ROUND NUMBER " << roundCounter << " ***" << std::endl;
		//Attack 1 for Chracter 1
		std::cout << "*** CHARACTER 1 ATTACK ***" << std::endl;
		P1Attack = P1Ptr->attack();
		P2Ptr->defend(P1Attack);
		std::cout << std::endl;
		std::cout << "Input any character to continue battle..." << std::endl;
		std::cin.get();
		std::cout << std::endl;
		//Break out of loop if a player goes below 0 strength points
		if (P2Ptr->getStrengthPts() <= 0)
		{
			break;
		}

		//Attack 2 for Chracter 1
		std::cout << "*** CHARACTER 1 SECOND ATTACK ***" << std::endl;
		P1Attack = P1Ptr->attack();
		P2Ptr->defend(P1Attack);
		std::cout << std::endl;
		std::cout << "Input any character to continue battle..." << std::endl;
		std::cin.get();
		std::cout << std::endl;
		//Break out of loop if a player goes below 0 strength points
		if (P2Ptr->getStrengthPts() <= 0)
		{
			break;
		}

		//Attack 1 for Chracter 2
		std::cout << "*** CHARACTER 2 FIRST ATTACK ***" << std::endl;
		P2Attack = P2Ptr->attack();
		P1Ptr->defend(P2Attack);
		std::cout << std::endl;
		std::cout << "Input any character to continue battle..." << std::endl;
		std::cin.get();
		//Break out of loop if a player goes below 0 strength points
		if (P1Ptr->getStrengthPts() <= 0)
		{
			break;
		}

		//Attack 2 for Chracter 2
		std::cout << "*** CHARACTER 2 SECOND ATTACK ***" << std::endl;
		P2Attack = P2Ptr->attack();
		P1Ptr->defend(P2Attack);
		std::cout << std::endl;
		std::cout << "Input any character to continue battle..." << std::endl;
		std::cin.get();
		//Break out of loop if a player goes below 0 strength points
		if (P1Ptr->getStrengthPts() <= 0)
		{
			break;
		}
		roundCounter++;
		std::cout << std::endl;
	}

	//Print who has won the game
	if (P1Ptr->getStrengthPts() <= 0)
	{
		std::cout << P2Ptr->getName() << " has won the combat." << std::endl;
		return P2Ptr;
	}
	else
	{
		std::cout << P1Ptr->getName() << " has won the combat." << std::endl;
		return P1Ptr;
	}
}
