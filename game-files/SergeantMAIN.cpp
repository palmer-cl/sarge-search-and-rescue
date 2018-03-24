#include "character.hpp"
#include <iostream>
#include "Sergeant.hpp"
#include "Yard.hpp"
#include "Game.hpp"
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

/**************************************************************
Main Method Implementation:
Game Setup:
- Map
- Action List
- Assign task to proper spaces

Loop rounds until user loses health or all 4 green men are found.

Display win or loss.
*************************************************************/
int main()
{
	int abortControl = 1;
	Game game;
	game.setupMap();
	game.setupMasterActionList();
	game.assignMasterActionList();
	
	cout << "\tWelcome to The Green Men Rescue by Clarence Palmer!" << endl;
	cout << "\t\tInspired by the Toy Story Movies." << endl;
	cout << endl;
	cout << "Your Goal: Recover all 4 of your fellow Green Army Men lost in the town." << endl;
	cout << endl;
	cout << "Here is a map for your reference:" << endl;
	game.printMap();

	while (game.getSarge()->getStrengthPts() > 0 &&
		dynamic_cast<Sergeant*>(game.getSarge())->getNumArmyFound() < 4 &&
		abortControl >0)
	{
		game.startRound(abortControl);
	}

	//If user wants to abort game
	if (abortControl <0)
	{
		return 0;
	}

	if (game.getSarge()->getStrengthPts()<=0)
	{
		cout << endl;
		cout << std::left << std::setw(74) << std::setfill('-') << '-' << endl;
		cout << std::setfill(' ') << std::setw(25) << " " << "GAME OVER" << std::setw(31) << ' ' << endl;
		cout << std::setfill(' ') << std::setw(15) << " " << "YOU HAVE LOST ALL OF YOUR STRENGTH POINTS" << endl;
		cout << std::left << std::setw(74) << std::setfill('-') << '-' << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << std::left << std::setw(74) << std::setfill('-') << '-' << endl;
		cout << std::setfill(' ') << std::setw(25) << " " << "YOU WIN" << std::setw(31) << ' ' << endl;
		cout << std::setfill(' ') << std::setw(15) << " " << "YOU HAVE FOUND ALL OF YOUR GREEN ARMY MEN" << endl;
		cout << std::left << std::setw(74) << std::setfill('-') << '-' << endl;
		cout << endl;
	}

	cin.ignore();
	cin.get();

	std::cin.get();
	return 0;
}
