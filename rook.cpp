#include "rook.h"
#include "desk.h"

#include <iostream>

char Rook::getTar() const //
{
	return 'R';
}

std::string Rook::getName() const
{
	return "Rook";
}

Rook::Rook(const int x, const int y, int guyn)
	: figure(x, y, guyn)
{
}

bool Rook::moveIsPossible(const desk& d, int x, int y, bool printError) const
{
	if(x==getX())
	{
		int mec=std::max(y, getY());
		int poqr=std::min(y, getY());

		for(int i=poqr+1; i<mec; i++)
			if (d.getVandak(x, i))
			{
				if(printError)
					std::cout<<std::endl<<"Sxal: "<<getName()<<" chi karox karox trnel urish qari vrayov"<<std::endl<<std::endl;
				return false;
			}
			return true;
	}
	else if(y==getY())
		{
			int mec=std::max(x, getX());
			int poqr=std::min(x, getX());;


			for(int i=poqr+1; i<mec; i++)
			if (d.getVandak(i, y))
			{
				if(printError)
					std::cout<<std::endl<<"Sxal: Ladyan chi karox trnel urish qari vrayov"<<std::endl<<std::endl;
				return false;
			}
			return true;
		}
		return false;
}
