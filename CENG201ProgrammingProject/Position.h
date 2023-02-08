//26.12
//position class to help in solving the maze
#ifndef _POSITION
#define _POSITION


class Position{
private:
	int x;
	int y;
public:
	Position();
	Position(const int& posx, const int& posy);

	void setx(const int& posx);
	void sety(const int& posy);
	int getx()const;
	int gety()const;
	Position east()const;
	Position west()const;
	Position north()const;
	Position south()const;
	bool isEquale(const Position& pos)const;
};
#endif