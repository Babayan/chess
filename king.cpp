#include <iostream>
#include "king.h"
#include "exceptions.h"

#include <cstdlib>

bool King::is_moved() const
{
	return madeMove;
}

void King::set_moved()
{
	madeMove=true;
}

char King::getTar() const //
{
	return 'K';
}
	
std::string King::getName() const
{
	return "King";
}
	
King::King(const int x, const int y, int guyn)
	: figure(x, y, guyn), madeMove(false)
{
}

void King::moveIsPossible(const desk&, const int x, const int y) const
{
	if(!((abs(getX()-x)==1 && getY()==y) || (abs(getY()-y)==1 && getX()==x) || (abs(getX()-x)==1 && abs(getY()-y)==1)))
		throw error("Tagavory chi karox mek vandakic avel trnel");
}
