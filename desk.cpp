#include "figure.h"
#include "pawn.h"
#include "knight.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "desk.h"
#include "exceptions.h"
#include <iostream>

using namespace std; //

desk::desk()
{
	for (int i=1; i<=8; i++)
	{
		for (int j=1; j<=8; j++)
		{
        vandak[i][j]=0;
		}
	}
	check=false;

	for(int i = 1; i <= 8; ++i) {
		vandak[i][2] = new Pawn(i, 2, 0);
		vandak[i][7] = new Pawn(i, 7, 1);
	}

	vandak[1][1] = new Rook(1, 1, 0);
	vandak[8][1] = new Rook(8, 1, 0);
	vandak[1][8] = new Rook(1, 8, 1);
	vandak[8][8] = new Rook(8, 8, 1);

	vandak[2][1] = new Knight(2, 1, 0);
	vandak[7][1] = new Knight(7, 1, 0);
	vandak[2][8] = new Knight(2, 8, 1);
	vandak[7][8] = new Knight(7, 8, 1);

	vandak[3][1] = new Bishop(3, 1, 0);
	vandak[6][1] = new Bishop(6, 1, 0);
	vandak[3][8] = new Bishop(3, 8, 1);
	vandak[6][8] = new Bishop(6, 8, 1);

	vandak[4][1] = new Queen(4, 1, 0);
	vandak[4][8] = new Queen(4, 8, 1);

	vandak[5][1] = new King(5, 1, 0);
	vandak[5][8] = new King(5, 8, 1);
}

desk::~desk() {
for(int i=1; i<=8; i++)
	for(int j=1; j<=8; j++)
		if(vandak[i][j])
			delete[] vandak[i][j];
}

bool desk::Check(int guyn)
{
	for(int i=1; i<=8;i++)
		for(int j=1; j<=8; j++)
		{
			if(vandak[i][j]!=0 && vandak[i][j]->getColor()!=guyn) {
				try {
					MoveIsPossible(*vandak[i][j], getKing(guyn)->getX(), getKing(guyn)->getY());
				} catch (error&) {
					continue;
				}
				return true;
			}
		}
		return false;
}

bool desk::ThereIsMove(int color)
{
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			if(getVandak(i, j) && getVandak(i, j)->getColor()==color)
				for(int p=getVandak(i, j)->getX()-2; p<=getVandak(i,j)->getX()+2; p++)
					for(int q=getVandak(i, j)->getY()-2; q<=getVandak(i, j)->getY()+2; q++)
					{
						if (q<1 || q>8 || p<1 ||p >8)
							continue;
						try {
							MoveIsPossible(*getVandak(i, j), p, q);
						} catch (error&) {
							continue;
						}

						try {
							KingIsProtected(*getVandak(i, j), p, q);
						} catch(error&) {
							continue;
						}
						return true;
					}
	return false;
}

void desk::KingIsProtected(figure& qar, const int x, const int y)
{
	//paymanakan katarum enq qayl@
	int x0=qar.getX();
	int y0=qar.getY();
    vandak[x0][y0]=nullptr;

	//stugum enq en vandaky vortex texapoxvum enq qar ka, ete ka hishum enq et qary mi tex
	figure* f(getVandak(x, y));

	qar.setX(x);
	qar.setY(y);
	vandak[x][y]=&qar;

	int guyn=qar.getColor();
	//bolor hakarakordi qareri hamar stugum enq tagavorin utelu hnaravorutyun@
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			if(getVandak(i, j) && (getVandak(i, j)->getColor()!=guyn))
			{
				try {
					MoveIsPossible(*getVandak(i, j), getKing(guyn)->getX(), getKing(guyn)->getY());
				} catch (error&) {
					continue;
				}

				vandak[x][y]=f;
				vandak[x0][y0]=&qar;
				qar.setX(x0);
				qar.setY(y0);
				throw error("Sxal: Hetevyal qaylov duq harvaci tak eq dnum dzer tagavorin");
			}

        vandak[x][y]=f;
		vandak[x0][y0]=&qar;
		qar.setX(x0);
		qar.setY(y0);
}

