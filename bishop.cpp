#include "bishop.h"
#include "desk.h"

#include <iostream>

char Bishop::getTar() const
{
	return 'B';
}

std::string Bishop::getName() const
{
	return "Bishop";
}

Bishop::Bishop(const int x, const int y, int guyn) //d
	: figure(x, y, guyn)
{
}

bool Bishop::moveIsPossible(const desk& d, int x, int y, bool printError) const
{
	if (x-y==getX()-getY()) {
		int minX = std::min(x, getX());
		int maxX = std::max(x, getX());
		int minY = std::min(y, getY());
		for(int i=minX+1; i<maxX; i++) {
			if(d.getVandak(i, minY + (i - minX)) != 0) {
				if(printError)
					std::cout<<std::endl<<"Sxal: Pixy chi karox trnel urish xaxa vrayov"<<std::endl<<std::endl;
				return false;
			}
		}
	} else  if(x+y==getX()+getY()) {
		int minX = std::min(x, getX()); // 2
		int maxX = std::max(x, getX()); // 7
		int maxY = std::max(y, getY()); // 6
		for(int i=minX+1; i<maxX; i++) {
			if(d.getVandak(i, maxY - (i - minX)) != 0) {
				if(printError)
					std::cout<<std::endl<<"Sxal: Pixy chi karox trnel urish xaxa vrayov"<<std::endl<<std::endl;
				return false;
			}
		}
	}
	if(printError)
		std::cout<<std::endl<<"Sxal: Pixy chi karox aydpes sharjvel"<<std::endl<<std::endl;
	return false;
}