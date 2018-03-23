#ifndef RANDOMNUM_HPP
#define RANDOMNUM_HPP

#include <ctime>
#include<cstdlib>

/**************************************************************
This class is a random number generator with options for different seeds. The default seed is explained
in a comment below. Methods for this class are defined inline.
*************************************************************/
class RandomGen
{
private:
	int seed;
public:
	RandomGen();
	RandomGen(int);
	RandomGen(double);
	int getSeed();
	int returnRand();
	int returnRandRange(int , int);

};


inline RandomGen::RandomGen()
{
	srand(time(NULL));

}

inline RandomGen::RandomGen(int x)
{
	seed = x;
}

inline RandomGen::RandomGen(double x)
{
	seed = x;
}

inline int RandomGen::getSeed() 
{
	return seed;
}

inline int RandomGen::returnRand()
{
	
	return rand();

}

inline int RandomGen::returnRandRange(int low, int high)
{

	int roll = 0;

		do
		{
			roll = rand();
		} while (roll >= RAND_MAX - RAND_MAX % high);
		roll %= high;
		roll++;


	return roll;
}


#endif 

