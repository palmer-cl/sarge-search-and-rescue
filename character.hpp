#ifndef CHARACTER_HPP
#define  CHARACTER_HPP
#include <string>
#include "RandNum.hpp"
#include "Container.hpp"

/**************************************************************
Character class is the base class for all characters in the game from which the
characters with special abilities are derived.
*************************************************************/
class Character
{
private:
protected:
	std::string name;
	int A_numDie = 1;
	int A_numSides = 6;
	int D_numDie = 1;
	int D_numSides = 6;
	int strengthPoints = 10;
	Container backpack;

public:
	Character();
	virtual ~Character() = 0;
	virtual int attack();
	virtual void defend(int attackPoints);
	virtual int rollAttackDie();
	virtual int rollDefendDie();
	virtual int getStrengthPts();
	virtual std::string getName();
	virtual Container* getBackpack() = 0;
	virtual void editStrengthPoints(int x) = 0;
};

#endif

