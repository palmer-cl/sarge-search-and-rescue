#include "InputVer.hpp"
#include<iostream>

InVer::InVer()
{
}

bool InVer::isPos(int x)
{
	if (x > 0)
		return true;
	else
		return false;
}

bool InVer::isPos(double x)
{
	if (x > 0)
		return true;
	else
		return false;
}

bool InVer::isBetween(int target, int low, int high)
{
	if (target > low && target < high)
		return true;
	else
		return false;
}

bool InVer::isBetween(double target, double low, double high)
{
	if (target > low && target < high)
		return true;
	else
		return false;
}

bool InVer::isBetweenInc(int target, int low, int high )
{

	if (target >= low && target <= high)
		return true;
	else
		return false;
}

int InVer::verifyBetweenInc(int l, int h)
{
	int x;

	std::cout << "Please enter a value: ";
	std::cin >> x;

	while (!isBetweenInc(x,l,h))
	{
		clearBuffer();
		std::cout << "Invalid entry. Please enter another value: ";
		std::cin >> x;
	}

	return x;

}

bool InVer::isBetweenInc(double target, double low, double high)
{
	if (target >= low && target <= high)
		return true;
	else
		return false;
}


bool InVer::isUpper(char c)
{
	bool flag = true;

		if ((c < 65) || (c > 90))
			flag = false;


	return flag;

}

bool InVer::isLower(char c)
{
	bool flag = true;

		if (((c < 97) || c >122))
			flag = false;

	return flag;

}
/*
bool InVer::isChar(string s)
{
	bool flag = true;
	char c = 0;

	for (int i = 0; i < s.length() && flag == true; i++)
	{
		c = s.at(i);
		if (!isLower(c) &!isUpper(c))
			flag = false;
	}

	return flag;
}
*/
void InVer::clearBuffer()
{
	std::cin.clear();
	std::cin.ignore(10, '\n');
}