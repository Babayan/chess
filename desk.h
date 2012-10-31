#ifndef CHESS_DESK_H
#define CHESS_DESK_H

#include <string>

class figure;

struct tox //
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
	mutable tox lastmove;

public:
	bool check;

	desk();

	~desk();

	bool Check(int guyn);

	bool ThereIsMove(int color);

	void KingIsProtected(figure& qar, const int x, const int y);

	bool CellIsProtected(const int, const int, int) const;

	void MoveIsPossible(const figure& qar, const int x, const int y) const;

	bool setCoordinates(figure& qar,const int x,const int y);

	bool makeShortCastling(int guyn);

	bool desk::makeLongCastling(int guyn);

	const figure* const getVandak(int x, int y) const;

	figure* getVandak(int x, int y);

	figure* getKing(int color);

	tox& getLastMove() const;

	void pawnReincarnation(int);

	void printDesk();

};

#endif
