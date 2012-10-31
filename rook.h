#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "figure.h"

class Rook: public figure //
{
private:
	bool madeMove;
public:
	bool is_moved() const;

	void set_moved();

	char getTar() const;

	std::string getName() const;

	Rook(const int x, const int y, int guyn);

	void moveIsPossible(const desk&, int, int) const;
};

#endif
