#ifndef Zurg_HPP
#define  Zurg_HPP
#include "character.hpp"

/**************************************************************
Sergeant class is a derived class of the Character class. It has one additional variable
which contains the number of Green Army friends found. Characters all have functions
used for battling. There is one battle in the game to get 2 army men in the crane.
*************************************************************/
class Zurg : public Character
{
private:
protected:
public:
	Zurg();
	~Zurg();
	int attack();
	void defend(int attackPoints);
	int rollAttackDie();
	int rollDefendDie();
	int getStrengthPts();
	std::string getName();
	Container* getBackpack();
	void editStrengthPoints(int x);
};

#endif

