#ifndef MENU_HPP
#define MENU_HPP

#include "InputVer.hpp"

/**************************************************************
This class is a generic menu class with input verification and the storing of a 
user choice from the menu.
*************************************************************/

class Menu
{
private:
	int userIntChoice;
	char userCharChoice;
	InVer menuChecker;

public:
	Menu();
	void displayMenu();
	void setCharChoice();
	int getUserIntChoice();
	char getUserCharChoice();

	

};


#endif
