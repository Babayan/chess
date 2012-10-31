#include <iostream>

#include "knight.h"
#include "desk.h"
#include "exceptions.h"

#include <cstdlib>

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

void Knight::moveIsPossible(const desk&, const int x, const int y) const
{
	if(!((abs(x-getX())==1 && abs(y-getY())==2) || (abs(x-getX())==2 && abs(y-getY())==1)))
		throw error("Dzin chi karox aydpes sharjvel");
}
