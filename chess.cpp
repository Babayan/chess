#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct tox
{
	char figure;
	int coord11;
	int coord12;
	bool kill;
	int coord21;
	int coord22;
	bool shax;	
};

tox* toxi_dasavorich(string x)
{
	tox* mika=new tox;
	mika->figure=false;
	mika->coord11=0;
	mika->coord12=0;
	mika->kill=false;

	int size=x.length(); 

	if (x[size-1]=='+') // Stugum enq shaxi arkayutyuny
	{
		mika->shax=true;
		x.erase(size-1, 1);
		size=x.length();
	} 
	else mika->shax=false;

	mika->coord22=int(x[size-1]-48); // Stanum enq 2 2 coordinaty
	x.erase(size-1, 1);
	size=x.length();

	mika->coord21=int(x[size-1]-96);

	x.erase(size-1, 1);
	size=x.length();
	
	if (size>0) // Kill i arkayutyuny
	{
		if(x[size-1]=='x')
		{
			mika->kill=true;
			x.erase(size-1, 1);
			size=x.length();;
		}
		else mika->kill=false;
	}
	
	if (size>0)
	{
	if (x[0]=='N' || x[0]=='B' || x[0]=='R' || x[0]=='Q' || x[0]=='K')
	{
		mika->figure=x[0];
		x.erase(0, 1);
		size=x.length();
	}
	else
		mika->figure=NULL;
	}

	if(size>0)
	{
		switch (x[0])
		{
		case 'a': mika->coord11=1;
			break;
		case 'b': mika->coord11=2;
			break;
		case 'c': mika->coord11=3;
			break;
		case 'd': mika->coord11=4;
			break;
		case 'e': mika->coord11=5;
			break;
		case 'f': mika->coord11=6;
			break;
		case 'g': mika->coord11=7;
			break;
		case 'h': mika->coord11=8;
			break;
		default: mika->coord11=0;
		};
		x.erase(0, 1);

		if(x.length()>0)
			mika->coord12=int(x[0]-48);
		else
			mika->coord12=0;
	}

	return mika;
};

class figure
{
public://stex piti lini private
	int lastycoord;
	enum {white, black} colorr;
	int color;
	char tar;
	int coordinate_x;
	int coordinate_y;
	string name;
	bool boool;
	figure()
	{
	}
	virtual int getColor()
	{
		return color;
	}
	virtual char getTar()
	{
		return tar;
	}
	virtual string getName()
	{
		return name;
	}
	virtual bool haveMove()
	{
		cout<<"ajiajiaji";
		return true;
	}
};

class desk
{
private:
	figure* vandak[9][9];
	tox lastmove;

public:
	bool check;
	desk()
	{
		
		for (int i=1; i<=8; i++)
		{
			for (int j=1; j<=8; j++)
			{
			vandak[i][j]=nullptr;
			}
		}
		check=false;
	}

	bool PawnMoveIsPossible(figure& qar, const int x, const int y, bool printError)
	{
		if (qar.getColor()==0)
		{
			if((vandak[x][y]!=0) & (abs(x-qar.coordinate_x)==1))
			{
				
				if(y-qar.coordinate_y==1)
					return true;
				if((x==qar.coordinate_x && x==5) && (getVandak(x,y)->lastycoord==7))
					return true;
			}
			if((vandak[x][y]==0) & (x==qar.coordinate_x))
			{
				if(y==qar.coordinate_y+1)
					return true;
				if((y==4) & (qar.coordinate_y==2))
					return true;
			}
			if((qar.coordinate_y==5) & (abs(qar.coordinate_x-x)==1) & (lastmove.coord11==lastmove.coord21) & (lastmove.coord11==x) & (lastmove.coord12-2==lastmove.coord22))
			{
				vandak[x][y-1]=0;
				return true;
			}
		}
		if (qar.getColor()==1)
		{
			if((vandak[x][y]!=0) & (abs(x-qar.coordinate_x)==1))
			{
				if(y-qar.coordinate_y==-1)
					return true;
				if(x==qar.coordinate_x && x==4 && getVandak(x,y)->lastycoord==2)
					return true;
			}
			if(vandak[x][y]==0 && x==qar.coordinate_x)
			{
				if(y==qar.coordinate_y-1)
					return true;
				if(y==5 && qar.coordinate_y==7)
					return true;
			}
			if(qar.coordinate_y==4 && abs(qar.coordinate_x-x)==1 && lastmove.coord11==lastmove.coord21 && lastmove.coord11==x && lastmove.coord12+2==lastmove.coord22)
			{
				vandak[x][y+1]=0;
				return true;
			}
		}
		if(printError)
			cout<<endl<<"Sxal: Peshkan chi karox aydpes sharjvel"<<endl<<endl;
		return false;
	};

