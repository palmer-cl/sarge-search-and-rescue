#include "Menu.hpp"
#include "InputVer.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

Menu::Menu()
{
}

//This is a function that prints the menu options to the screen.
 void Menu::displayMenu()
{
	cout << endl;
	cout << "Please select an option from the menu below:" << endl;
	cout << "1. Action" << endl;
	cout << "2. Check the floor for objects." << endl;
	cout << "3. Move to an adjacent location" << endl;
	cout << "4. Display current inventory." << endl;
	cout << "5. Display map." << endl;
	cout << "6. Display current Green Men found." << endl;
	cout << "7. Display your current strength points." << endl;
	cout << "8. Use an item." << endl;
	cout << "9. Exit Game" << endl;
	cout << endl;
}

 void Menu::setCharChoice()
{
	//No Char choice for this program
}

int Menu::getUserIntChoice()
{
	displayMenu();
	int x;

	cout << "Enter selection:" << endl;
	cin >> x;

	while (!menuChecker.isBetweenInc(x, 1, 9))
	{
		menuChecker.clearBuffer();

		std::cout << "Invalid menu entry. Please try again." << std::endl;

		std::cin >> x;

	}

	return x;

}
char Menu::getUserCharChoice()
{
//No char
	return '0';
}

