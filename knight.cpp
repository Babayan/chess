#include <iostream>

#include "knight.h"
#include "desk.h"

char Knight::getTar() const //
{
	return 'N';
}
	
std::string Knight::getName() const
{
	return "Knight";
}

Knight::Knight(const int x, const int y, int guyn)
	: figure(x, y, guyn)
{
}

bool Knight::moveIsPossible(const desk&, const int x, const int y, bool printError) const
{
	if((abs(x-getX())==1 && abs(y-getY())==2) || (abs(x-getX())==2 && abs(y-getY())==1))
		return true;
	else
	{
		if(printError)
			std::cout<<std::endl<<"Sxal: Dzin chi karox aydpes sharjvel"<<std::endl<<std::endl;
		return false;
	}

}