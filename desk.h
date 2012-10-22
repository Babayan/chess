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

	bool Check(int guyn);

	bool ThereIsMove(int color);

	bool KingIsProtected(figure& qar, const int x, const int y, bool printError);

	bool MoveIsPossible(const figure& qar, const int x, const int y, bool printError);

	bool setCoordinates(figure& qar,const int x,const int y);

	bool makeShortCastling(int guyn);

	const figure* const getVandak(int x, int y) const;

	figure* getKing(int color);

	tox& getLastMove() const;

	void printDesk();

};