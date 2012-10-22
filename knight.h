#include "figure.h"

class Knight: public figure //
{
public:
Knight(const int x, const int y, int guyn);

char getTar() const;
	
std::string getName() const;

virtual bool moveIsPossible(const desk&, int, int, bool) const;
};