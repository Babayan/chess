#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "figure.h"

class King: public figure //
{
private:
	bool madeMove;
public:
	bool is_moved() const;
	
	void set_moved();

	char getTar() const;
	
	std::string getName() const;
	
	King(const int x, const int y, int guyn);

	virtual void moveIsPossible(const desk&, int, int) const;
};

#endif