bool desk::CellIsProtected(const int x, const int y, int guyn) const
{
	for(int i=1; i<=8; i++) {
		for(int j=1; j<=8; j++)
		{
			if(getVandak(i, j) && (getVandak(i, j)->getColor()==guyn)) {
				try {
					MoveIsPossible(*getVandak(i, j), x, y);
				} catch (error&) {
					continue;
				}
				return false;
			}
		}
	}
	return true;
}

void desk::MoveIsPossible(const figure& qar, const int x, const int y) const// stanuma figuran ev nor coord., ete hnaravora qayl@ veradarcnuma true 
{
	if(x<1 ||x>8 ||y<1 ||y>8)
		throw error("Coordinatner@ sxal en");

	if(qar.getX()==x && qar.getY()==y) //Stugum e, ardyoq xaxaqary texapoxvel e.
	{
		throw error("Duq cheq texapoxel xaxaqary");
	}

	qar.moveIsPossible(*this, x, y);

	if (getVandak(x,y)!=0 && getVandak(x,y)->getColor()==getVandak(qar.getX(),qar.getY())->getColor())
	{
		throw error("Texapoxman vandakum duq xaxaqar uneq");
	}
}

bool desk::setCoordinates(figure& qar,const int x,const int y)
{
        vandak[qar.getX()][qar.getY()]=0;

		//lastmove um hishum enq verjin qayl@
		lastmove.coord11=qar.getX();
		lastmove.coord12=qar.getY();
		lastmove.coord21=x;
		lastmove.coord22=y;

		if(qar.getName()=="King") {
			King* k=dynamic_cast<King*> (&qar);
			k->set_moved();
		}

		if(qar.getName()=="Rook") {
			Rook* r=dynamic_cast<Rook*> (&qar);
			r->set_moved();
		}

		qar.setX(x); 
		qar.setY(y);
		vandak[x][y]=&qar;
		return true;
}

bool desk::makeShortCastling(int guyn)
{
	if(Check(guyn))
	{
		cout<<"Duq cheq karox katarel karch rokirovka, qani vor gtnvum eq shaxi tak";
		return false;
	}
	int y(8);
	if(guyn==0)
		y=1;

	if(getVandak(5,y)->getName()=="King" && getVandak(5,y)->getColor()==guyn && getVandak(6,y)==0 && CellIsProtected(6, y, 1-guyn) && getVandak(7,y)==0 && CellIsProtected(7, y, 1-guyn) && getVandak(8, y)!=0 && getVandak(8,y)->getName()=="Rook" && getVandak(8,y)->getColor()==guyn) 
	{
		
		King* k=dynamic_cast<King*> (getVandak(5,y));
		Rook* r=dynamic_cast<Rook*> (getVandak(8,y));
		if (!(k->is_moved() || r->is_moved()))
		{
			vandak[7][y]=getVandak(5,y);
			vandak[5][y]=0;
			vandak[6][y]=getVandak(8,y);
			vandak[8][y]=0;
			getVandak(7,y)->setX(7);
			getVandak(6,y)->setX(6);
			printDesk();
			return true;
		}
	}
	cout<<endl<<"Sxal: Duq cheq karox katarel karch rokirovka"<<endl<<endl;
	return false;
}

bool desk::makeLongCastling(int guyn)
{
	if(Check(guyn)) {
		cout<<"Duq cheq karox katarel karch rokirovka, qani vor gtnvum eq shaxi tak";
		return false;
	}

	int y(8);
	if(guyn==0)
		y=1;

	if(getVandak(5,y)->getName()=="King" && getVandak(5,y)->getColor()==guyn && getVandak(4,y)==0 && CellIsProtected(4, y, 1-guyn) && getVandak(3,y)==0 && CellIsProtected(3, y, 1-guyn) && getVandak(2,y)==0 && CellIsProtected(2, y, 1-guyn) && getVandak(1, y)!=0 && getVandak(1,y)->getName()=="Rook" && getVandak(1,y)->getColor()==guyn) 
	{
		King* k=dynamic_cast<King*> (getVandak(5,y));
		Rook* r=dynamic_cast<Rook*> (getVandak(8,y));

		if (!(k->is_moved() || r->is_moved())) {

			vandak[3][y]=getVandak(5,y);
			vandak[5][y]=0;
			vandak[4][y]=getVandak(1,y);
			vandak[1][y]=0;
			getVandak(3,y)->setX(3);
			getVandak(4,y)->setX(4);
			printDesk();
			return true;
		}
	}
	cout<<endl<<"Sxal: Duq cheq karox katarel karch rokirovka"<<endl<<endl;
	return false;
}

