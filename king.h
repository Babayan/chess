#include "figure.h"

class King: public figure //
{
public:
	char getTar() const;
	
	std::string getName() const;
	
	King(const int x, const int y, int guyn);

	virtual bool moveIsPossible(const desk&, int, int, bool) const;
};