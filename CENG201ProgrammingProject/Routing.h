//27.12.2014
//The class of the Alogrothims that will solve the maze
#ifndef _ROUTING
#define _ROUTING
#include "Position.h"
#include "Lists.cpp"




class Routing{

public:
	static bool Stack_Solving(char ** maze, const int& size, const Position& robot, const Position& goal);
	static bool Queue_Solving(char ** maze, const int& size, const Position& robot, const Position& goal);
	static bool Opt_Solving(char ** maze, const int& size, const Position& robot, const Position& goal);

	
};
#endif