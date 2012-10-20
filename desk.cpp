#include "figure.h"
#include "desk.h"
#include <iostream>

using namespace std;

desk::desk()
{
	for (int i=1; i<=8; i++)
	{
		for (int j=1; j<=8; j++)
		{
		vandak[i][j]=nullptr;
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

bool desk::PawnMoveIsPossible(const figure& qar, const int x, const int y, bool printError)
{
	if (qar.getColor()==0)
	{
		if((vandak[x][y]!=0) & (abs(x-qar.getX())==1))
		{
				
			if(y-qar.getY()==1)
				return true;
			if((x==qar.getX() && x==5) && (getVandak(x,y)->lastycoord==7))
				return true;
		}
		if((vandak[x][y]==0) & (x==qar.getX()))
		{
			if(y==qar.getY()+1)
				return true;
			if((y==4) & (qar.getY()==2))
				return true;
		}
		if((qar.getY()==5) & (abs(qar.getX()-x)==1) & (lastmove.coord11==lastmove.coord21) & (lastmove.coord11==x) & (lastmove.coord12-2==lastmove.coord22))
		{
			vandak[x][y-1]=0;
			return true;
		}
	}
	if (qar.getColor()==1)
	{
		if((vandak[x][y]!=0) & (abs(x-qar.getX())==1))
		{
			if(y-qar.getY()==-1)
				return true;
			if(x==qar.getX() && x==4 && getVandak(x,y)->lastycoord==2)
				return true;
		}
		if(vandak[x][y]==0 && x==qar.getX())
		{
			if(y==qar.getY()-1)
				return true;
			if(y==5 && qar.getY()==7)
				return true;
		}
		if(qar.getY()==4 && abs(qar.getX()-x)==1 && lastmove.coord11==lastmove.coord21 && lastmove.coord11==x && lastmove.coord12+2==lastmove.coord22)
		{
			vandak[x][y+1]=0;
			return true;
		}
	}
	if(printError)
		cout<<endl<<"Sxal: Peshkan chi karox aydpes sharjvel"<<endl<<endl;
	return false;
}

bool desk::RookMoveIsPossible(const figure& qar, const int x, const int y, bool printError)
{
	if(x==qar.getX())
	{
		int mec;
		int poqr;

		if (y>qar.getY())
		{
			poqr=qar.getY();
			mec=y;
		}
		else  
		{
			poqr=y;
			mec=qar.getY();
		}

		if (mec-poqr>1)
		{

			for(int i=poqr+1; i<mec; i++)
				if (vandak[x][i])
				{
					if(printError)
						cout<<endl<<"Sxal: Ladyan chi karox karox trnel urish qari vrayov"<<endl<<endl;
					return false;
				}
				return true;
		}
	}

	else if(y==qar.getY())
		{
			int mec;
			int poqr;

			if (x>qar.getX())
			{
				poqr=qar.getX();
				mec=x;
			}
			else  
			{
				poqr=x;
				mec=qar.getX();
			}

			if (mec-poqr>1)
			{
				for(int i=poqr+1; i<mec; i++)
				if (vandak[i][y])
				{
					if(printError)
						cout<<endl<<"Sxal: Ladyan chi karox trnel urish qari vrayov"<<endl<<endl;
					return false;
				}
				return true;
			}
		}  
	else
		return false;
};

bool desk::KnightMoveIsPossible(const figure& qar, const int x, const int y, bool printError)
{
	if((abs(x-qar.getX())==1 && abs(y-qar.getY())==2) || (abs(x-qar.getX())==2 && abs(y-qar.getY())==1))
		return true;
	else
	{
		if(printError)
			cout<<endl<<"Sxal: Dzin chi karox aydpes sharjvel"<<endl<<endl;
		return false;
	}

}

bool desk::BishopMoveIsPossible(const figure& qar, const int x, const int y, bool printError)
{
	bool flag=true;
	if (x-y==qar.getX()-qar.getY() || x+y==qar.getX()+qar.getY())
	{
		//flag=true;
		if (abs(x-qar.getX())>1)
		{
			if (x<qar.getX() && y<qar.getY())
				for(int i=x+1; i<=qar.getX()-1; i++)
					for(int j=y+1; j<=qar.getY()-1; j++)
						if(vandak[i][j]!=0 && i-j==x-y)
						{
							if(printError)
								cout<<endl<<"Sxal: Pixy chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};
			if (x>qar.getX() && y>qar.getY())
				for(int i=qar.getX()+1; i<=x-1; i++)
					for(int j=qar.getY()+1; j<=y-1; j++)
						if(vandak[i][j]!=0 && i-j==x-y)
						{
							if(printError)
								cout<<endl<<"Sxal: Pixy chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};
			if (x>qar.getX() && y<qar.getY())
				for(int i=qar.getX()+1; i<=x-1; i++)
					for(int j=y+1; j<=qar.getY()-1; j++)
						if(vandak[i][j]!=0 && i+j==x+y)
						{
							if(printError)
								cout<<endl<<"Sxal: Pixy chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};
			if (x<qar.getX() && y>qar.getY())
				for(int i=x+1; i<=qar.getX()-1; i++)
					for(int j=qar.getY()+1; j<=y-1; j++)
						if(vandak[i][j]!=0 && i+j==x+y)
						{
							if(printError)
								cout<<endl<<"Sxal: Pixy chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};


		}
	}

	else
		{
			if(printError)
				cout<<endl<<"Sxal: Pixy chi karox aydpes sharjvel"<<endl<<endl;
			return false;
		}
	return flag;
}

bool desk::QueenMoveIsPossible(const figure& qar, const int x, const int y, bool printError)
{
	bool flag=false;
	//ete ankyunagceri vraya verjnakan kety
	if (x-y==qar.getX()-qar.getY() || x+y==qar.getX()+qar.getY())
	{
		flag=true;
		//ete aranqum gone mi vandak ka
		if (abs(x-qar.getX())>1)
		{
			if (x<qar.getX() && y<qar.getY())
				for(int i=x+1; i<=qar.getX()-1; i++)
					for(int j=y+1; j<=qar.getY()-1; j++)
						if(vandak[i][j]!=0 && i-j==x-y)
						{
							if(printError)
								cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};
			if ((x>qar.getX()) && (y>qar.getY()))
				for(int i=qar.getX()+1; i<=x-1; i++)
					for(int j=qar.getY()+1; j<=y-1; j++)
						if(vandak[i][j]!=0 && i-j==x-y)
						{
							if(printError)
								cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};
			if (x>qar.getX() && y<qar.getY())
				for(int i=qar.getX()+1; i<=x-1; i++)
					for(int j=y+1; j<=qar.getY()-1; j++)
						if(vandak[i][j]!=0 && i+j==x+y)
						{
							if(printError)
								cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};
			if (x<qar.getX() && y>qar.getY())
				for(int i=x+1; i<=qar.getX()-1; i++)
					for(int j=qar.getY()+1; j<=y-1; j++)
						if(vandak[i][j]!=0 && i+j==x+y)
						{
							if(printError)
								cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
							return false;
						};


		}
	}

	if(x==qar.getX())
	{
		flag=true;
		int mec;
		int poqr;

		if (y>qar.getY())
		{
			poqr=qar.getY();
			mec=y;
		}
		else  
		{
			poqr=y;
			mec=qar.getY();
		}

		if (mec-poqr>1)
		{

			for(int i=poqr+1; i<mec; i++)
				if (vandak[x][i])
				{
					if(printError)
						cout<<endl<<"Sxal: Taguhin chi karox trnel urish qari vrayov"<<endl<<endl;
					return false;
				}
				return true;
		}
	}

	else if(y==qar.getY())
		{
			flag=true;
			int mec;
			int poqr;

			if (x>qar.getX())
			{
				poqr=qar.getX();
				mec=x;
			}
			else  
			{
				poqr=x;
				mec=qar.getX();
			}

			if (mec-poqr>1)
			{
				for(int i=poqr+1; i<mec; i++)
				if (vandak[i][y])
				{
					if(printError)
						cout<<endl<<"Sxal qayl: Taguhin chi karox trnel urish qari vrayov"<<endl<<endl;
					return false;
				}
				return true;
			}
		}  
	return flag;
}

bool desk::KingMoveIsPossible(const figure& qar, const int x, const int y, bool printError)
{
	if((abs(qar.getX()-x)==1 && qar.getY()==y) || (abs(qar.getY()-y)==1 && qar.getX()==x) || (abs(qar.getX()-x)==1 && abs(qar.getY()-y)==1))
		return true;
	else
	{
		//stex inch vor error@ etqan el chisht chem grel, chnayac harca
		if(printError)
			cout<<endl<<"Sxal: Tagavory chi karox mek vandakic avel trnel"<<endl<<endl;
		return false;
	}
};

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
	vandak[x0][y0]=nullptr;
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

					vandak[x][y]=nullptr;
					vandak[x0][y0]=&qar;
					qar.setX(x0);
					qar.setY(y0);
					return false;
				}
		}
			vandak[x][y]=nullptr;
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

	if(qar.getName()=="Pawn")
	{
		if(PawnMoveIsPossible(qar, x, y, printError))
		{
		veradardz=true;
		}
	}
	if(qar.getName()=="Rook")
	{
		if(RookMoveIsPossible(qar, x, y, printError))
		{
		veradardz=true;
		}
	}
	if(qar.getName()=="Knight")
	{
		if(KnightMoveIsPossible(qar, x, y, printError))
		{
		veradardz=true;
		}
	}
	if(qar.getName()=="Bishop")
	{
		if(BishopMoveIsPossible(qar, x, y, printError))
		{
		veradardz=true;
		}
	}
	if(qar.getName()=="Queen")
	{
		if(QueenMoveIsPossible(qar, x, y, printError))
		{
		veradardz=true;
		}
	}
	if(qar.getName()=="King")
	{
		if(KingMoveIsPossible(qar, x, y, printError))
		{
		veradardz=true;
		}
	}
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
		vandak[qar.getX()][qar.getY()]=nullptr;

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