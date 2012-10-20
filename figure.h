#include <string>

class figure
{
public:
	enum  colorr {white, black};

private:
	const int color;
	int coordinate_x;
	int coordinate_y;

public:
	int lastycoord;

public:
	figure(int x, int y, int c);
	
	const int getColor() const;

	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);

	virtual char getTar() const = 0;
	virtual std::string getName() const = 0;
};

class Pawn: public figure
{
public:
	Pawn(const int x, const int y, int guyn)
		: figure(x, y, guyn)
	{
	}

	char getTar() const
	{
		return 'P';
	}

	std::string getName() const
	{
		return "Pawn";
	}
};

class Knight: public figure
{
public:
	char getTar() const
	{
		return 'N';
	}
	
	std::string getName() const
	{
		return "Knight";
	}

	Knight(const int x, const int y, int guyn)
		: figure(x, y, guyn)
	{
	}
	
};

class Bishop: public figure
{
public:
	char getTar() const
	{
		return 'B';
	}

	std::string getName() const
	{
		return "Bishop";
	}

	Bishop(const int x, const int y, int guyn)
		: figure(x, y, guyn)
	{
	}
};

class Rook: public figure
{
public:
	char getTar() const
	{
		return 'R';
	}

	std::string getName() const
	{
		return "Rook";
	}
	Rook(const int x, const int y, int guyn)
		: figure(x, y, guyn)
	{
	}
};

class Queen: public figure
{
public:

	char getTar() const
	{
		return 'Q';
	}
	
	std::string getName() const
	{
		return "Queen";
	}

	Queen(const int x, const int y, int guyn)
		: figure(x, y, guyn)
	{
	}
};

class King: public figure
{
public:
	char getTar() const
	{
		return 'K';
	}
	
	std::string getName() const
	{
		return "King";
	}
	
	King(const int x, const int y, int guyn)
		: figure(x, y, guyn)
	{
	}
};