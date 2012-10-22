#include "figure.h"
#include "desk.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std; //s

tox* toxi_dasavorich(std::string x)
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
		if(x[size-1]=='x') {
			mika->kill=true;
			x.erase(size-1, 1);
			size=x.length();
		} else {
			mika->kill=false;
		}
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
		if(doska.Check(this->getColor())) {
			doska.check=true;
		} else {
			doska.check=false;
		}

		if(doska.ThereIsMove(this->getColor())==0) {
			if(doska.check==true) {
				cout << endl << "    Xaxn avartvac e" <<endl << this->getName() << "-@ partutyun e krum" << endl <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";		
			} else {
				cout<<"Voch voqi";
			}
			int x;
			cin >> x;
			exit(0);
		} else if(doska.Check(this->getColor())) {
			cout<<endl<<"Duq gtnvum eq Shax i tak"<<endl;
		}
		
		string command;
		cout<<endl<<"Mutqagreq hramany "<<this->getName()<<": ";
		cin>>command;

		figure* pfigure;
		if (command=="O-O") {
			return makeShortCastling(doska);
		}

		if(commandIsTrue(command)==false) {
			cout<<endl<<"Sxal: Dzer koxmic nshvac hraman@ sxal e"<<endl<<endl;
			return false;
		}
		int x1=toxi_dasavorich(command)->coord11;
		int y1=toxi_dasavorich(command)->coord12;
		if (doska.getVandak(x1, y1)==0) {
			cout << endl << "Sxal: Duq cheq @ntrel xaxaqary" << endl << endl;
			return false;
		} else if (doska.getVandak(x1, y1)->getColor() != this->color) {
			cout << endl << "Sxal: Duq cheq karox xaxal hakarakordi xaxaqarerov" << endl << endl;
			return false;
		} else {
			pfigure=doska.getVandak(x1, y1);

			int x2=toxi_dasavorich(command)->coord21;
			int y2=toxi_dasavorich(command)->coord22;
		
			if(doska.MoveIsPossible(*pfigure, x2, y2, true) && (doska.KingIsProtected(*pfigure, x2, y2, true))) {
				doska.setCoordinates(*pfigure, x2, y2);
				doska.printDesk();
				return true;
			} else {
				return false;
			}
		}
	}
};



int main()
{
	int i(1);
	
	string playername1;
	string playername2;
	cout<<endl<<"Welcome to Console Chess!"<<endl<<endl<<endl;
	cout<<"Set the name of Player 1: ";
	cin>>playername1;
	cout<<endl<<"Set the name of Player 2: ";
	cin>>playername2;
	player player1(0, playername1);
	player player2(1, playername2);


	desk rdeskk;
	
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
	rdeskk.printDesk();

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
    return 0;
}
