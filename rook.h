#include "figure.h"

class Rook: public figure
{
public:
	char getTar() const;

	std::string getName() const;

	Rook(const int x, const int y, int guyn);

	bool moveIsPossible(const desk&, int, int, bool) const;
};

