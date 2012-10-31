#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "figure.h"

class Queen: public figure //
{
public:

	char getTar() const;
	std::string getName() const;
	Queen(const int x, const int y, int guyn);
    void moveIsPossible(const desk& d, int, int) const;
};

#endif
