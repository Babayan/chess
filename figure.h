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
	virtual bool moveIsPossible(const desk&, int, int, bool) const = 0;
	bool isPawnSpecMove() const;
};




