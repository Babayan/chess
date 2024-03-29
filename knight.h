#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "figure.h"

class Knight: public figure //
{
public:
Knight(const int x, const int y, int guyn);

char getTar() const;
	
std::string getName() const;

virtual void moveIsPossible(const desk&, int, int) const;
};

#endif
