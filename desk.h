#include <string>

class figure;

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

class desk
{
private:
	figure* vandak[9][9];
	tox lastmove;

public:
	bool check;
	desk();

	bool PawnMoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool RookMoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool KnightMoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool BishopMoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool QueenMoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool KingMoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool Check(int guyn);

	bool ThereIsMove(int color);

	bool KingIsProtected(figure& qar, const int x, const int y, bool printError);

	bool MoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool setCoordinates(figure& qar,const int x,const int y);

	bool makeShortCastling(int guyn);

	figure* getVandak(int x, int y);

	figure* getKing(int color);

	void printDesk();

};