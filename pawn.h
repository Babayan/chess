#include "figure.h"

class Pawn: public figure
{
private:
	mutable bool specMove;
public:
	Pawn(const int x, const int y, int guyn);

	char getTar() const;

	std::string getName() const;

	virtual bool moveIsPossible(const desk&, int, int, bool) const;

	bool isPawnSpecMove() const
	{
		return specMove;
	}
};