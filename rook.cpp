#include "rook.h"
#include "desk.h"
#include "exceptions.h"

#include <iostream>

Rook::Rook(const int x, const int y, int guyn)
	: figure(x, y, guyn), madeMove(false)
{
}

bool Rook::is_moved() const
{
	return madeMove;
}

void Rook::set_moved()
{
	madeMove=true;
}

char Rook::getTar() const //
{
	return 'R';
}

std::string Rook::getName() const
{
	return "Rook";
}

void Rook::moveIsPossible(const desk& d, int x, int y) const
{
	if(x==getX())
	{
		int mec=std::max(y, getY());
		int poqr=std::min(y, getY());

		for(int i=poqr+1; i<mec; i++)
			if (d.getVandak(x, i))
			{
				throw error("Navak@ chi karox karox trnel urish qari vrayov");
			}
		return;
	} else if(y==getY()) {
		int mec=std::max(x, getX());
		int poqr=std::min(x, getX());;


		for(int i=poqr+1; i<mec; i++)
		if (d.getVandak(i, y))
		{
			throw error("Navak@ chi karox karox trnel urish qari vrayov");
		}
		return;
	}
	throw error("Navak@ chi karox aydpes sharjvel");
}
