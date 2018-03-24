#ifndef Sergeant_HPP
#define  Sergeant_HPP
#include "character.hpp"
#include <vector>
#include "Container.hpp"

/**************************************************************
Sergeant class is a derived class of the Character class. It has one additional variable
which contains the number of Green Army friends found. Characters all have functions
used for battling. There is one battle in the game in order to recieve 
2 army men, after defeating Zurg. 
*************************************************************/
class Sergeant : public Character
{
private:
	int numArmyFound = 0;

protected:
public:
	Sergeant();
	~Sergeant();
	int attack();
	void defend(int attackPoints);
	int rollAttackDie();
	int rollDefendDie();
	int getStrengthPts();
	std::string getName();
	void moveSarge();
	int getNumArmyFound();
	void incNumArmy();
	Container* getBackpack();
	void editStrengthPoints(int x);


};

#endif

