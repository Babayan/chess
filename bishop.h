#include "figure.h"

class Bishop: public figure
{
public:
	char getTar() const; //d

	std::string getName() const;

	Bishop(const int x, const int y, int guyn);

	bool moveIsPossible(const desk&, int, int, bool) const;
};