const figure* const desk::getVandak(int x, int y) const
{
	if (vandak[x][y])
	return vandak[x][y];
	else return 0;
}

figure* desk::getVandak(int x, int y)
{
	if (vandak[x][y])
	return vandak[x][y];
	else return 0;
}

figure* desk::getKing(int color)
{
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			if(getVandak(i,j)!=0)
				if(getVandak(i,j)->getName()=="King" && getVandak(i,j)->getColor()==color)
				{
					return getVandak(i,j);
                }
    return 0;
}

tox& desk::getLastMove() const
{
	return lastmove;
}

void desk::pawnReincarnation(int color)
{
	char tar;
	int x(0);
	int y(0);
	for(int i=1; i<=8; i++) {
		if(color==0 && getVandak(i, 8)!=0 && getVandak(i, 8)->getName()=="Pawn") {
			x=i;
			y=8;
			break;
		}
		if(color==1 && getVandak(i, 1)!=0 && getVandak(i, 1)->getName()=="Pawn") {
			x=i;
			y=1; 
			break;
		}
	}
	if(x)
	{	
		cout<<endl<<"Dzer peshkan hasel e taxtaki Yezrin."
		<<endl<<"Mutqagreq 'Q' damai, 'R' navaki, 'B' pxi kam 'N' dziu ayn verapoxelu hamar"<<endl;
		cin>>tar;
//		if (tar!='Q' && tar!='q')
		vandak[x][y]=0;
		if (tar=='Q' || tar=='q')
		{
			vandak[x][y]=new Queen(x, y, color);
		}
		if (tar=='R' || tar=='r')
		{
			vandak[x][y]=new Rook(x, y, color);
		}
		if (tar=='B' || tar=='b')
		{
			vandak[x][y]=new Bishop(x, y, color);
		}
		if (tar=='N' || tar=='n')
		{
			vandak[x][y]=new Knight(x, y, color);
		}
	}
}

void desk::printDesk()
{
	cout<<endl<<"   _________________________________"<<endl;
	for (int j=8; j>=1; j--)
	{
		if(j%2==0)
		{
			cout<<"   |    ****    ****    ****    ****|"<<endl<<" "<<j<<" |";
		}
		else
			cout<<"   |****    ****    ****    ****    |"<<endl<<" "<<j<<" |";
			
		for(int i=1; i<=8; i++)
		{
			if((i+j)%2==0)
				cout<<"*";
			else
				cout<<" ";
			if(vandak[i][j])
			{
				if(vandak[i][j]->getColor()==0)
					cout<<'W';
				else
					cout<<'B';
				cout<<vandak[i][j]->getTar();
			}
			else
			{
				if((i+j)%2==0)
				cout<<"**";
				else
					cout<<"  ";
			}
			if((i+j)%2==0)
				cout<<"*";
			else
				cout<<" ";
		}
		if(j%2==0)
		{
			cout<<"|";
			if(j==6)
				cout<<"      Move Figure:    ex. b1c3";
			if(j==4)
				cout<<"      Long Castling:  O-O-O";
			cout<<endl<<"   |    ****    ****    ****    ****|"<<endl;
		}
		else
		{
			cout<<"|";
			if(j==7)
				cout<<"            GAME COMMANDS";
			if(j==5)
				cout<<"      Short Castling: O-O";
			if(j==3)
				cout<<"      Offer Nichya:   Nichya";


			cout<<endl<<"   |****    ****    ****    ****    |"<<endl;
		}
	}
	cout<<"   _________________________________"<<endl<<endl;
	cout<<"     A   B   C   D   E   F   G   H  "<<endl<<endl;
}