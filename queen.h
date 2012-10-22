#include "figure.h"

class Queen: public figure //
{
public:

	char getTar() const;
	std::string getName() const;
	Queen(const int x, const int y, int guyn);
	bool moveIsPossible(const desk& d, const int x, const int y, bool printError);
};