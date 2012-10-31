#include <iostream>
#include "queen.h"
#include "desk.h"
#include "exceptions.h"


char Queen::getTar() const //
{
	return 'Q';
}

std::string Queen::getName() const
{
	return "Queen";
}

Queen::Queen(const int x, const int y, int guyn)
	: figure(x, y, guyn)
{
}

void Queen::moveIsPossible(const desk& d, const int x, const int y) const
{
	if(x==getX())
	{
		int mec=std::max(y, getY());
		int poqr=std::min(y, getY());

		for(int i=poqr+1; i<mec; i++)
			if (d.getVandak(x, i))
			{
				throw error("Queen@ chi karox karox trnel urish qari vrayov");
			}
		return;
	} else if(y==getY()) {
		int mec=std::max(x, getX());
		int poqr=std::min(x, getX());;


		for(int i=poqr+1; i<mec; i++)
			if (d.getVandak(i, y))
			{
				throw error("Queen@ chi karox karox trnel urish qari vrayov");
			}
		return;
	}

    if (x-y==getX()-getY()) {
        int minX = std::min(x, getX());
        int maxX = std::max(x, getX());
        int minY = std::min(y, getY());
        for(int i=minX+1; i<maxX; i++) {
            if(d.getVandak(i, minY + (i - minX)) != 0) {
				throw error("Queen@ chi karox karox trnel urish qari vrayov");
            }
        }
        return;
    } else  if(x+y==getX()+getY()) {
        int minX = std::min(x, getX()); // 2
        int maxX = std::max(x, getX()); // 7
        int maxY = std::max(y, getY()); // 6
        for(int i=minX+1; i<maxX; i++) {
            if(d.getVandak(i, maxY - (i - minX)) != 0) {
				throw error("Queen@ chi karox karox trnel urish qari vrayov");
            }
        }
        return;
    }
	throw error("Queen@ chi karox aydpes sharjvel");
}