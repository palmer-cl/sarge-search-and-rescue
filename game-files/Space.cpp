#include "Space.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

Space::Space()
{
}

Space::~Space()
{
}

/**************************************************************
This is a void function that takes 2 arguments, a character and an item. We need the character
to know where the character is, and we need the item to be able to swap it. 
Function will show the inventory and ask the user which they would like to swap.
Call secondary function to remove inventory from the floor and place it in backpack. 
*************************************************************/
void Space::swapInventoryforFloor(Character* c, Item i)
{
	int swapChoice;

	cout << "Preparing to swap out an inventory item and leave one on the floor." << endl;
	cout << endl;
	cout << "Here are your current inventory items: " << endl;
	c->getBackpack()->printInventory();
	cout << "Select an item to swap out of your inventory: " << endl;
	swapChoice = SpaceVerifier.verifyBetweenInc(1, 2);
	
	//Swapchoice - 1 is the array index to remove.
	c->getBackpack()->removeFromInventory(swapChoice - 1);

	//Add the new item to the character inventory
	c->getBackpack()->addToInventory(i);



}

/**************************************************************
This is a void function that takes 4 arguments, which are all pointers
to other spaces. This function helps orient the map. 
*************************************************************/
void Space::setAllDirections(Space* N, Space* E, Space* S, Space* W)
{
	North = N;
	East = E;
	South = S;
	West = W;
}

/**************************************************************
This is a void function that takes 1 argement, and item. It places this item
in the floor vector.
*************************************************************/
void Space::addToFloor(Item i)
{
	floor.push_back(i);
}

/**************************************************************
This is a void function that takes 1 argement, and integer. It makes 
a copy of the item that is on the floor at that index, erases the 
item from the floor vector, and returns the item for use. 
*************************************************************/
Item Space::removeFromFloor(int i)
{
	Item TempItem = floor[i];

	floor.erase(floor.begin() + i);

	return TempItem;
}

/**************************************************************
This is function iterates thruogh the floor vector and prints the names
of the items on the floor.
*************************************************************/
void Space::printFloor()
{

	for(int i=0;i<floor.size();i++)
	{
		cout << i + 1 << ": " << floor[i].getName() << endl;
	}
	cout << endl;
}

/**************************************************************
This is function takes a character parameter for item swapping. The function
works through the logic of checking whether there is space to hold the new item
or an item must be swapped out. The function then calls other helper functions
to perform the swapping.
*************************************************************/
void Space::floorOptions(Character * c)
{
	int userChoice;
	int indexItemWanted;
	int indexBackpackRemove;
	Item TempItem;
	
	if (floor.empty())
	{
		cout << "Floor is empty." << endl;
	}
	else
	{
		cout << endl;
		cout << "Current items on the floor here: " << endl;
		printFloor();
		
		cout << "Press 1 to take something off the floor, or 2 to leave the items." << endl;
		userChoice = SpaceVerifier.verifyBetweenInc(1, 2);

		switch (userChoice)
		{
		case 1:
			cout << "Which item do you want: " << endl;
			printFloor();

			indexItemWanted = SpaceVerifier.verifyBetweenInc(1, floor.size());
			indexItemWanted -= 1;

			/**************************************************
			 * If backpack is full, swap the items
			 * If backpack has space, add the item to backpack
			 *************************************************/

			//Backpack is full
			if (c->getBackpack()->getInventory().size() == c->getBackpack()->getMax())
			{
				cout << "Your backpack is full. You need to swap an item out of your backpack." << endl;
				indexBackpackRemove = SpaceVerifier.verifyBetweenInc(1, 2);
				indexBackpackRemove -= 1; //This will get us the array index.

				//Remove an item and then add an item from the floor
				c->getBackpack()->removeFromInventory(indexBackpackRemove);
			}

			//Free space open
			TempItem = floor[indexItemWanted];

			//Add Item to backpack
			c->getBackpack()->addToInventory(TempItem);

			//Remove item from the floor
			floor.erase(floor.begin() + indexItemWanted);
		
			break;

		case 2:
			cout << endl;
			cout << "Items left on ground." << endl;
			break;
		}


		

	}

	


}

