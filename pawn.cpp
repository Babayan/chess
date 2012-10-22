#include <iostream>
#include "figure.h"
#include "pawn.h"
#include "desk.h"

#include <cstdlib>

Pawn::Pawn(const int x, const int y, int guyn) //
	: figure(x, y, guyn), specMove(false)
{
}

bool Pawn::moveIsPossible(const desk& d, const int x, const int y, bool printError) const
{
	specMove=false;
    if (getColor()==0) {
        if((d.getVandak(x, y)==0) && (x==getX())) {
            if(y==getY()+1) {
                return true;
            }
            if((y==4) && (getY()==2) && (d.getVandak(x, 3)==0)) {
                return true;
            }
		}

        if((abs(x-getX())==1) && (y-getY()==1)) {
            if((d.getVandak(x, y)!=0)) {
                return true;
                        }
            if((getY()==5) && (d.getLastMove().coord11==d.getLastMove().coord21) && (d.getLastMove().coord11==x) && (d.getLastMove().coord12-2==d.getLastMove().coord22) && (d.getVandak(x, getY())->getName()=="Pawn")) {
                specMove=true;
                return true;
            }
                }
	}
    if (getColor()==1) {
        if((d.getVandak(x, y)==0) && (x==getX())) {
			if(y==getY()-1)
				return true;
			if((y==5) && (getY()==7) && (d.getVandak(x, 6)==0))
				return true;
		}
        if((abs(x-getX())==1) && (y-getY()==-1)) {
            if((d.getVandak(x, y)!=0)) {
                return true;
                        }
            if((getY()==4) && (d.getLastMove().coord11==d.getLastMove().coord21) && (d.getLastMove().coord11==x) && (d.getLastMove().coord12+2==d.getLastMove().coord22) && (d.getVandak(x, getY())->getName()=="Pawn")) {
                specMove=true;
                return true;
            }
        }
	}
    if(printError) {
        std::cout<<std::endl<<"Sxal: Peshkan chi karox aydpes sharjvel"<<std::endl<<std::endl;
    }
	return false;
}
char Pawn::getTar() const
{
	return 'P';
}

std::string Pawn::getName() const
{
	return "Pawn";
}
