#ifndef INPUTVER_HPP
#define INPUTVER_HPP

#include<string>

using std::string;

/**************************************************************
This class is a generic input verification class. Also has a clear 
buffer functionality. 
*************************************************************/
class InVer
{
private:
public:
	InVer();
	
	bool isPos(int);
	bool isPos(double);
	bool isBetween(int, int, int);
	bool isBetweenInc (int, int, int);
	int verifyBetweenInc(int l, int h);
	bool isBetween(double, double, double);
	bool isBetweenInc(double, double, double);
	bool isUpper(char);
	bool isLower(char);
	bool isChar(string);
	void clearBuffer();


};

	
#endif 