	bool RookMoveIsPossible(figure& qar, const int x, const int y, bool printError)
	{
		if(x==qar.coordinate_x)
		{
			int mec;
			int poqr;

			if (y>qar.coordinate_y)
			{
				poqr=qar.coordinate_y;
				mec=y;
			}
			else  
			{
				poqr=y;
				mec=qar.coordinate_y;
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

		else if(y==qar.coordinate_y)
			{
				int mec;
				int poqr;

				if (x>qar.coordinate_x)
				{
					poqr=qar.coordinate_x;
					mec=x;
				}
				else  
				{
					poqr=x;
					mec=qar.coordinate_x;
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

	bool KnightMoveIsPossible(figure& qar, const int x, const int y, bool printError)
	{
		if((abs(x-qar.coordinate_x)==1 && abs(y-qar.coordinate_y)==2) || (abs(x-qar.coordinate_x)==2 && abs(y-qar.coordinate_y)==1))
			return true;
		else
		{
			if(printError)
				cout<<endl<<"Sxal: Dzin chi karox aydpes sharjvel"<<endl<<endl;
			return false;
		}

	}

	bool BishopMoveIsPossible(figure& qar, const int x, const int y, bool printError)
	{
		bool flag=true;
		if (x-y==qar.coordinate_x-qar.coordinate_y || x+y==qar.coordinate_x+qar.coordinate_y)
		{
			//flag=true;
			if (abs(x-qar.coordinate_x)>1)
			{
				if (x<qar.coordinate_x && y<qar.coordinate_y)
					for(int i=x+1; i<=qar.coordinate_x-1; i++)
						for(int j=y+1; j<=qar.coordinate_y-1; j++)
							if(vandak[i][j]!=0 && i-j==x-y)
							{
								if(printError)
									cout<<endl<<"Sxal: Pixy chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
								return false;
							};
				if (x>qar.coordinate_x && y>qar.coordinate_y)
					for(int i=qar.coordinate_x+1; i<=x-1; i++)
						for(int j=qar.coordinate_y+1; j<=y-1; j++)
							if(vandak[i][j]!=0 && i-j==x-y)
							{
								if(printError)
									cout<<endl<<"Sxal: Pixy chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
								return false;
							};
				if (x>qar.coordinate_x && y<qar.coordinate_y)
					for(int i=qar.coordinate_x+1; i<=x-1; i++)
						for(int j=y+1; j<=qar.coordinate_y-1; j++)
							if(vandak[i][j]!=0 && i+j==x+y)
							{
								if(printError)
									cout<<endl<<"Sxal: Pixy chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
								return false;
							};
				if (x<qar.coordinate_x && y>qar.coordinate_y)
					for(int i=x+1; i<=qar.coordinate_x-1; i++)
						for(int j=qar.coordinate_y+1; j<=y-1; j++)
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

	bool QueenMoveIsPossible(figure& qar, const int x, const int y, bool printError)
	{
		bool flag=false;
		//ete ankyunagceri vraya verjnakan kety
		if (x-y==qar.coordinate_x-qar.coordinate_y || x+y==qar.coordinate_x+qar.coordinate_y)
		{
			flag=true;
			//ete aranqum gone mi vandak ka
			if (abs(x-qar.coordinate_x)>1)
			{
				if (x<qar.coordinate_x && y<qar.coordinate_y)
					for(int i=x+1; i<=qar.coordinate_x-1; i++)
						for(int j=y+1; j<=qar.coordinate_y-1; j++)
							if(vandak[i][j]!=0 && i-j==x-y)
							{
								if(printError)
									cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
								return false;
							};
				if ((x>qar.coordinate_x) && (y>qar.coordinate_y))
					for(int i=qar.coordinate_x+1; i<=x-1; i++)
						for(int j=qar.coordinate_y+1; j<=y-1; j++)
							if(vandak[i][j]!=0 && i-j==x-y)
							{
								if(printError)
									cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
								return false;
							};
				if (x>qar.coordinate_x && y<qar.coordinate_y)
					for(int i=qar.coordinate_x+1; i<=x-1; i++)
						for(int j=y+1; j<=qar.coordinate_y-1; j++)
							if(vandak[i][j]!=0 && i+j==x+y)
							{
								if(printError)
									cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
								return false;
							};
				if (x<qar.coordinate_x && y>qar.coordinate_y)
					for(int i=x+1; i<=qar.coordinate_x-1; i++)
						for(int j=qar.coordinate_y+1; j<=y-1; j++)
							if(vandak[i][j]!=0 && i+j==x+y)
							{
								if(printError)
									cout<<endl<<"Sxal: Taguhin chi karox trnel urish xaxaqari vrayov"<<endl<<endl;
								return false;
							};


			}
		}

		if(x==qar.coordinate_x)
		{
			flag=true;
			int mec;
			int poqr;

			if (y>qar.coordinate_y)
			{
				poqr=qar.coordinate_y;
				mec=y;
			}
			else  
			{
				poqr=y;
				mec=qar.coordinate_y;
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

		else if(y==qar.coordinate_y)
			{
				flag=true;
				int mec;
				int poqr;

				if (x>qar.coordinate_x)
				{
					poqr=qar.coordinate_x;
					mec=x;
				}
				else  
				{
					poqr=x;
					mec=qar.coordinate_x;
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

	bool KingMoveIsPossible(figure& qar, const int x, const int y, bool printError)
	{
		if((abs(qar.coordinate_x-x)==1 && qar.coordinate_y==y) || (abs(qar.coordinate_y-y)==1 && qar.coordinate_x==x) || (abs(qar.coordinate_x-x)==1 && abs(qar.coordinate_y-y)==1))
			return true;
		else
		{
			//stex inch vor error@ etqan el chisht chem grel, chnayac harca
			if(printError)
				cout<<endl<<"Sxal: Tagavory chi karox mek vandakic avel trnel"<<endl<<endl;
			return false;
		}
	};

	bool Check(int guyn)
	{
		for(int i=1; i<=8;i++)
			for(int j=1; j<=8; j++)
			{
				if(vandak[i][j]!=0)
					if((vandak[i][j]->getColor()!=guyn))
						if ((MoveIsPossible(*vandak[i][j], getKing(guyn)->coordinate_x, getKing(guyn)->coordinate_y, false)))
						{
						return true;
						}
			}
			return false;
	}

	bool ThereIsMove(int color)
	{
		for(int i=1; i<=8; i++)
			for(int j=1; j<=8; j++)
				if(getVandak(i,j)!=0 && getVandak(i, j)->getColor()==color)
					for(int p=getVandak(i, j)->coordinate_x-2; p<=getVandak(i,j)->coordinate_x+2; p++)
						for(int q=getVandak(i, j)->coordinate_y-2; q<=getVandak(i, j)->coordinate_y+2; q++)
						{
							if(MoveIsPossible(*getVandak(i, j), p, q, false) && KingIsProtected(*getVandak(i, j), p, q, false))
							
							return true;
						}
		return false;
	}

	bool KingIsProtected(figure& qar, const int x, const int y, bool printError)
	{
		//paymanakan katarum enq qayl@
		int x0=qar.coordinate_x;
		int y0=qar.coordinate_y;
		vandak[x0][y0]=nullptr;
		vandak[x][y]=&qar;
		qar.coordinate_x=x;
		qar.coordinate_y=y;
		int guyn=qar.getColor();
		//bolor hakarakordi qareri hamar stugum enq tagavorin utelu hnaravorutyun@
		for(int i=1; i<=8;i++)
			for(int j=1; j<=8; j++)
			{
				if(vandak[i][j]!=0)
					if((vandak[i][j]->getColor()!=guyn))
						if ((MoveIsPossible(*vandak[i][j], getKing(guyn)->coordinate_x, getKing(guyn)->coordinate_y, false)))
					{
						if(printError)
						cout<<endl<<"Sxal: Hetevyal qaylov duq harvaci tak eq dnum dzer tagavorin"<<endl<<endl;

						vandak[x][y]=nullptr;
						vandak[x0][y0]=&qar;
						qar.coordinate_x=x0;
						qar.coordinate_y=y0;
						return false;
					}
			}
				vandak[x][y]=nullptr;
				vandak[x0][y0]=&qar;
				qar.coordinate_x=x0;
				qar.coordinate_y=y0;
				return true;
	}

	bool MoveIsPossible(figure& qar, const int x, const int y, bool printError) // stanuma figuran ev nor coord., ete hnaravora qayl@ veradarcnuma true 
	{
		bool veradardz=false;

		if(x<1 ||x>8 ||y<1 ||y>8)
			return false;
		if(qar.coordinate_x==x && qar.coordinate_y==y) //Stugum e, ardyoq xaxaqary texapoxvel e.
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
			if (getVandak(x,y)->getColor()==getVandak(qar.coordinate_x,qar.coordinate_y)->getColor())
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

	void setStartCoord(figure& qar, const int x, const int y)
	{
		qar.coordinate_x=x; 
		qar.coordinate_y=y;
		vandak[x][y]=&qar;
	};

	bool setCoordinates(figure& qar,const int x,const int y)
	{
			vandak[qar.coordinate_x][qar.coordinate_y]=nullptr;

			//lastmove um hishum enq verjin qayl@
			lastmove.coord11=qar.coordinate_x;
			lastmove.coord12=qar.coordinate_y;
			lastmove.coord21=x;
			lastmove.coord22=y;

			qar.coordinate_x=x; 
			qar.coordinate_y=y;
			vandak[x][y]=&qar;
			return true;
	}

	bool makeShortCastling(int guyn)
	{
		cout<<"mtanq makeSHortCastling"<<getVandak(5,1)->getName()<<getVandak(5,1)->getColor()<<getVandak(8,1)->getName();
		if(guyn==0 && getVandak(5,1)->getName()=="King" && getVandak(5,1)->getColor()==0 && getVandak(6,1)==0 && getVandak(7,1)==0 && getVandak(8,1)->getName()=="Rook" && getVandak(8,1)->getColor()==0) 
		{
			cout<<"lala";
			vandak[7][1]=getVandak(5,1);
			vandak[5][1]=0;
			vandak[6][1]=getVandak(8,1);
			vandak[8][1]=0;
			getVandak(7,1)->coordinate_x=7;
			getVandak(7,1)->coordinate_y=1;
			getVandak(6,1)->coordinate_x=6;
			getVandak(6,1)->coordinate_y=1;
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
			getVandak(7,8)->coordinate_x=7;
			getVandak(7,8)->coordinate_y=8;
			getVandak(6,8)->coordinate_x=6;
			getVandak(6,8)->coordinate_y=8;
			printDesk();
			return true;
		}
		return false;
	}

	figure* getVandak(int x, int y)
	{
		if (vandak[x][y])
		return vandak[x][y];
		else return 0;
	}

	figure* getKing(int color)
	{
		for(int i=1; i<=8; i++)
			for(int j=1; j<=8; j++)
				if(getVandak(i,j)!=0)
					if(getVandak(i,j)->getName()=="King" && getVandak(i,j)->getColor()==color)
					{
						return getVandak(i,j);
					}
	}

	void printDesk()
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

};

class Pawn: public figure
{
	string name;
	enum {white=1, black=2} colorr;
public:	int color;
		int lastycoord;
public:
	int getColor()
	{
		return color;
	}
	char getTar()
	{
		return 'P';
	}
	bool haveMove(desk& desk1)
	{
		cout<<"ES PAWN I HAVEMOVE NEM";
		for(int i=this->coordinate_x-1; i<=this->coordinate_x+1; i++)
			for(int j=this->coordinate_y-1; i<=this->coordinate_y+1; j++)
				if(desk1.MoveIsPossible(*this, i, j, false) && desk1.KingIsProtected(*this, i, j, false))
					return true;
			return false;
	}

	Pawn(desk& doska, const int x, const int y, int guyn)
	{
		color=guyn;
		name="Pawn";
		doska.setStartCoord(*this, x, y);
	}
	string getName()
	{
		return name;
	}
};

class Knight: public figure
{
	string name;
	int color;
public:
	bool haveMove(desk& desk1)
	{
		cout<<"ES KNIGHT I HAVEMOVE NEM";
		for(int i=this->coordinate_x-2; i<=this->coordinate_x+2; i++)
			for(int j=this->coordinate_y-2; i<=this->coordinate_y+2; j++)
				//if(desk1.MoveIsPossible(*this, i, j, false) && desk1.KingIsProtected(*this, i, j))
					return true;
			return false;
	}
	int getColor()
	{
		return color;
	}
	char getTar()
	{
		return 'N';
	}
	Knight(desk& doska, const int x, const int y, int guyn)
	{
		color=guyn;
		name="Knight";
		doska.setStartCoord(*this, x, y);
	}
	string getName()
	{
		return name;
	}
};

class Bishop: public figure
{
	string name;
	int color;
public:
	bool haveMove(desk& desk1)
	{
		cout<<"ES BISHOP I HAVEMOVE NEM";
		for(int i=this->coordinate_x-1; i<=this->coordinate_x+1; i++)
			for(int j=this->coordinate_y-1; i<=this->coordinate_y+1; j++)
			//	if(desk1.MoveIsPossible(*this, i, j, false) && desk1.KingIsProtected(*this, i, j))
					return true;
			return false;
	}
	int getColor()
	{
		return color;
	}
	char getTar()
	{
		return 'B';
	}
	Bishop(desk& doska, const int x, const int y, int guyn)
	{
		color=guyn;
		name="Bishop";
		doska.setStartCoord(*this, x, y);
	}
	string getName()
	{
		return name;
	}
};

class Rook: public figure
{
	string name;
	int color;
public:
	bool haveMove(desk& desk1)
	{
		cout<<"ES ROOK I HAVEMOVE NEM";
		for(int i=this->coordinate_x-1; i<=this->coordinate_x+1; i++)
			for(int j=this->coordinate_y-1; i<=this->coordinate_y+1; j++)
			//	if(desk1.MoveIsPossible(*this, i, j, false) && desk1.KingIsProtected(*this, i, j))
					return true;
			return false;
	}
	int getColor()
	{
		return color;
	}
	char getTar()
	{
		return 'R';
	}
	Rook(desk& doska, const int x, const int y, int guyn)
	{
		color=guyn;
		name="Rook";
		doska.setStartCoord(*this, x, y);
	}
	string getName()
	{
		return name;
	}
};

class Queen: public figure
{
	string name;
	int color;
public:
	bool haveMove(desk& desk1)
	{
		cout<<"ES QUEEN I HAVEMOVE NEM";
		for(int i=this->coordinate_x-1; i<=this->coordinate_x+1; i++)
			for(int j=this->coordinate_y-1; i<=this->coordinate_y+1; j++)
			//	if(desk1.MoveIsPossible(*this, i, j, false) && desk1.KingIsProtected(*this, i, j))
					return true;
			return false;
	}
	int getColor()
	{
		return color;
	}
	char getTar()
	{
		return 'Q';
	}
	Queen(desk& doska, const int x, const int y, int guyn)
	{
		color=guyn;
		name="Queen";
		doska.setStartCoord(*this, x, y);
	}
	string getName()
	{
		return name;
	}
};

class King: public figure
{
	string name;
	int color;
public:
	bool haveMove(desk& desk1)
	{
		cout<<"ES KING I HAVEMOVE NEM";
		for(int i=this->coordinate_x-1; i<=this->coordinate_x+1; i++)
			for(int j=this->coordinate_y-1; i<=this->coordinate_y+1; j++)
			//	if(desk1.MoveIsPossible(*this, i, j, false) && desk1.KingIsProtected(*this, i, j))
					return true;
			return false;
	}
	int getColor()
	{
		return color;
	}
	char getTar()
	{
		return 'K';
	}
	King(desk& doska, const int x, const int y, int guyn)
	{
		color=guyn;
		name="King";
		doska.setStartCoord(*this, x, y);
	}
	string getName()
	{
		return name;
	}
};

class player
{
private:
	string name;
	int color;

public:
	player(int color1, string name1)
	{
		color=color1;
		name=name1;
	}

	string getName()
	{
		return name;
	}

	int getColor()
	{
		return color;
	}

	bool commandIsTrue(string command1)
	{
		if(command1.length()!=4 || command1[0]-96>8 || command1[0]-96<1 || command1[2]-96>8 || command1[2]-96<1 || command1[1]-48>8 || command1[1]-48<1 || command1[3]-48>8 || command1[3]-48<1)
		{
			return false;
		}
		return true;
	}

	bool makeShortCastling(desk& doska)
	{
		cout<<"mtanq O-O u this->color="<<this->color;
			int bigudi=this->color;
			if(doska.makeShortCastling(bigudi)==true)
				return true;
			else
			{
				cout<<endl<<"Sxal: Duq cheq karox katarel karch rokirovka"<<endl<<endl;
				return false;
			}
	}

	bool makeMove(desk& doska)
	{

		if(doska.Check(this->getColor()))
			{
				doska.check=true;
			}
			else
			doska.check=false;

		if(doska.ThereIsMove(this->getColor())==0)
			if(doska.check==true)
			{
				cout<<endl<<"    Xaxn avartvac e"<<endl<<this->getName()<<"-@ partutyun e krum"<<endl<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
				int x;
				cin>>x;
			}
			else
			{
				cout<<"Voch voqi";
				int x;
				cin>>x;
			}
		else
				if(doska.Check(this->getColor()))
				cout<<endl<<"Duq gtnvum eq Shax i tak"<<endl;
			


		string command;
		cout<<endl<<"Mutqagreq hramany "<<this->getName()<<": ";
		cin>>command;

		figure* pfigure;
		if (command=="O-O")
		{
			if (makeShortCastling(doska))
				return true;
			else 
				return false;
		}

		if(commandIsTrue(command)==false)
		{
			cout<<endl<<"Sxal: Dzer koxmic nshvac hraman@ sxal e"<<endl<<endl;
			return false;
		}

		int x1=toxi_dasavorich(command)->coord11;
		int y1=toxi_dasavorich(command)->coord12;
		if (doska.getVandak(x1, y1)==0)
		{
			cout<<endl<<"Sxal: Duq cheq @ntrel xaxaqary"<<endl<<endl;
			return false;
		}
		else if (doska.getVandak(x1, y1)->getColor()!=this->color)
				{
					cout<<endl<<"Sxal: Duq cheq karox xaxal hakarakordi xaxaqarerov"<<endl<<endl;
					return false;
				}

				else
					{
						
						pfigure=doska.getVandak(x1, y1);

						int x2=toxi_dasavorich(command)->coord21;
						int y2=toxi_dasavorich(command)->coord22;
		
						if(doska.MoveIsPossible(*pfigure, x2, y2, true) && (doska.KingIsProtected(*pfigure, x2, y2, true)))
						{
							doska.setCoordinates(*pfigure, x2, y2);
							doska.printDesk();
							return true;
						}
						else
							return false;
					}
	}



	
};

void main()
{int i(1);
	
	string playername1;
	string playername2;
	cout<<endl<<"Welcome to Console Chess!"<<endl<<endl<<endl;
	cout<<"Set the name of Player 1: ";
	cin>>playername1;
	cout<<endl<<"Set the name of Player 2: ";
	cin>>playername2;
	player player1(0, playername1);
	player player2(1, playername2);


	desk deskk;
	desk& rdeskk(deskk);
	int winner;

	/*cin>>command;
	cout<<endl
		<<toxi_dasavorich(command)->figure
		<<toxi_dasavorich(command)->coord11
		<<toxi_dasavorich(command)->coord12
		<<toxi_dasavorich(command)->kill
		<<toxi_dasavorich(command)->coord21
		<<toxi_dasavorich(command)->coord22
		<<toxi_dasavorich(command)->shax<<endl;
	*/

	Pawn pawn1(rdeskk, 1, 2, 0);
	Pawn& rpawn1(pawn1);

	Pawn pawn2(rdeskk, 2, 2, 0);
	Pawn& rpawn2(pawn2);

	Pawn pawn3(rdeskk, 3, 2, 0);
	Pawn& rpawn3(pawn3);

	Pawn pawn4(rdeskk, 4, 2, 0);
	Pawn& rpawn4(pawn4);

	Pawn pawn5(rdeskk, 5, 2, 0);
	Pawn& rpawn5(pawn5);

	Pawn pawn6(rdeskk, 6, 2, 0);
	Pawn& rpawn6(pawn6);

	Pawn pawn7(rdeskk, 7, 2, 0);
	Pawn& rpawn7(pawn7);

	Pawn pawn8(rdeskk, 8, 2, 0);
	Pawn& rpawn8(pawn8);

	Rook rook1(rdeskk, 1, 1, 0);
	Rook& rrook1(rook1);
	Rook rook2(rdeskk, 8, 1, 0);
	Rook& rrook2(rook2);

	Knight knight1(rdeskk, 2, 1, 0);
	Knight& rknight1(knight1);
	Knight knight2(rdeskk, 7, 1, 0);
	Knight& rknight2(knight2);

	Bishop bishop1(rdeskk, 3, 1, 0);
	Bishop& rbishop1(bishop1);
	Bishop bishop2(rdeskk, 6, 1, 0);
	Bishop& rbishop2(bishop2);

	Queen queen1(rdeskk, 4, 1, 0);
	Queen& rqueen1(queen1);

	King king1(rdeskk, 5, 1, 0);
	King& rking1(king1);



	Pawn pawn9(rdeskk, 1, 7, 1);
	Pawn& rpawn9(pawn9);

	Pawn pawn10(rdeskk, 2, 7, 1);
	Pawn& rpawn10(pawn10);

	Pawn pawn11(rdeskk, 3, 7, 1);
	Pawn& rpawn11(pawn11);

	Pawn pawn12(rdeskk, 4, 7, 1);
	Pawn& rpawn12(pawn12);

	Pawn pawn13(rdeskk, 5, 7, 1);
	Pawn& rpawn13(pawn13);

	Pawn pawn14(rdeskk, 6, 7, 1);
	Pawn& rpawn14(pawn14);

	Pawn pawn15(rdeskk, 7, 7, 1);
	Pawn& rpawn15(pawn15);

	Pawn pawn16(rdeskk, 8, 7, 1);
	Pawn& rpawn16(pawn16);

	Rook rook3(rdeskk, 1, 8, 1);
	Rook& rrook3(rook3);
	Rook rook4(rdeskk, 8, 8, 1);
	Rook& rrook4(rook4);

	Knight knight3(rdeskk, 2, 8, 1);
	Knight& rknight3(knight3);
	Knight knight4(rdeskk, 7, 8, 1);
	Knight& rknight4(knight4);

	Bishop bishop3(rdeskk, 3, 8, 1);
	Bishop& rbishop3(bishop3);
	Bishop bishop4(rdeskk, 6, 8, 1);
	Bishop& rbishop4(bishop4);

	Queen queen2(rdeskk, 4, 8, 1);
	Queen& rqueen2(queen2);

	King king2(rdeskk, 5, 8, 1);
	King& rking2(king2);


	deskk.printDesk();





	
	while (i)
	{
		do 
		{
		}
		while (player1.makeMove(rdeskk)==false);

		do 
		{
		}
		while (player2.makeMove(rdeskk)==false);
	}

	if (winner==1)
		cout<<endl<<"Xaxn avartvac e. Haxtox i anunn e` "<<player1.getName()<<endl;
	else if(winner==2)
			cout<<endl<<"Xaxn avartvac e. Haxtox i anunn e` "<<player2.getName()<<endl;
	else
		cout<<endl<<"Xaxn avartvac e voch voqi ov";

	cin>>i;
}