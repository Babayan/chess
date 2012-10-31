#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "figure.h"

class Pawn: public figure //
{
private:
	mutable bool specMove;
public:
	Pawn(const int x, const int y, int guyn);

	char getTar() const;

	std::string getName() const;

	virtual void moveIsPossible(const desk&, int, int) const;

	bool isPawnSpecMove() const
	{
		return specMove;
	}
};

#endif
