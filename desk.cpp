#include "figure.h"
#include "pawn.h"
#include "knight.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "desk.h"
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

	vandak[2][1] = new Knight(1, 2, 0);
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

bool desk::Check(int guyn)
{
	for(int i=1; i<=8;i++)
		for(int j=1; j<=8; j++)
		{
			if(vandak[i][j]!=0)
				if((vandak[i][j]->getColor()!=guyn))
					if ((MoveIsPossible(*vandak[i][j], getKing(guyn)->getX(), getKing(guyn)->getY(), false)))
					{
					return true;
					}
		}
		return false;
}

bool desk::ThereIsMove(int color)
{
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			if(getVandak(i,j)!=0 && getVandak(i, j)->getColor()==color)
				for(int p=getVandak(i, j)->getX()-2; p<=getVandak(i,j)->getX()+2; p++)
					for(int q=getVandak(i, j)->getY()-2; q<=getVandak(i, j)->getY()+2; q++)
					{
						if(MoveIsPossible(*getVandak(i, j), p, q, false) && KingIsProtected(*getVandak(i, j), p, q, false))
							
						return true;
					}
	return false;
}

bool desk::KingIsProtected(figure& qar, const int x, const int y, bool printError)
{
	//paymanakan katarum enq qayl@
	int x0=qar.getX();
	int y0=qar.getY();
    vandak[x0][y0]=0;
	vandak[x][y]=&qar;
	qar.setX(x);
	qar.setY(y);
	int guyn=qar.getColor();
	//bolor hakarakordi qareri hamar stugum enq tagavorin utelu hnaravorutyun@
	for(int i=1; i<=8;i++)
		for(int j=1; j<=8; j++)
		{
			if(vandak[i][j]!=0)
				if((vandak[i][j]->getColor()!=guyn))
					if ((MoveIsPossible(*vandak[i][j], getKing(guyn)->getX(), getKing(guyn)->getY(), false)))
				{
					if(printError)
					cout<<endl<<"Sxal: Hetevyal qaylov duq harvaci tak eq dnum dzer tagavorin"<<endl<<endl;

                    vandak[x][y]=0;
					vandak[x0][y0]=&qar;
					qar.setX(x0);
					qar.setY(y0);
					return false;
				}
		}
            vandak[x][y]=0;
			vandak[x0][y0]=&qar;
			qar.setX(x0);
			qar.setY(y0);
			return true;
}

bool desk::MoveIsPossible(const figure& qar, const int x, const int y, bool printError) // stanuma figuran ev nor coord., ete hnaravora qayl@ veradarcnuma true 
{
	bool veradardz=false;

	if(x<1 ||x>8 ||y<1 ||y>8)
		return false;

	if(qar.getX()==x && qar.getY()==y) //Stugum e, ardyoq xaxaqary texapoxvel e.
	{
		if(printError)
			cout<<endl<<"Sxal: Duq cheq texapoxel xaxaqary"<<endl<<endl;
		return false;
	}

	veradardz=qar.moveIsPossible(*this, x, y, printError);

	if (veradardz==true && getVandak(x,y)!=0)
	{
		if (getVandak(x,y)->getColor()==getVandak(qar.getX(),qar.getY())->getColor())
		{
			if(printError)
				cout<<endl<<"Sxal: Texapoxman vandakum duq xaxaqar uneq"<<endl<<endl;
			return false;
		}
		else
		{
			//delete enq anum et x,y ketum gtnvox xaxaqary
		}
	}
	return veradardz;
}

bool desk::setCoordinates(figure& qar,const int x,const int y)
{
        vandak[qar.getX()][qar.getY()]=0;

		//lastmove um hishum enq verjin qayl@
		lastmove.coord11=qar.getX();
		lastmove.coord12=qar.getY();
		lastmove.coord21=x;
		lastmove.coord22=y;

		qar.setX(x); 
		qar.setY(y);
		vandak[x][y]=&qar;
		return true;
}

bool desk::makeShortCastling(int guyn)
{
	cout<<"mtanq makeSHortCastling"<<getVandak(5,1)->getName()<<getVandak(5,1)->getColor()<<getVandak(8,1)->getName();
	if(guyn==0 && getVandak(5,1)->getName()=="King" && getVandak(5,1)->getColor()==0 && getVandak(6,1)==0 && getVandak(7,1)==0 && getVandak(8,1)->getName()=="Rook" && getVandak(8,1)->getColor()==0) 
	{
		cout<<"lala";
		vandak[7][1]=getVandak(5,1);
		vandak[5][1]=0;
		vandak[6][1]=getVandak(8,1);
		vandak[8][1]=0;
		getVandak(7,1)->setX(7);
		getVandak(7,1)->setY(1);
		getVandak(6,1)->setX(6);
		getVandak(6,1)->setY(1);
		printDesk();
		return true;
	}
	if(guyn==1 && getVandak(5,8)->getName()=="King" && getVandak(5,8)->getColor()==1 && getVandak(6,8)==0 && getVandak(7,8)==0 && getVandak(8,8)->getName()=="Rook" && getVandak(8,8)->getColor()==1)
	{
		cout<<"barev azz";
		vandak[7][8]=getVandak(5,8);
		vandak[5][8]=0;
		vandak[6][8]=getVandak(8,8);
		vandak[8][8]=0;
		getVandak(7,8)->setX(7);
		getVandak(7,8)->setY(8);
		getVandak(6,8)->setX(6);
		getVandak(6,8)->setY(8);
		printDesk();
		return true;
	}
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
