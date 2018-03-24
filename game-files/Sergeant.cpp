#include "Sergeant.hpp"
#include <iostream>

/**************************************************************
Default constructor that sets the name of the character for printing and
also sets the die, armor, and strength points.
*************************************************************/
Sergeant::Sergeant() : Character()
{
	name = "Sergeant";

}

/**************************************************************
Default destructor
*************************************************************/
Sergeant::~Sergeant()
{
}

/**************************************************************
This is the attack function. The attack function returns an int based
on a roll of the die. Die roll function is explained below.
This function also prints who is attacking and what their die roll
returned.

Special abilities of this attack function:
*************************************************************/
int Sergeant::attack()
{
	int attackPoints = rollAttackDie();
	std::cout << "Attack was made by " << this->name << "." << std::endl;
	std::cout << "Attacker die roll is: " << attackPoints << std::endl;

	
	return attackPoints;

}

/**************************************************************
This is the defending function. The defending function is void and takes
a parameter of int from the attacking player. The function rolls a die
and then determines how much of the attackers points actually will cause damange
based on armor. The function prints this information and also adjusts the
strength points accordingly.



*************************************************************/

void Sergeant::defend(int attackPoints)
{
	
	int defendingRoll = rollDefendDie();
	int AttackAfterDefense = attackPoints - defendingRoll;
	
	std::cout << "Defender is " << this->name << "." << std::endl;
	std::cout << "Defender die roll is: " << defendingRoll << std::endl;

	if(AttackAfterDefense <= 0)
	{
		std::cout << "Defending character blocked all attacks. No strength points deducted." << std::endl;
		std::cout << "Defending character actual damage inflicted: 0" << std::endl;

	}

	else
	{
		std::cout << "Defending character will take " << AttackAfterDefense << " points of damage."<< std::endl;
		
		strengthPoints -= AttackAfterDefense;

		std::cout << "Defending character has " << strengthPoints << " strength points remaining." << std::endl;


	}

}
/**************************************************************
Note: I realised my own RandomNum generator was implementing a bias in its choices,
so I used a different formula for the random number found here.

Source: https://stackoverflow.com/questions/10984974/why-do-people-say-there-is-modulo-bias-when-using-a-random-number-generator

Attack Die seeds the rand function, but Defend only calls it. These functions then add
rolls together depending on how many die there are and returns that number to the calling
function
*************************************************************/
int Sergeant::rollAttackDie()
{
	int totalRoll = 0;
	int roll = 0;
	srand(time(NULL));

	for (int j=0;j<A_numDie;j++)
	{
		do
		{
			roll = rand();
		} while (roll >= RAND_MAX - RAND_MAX % A_numSides);
		roll %= A_numSides;
		roll++;

		totalRoll += roll;

	}
	return totalRoll;
}

int Sergeant::rollDefendDie()
{
	int totalRoll = 0;
	int roll = 0;

	for (int j = 0; j<D_numDie; j++)
	{
		do
		{
			roll = rand();
		} while (roll >= RAND_MAX - RAND_MAX % D_numSides);
		roll %= D_numSides;
		roll++;

		totalRoll += roll;

	}
	return totalRoll;
}

//Set and get functions
int Sergeant::getStrengthPts()
{
	return strengthPoints;
}

//Set and get functions
std::string Sergeant::getName()
{
	return name;
}

//Set and get functions
int Sergeant::getNumArmyFound()
{
	return numArmyFound;
}
//Increases the vairable numArmyFound
void Sergeant::incNumArmy()
{
	numArmyFound++;
}

//Returns the address of backpack to make edits within the program
Container* Sergeant::getBackpack()
{
	return &backpack;
}

//Adds or removes strength points throughout the program
void Sergeant::editStrengthPoints(int x)
{
	strengthPoints += x;
}

