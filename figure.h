#ifndef CHESS_FIGURE_H
#define CHESS_FIGURE_H

#include <string>

class desk;

class figure //
{
public:
	enum  colorr {white, black};

private:
	const int color;
	int coordinate_x;
	int coordinate_y;

public:
	figure(int x, int y, int c);
	
	const int getColor() const;

	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);

	virtual char getTar() const = 0;
	virtual std::string getName() const = 0;
	virtual void moveIsPossible(const desk&, int, int) const = 0;
	bool isPawnSpecMove() const;
};

#endif
