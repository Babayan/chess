#include <iostream>
#include "king.h"

char King::getTar() const
{
	return 'K';
}
	
std::string King::getName() const
{
	return "King";
}
	
King::King(const int x, const int y, int guyn)
	: figure(x, y, guyn)
{
}

bool King::moveIsPossible(const desk&, const int x, const int y, bool printError) const
{
	if((abs(getX()-x)==1 && getY()==y) || (abs(getY()-y)==1 && getX()==x) || (abs(getX()-x)==1 && abs(getY()-y)==1))
		return true;

	//stex inch vor error@ etqan el chisht chem grel, chnayac harca
	if(printError)
		std::cout<<std::endl<<"Sxal: Tagavory chi karox mek vandakic avel trnel"<<std::endl<<std::endl;
	return false;

}