#include "figure.h"

figure::figure(int x, int y, int c)
	: color(c), coordinate_x(x), coordinate_y(y)
{
}

const int figure::getColor() const
{
	return color;
}

int figure::getX() const
{
	return coordinate_x;
}

int figure::getY() const
{
	return coordinate_y;
}

void figure::setX(int x)
{
	coordinate_x = x;
}

void figure::setY(int y)
{
	coordinate_y = y;
}