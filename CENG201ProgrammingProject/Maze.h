//26/12
#ifndef _MAZE
#define _MAZE


#include<string>
#include "Position.h"
#include <fstream>
#include <iostream>
using namespace std;

class Maze{
private:
	Position robotpos;
	Position goalpos;
	int dimantion;
	char ** map;//our maze map
	bool search();//search for goal and robot positions
public:
	Maze();
	void read(const string& file, bool coordinate);
	void write(const string& file, bool coordinate);
	Position getrobot()const;
	Position getgoal()const;
	char** getmaze()const;
	int getDimantion()const;

};
#endif