#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "figure.h"

class Bishop: public figure
{
public:
	char getTar() const; //d

	std::string getName() const;

	Bishop(const int x, const int y, int guyn);

	void moveIsPossible(const desk&, int, int) const;
};

#endif
